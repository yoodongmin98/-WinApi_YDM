
#include <GameEngineBase/GameEngineDirectory.h>

#include <GameEnginePlatform/GameEngineInput.h>

#include <GameEngineCore/GameEngineRender.h>
#include <GameEngineCore/GameEngineResources.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCollision.h>


#include "Isaac.h"
#include "IsaacEnum.h"
#include "Clot.h"

#include "BloodTear.h"


Clot::Clot()
{

}

Clot::~Clot()
{
}

bool ClotLoad = true;
void Clot::ImageLoad()
{
	GameEngineDirectory Dir;
	Dir.MoveParentToDirectory("ContentsResources");
	Dir.Move("ContentsResources");
	Dir.Move("Image");
	Dir.Move("Play");
	Dir.Move("Monster");

	GameEngineImage* L_Blob = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("M_Clot_L.BMP"));
	L_Blob->Cut(4, 3);
	GameEngineImage* R_Blob = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("M_Clot_R.BMP"));
	R_Blob->Cut(4, 3);
}


void Clot::Start()
{
	if (true == ClotLoad)
	{
		ImageLoad();
		ClotLoad = false;
	}
	M_Clot = CreateRender(IsaacOrder::R_Monster);
	M_Clot->SetScale({ 100, 100 });

	DeadRender_Clot = CreateRender(IsaacOrder::R_MonsterDead);
	DeadRender_Clot->SetScale({ 30, 30 });

	M_Clot->CreateAnimation({ .AnimationName = "M_Clot_Idle_L",  .ImageName = "M_Clot_L.bmp", .Start = 0, .End = 7, .InterTime = 0.15f });
	M_Clot->CreateAnimation({ .AnimationName = "M_Clot_Damage",  .ImageName = "M_Clot_L.bmp", .Start = 10, .End = 11, .InterTime = 0.1f });
	M_Clot->CreateAnimation({ .AnimationName = "M_Clot_Idle_R",  .ImageName = "M_Clot_R.bmp", .Start = 0, .End = 7, .InterTime = 0.15f });
	M_Clot->ChangeAnimation("M_Clot_Idle_L");


	DeadRender_Clot->CreateAnimation({ .AnimationName = "DeadClot",  .ImageName = "M_Blood_deadbody.bmp", .Start = 1, .End = 1, .InterTime = 0.15f });
	DeadRender_Clot->ChangeAnimation("DeadClot");
	DeadRender_Clot->Off();
	{

		M_Clot_Coll = CreateCollision(IsaacCollisionOrder::C_Monster);
		M_Clot_Coll->SetScale({ 35, 35 });
		M_Clot_Coll->On();
		M_Clot_Coll->SetDebugRenderType(CollisionType::CT_Rect);

		M_Clot_SetColl_R = CreateCollision(IsaacCollisionOrder::C_Moster_Set);
		M_Clot_SetColl_R->SetScale({ 1000, 800 });
		M_Clot_SetColl_R->SetPosition({ 500,0 });
		M_Clot_SetColl_R->On();
		M_Clot_SetColl_R->SetDebugRenderType(CollisionType::CT_Rect);
	}

}


void Clot::Update(float _DeltaTime)
{
	ClotAttTime += _DeltaTime;
	if (ClotAttTime > 4.0f)
	{
		if (ClotDeathcheck == false)
		{
			BloodTear* ClotAtt1 = GetLevel()->CreateActor<BloodTear>();
			BloodTear* ClotAtt2 = GetLevel()->CreateActor<BloodTear>();
			BloodTear* ClotAtt3 = GetLevel()->CreateActor<BloodTear>();
			BloodTear* ClotAtt4 = GetLevel()->CreateActor<BloodTear>();
			ClotAtt1->SetBloodMoveDir(float4::Up);
			ClotAtt2->SetBloodMoveDir(float4::Down);
			ClotAtt3->SetBloodMoveDir(float4::Right);
			ClotAtt4->SetBloodMoveDir(float4::Left);
			ClotAtt1->SetPos(GetPos());
			ClotAtt2->SetPos(GetPos());
			ClotAtt3->SetPos(GetPos());
			ClotAtt4->SetPos(GetPos());
			ClotAttTime = 0.0f;
		}
	}

	
	if (true == ClotDeathcheck)
	{
		if (true == Countbool)
		{
			Isaac::MainPlayer->MinusMonsterCount(1);
			Countbool = false;
		}
		M_Clot->Death();
		M_Clot_Coll->Death();
		M_Clot_SetColl_R->Death();
		DeadRender_Clot->On();
	}
	Movecalculation(_DeltaTime);
	CollisionCheck(_DeltaTime);
}

void Clot::Movecalculation(float _DeltaTime)
{
	float4 M_Move = Isaac::MainPlayer->GetPos() - GetPos();
	M_Move.Normalize();
	if (true == ClotDeathcheck)
	{
		M_Move = float4::Zero;
	}

	SetMove(M_Move * 40.0f * _DeltaTime);
}


void Clot::CollisionCheck(float _DeltaTime)
{
	NowTime += _DeltaTime;

	if (NowTime >= 0.5f)
	{
		if (true == M_Clot_SetColl_R->Collision({ .TargetGroup = static_cast<int>(IsaacCollisionOrder::C_Player), .TargetColType = CT_Rect, .ThisColType = CT_Rect }))
		{
			M_Clot->ChangeAnimation("M_Clot_Idle_R"); //다시 idle로바꾸고
		}
		else
		{
			M_Clot->ChangeAnimation("M_Clot_Idle_L");
		}
		NowTime = 0.0f;
		M_Clot_Coll->On();  //시간이지나면 다시collision을킨다
		RESET = 1;
	}

	std::vector<GameEngineCollision*> FCollisions;
	CollisionCheckParameter Check = { .TargetGroup = static_cast<int>(IsaacCollisionOrder::C_PlayerAtt_L), .TargetColType = CT_Rect, .ThisColType = CT_Rect };
	CollisionCheckParameter Check1 = { .TargetGroup = static_cast<int>(IsaacCollisionOrder::C_PlayerAtt_R), .TargetColType = CT_Rect, .ThisColType = CT_Rect };
	CollisionCheckParameter Check2 = { .TargetGroup = static_cast<int>(IsaacCollisionOrder::C_PlayerAtt_U), .TargetColType = CT_Rect, .ThisColType = CT_Rect };
	CollisionCheckParameter Check3 = { .TargetGroup = static_cast<int>(IsaacCollisionOrder::C_PlayerAtt_D), .TargetColType = CT_Rect, .ThisColType = CT_Rect };

	//함수짤 시간에 그냥 복붙을하겠노라
	if (true == M_Clot_Coll->Collision(Check, FCollisions)) //PlayerAtt에 닿았을때
	{
		M_Clot->ChangeAnimation("M_Clot_Damage");
		FCollisions[0]->GetActor()->Death(); //닿은 ATT는 지워버리고
		SetMove(float4::Left * 20); //맞으면 밀려남(매끄럽게안밀려남) 방향에따른 설정도해야할듯

		if (1 == RESET)
		{
			ClotHp = ClotHp - Isaac::MainPlayer->GetTearDamage();
			RESET = 0;
			M_Clot_Coll->Off(); //맞아도 일정시간동안 상호작용이안된다.
		}
		if (0 >= ClotHp)
		{
			//M_Blob->ChangeAnimation("M_fly_Dead");
			ClotDeathcheck = true;
		}
	}
	if (true == M_Clot_Coll->Collision(Check1, FCollisions))
	{
		M_Clot->ChangeAnimation("M_Clot_Damage");
		FCollisions[0]->GetActor()->Death();
		SetMove(float4::Right * 20);

		if (1 == RESET)
		{
			ClotHp = ClotHp - Isaac::MainPlayer->GetTearDamage();
			RESET = 0;
			M_Clot_Coll->Off();
		}
		if (0 >= ClotHp)
		{
			ClotDeathcheck = true;
		}
	}
	if (true == M_Clot_Coll->Collision(Check2, FCollisions))
	{
		M_Clot->ChangeAnimation("M_Clot_Damage");
		FCollisions[0]->GetActor()->Death();
		SetMove(float4::Up * 20);

		if (1 == RESET)
		{
			ClotHp = ClotHp - Isaac::MainPlayer->GetTearDamage();
			RESET = 0;
			M_Clot_Coll->Off();
		}
		if (0 >= ClotHp)
		{
			ClotDeathcheck = true;
		}
	}
	if (true == M_Clot_Coll->Collision(Check3, FCollisions))
	{
		M_Clot->ChangeAnimation("M_Clot_Damage");
		FCollisions[0]->GetActor()->Death();
		SetMove(float4::Down * 20);

		if (1 == RESET)
		{
			ClotHp = ClotHp - Isaac::MainPlayer->GetTearDamage();
			RESET = 0;
			M_Clot_Coll->Off();
		}
		if (0 >= ClotHp)
		{
			ClotDeathcheck = true;
		}
	}














	CollisionCheckParameter B_Check = { .TargetGroup = static_cast<int>(IsaacCollisionOrder::C_Isaac_Bomb), .TargetColType = CT_Rect, .ThisColType = CT_Rect };
	if (true == M_Clot_Coll->Collision(B_Check, FCollisions))
	{
		ClotHp = ClotHp - 5; 
		if (0 >= ClotHp)
		{
			ClotDeathcheck = true;
		}
	}
}

void Clot::Render(float _DeltaTime)
{
	//M_Blob_Coll->DebugRender();
	//M_Clot_SetColl_R->DebugRender();
}