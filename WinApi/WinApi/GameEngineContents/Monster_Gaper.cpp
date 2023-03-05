
#include <GameEngineBase/GameEngineDirectory.h>

#include <GameEnginePlatform/GameEngineInput.h>

#include <GameEngineCore/GameEngineRender.h>
#include <GameEngineCore/GameEngineResources.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCollision.h>


#include "Isaac.h"
#include "IsaacEnum.h"
#include "Monster_Gaper.h"

Gaper::Gaper()
{

}

Gaper::~Gaper()
{
}


bool GaperLoad = true;
void Gaper::ImageLoad()
{
	GameEngineDirectory Dir;
	Dir.MoveParentToDirectory("ContentsResources");
	Dir.Move("ContentsResources");
	Dir.Move("Image");
	Dir.Move("Play");
	Dir.Move("Monster");

	GameEngineImage* Gapers = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("M_Gaper.BMP"));
	Gapers->Cut(2, 2);
	GameEngineImage* GaperBodysL = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("M_Bodys_L.BMP"));
	GaperBodysL->Cut(4, 5);
	GameEngineImage* GaperBodysR = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("M_Bodys_R.BMP"));
	GaperBodysR->Cut(4, 5);
}


void Gaper::Start()
{
	if (true == GaperLoad)
	{
		ImageLoad();
		GaperLoad = false;
	}
	M_GaperBodys = CreateRender(IsaacOrder::R_Monster); //몸
	M_GaperBodys->SetScale({ 50, 50 }); //크기
	M_GaperBodys->SetPosition({ 0,32 }); //위치

	M_Gaper = CreateRender(IsaacOrder::R_Monster); //얼굴
	M_Gaper->SetScale({ 70, 70 }); 

	GaperDeadRender = CreateRender(IsaacOrder::R_MonsterDead);
	GaperDeadRender->SetScale({ 50, 50 });
	GaperDeadRender->SetPosition({ 0,20 });
	

	M_Gaper->CreateAnimation({ .AnimationName = "M_GaperIdle",  .ImageName = "M_Gaper.bmp", .Start = 1, .End = 1, .InterTime = 0.2f });
	M_Gaper->CreateAnimation({ .AnimationName = "M_GaperDamaged",  .ImageName = "M_Gaper.bmp", .Start = 3, .End = 3, .InterTime = 0.3f });
	M_Gaper->ChangeAnimation("M_GaperIdle");
	
	M_GaperBodys->CreateAnimation({ .AnimationName = "M_GaperBodys",  .ImageName = "M_Bodys_L.bmp", .Start = 0, .End = 9, .InterTime = 0.1f });
	M_GaperBodys->CreateAnimation({ .AnimationName = "M_GaperBodys_L",  .ImageName = "M_Bodys_L.bmp", .Start = 10, .End = 19, .InterTime = 0.1f });
	M_GaperBodys->CreateAnimation({ .AnimationName = "M_GaperBodys_R",  .ImageName = "M_Bodys_R.bmp", .Start = 10, .End = 19, .InterTime = 0.1f });
	M_GaperBodys->ChangeAnimation("M_GaperBodys");

	GaperDeadRender->CreateAnimation({ .AnimationName = "GaperDead",  .ImageName = "M_Blood_deadbody.bmp", .Start = 9, .End = 9, .InterTime = 0.1f });
	GaperDeadRender->ChangeAnimation("GaperDead");
	GaperDeadRender->Off();


	{

		M_Gaper_Coll = CreateCollision(IsaacCollisionOrder::C_Monster);
		M_Gaper_Coll->SetScale({ 35, 35 });
		M_Gaper_Coll->On();
		M_Gaper_Coll->SetDebugRenderType(CollisionType::CT_Rect);

		M_GaperBody_Coll = CreateCollision(IsaacCollisionOrder::C_Monster);
		M_GaperBody_Coll->SetScale({ 35, 35 });
		M_GaperBody_Coll->SetPosition({ 0,30 });
		M_GaperBody_Coll->Off();
		M_GaperBody_Coll->SetDebugRenderType(CollisionType::CT_Rect);



		M_GaperBodys_SetColl_R = CreateCollision(IsaacCollisionOrder::C_Moster_Set);
		M_GaperBodys_SetColl_R->SetScale({ 1000, 800 });
		M_GaperBodys_SetColl_R->SetPosition({ 500,0 });
		M_GaperBodys_SetColl_R->On();
		M_GaperBodys_SetColl_R->SetDebugRenderType(CollisionType::CT_Rect);
	}

}


void Gaper::Update(float _DeltaTime)
{
	if (true == GaperDeathcheck)
	{
		if (true == Countbool)
		{
			Isaac::MainPlayer->MinusMonsterCount(1);
			Countbool = false;
		}
		M_Gaper_Coll->Death();
		M_GaperBody_Coll->Death();
		M_GaperBodys_SetColl_R->Death();
		M_GaperBodys->Death();
		M_Gaper->Death();
		GaperDeadRender->On();
	}
	Movecalculation(_DeltaTime);
	CollisionCheck(_DeltaTime);
	HpCheck(_DeltaTime);
}

void Gaper::Movecalculation(float _DeltaTime)
{
	float4 M_Move = Isaac::MainPlayer->GetPos() - GetPos();
	M_Move.Normalize();
	if (true == GaperDeathcheck)
	{
		M_Move = float4::Zero;
	}

	SetMove(M_Move * GaperSpeed * _DeltaTime);
}

void Gaper::HpCheck(float _DeltaTime)
{
	if (GaperHp <= 3)
	{
		M_Gaper->Death();
		M_Gaper_Coll->Death();
	}
}


void Gaper::CollisionCheck(float _DeltaTime)
{
	NowTime += _DeltaTime;

	if (NowTime >= 0.5f)
	{
		if (true == M_GaperBodys_SetColl_R->Collision({ .TargetGroup = static_cast<int>(IsaacCollisionOrder::C_Player), .TargetColType = CT_Rect, .ThisColType = CT_Rect }))
		{
			M_GaperBodys->ChangeAnimation("M_GaperBodys_R"); //다시 idle로바꾸고
		}
		else
		{
			M_GaperBodys->ChangeAnimation("M_GaperBodys_L");
		}
		NowTime = 0.0f;
		
		M_Gaper_Coll->On();
		if (GaperHp <= 3)
		{
			M_GaperBody_Coll->On();//시간이지나면 다시collision을킨다
		}
		

		RESET = 1;
		
	}

	std::vector<GameEngineCollision*> FCollisions;
	CollisionCheckParameter Check = { .TargetGroup = static_cast<int>(IsaacCollisionOrder::C_PlayerAtt_L), .TargetColType = CT_Rect, .ThisColType = CT_Rect };
	CollisionCheckParameter Check1 = { .TargetGroup = static_cast<int>(IsaacCollisionOrder::C_PlayerAtt_R), .TargetColType = CT_Rect, .ThisColType = CT_Rect };
	CollisionCheckParameter Check2 = { .TargetGroup = static_cast<int>(IsaacCollisionOrder::C_PlayerAtt_U), .TargetColType = CT_Rect, .ThisColType = CT_Rect };
	CollisionCheckParameter Check3 = { .TargetGroup = static_cast<int>(IsaacCollisionOrder::C_PlayerAtt_D), .TargetColType = CT_Rect, .ThisColType = CT_Rect };

	//함수짤 시간에 그냥 복붙을하겠노라
	if (true == M_Gaper_Coll->Collision(Check, FCollisions)|| true == M_GaperBody_Coll->Collision(Check, FCollisions)) //PlayerAtt에 닿았을때
	{
		M_Gaper->ChangeAnimation("M_GaperDamaged");
		FCollisions[0]->GetActor()->Death(); //닿은 ATT는 지워버리고
		SetMove(float4::Left * 20); //맞으면 밀려남(매끄럽게안밀려남) 방향에따른 설정도해야할듯

		if (1 == RESET)
		{
			GaperHp = GaperHp - Isaac::MainPlayer->GetTearDamage();
			RESET = 0;
			M_GaperBody_Coll->Off();
			M_Gaper_Coll->Off();
		}
		if (0 >= GaperHp)
		{
			//M_Blob->ChangeAnimation("M_fly_Dead");
			GaperDeathcheck = true;
		}
	}
	if (true == M_Gaper_Coll->Collision(Check1, FCollisions) || true == M_GaperBody_Coll->Collision(Check1, FCollisions))
	{
		M_Gaper->ChangeAnimation("M_GaperDamaged");
		FCollisions[0]->GetActor()->Death();
		SetMove(float4::Right * 20);

		if (1 == RESET)
		{
			GaperHp = GaperHp - Isaac::MainPlayer->GetTearDamage();
			RESET = 0;
			M_GaperBody_Coll->Off();
			M_Gaper_Coll->Off();
		}
		if (0 >= GaperHp)
		{
			//M_Blob->ChangeAnimation("M_fly_Dead");
			GaperDeathcheck = true;
		}
	}
	if (true == M_Gaper_Coll->Collision(Check2, FCollisions) || true == M_GaperBody_Coll->Collision(Check2, FCollisions))
	{
		M_Gaper->ChangeAnimation("M_GaperDamaged");
		FCollisions[0]->GetActor()->Death();
		SetMove(float4::Up * 20);

		if (1 == RESET)
		{
			GaperHp = GaperHp - Isaac::MainPlayer->GetTearDamage();
			RESET = 0;
			M_GaperBody_Coll->Off();
			M_Gaper_Coll->Off();
		}
		if (0 >= GaperHp)
		{
			//M_Blob->ChangeAnimation("M_fly_Dead");
			GaperDeathcheck = true;
		}
	}
	if (true == M_Gaper_Coll->Collision(Check3, FCollisions) || true == M_GaperBody_Coll->Collision(Check3, FCollisions))
	{
		M_Gaper->ChangeAnimation("M_GaperDamaged");
		FCollisions[0]->GetActor()->Death();
		SetMove(float4::Down * 20);

		if (1 == RESET)
		{
			GaperHp = GaperHp - Isaac::MainPlayer->GetTearDamage();
			RESET = 0;
			M_GaperBody_Coll->Off();
			M_Gaper_Coll->Off();
		}
		if (0 >= GaperHp)
		{
			//M_Blob->ChangeAnimation("M_fly_Dead");
			GaperDeathcheck = true;
		}
	}











	CollisionCheckParameter B_Check = { .TargetGroup = static_cast<int>(IsaacCollisionOrder::C_Isaac_Bomb), .TargetColType = CT_Rect, .ThisColType = CT_Rect };
	if (true == M_Gaper_Coll->Collision(B_Check, FCollisions) || true == M_GaperBody_Coll->Collision(Check, FCollisions))
	{
		GaperHp = GaperHp - 5; //이것은 폭탄의 데미지여
		if (0 >= GaperHp)
		{
			//M_Blob->ChangeAnimation("M_fly_Dead");
			GaperDeathcheck = true;
		}
	}
}

void Gaper::Render(float _DeltaTime)
{
	//M_Gaper_Coll->DebugRender();
	//M_GaperBody_Coll->DebugRender();
	//M_GaperBodys_SetColl_R->DebugRender();
}