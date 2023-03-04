
#include <GameEngineBase/GameEngineDirectory.h>

#include <GameEnginePlatform/GameEngineInput.h>

#include <GameEngineCore/GameEngineRender.h>
#include <GameEngineCore/GameEngineResources.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCollision.h>


#include "Isaac.h"
#include "IsaacEnum.h"
#include "Clotty.h"

#include "BloodTear.h"


Clotty::Clotty()
{

}

Clotty::~Clotty()
{
}

bool ClottyLoad = true;
void Clotty::ImageLoad()
{
	GameEngineDirectory Dir;
	Dir.MoveParentToDirectory("ContentsResources");
	Dir.Move("ContentsResources");
	Dir.Move("Image");
	Dir.Move("Play");
	Dir.Move("Monster");

	GameEngineImage* L_Clotty = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("M_Clotty_L.BMP"));
	L_Clotty->Cut(4, 3);
	GameEngineImage* R_Clotty = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("M_Clotty_R.BMP"));
	R_Clotty->Cut(4, 3);
}


void Clotty::Start()
{
	if (true == ClottyLoad)
	{
		ImageLoad();
		ClottyLoad = false;
	}
	M_Clotty = CreateRender(IsaacOrder::R_Monster);
	M_Clotty->SetScale({ 100, 100 });

	DeadRender_Clotty = CreateRender(IsaacOrder::R_MonsterDead);
	DeadRender_Clotty->SetScale({ 30, 30 });

	M_Clotty->CreateAnimation({ .AnimationName = "M_Clotty_Idle_L",  .ImageName = "M_Clotty_L.bmp", .Start = 0, .End = 7, .InterTime = 0.15f });
	M_Clotty->CreateAnimation({ .AnimationName = "M_Clotty_Damage",  .ImageName = "M_Clotty_L.bmp", .Start = 10, .End = 11, .InterTime = 0.1f });
	M_Clotty->CreateAnimation({ .AnimationName = "M_Clotty_Idle_R",  .ImageName = "M_Clotty_R.bmp", .Start = 0, .End = 7, .InterTime = 0.15f });
	M_Clotty->ChangeAnimation("M_Clotty_Idle_L");


	DeadRender_Clotty->CreateAnimation({ .AnimationName = "DeadClotty",  .ImageName = "M_Blood.bmp", .Start = 8, .End = 8, .InterTime = 0.15f });
	DeadRender_Clotty->ChangeAnimation("DeadClotty");
	DeadRender_Clotty->Off();
	{

		M_Clotty_Coll = CreateCollision(IsaacCollisionOrder::C_Monster);
		M_Clotty_Coll->SetScale({ 35, 35 });
		M_Clotty_Coll->On();
		M_Clotty_Coll->SetDebugRenderType(CollisionType::CT_Rect);

		M_Clotty_SetColl_R = CreateCollision(IsaacCollisionOrder::C_Moster_Set);
		M_Clotty_SetColl_R->SetScale({ 1000, 800 });
		M_Clotty_SetColl_R->SetPosition({ 500,0 });
		M_Clotty_SetColl_R->On();
		M_Clotty_SetColl_R->SetDebugRenderType(CollisionType::CT_Rect);
	}

}


void Clotty::Update(float _DeltaTime)
{
	ClottyAttTime += _DeltaTime;
	if (ClottyAttTime > 4.0f)
	{
		if (ClottyDeathcheck == false)
		{
			BloodTear* ClottyAtt1 = GetLevel()->CreateActor<BloodTear>();
			BloodTear* ClottyAtt2 = GetLevel()->CreateActor<BloodTear>();
			BloodTear* ClottyAtt3 = GetLevel()->CreateActor<BloodTear>();
			BloodTear* ClottyAtt4 = GetLevel()->CreateActor<BloodTear>();
			BloodTear* ClottyAtt5 = GetLevel()->CreateActor<BloodTear>();
			BloodTear* ClottyAtt6 = GetLevel()->CreateActor<BloodTear>();
			BloodTear* ClottyAtt7 = GetLevel()->CreateActor<BloodTear>();
			BloodTear* ClottyAtt8 = GetLevel()->CreateActor<BloodTear>();

			float4 MoveDir1 = float4::Up + float4::Right;
			MoveDir1.Normalize();
			float4 MoveDir2 = float4::Up + float4::Left;
			MoveDir2.Normalize();
			float4 MoveDir3 = float4::Down + float4::Right;
			MoveDir3.Normalize();
			float4 MoveDir4 = float4::Down + float4::Left;
			MoveDir4.Normalize();

			ClottyAtt1->SetBloodMoveDir(float4::Up);
			ClottyAtt2->SetBloodMoveDir(float4::Down);
			ClottyAtt3->SetBloodMoveDir(float4::Right);
			ClottyAtt4->SetBloodMoveDir(float4::Left);
			ClottyAtt5->SetBloodMoveDir(MoveDir1);
			ClottyAtt6->SetBloodMoveDir(MoveDir2);
			ClottyAtt7->SetBloodMoveDir(MoveDir3);
			ClottyAtt8->SetBloodMoveDir(MoveDir4);

			ClottyAtt1->SetPos(GetPos());
			ClottyAtt2->SetPos(GetPos());
			ClottyAtt3->SetPos(GetPos());
			ClottyAtt4->SetPos(GetPos());
			ClottyAtt5->SetPos(GetPos());
			ClottyAtt6->SetPos(GetPos());
			ClottyAtt7->SetPos(GetPos());
			ClottyAtt8->SetPos(GetPos());



			ClottyAttTime = 0.0f;
		}
	}


	if (true == ClottyDeathcheck)
	{
		M_Clotty->Death();
		M_Clotty_Coll->Death();
		M_Clotty_SetColl_R->Death();
		DeadRender_Clotty->On();
	}
	Movecalculation(_DeltaTime);
	CollisionCheck(_DeltaTime);
}

void Clotty::Movecalculation(float _DeltaTime)
{
	float4 M_Move = Isaac::MainPlayer->GetPos() - GetPos();
	M_Move.Normalize();
	if (true == ClottyDeathcheck)
	{
		M_Move = float4::Zero;
	}

	SetMove(M_Move * 50.0f * _DeltaTime);
}


void Clotty::CollisionCheck(float _DeltaTime)
{
	NowTime += _DeltaTime;

	if (NowTime >= 0.5f)
	{
		if (true == M_Clotty_SetColl_R->Collision({ .TargetGroup = static_cast<int>(IsaacCollisionOrder::C_Player), .TargetColType = CT_Rect, .ThisColType = CT_Rect }))
		{
			M_Clotty->ChangeAnimation("M_Clotty_Idle_R"); //다시 idle로바꾸고
		}
		else
		{
			M_Clotty->ChangeAnimation("M_Clotty_Idle_L");
		}
		NowTime = 0.0f;
		M_Clotty_Coll->On();  //시간이지나면 다시collision을킨다
		RESET = 1;
	}

	std::vector<GameEngineCollision*> FCollisions;
	CollisionCheckParameter Check = { .TargetGroup = static_cast<int>(IsaacCollisionOrder::C_PlayerAtt_L), .TargetColType = CT_Rect, .ThisColType = CT_Rect };
	CollisionCheckParameter Check1 = { .TargetGroup = static_cast<int>(IsaacCollisionOrder::C_PlayerAtt_R), .TargetColType = CT_Rect, .ThisColType = CT_Rect };
	CollisionCheckParameter Check2 = { .TargetGroup = static_cast<int>(IsaacCollisionOrder::C_PlayerAtt_U), .TargetColType = CT_Rect, .ThisColType = CT_Rect };
	CollisionCheckParameter Check3 = { .TargetGroup = static_cast<int>(IsaacCollisionOrder::C_PlayerAtt_D), .TargetColType = CT_Rect, .ThisColType = CT_Rect };

	//함수짤 시간에 그냥 복붙을하겠노라
	if (true == M_Clotty_Coll->Collision(Check, FCollisions)) //PlayerAtt에 닿았을때
	{
		M_Clotty->ChangeAnimation("M_Clotty_Damage");
		FCollisions[0]->GetActor()->Death(); //닿은 ATT는 지워버리고
		SetMove(float4::Left * 20); //맞으면 밀려남(매끄럽게안밀려남) 방향에따른 설정도해야할듯

		if (1 == RESET)
		{
			ClottyHp = ClottyHp - Isaac::MainPlayer->GetTearDamage();
			RESET = 0;
			M_Clotty_Coll->Off(); //맞아도 일정시간동안 상호작용이안된다.
		}
		if (0 >= ClottyHp)
		{
			//M_Blob->ChangeAnimation("M_fly_Dead");
			ClottyDeathcheck = true;
		}
	}
	if (true == M_Clotty_Coll->Collision(Check1, FCollisions))
	{
		M_Clotty->ChangeAnimation("M_Clotty_Damage");
		FCollisions[0]->GetActor()->Death();
		SetMove(float4::Right * 20);

		if (1 == RESET)
		{
			ClottyHp = ClottyHp - Isaac::MainPlayer->GetTearDamage();
			RESET = 0;
			M_Clotty_Coll->Off();
		}
		if (0 >= ClottyHp)
		{
			ClottyDeathcheck = true;
		}
	}
	if (true == M_Clotty_Coll->Collision(Check2, FCollisions))
	{
		M_Clotty->ChangeAnimation("M_Clotty_Damage");
		FCollisions[0]->GetActor()->Death();
		SetMove(float4::Up * 20);

		if (1 == RESET)
		{
			ClottyHp = ClottyHp - Isaac::MainPlayer->GetTearDamage();
			RESET = 0;
			M_Clotty_Coll->Off();
		}
		if (0 >= ClottyHp)
		{
			ClottyDeathcheck = true;
		}
	}
	if (true == M_Clotty_Coll->Collision(Check3, FCollisions))
	{
		M_Clotty->ChangeAnimation("M_Clotty_Damage");
		FCollisions[0]->GetActor()->Death();
		SetMove(float4::Down * 20);

		if (1 == RESET)
		{
			ClottyHp = ClottyHp - Isaac::MainPlayer->GetTearDamage();
			RESET = 0;
			M_Clotty_Coll->Off();
		}
		if (0 >= ClottyHp)
		{
			ClottyDeathcheck = true;
		}
	}


	CollisionCheckParameter B_Check = { .TargetGroup = static_cast<int>(IsaacCollisionOrder::C_Isaac_Bomb), .TargetColType = CT_Rect, .ThisColType = CT_Rect };
	if (true == M_Clotty_Coll->Collision(B_Check, FCollisions))
	{
		ClottyHp = ClottyHp - 5;
		if (0 >= ClottyHp)
		{
			ClottyDeathcheck = true;
		}
	}
}

void Clotty::Render(float _DeltaTime)
{
	//M_Blob_Coll->DebugRender();
	//M_Clot_SetColl_R->DebugRender();
}