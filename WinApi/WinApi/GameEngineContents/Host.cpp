
#include <GameEngineBase/GameEngineDirectory.h>
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEnginePlatform/GameEngineInput.h>

#include <GameEngineCore/GameEngineRender.h>
#include <GameEngineCore/GameEngineResources.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCollision.h>


#include "Isaac.h"
#include "IsaacEnum.h"
#include "Host.h"
#include "BloodTear.h"


Host::Host()
{

}

Host::~Host()
{
}

bool HostLoad = true;
void Host::ImageLoad()
{
	GameEngineDirectory Dir;
	Dir.MoveParentToDirectory("ContentsResources");
	Dir.Move("ContentsResources");
	Dir.Move("Image");
	Dir.Move("Play");
	Dir.Move("Monster");

	GameEngineImage* MonsterHost = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("M_Host.BMP"));
	MonsterHost->Cut(3, 1);
	GameEngineImage* DamageHost = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("M_Redhost.BMP"));
	DamageHost->Cut(3, 1);
}


void Host::Start()
{

	if (true == HostLoad)
	{
		ImageLoad();
		HostLoad = false;
	}
	M_Host = CreateRender(IsaacOrder::R_Monster);
	M_Host->SetScale({ 80, 80 });

	DeadHost = CreateRender(IsaacOrder::R_MonsterDead);
	DeadHost->SetScale({ 80, 80 });


	M_Host->CreateAnimation({ .AnimationName = "HostIdle",  .ImageName = "M_Host.bmp", .Start = 0, .End = 0, .InterTime = 0.1f });
	M_Host->CreateAnimation({ .AnimationName = "HostOn",  .ImageName = "M_Host.bmp", .Start = 1, .End = 1, .InterTime = 0.1f });
	M_Host->CreateAnimation({ .AnimationName = "HostDamaged",  .ImageName = "M_Redhost.bmp", .Start = 1, .End = 1, .InterTime = 0.1f });
	M_Host->ChangeAnimation("HostIdle");


	DeadHost->CreateAnimation({ .AnimationName = "DeadHosts",  .ImageName = "M_Blood.bmp", .Start = 10, .End = 10, .InterTime = 0.1f, .Loop = false });
	DeadHost->ChangeAnimation("DeadHosts");
	DeadHost->Off();

	{

		M_Host_Coll = CreateCollision(IsaacCollisionOrder::C_Monster);
		M_Host_Coll->SetScale({ 35, 35 });
		M_Host_Coll->SetPosition({ 0, 20 });
		M_Host_Coll->Off();
		M_Host_Coll->SetDebugRenderType(CollisionType::CT_Rect);
	}

}


void Host::Update(float _DeltaTime)
{
	if (true == HostDeathcheck) //hp가 떨어진게 확인되면
	{
		M_Host->Death();
		M_Host_Coll->Death();
		DeadHost->On();
	}
	CollisionCheck(_DeltaTime);
}



bool HostTearbool = true;
void Host::CollisionCheck(float _DeltaTime)
{
	NowTime += _DeltaTime;
	if (NowTime > 1.0f)
	{
		M_Host->ChangeAnimation("HostIdle");
		if (NowTime >= 6.0f)
		{
			M_Host->ChangeAnimation("HostOn");
			M_Host_Coll->On();
			RESET = 1;
			if (true == HostTearbool&&false== HostDeathcheck)
			{
				float4 PlayerPos = Isaac::MainPlayer->GetPos() - GetPos();
				BloodTear* NewBloodTear = GetLevel()->CreateActor<BloodTear>();
				NewBloodTear->SetBloodMoveDir(PlayerPos);
				NewBloodTear->SetPos(GetPos());
				HostTearbool = false;
			}
			
			if (NowTime >= 10.0f)
			{
				M_Host->ChangeAnimation("HostIdle");
				NowTime = 0.0f;
				M_Host_Coll->Off();
				HostTearbool = true;
			}
		}
	}
	

	std::vector<GameEngineCollision*> FCollisions;
	CollisionCheckParameter Check = { .TargetGroup = static_cast<int>(IsaacCollisionOrder::C_PlayerAtt_L), .TargetColType = CT_Rect, .ThisColType = CT_Rect };
	CollisionCheckParameter Check1 = { .TargetGroup = static_cast<int>(IsaacCollisionOrder::C_PlayerAtt_R), .TargetColType = CT_Rect, .ThisColType = CT_Rect };
	CollisionCheckParameter Check2 = { .TargetGroup = static_cast<int>(IsaacCollisionOrder::C_PlayerAtt_U), .TargetColType = CT_Rect, .ThisColType = CT_Rect };
	CollisionCheckParameter Check3 = { .TargetGroup = static_cast<int>(IsaacCollisionOrder::C_PlayerAtt_D), .TargetColType = CT_Rect, .ThisColType = CT_Rect };

	//함수짤 시간에 그냥 복붙을하겠노라
	if (true == M_Host_Coll->Collision(Check, FCollisions)) //PlayerAtt에 닿았을때
	{
		M_Host->ChangeAnimation("HostDamaged");
		FCollisions[0]->GetActor()->Death(); //닿은 ATT는 지워버리고
		if (1 == RESET)
		{
			HostHp = HostHp - Isaac::MainPlayer->GetTearDamage();
			RESET = 0;
		}
		if (0 >= HostHp)
		{
			HostDeathcheck = true;
		}
	}
	if (true == M_Host_Coll->Collision(Check1, FCollisions))
	{
		M_Host->ChangeAnimation("HostDamaged");
		FCollisions[0]->GetActor()->Death();
		if (1 == RESET)
		{
			HostHp = HostHp - Isaac::MainPlayer->GetTearDamage();
			RESET = 0;
		}
		if (0 >= HostHp)
		{
			HostDeathcheck = true;
		}
	}
	if (true == M_Host_Coll->Collision(Check2, FCollisions))
	{
		M_Host->ChangeAnimation("HostDamaged");
		FCollisions[0]->GetActor()->Death();

		if (1 == RESET)
		{
			HostHp = HostHp - Isaac::MainPlayer->GetTearDamage();
			RESET = 0;
		}
		if (0 >= HostHp)
		{
			HostDeathcheck = true;
		}
	}
	if (true == M_Host_Coll->Collision(Check3, FCollisions))
	{
		M_Host->ChangeAnimation("HostDamaged");
		FCollisions[0]->GetActor()->Death();

		if (1 == RESET)
		{
			HostHp = HostHp - Isaac::MainPlayer->GetTearDamage();
			RESET = 0;
		}
		if (0 >= HostHp)
		{
			HostDeathcheck = true;
		}
	}
}

void Host::Render(float _DeltaTime)
{
	
	//M_Host_Coll->DebugRender();
}