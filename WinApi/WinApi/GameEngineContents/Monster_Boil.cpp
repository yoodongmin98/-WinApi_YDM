
#include <GameEngineBase/GameEngineDirectory.h>

#include <GameEnginePlatform/GameEngineInput.h>

#include <GameEngineCore/GameEngineRender.h>
#include <GameEngineCore/GameEngineResources.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCollision.h>




#include "BloodTear.h"

#include "Isaac.h"
#include "IsaacEnum.h"
#include "Monster_Boil.h"


Boil::Boil()
{

}

Boil::~Boil()
{
}

bool BoilLoad = true;
void Boil::ImageLoad()
{
	GameEngineDirectory Dir;
	Dir.MoveParentToDirectory("ContentsResources");
	Dir.Move("ContentsResources");
	Dir.Move("Image");
	Dir.Move("Play");
	Dir.Move("Monster");

	GameEngineImage* Boils = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("M_Boil.BMP"));
	Boils->Cut(4, 3);
}


void Boil::Start()
{
	Isaac::MainPlayer->PlusMOnsterCount(1);
	if (true == BoilLoad)
	{
		ImageLoad();
		BoilLoad = false;
	}
	
	M_Boil = CreateRender(IsaacOrder::R_Monster);
	M_Boil->SetScale({ 70, 70 });
	
	DeadBoil = CreateRender(IsaacOrder::R_MonsterDead);
	DeadBoil->SetScale({ 70, 70 });



	M_Boil->CreateAnimation({ .AnimationName = "BoilHp10",  .ImageName = "M_Boil.bmp", .Start = 0, .End = 0, .InterTime = 0.1f });
	M_Boil->CreateAnimation({ .AnimationName = "BoilHp9",  .ImageName = "M_Boil.bmp", .Start = 1, .End = 1, .InterTime = 0.1f });
	M_Boil->CreateAnimation({ .AnimationName = "BoilHp8",  .ImageName = "M_Boil.bmp", .Start = 2, .End = 2, .InterTime = 0.1f });
	M_Boil->CreateAnimation({ .AnimationName = "BoilHp7",  .ImageName = "M_Boil.bmp", .Start = 3, .End = 3, .InterTime = 0.1f });
	M_Boil->CreateAnimation({ .AnimationName = "BoilHp6",  .ImageName = "M_Boil.bmp", .Start = 4, .End = 4, .InterTime = 0.1f });
	M_Boil->CreateAnimation({ .AnimationName = "BoilHp5",  .ImageName = "M_Boil.bmp", .Start = 5, .End = 5, .InterTime = 0.1f });
	M_Boil->CreateAnimation({ .AnimationName = "BoilHp4",  .ImageName = "M_Boil.bmp", .Start = 6, .End = 6, .InterTime = 0.1f });
	M_Boil->CreateAnimation({ .AnimationName = "BoilHp3",  .ImageName = "M_Boil.bmp", .Start = 7, .End = 7, .InterTime = 0.1f });
	M_Boil->CreateAnimation({ .AnimationName = "BoilHp2",  .ImageName = "M_Boil.bmp", .Start = 8, .End = 8, .InterTime = 0.1f });
	M_Boil->CreateAnimation({ .AnimationName = "BoilHp1",  .ImageName = "M_Boil.bmp", .Start = 9, .End = 9, .InterTime = 0.1f });
	
	M_Boil->ChangeAnimation("BoilHp1");
	

	DeadBoil->CreateAnimation({ .AnimationName = "DeadBoil",  .ImageName = "M_Blood.bmp", .Start = 2, .End = 2, .InterTime = 0.1f });
	DeadBoil->ChangeAnimation("DeadBoil");
	DeadBoil->Off();

	{
		M_Boil_Coll = CreateCollision(IsaacCollisionOrder::C_Monster);
		M_Boil_Coll->SetScale({ 40, 40 });
		M_Boil_Coll->SetPosition({ 0,15 });
		M_Boil_Coll->On();
		M_Boil_Coll->SetDebugRenderType(CollisionType::CT_Rect);
	}

}


void Boil::Update(float _DeltaTime)
{
	BoilAttTime += _DeltaTime;
	if (BoilAttTime > 3.0f && 10==BoilHp&&false== BoilDeathcheck)
	{
		BoilAttTime = 0.0f;
		float4 PlayerPos = Isaac::MainPlayer->GetPos() - GetPos();
		BloodTear* NewBloodTear = GetLevel()->CreateActor<BloodTear>();
		NewBloodTear->SetBloodMoveDir(PlayerPos);
		NewBloodTear->SetPos(GetPos());
	}
	CollisionCheck(_DeltaTime);
	HpCheck(_DeltaTime);
}

void Boil::HpCheck(float _DeltaTime)
{
	
	if (10 == BoilHp){ M_Boil->ChangeAnimation("BoilHp10");}
	if (9 == BoilHp) { M_Boil->ChangeAnimation("BoilHp9"); }
	if (8 == BoilHp) { M_Boil->ChangeAnimation("BoilHp8"); }
	if (7 == BoilHp) { M_Boil->ChangeAnimation("BoilHp7"); }
	if (6 == BoilHp) { M_Boil->ChangeAnimation("BoilHp6"); }
	if (5 == BoilHp) { M_Boil->ChangeAnimation("BoilHp5"); }
	if (4 == BoilHp) { M_Boil->ChangeAnimation("BoilHp4"); }
	if (3 == BoilHp) { M_Boil->ChangeAnimation("BoilHp3"); }
	if (2 == BoilHp) { M_Boil->ChangeAnimation("BoilHp2"); }
	if (1 == BoilHp) { M_Boil->ChangeAnimation("BoilHp1"); }
}


void Boil::CollisionCheck(float _DeltaTime)
{
	NowTime += _DeltaTime;

	if (NowTime >= 0.1f) //상호작용시간
	{
		NowTime = 0.0f;
		
		
		M_Boil_Coll->On();
		RESET = 1;
		if (true == BoilDeathcheck)
		{
			if (true == Countbool)
			{
				Isaac::MainPlayer->MinusMonsterCount(1);
				Countbool = false;
			}
			
			if(true==RenderCheck)
			{
				BloodTear* NewBloodTear = GetLevel()->CreateActor<BloodTear>();
				NewBloodTear->SetBloodMoveDir(float4::Up);
				NewBloodTear->SetPos(GetPos());
				BloodTear* NewBloodTear1 = GetLevel()->CreateActor<BloodTear>();
				NewBloodTear1->SetBloodMoveDir(float4::Down);
				NewBloodTear1->SetPos(GetPos());
				BloodTear* NewBloodTear2 = GetLevel()->CreateActor<BloodTear>();
				NewBloodTear2->SetBloodMoveDir(float4::Left);
				NewBloodTear2->SetPos(GetPos());
				BloodTear* NewBloodTear3 = GetLevel()->CreateActor<BloodTear>();
				NewBloodTear3->SetBloodMoveDir(float4::Right);
				NewBloodTear3->SetPos(GetPos());
				M_Boil->Death();
				M_Boil_Coll->Death();
				DeadBoil->On();
				RenderCheck = false;
			}
		}
	}
	HpPlusTime += _DeltaTime;
	if (HpPlusTime > 1.0f)
	{
		HpPlusTime = 0.0f;
		if (BoilHp >= MaxBoilHp)
		{
			BoilHp = BoilHp;
		}
		else
		{
			BoilHp = BoilHp + 1;
		}
	}

	

	std::vector<GameEngineCollision*> FCollisions;
	CollisionCheckParameter Check = { .TargetGroup = static_cast<int>(IsaacCollisionOrder::C_PlayerAtt_L), .TargetColType = CT_Rect, .ThisColType = CT_Rect };
	CollisionCheckParameter Check1 = { .TargetGroup = static_cast<int>(IsaacCollisionOrder::C_PlayerAtt_R), .TargetColType = CT_Rect, .ThisColType = CT_Rect };
	CollisionCheckParameter Check2 = { .TargetGroup = static_cast<int>(IsaacCollisionOrder::C_PlayerAtt_U), .TargetColType = CT_Rect, .ThisColType = CT_Rect };
	CollisionCheckParameter Check3 = { .TargetGroup = static_cast<int>(IsaacCollisionOrder::C_PlayerAtt_D), .TargetColType = CT_Rect, .ThisColType = CT_Rect };

	//함수짤 시간에 그냥 복붙을하겠노라
	if (true == M_Boil_Coll->Collision(Check, FCollisions)) //PlayerAtt에 닿았을때
	{
		FCollisions[0]->GetActor()->Death(); //닿은 ATT는 지워버리고
		if (1 == RESET)
		{
			BoilHp = BoilHp - Isaac::MainPlayer->GetTearDamage();
			RESET = 0;
			M_Boil_Coll->Off();
		}
		if (0 >= BoilHp)
		{
			//M_Blob->ChangeAnimation("M_fly_Dead");
			BoilDeathcheck = true;
		}
	}
	if (true == M_Boil_Coll->Collision(Check1, FCollisions))
	{
		FCollisions[0]->GetActor()->Death();
		if (1 == RESET)
		{
			BoilHp = BoilHp - Isaac::MainPlayer->GetTearDamage();
			RESET = 0;
			M_Boil_Coll->Off();
		}
		if (0 >= BoilHp)
		{
			//M_Blob->ChangeAnimation("M_fly_Dead");
			BoilDeathcheck = true;
		}
	}
	if (true == M_Boil_Coll->Collision(Check2, FCollisions))
	{
		FCollisions[0]->GetActor()->Death();
		if (1 == RESET)
		{
			BoilHp = BoilHp - Isaac::MainPlayer->GetTearDamage();
			RESET = 0;
			M_Boil_Coll->Off();
		}
		if (0 >= BoilHp)
		{
			//M_Blob->ChangeAnimation("M_fly_Dead");
			BoilDeathcheck = true;
		}
	}
	if (true == M_Boil_Coll->Collision(Check3, FCollisions))
	{
		FCollisions[0]->GetActor()->Death();
		if (1 == RESET)
		{
			BoilHp = BoilHp - Isaac::MainPlayer->GetTearDamage();
			RESET = 0;
			M_Boil_Coll->Off();
		}
		if (0 >= BoilHp)
		{
			//M_Blob->ChangeAnimation("M_fly_Dead");
			BoilDeathcheck = true;
		}
	}



	CollisionCheckParameter B_Check = { .TargetGroup = static_cast<int>(IsaacCollisionOrder::C_Isaac_Bomb), .TargetColType = CT_Rect, .ThisColType = CT_Rect };
	if (true == M_Boil_Coll->Collision(B_Check, FCollisions))
	{
		BoilHp = BoilHp - 5; //이것은 폭탄의 데미지여
		if (0 >= BoilHp)
		{
			//M_Blob->ChangeAnimation("M_fly_Dead");
			BoilDeathcheck = true;
		}
	}
}

void Boil::Render(float _DeltaTime)
{
	//M_Boil_Coll->DebugRender();
	
}