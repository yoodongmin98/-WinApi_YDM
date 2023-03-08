
#include <GameEngineBase/GameEngineDirectory.h>

#include <GameEnginePlatform/GameEngineInput.h>

#include <GameEngineCore/GameEngineRender.h>
#include <GameEngineCore/GameEngineResources.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCollision.h>


#include "Isaac.h"
#include "IsaacEnum.h"
#include "Pooter.h"
#include "BloodTear.h"


Pooter::Pooter()
{

}

Pooter::~Pooter()
{
}

bool PooterLoad = true;
void Pooter::ImageLoad()
{
	GameEngineDirectory Dir;
	Dir.MoveParentToDirectory("ContentsResources");
	Dir.Move("ContentsResources");
	Dir.Move("Image");
	Dir.Move("Play");
	Dir.Move("Monster");

	GameEngineImage* Monster12 = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("M_Pooter.BMP"));
	Monster12->Cut(4, 4);
	GameEngineImage* Monster123 = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("M_Pooter_L.BMP"));
	Monster123->Cut(4, 4);
	
}


void Pooter::Start()
{
	Isaac::MainPlayer->PlusMOnsterCount(1);
	if (true == PooterLoad)
	{
		ImageLoad();
		PooterLoad = false;
	}
	M_Pooter = CreateRender(IsaacOrder::R_Monster);
	M_Pooter->SetScale({ 80, 80 });

	M_PooterDead = CreateRender(IsaacOrder::R_MonsterDead);
	M_PooterDead->SetScale({ 80, 80 });

	M_Pooter->CreateAnimation({ .AnimationName = "M_Pooter_Idle",  .ImageName = "M_Pooter.bmp", .Start = 0, .End = 1, .InterTime = 0.1f });
	M_Pooter->CreateAnimation({ .AnimationName = "M_Pooter_Damage",  .ImageName = "M_Pooter.bmp", .Start = 14, .End = 15, .InterTime = 0.1f });
	M_Pooter->CreateAnimation({ .AnimationName = "M_Pooter_Shoot",  .ImageName = "M_Pooter.bmp", .Start = 2, .End = 11, .InterTime = 0.03f , .Loop = false });

	M_Pooter->CreateAnimation({ .AnimationName = "M_Pooter_L_Idle",  .ImageName = "M_Pooter_L.bmp", .Start = 0, .End = 1, .InterTime = 0.1f });
	M_Pooter->CreateAnimation({ .AnimationName = "M_Pooter_L_Damage",  .ImageName = "M_Pooter_L.bmp", .Start = 14, .End = 15, .InterTime = 0.1f });
	M_Pooter->CreateAnimation({ .AnimationName = "M_Pooter_L_Shoot",  .ImageName = "M_Pooter_L.bmp", .Start = 2, .End = 11, .InterTime = 0.03f , .Loop = false });
	M_Pooter->CreateAnimation({ .AnimationName = "M_Pooter_Dead",  .ImageName = "M_fly_Dead.bmp", .Start = 0, .End = 11, .InterTime = 0.03f, .Loop = false });
	M_Pooter->ChangeAnimation("M_Pooter_Idle");


	M_PooterDead->CreateAnimation({ .AnimationName = "PooterDead",  .ImageName = "M_Blood.bmp", .Start = 5, .End = 5, .InterTime = 0.1f });
	M_PooterDead->ChangeAnimation("PooterDead");
	M_PooterDead->Off();

	{

		M_fly_Pooter = CreateCollision(IsaacCollisionOrder::C_Monster);
		M_fly_Pooter->SetScale({ 35, 35 });
		M_fly_Pooter->On();
		M_fly_Pooter->SetDebugRenderType(CollisionType::CT_Rect);

		M_fly_Pooter_Set = CreateCollision(IsaacCollisionOrder::C_Moster_Set);
		M_fly_Pooter_Set->SetScale({ 800, 800 });
		M_fly_Pooter_Set->SetPosition({ 400,0 });
		M_fly_Pooter_Set->On();
		M_fly_Pooter_Set->SetDebugRenderType(CollisionType::CT_Rect);

		
	}

}


void Pooter::Update(float _DeltaTime)
{
	if (true == PooterDeathcheck) //hp가 떨어진게 확인되면
	{
		if (true == Countbool)
		{
			Isaac::MainPlayer->MinusMonsterCount(1);
			Countbool = false;
		}
		M_Pooter->ChangeAnimation("M_Pooter_Dead");
		if (true == M_Pooter->IsAnimationEnd())
		{
			M_PooterDead->On();
			M_Pooter->Death();
		}
		M_fly_Pooter->Death(); //없앤다
		M_fly_Pooter_Set->Death();
	}
	PooterAttTime += _DeltaTime;
	if (PooterAttTime > 3.0f)
	{
		PooterAttTime = 0.0f;
		if (false == PooterDeathcheck)
		{

			if (true == M_fly_Pooter_Set->Collision({ .TargetGroup = static_cast<int>(IsaacCollisionOrder::C_Player), .TargetColType = CT_Rect, .ThisColType = CT_Rect }))
			{
				M_Pooter->ChangeAnimation("M_Pooter_Shoot");
				float4 PlayerPos_P = Isaac::MainPlayer->GetPos() - GetPos();
				BloodTear* PooterAtt = GetLevel()->CreateActor<BloodTear>();
				PooterAtt->SetBloodMoveDir(PlayerPos_P);
				PooterAtt->SetPos(GetPos());
			}
			else
			{
				M_Pooter->ChangeAnimation("M_Pooter_L_Shoot");
				float4 PlayerPos_P1 = Isaac::MainPlayer->GetPos()-GetPos();
				BloodTear* PooterAtt1 = GetLevel()->CreateActor<BloodTear>();
				PooterAtt1->SetBloodMoveDir(PlayerPos_P1);
				PooterAtt1->SetPos(GetPos());
			}
		}
	}
	if (true == M_Pooter->IsAnimationEnd())
	{
		if (true == M_fly_Pooter_Set->Collision({ .TargetGroup = static_cast<int>(IsaacCollisionOrder::C_Player), .TargetColType = CT_Rect, .ThisColType = CT_Rect }))
		{
			M_Pooter->ChangeAnimation("M_Pooter_Idle"); //다시 idle로바꾸고
		}
		else
		{
			M_Pooter->ChangeAnimation("M_Pooter_L_Idle");
		}
	}
	
	Movecalculation(_DeltaTime);
	CollisionCheck(_DeltaTime);
}

void Pooter::Movecalculation(float _DeltaTime)
{
	float4 M_Move = Isaac::MainPlayer->GetPos() - GetPos();
	M_Move.Normalize();
	if (true == PooterDeathcheck)
	{
		M_Move = float4::Zero;
	}

	SetMove(M_Move * 15.0f * _DeltaTime); //안따라다니게할때는 M_Move를 다르게설정하면될듯 >>움직이는 제한pos를 BackGround_CS로 해야함
}


void Pooter::CollisionCheck(float _DeltaTime)
{
	NowTime += _DeltaTime;
	
	if (NowTime >= 0.5f) //다음상호작용이 되려면 이만큼의 시간이 흘러야한다(몬스터가 죽는애니메이션시간보다는 길어야함)
	{
		NowTime = 0.0f;
		M_fly_Pooter->On();  //시간이지나면 다시collision을킨다
		RESET = 1;
		
	}
	
	std::vector<GameEngineCollision*> FCollisions;
	CollisionCheckParameter Check = { .TargetGroup = static_cast<int>(IsaacCollisionOrder::C_PlayerAtt_L), .TargetColType = CT_Rect, .ThisColType = CT_Rect };
	CollisionCheckParameter Check1 = { .TargetGroup = static_cast<int>(IsaacCollisionOrder::C_PlayerAtt_R), .TargetColType = CT_Rect, .ThisColType = CT_Rect };
	CollisionCheckParameter Check2 = { .TargetGroup = static_cast<int>(IsaacCollisionOrder::C_PlayerAtt_U), .TargetColType = CT_Rect, .ThisColType = CT_Rect };
	CollisionCheckParameter Check3 = { .TargetGroup = static_cast<int>(IsaacCollisionOrder::C_PlayerAtt_D), .TargetColType = CT_Rect, .ThisColType = CT_Rect };

	//함수짤 시간에 그냥 복붙을하겠노라
	if (true == M_fly_Pooter->Collision(Check, FCollisions)) //PlayerAtt에 닿았을때
	{
		M_Pooter->ChangeAnimation("M_Pooter_Damage");
		FCollisions[0]->GetActor()->Death(); //닿은 ATT는 지워버리고
		SetMove(float4::Left * 20); //맞으면 밀려남(매끄럽게안밀려남) 방향에따른 설정도해야할듯

		if (1 == RESET)
		{
			PooterHp = PooterHp - Isaac::MainPlayer->GetTearDamage();
			RESET = 0;
			M_fly_Pooter->Off(); //맞아도 일정시간동안 상호작용이안된다.
		}
		if (0 >= PooterHp)
		{
			PooterDeathcheck = true;
		}
	}
	if (true == M_fly_Pooter->Collision(Check1, FCollisions))
	{
		M_Pooter->ChangeAnimation("M_Pooter_Damage");
		FCollisions[0]->GetActor()->Death();
		SetMove(float4::Right * 20);

		if (1 == RESET)
		{
			PooterHp = PooterHp - Isaac::MainPlayer->GetTearDamage();
			RESET = 0;
			M_fly_Pooter->Off();
		}
		if (0 >= PooterHp)
		{
			M_Pooter->ChangeAnimation("M_Pooter_Dead");
			PooterDeathcheck = true;
		}
	}
	if (true == M_fly_Pooter->Collision(Check2, FCollisions))
	{
		M_Pooter->ChangeAnimation("M_Pooter_Damage");
		FCollisions[0]->GetActor()->Death();
		SetMove(float4::Up * 20);

		if (1 == RESET)
		{
			PooterHp = PooterHp - Isaac::MainPlayer->GetTearDamage();
			RESET = 0;
			M_fly_Pooter->Off();
		}
		if (0 >= PooterHp)
		{
			M_Pooter->ChangeAnimation("M_Pooter_Dead");
			PooterDeathcheck = true;
		}
	}
	if (true == M_fly_Pooter->Collision(Check3, FCollisions))
	{
		M_Pooter->ChangeAnimation("M_Pooter_Damage");
		FCollisions[0]->GetActor()->Death();
		SetMove(float4::Down * 20);

		if (1 == RESET)
		{
			PooterHp = PooterHp - Isaac::MainPlayer->GetTearDamage();
			RESET = 0;
			M_fly_Pooter->Off();
		}
		if (0 >= PooterHp)
		{
			M_Pooter->ChangeAnimation("M_Pooter_Dead");
			PooterDeathcheck = true;
		}
	}


	CollisionCheckParameter B_Check = { .TargetGroup = static_cast<int>(IsaacCollisionOrder::C_Isaac_Bomb), .TargetColType = CT_Rect, .ThisColType = CT_Rect };
	if (true == M_fly_Pooter->Collision(B_Check, FCollisions))
	{
		PooterHp = PooterHp - 5; //이것은 폭탄의 데미지여
		if (0 >= PooterHp)
		{
			M_Pooter->ChangeAnimation("M_Pooter_Dead");
			PooterDeathcheck = true;
		}
	}
}

void Pooter::Render(float _DeltaTime)
{
	//M_fly_Pooter->DebugRender();
	//M_fly_Pooter_Set->DebugRender();
}