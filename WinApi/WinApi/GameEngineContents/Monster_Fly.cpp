
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


void Monster_Fly::ImageLoad()
{
		GameEngineDirectory Dir;
		Dir.MoveParentToDirectory("ContentsResources");
		Dir.Move("ContentsResources");
		Dir.Move("Image");
		Dir.Move("Play");
		Dir.Move("Monster");

		GameEngineImage* Monster1 = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("M_fly.BMP"));
		Monster1->Cut(2, 1);
		GameEngineImage* Monster1D = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("M_fly_Dead.BMP"));
		Monster1D->Cut(5, 3);
}


void Monster_Fly::Start()
{
	ImageLoad();
	M_fly = CreateRender(IsaacOrder::R_Monster);
	M_fly->SetScale({ 150, 150 });
	SetPos({ 200,200 });
	
	
	M_fly->CreateAnimation({ .AnimationName = "M_fly_Idle",  .ImageName = "M_fly.bmp", .Start = 0, .End = 1, .InterTime = 0.1f });
	M_fly->CreateAnimation({ .AnimationName = "M_fly_Dead",  .ImageName = "M_fly_Dead.bmp", .Start = 0, .End = 11, .InterTime = 0.03f, .Loop = false});
	//처음엔 그냥 날아다니게
	M_fly->ChangeAnimation("M_fly_Idle");
	
	{
		
		M_fly_Coll = CreateCollision(IsaacCollisionOrder::C_Monster);
		M_fly_Coll->SetScale({ 35, 35});
		M_fly_Coll->On();
		M_fly_Coll->SetDebugRenderType(CollisionType::CT_Rect);
	}
	
}

bool Deathcheck = false;
void Monster_Fly::Update(float _DeltaTime)
{
	Movecalculation(_DeltaTime);
	CollisionCheck(_DeltaTime);
}

void Monster_Fly::Movecalculation(float _DeltaTime)
{
	float4 M_Move = Isaac::MainPlayer->GetPos() - GetPos();
	M_Move.Normalize();

	SetMove(M_Move * 100.0f * _DeltaTime); //안따라다니게할때는 M_Move를 다르게설정하면될듯 >>움직이는 제한pos를 BackGround_CS로 해야함
}


void Monster_Fly::CollisionCheck(float _DeltaTime)
{
	NowTime += _DeltaTime;
	if (NowTime >= 0.5f) //다음상호작용이 되려면 이만큼의 시간이 흘러야한다(몬스터가 죽는애니메이션시간보다는 길어야함)
	{
		NowTime = 0.0f;
		M_fly_Coll->On();  //시간이지나면 다시collision을킨다
		RESET = 1;
		if (true == Deathcheck) //hp가 떨어진게 확인되면
		{
			Death(); //없앤다
		}
	}

	std::vector<GameEngineCollision*> FCollisions;
	CollisionCheckParameter Check = { .TargetGroup = static_cast<int>(IsaacCollisionOrder::C_PlayerAtt), .TargetColType = CT_Rect, .ThisColType = CT_Rect };

	if (true == M_fly_Coll->Collision(Check, FCollisions)) //PlayerAtt에 닿았을때
	{
		FCollisions[0]->GetActor()->Death(); //닿은 ATT는 지워버리고

		if (1 == RESET)
		{
			SetMove(float4::Left * 10); //맞으면 밀려남(매끄럽게안밀려남) 방향에따른 설정도해야할듯
			FlyHp = FlyHp - 1;
			RESET = 0;
			M_fly_Coll->Off(); //맞아도 일정시간동안 상호작용이안된다.
		}
		if (0 >= FlyHp)
		{
			M_fly->ChangeAnimation("M_fly_Dead");
			Deathcheck = true;
		}
	}
	
	CollisionCheckParameter B_Check = { .TargetGroup = static_cast<int>(IsaacCollisionOrder::C_Bomb), .TargetColType = CT_Rect, .ThisColType = CT_Rect };
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
	//M_fly_Coll->DebugRender();
}