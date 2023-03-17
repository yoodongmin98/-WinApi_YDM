
#include <GameEngineBase/GameEngineDirectory.h>

#include <GameEnginePlatform/GameEngineInput.h>

#include <GameEngineCore/GameEngineRender.h>
#include <GameEngineCore/GameEngineResources.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCollision.h>


#include "Isaac.h"
#include "IsaacEnum.h"
#include "Monster_Fly.h"


Monster_Fly::Monster_Fly()
{
	
}

Monster_Fly::~Monster_Fly()
{
	
}

bool FlyLoad = true;
void Monster_Fly::ImageLoad()
{
		GameEngineDirectory Dir;
		Dir.MoveParentToDirectory("ContentsResources");
		Dir.Move("ContentsResources");
		Dir.Move("Image");
		Dir.Move("Play");
		Dir.Move("Monster");

		GameEngineImage* Monster1 = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("M_fly.BMP"));
		Monster1->Cut(4, 2);
		GameEngineImage* Monster1D = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("M_fly_Dead.BMP"));
		Monster1D->Cut(5, 3);

		////////////////////Dead Defalut
		GameEngineImage* MonsterDeads = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("M_Blood.BMP"));
		MonsterDeads->Cut(5, 4);
		GameEngineImage* MonsterBodys = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("M_Blood_deadbody.BMP"));
		MonsterBodys->Cut(4, 4);
}


void Monster_Fly::Start()
{
	Isaac::MainPlayer->PlusMOnsterCount(1);
	if (true == FlyLoad)
	{
		ImageLoad();
		FlyLoad = false;
	}
	M_fly = CreateRender(IsaacOrder::R_Monster);
	M_fly->SetScale({ 80, 80 });

	DeadRender = CreateRender(IsaacOrder::R_MonsterDead);
	DeadRender->SetScale({ 80, 80 });
	
	
	M_fly->CreateAnimation({ .AnimationName = "M_fly_Idle",  .ImageName = "M_fly.bmp", .Start = 0, .End = 1, .InterTime = 0.1f });
	M_fly->CreateAnimation({ .AnimationName = "M_fly_Damage",  .ImageName = "M_fly.bmp", .Start = 5, .End = 6, .InterTime = 0.1f });
	M_fly->CreateAnimation({ .AnimationName = "M_fly_Dead",  .ImageName = "M_fly_Dead.bmp", .Start = 0, .End = 11, .InterTime = 0.03f, .Loop = false});
	//처음엔 그냥 날아다니게
	M_fly->ChangeAnimation("M_fly_Idle");


	DeadRender->CreateAnimation({ .AnimationName = "Dead",  .ImageName = "M_Blood.bmp", .Start = 0, .End = 0, .InterTime = 0.1f, .Loop = false });
	DeadRender->ChangeAnimation("Dead");
	DeadRender->Off();
	
	{
		
		M_fly_Coll = CreateCollision(IsaacCollisionOrder::C_Monster);
		M_fly_Coll->SetScale({ 35, 35});
		M_fly_Coll->On();
		M_fly_Coll->SetDebugRenderType(CollisionType::CT_Rect);
	}

	FlyHp = 3;
}


void Monster_Fly::Update(float _DeltaTime)
{
	if (0 >= FlyHp)
	{
		M_fly->ChangeAnimation("M_fly_Dead");
		Deathcheck = true;
	}
	
	if (true == Deathcheck) //hp가 떨어진게 확인되면
	{
		if (true == Countbool)
		{
			Isaac::MainPlayer->MinusMonsterCount(1);
			Countbool = false;
		}
		M_fly->Death();
		M_fly_Coll->Death();
		DeadRender->On();
	}
	Movecalculation(_DeltaTime);
	CollisionCheck(_DeltaTime);
}

void Monster_Fly::Movecalculation(float _DeltaTime)
{
	float4 M_Move = Isaac::MainPlayer->GetPos() - GetPos();
	M_Move.Normalize();
	if (true == Deathcheck) //hp가 떨어진게 확인되면
	{
		M_Move = float4::Zero;
	}
	SetMove(M_Move * 70.0f * _DeltaTime); //안따라다니게할때는 M_Move를 다르게설정하면될듯 >>움직이는 제한pos를 BackGround_CS로 해야함
}


void Monster_Fly::CollisionCheck(float _DeltaTime)
{
	NowTime += _DeltaTime;
	if (NowTime >= 0.5f) //다음상호작용이 되려면 이만큼의 시간이 흘러야한다(몬스터가 죽는애니메이션시간보다는 길어야함)
	{
		M_fly->ChangeAnimation("M_fly_Idle"); //다시 idle로바꾸고
		NowTime = 0.0f;
		M_fly_Coll->On();  //시간이지나면 다시collision을킨다
		RESET = 1;
	}

	std::vector<GameEngineCollision*> FCollisions;
	CollisionCheckParameter Check = { .TargetGroup = static_cast<int>(IsaacCollisionOrder::C_PlayerAtt_L), .TargetColType = CT_Rect, .ThisColType = CT_Rect };
	CollisionCheckParameter Check1 = { .TargetGroup = static_cast<int>(IsaacCollisionOrder::C_PlayerAtt_R), .TargetColType = CT_Rect, .ThisColType = CT_Rect };
	CollisionCheckParameter Check2 = { .TargetGroup = static_cast<int>(IsaacCollisionOrder::C_PlayerAtt_U), .TargetColType = CT_Rect, .ThisColType = CT_Rect };
	CollisionCheckParameter Check3 = { .TargetGroup = static_cast<int>(IsaacCollisionOrder::C_PlayerAtt_D), .TargetColType = CT_Rect, .ThisColType = CT_Rect };

	//함수짤 시간에 그냥 복붙을하겠노라
	if (true == M_fly_Coll->Collision(Check, FCollisions)) //PlayerAtt에 닿았을때
	{
		M_fly->ChangeAnimation("M_fly_Damage");
		FCollisions[0]->GetActor()->Death(); //닿은 ATT는 지워버리고
		SetMove(float4::Left * 20); //맞으면 밀려남(매끄럽게안밀려남)

		if (1 == RESET)
		{
			FlyHp = FlyHp - Isaac::MainPlayer->GetTearDamage();
			RESET = 0;
			M_fly_Coll->Off(); //맞아도 일정시간동안 상호작용이안된다.
		}
		
	}

	if (true == M_fly_Coll->Collision(Check1, FCollisions)) 
	{
		M_fly->ChangeAnimation("M_fly_Damage");
		FCollisions[0]->GetActor()->Death();
		SetMove(float4::Right * 20); 

		if (1 == RESET)
		{
			FlyHp = FlyHp - Isaac::MainPlayer->GetTearDamage();
			RESET = 0;
			M_fly_Coll->Off(); 
		}
	}
	if (true == M_fly_Coll->Collision(Check2, FCollisions)) 
	{
		M_fly->ChangeAnimation("M_fly_Damage");
		FCollisions[0]->GetActor()->Death(); 
		SetMove(float4::Up * 20); 

		if (1 == RESET)
		{
			FlyHp = FlyHp - Isaac::MainPlayer->GetTearDamage();
			RESET = 0;
			M_fly_Coll->Off(); 
		}
	}
	if (true == M_fly_Coll->Collision(Check3, FCollisions)) 
	{
		M_fly->ChangeAnimation("M_fly_Damage");
		FCollisions[0]->GetActor()->Death(); 
		SetMove(float4::Down * 20); 

		if (1 == RESET)
		{
			FlyHp = FlyHp - Isaac::MainPlayer->GetTearDamage();
			RESET = 0;
			M_fly_Coll->Off(); 
		}
	}
	













	CollisionCheckParameter B_Check = { .TargetGroup = static_cast<int>(IsaacCollisionOrder::C_Isaac_Bomb), .TargetColType = CT_Rect, .ThisColType = CT_Rect };
	if (true == M_fly_Coll->Collision(B_Check, FCollisions))
	{
		FlyHp = FlyHp - 5; //이것은 폭탄의 데미지여
		if (0 >= FlyHp)
		{
			M_fly->ChangeAnimation("M_fly_Dead");
			Deathcheck = true;
		}
	}
}

void Monster_Fly::Render(float _DeltaTime)
{
	if (GameEngineInput::IsPress("MapCollisionSwitch"))
	{
		M_fly_Coll->DebugRender();
	}
	//M_fly_Coll->DebugRender();
}