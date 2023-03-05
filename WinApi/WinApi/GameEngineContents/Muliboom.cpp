
#include <GameEngineBase/GameEngineDirectory.h>

#include <GameEnginePlatform/GameEngineInput.h>

#include <GameEngineCore/GameEngineRender.h>
#include <GameEngineCore/GameEngineResources.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCollision.h>


#include "Isaac.h"
#include "IsaacEnum.h"
#include "MuliBoom.h"
#include "Bomb.h"

MuliBoom::MuliBoom()
{

}

MuliBoom::~MuliBoom()
{
}


bool MuliBoomLoad = true;
void MuliBoom::ImageLoad()
{
	GameEngineDirectory Dir;
	Dir.MoveParentToDirectory("ContentsResources");
	Dir.Move("ContentsResources");
	Dir.Move("Image");
	Dir.Move("Play");
	Dir.Move("Monster");

	GameEngineImage* M_Mulibooms = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("M_Muliboom.BMP"));
	M_Mulibooms->Cut(3, 2);

	GameEngineImage* DeadEffect = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("M_Bomb_Effect.BMP"));
	DeadEffect->Cut(4, 3);

}


void MuliBoom::Start()
{
	if (true == MuliBoomLoad)
	{
		ImageLoad();
		MuliBoomLoad = false;
	}
	M_MuliBoomBodys = CreateRender(IsaacOrder::R_Monster);
	M_MuliBoomBodys->SetScale({ 50, 50 });
	M_MuliBoomBodys->SetPosition({ 0,32 });

	M_MuliBoom = CreateRender(IsaacOrder::R_Monster);
	M_MuliBoom->SetScale({ 100, 100 });



	M_MuliBoom->CreateAnimation({ .AnimationName = "M_MuliBoomIdle",  .ImageName = "M_Muliboom.bmp", .Start = 0, .End = 2, .InterTime = 0.15f });
	M_MuliBoom->CreateAnimation({ .AnimationName = "M_MuliBoomDamaged",  .ImageName = "M_Muliboom.bmp", .Start = 3, .End = 5, .InterTime = 0.1f , .Loop=false});

	M_MuliBoom->ChangeAnimation("M_MuliBoomIdle");

	M_MuliBoomBodys->CreateAnimation({ .AnimationName = "M_MuliBoomBodys",  .ImageName = "M_Bodys_L.bmp", .Start = 0, .End = 9, .InterTime = 0.1f });
	M_MuliBoomBodys->CreateAnimation({ .AnimationName = "M_MuliBoomBodys_L",  .ImageName = "M_Bodys_L.bmp", .Start = 10, .End = 19, .InterTime = 0.1f });
	M_MuliBoomBodys->CreateAnimation({ .AnimationName = "M_MuliBoomBodys_R",  .ImageName = "M_Bodys_R.bmp", .Start = 10, .End = 19, .InterTime = 0.1f });
	M_MuliBoomBodys->ChangeAnimation("M_MuliBoomBodys");

	{

		M_MuliBoom_Coll = CreateCollision(IsaacCollisionOrder::C_Monster);
		M_MuliBoom_Coll->SetScale({ 35, 35 });
		M_MuliBoom_Coll->On();
		M_MuliBoom_Coll->SetDebugRenderType(CollisionType::CT_Rect);

		M_MuliBoomBody_Coll = CreateCollision(IsaacCollisionOrder::C_Monster);
		M_MuliBoomBody_Coll->SetScale({ 35, 35 });
		M_MuliBoomBody_Coll->SetPosition({ 0,30 });
		M_MuliBoomBody_Coll->Off();
		M_MuliBoomBody_Coll->SetDebugRenderType(CollisionType::CT_Rect);



		M_MuliBoomBodys_SetColl_R = CreateCollision(IsaacCollisionOrder::C_Moster_Set);
		M_MuliBoomBodys_SetColl_R->SetScale({ 1000, 800 });
		M_MuliBoomBodys_SetColl_R->SetPosition({ 500,0 });
		M_MuliBoomBodys_SetColl_R->On();
		M_MuliBoomBodys_SetColl_R->SetDebugRenderType(CollisionType::CT_Rect);
	}

}


void MuliBoom::Update(float _DeltaTime)
{
	if (true == MuliBoomDeathcheck)
	{
		if (true == Countbool)
		{
			Isaac::MainPlayer->MinusMonsterCount(1);
			Countbool = false;
		}
		Bomb* MuliBoomBomb = GetLevel()->CreateActor<Bomb>();
		MuliBoomBomb->SetPos(GetPos());
		Death();
	}
	Movecalculation(_DeltaTime);
	CollisionCheck(_DeltaTime);
	HpCheck(_DeltaTime);
}

void MuliBoom::Movecalculation(float _DeltaTime)
{
	float4 M_Move = Isaac::MainPlayer->GetPos() - GetPos();
	M_Move.Normalize();

	SetMove(M_Move * 40.0f * _DeltaTime);
}

void MuliBoom::HpCheck(float _DeltaTime)
{
	if (MuliBoomHp <= 3)
	{
		M_MuliBoom->Death();
		M_MuliBoom_Coll->Death();
	}
}


void MuliBoom::CollisionCheck(float _DeltaTime)
{
	NowTime += _DeltaTime;

	if (NowTime >= 0.5f)
	{
		M_MuliBoom->ChangeAnimation("M_MuliBoomIdle");
		if (true == M_MuliBoomBodys_SetColl_R->Collision({ .TargetGroup = static_cast<int>(IsaacCollisionOrder::C_Player), .TargetColType = CT_Rect, .ThisColType = CT_Rect }))
		{
			M_MuliBoomBodys->ChangeAnimation("M_MuliBoomBodys_R"); //다시 idle로바꾸고
		}
		else
		{
			M_MuliBoomBodys->ChangeAnimation("M_MuliBoomBodys_L");
		}
		NowTime = 0.0f;

		M_MuliBoom_Coll->On();
		if (MuliBoomHp <= 3)
		{
			M_MuliBoomBody_Coll->On();
		}
		RESET = 1;
	}

	std::vector<GameEngineCollision*> FCollisions;
	CollisionCheckParameter Check = { .TargetGroup = static_cast<int>(IsaacCollisionOrder::C_PlayerAtt_L), .TargetColType = CT_Rect, .ThisColType = CT_Rect };
	CollisionCheckParameter Check1 = { .TargetGroup = static_cast<int>(IsaacCollisionOrder::C_PlayerAtt_R), .TargetColType = CT_Rect, .ThisColType = CT_Rect };
	CollisionCheckParameter Check2 = { .TargetGroup = static_cast<int>(IsaacCollisionOrder::C_PlayerAtt_U), .TargetColType = CT_Rect, .ThisColType = CT_Rect };
	CollisionCheckParameter Check3 = { .TargetGroup = static_cast<int>(IsaacCollisionOrder::C_PlayerAtt_D), .TargetColType = CT_Rect, .ThisColType = CT_Rect };

	//함수짤 시간에 그냥 복붙을하겠노라
	if (true == M_MuliBoom_Coll->Collision(Check, FCollisions) || true == M_MuliBoomBody_Coll->Collision(Check, FCollisions)) //PlayerAtt에 닿았을때
	{
		M_MuliBoom->ChangeAnimation("M_MuliBoomDamaged");
		FCollisions[0]->GetActor()->Death(); //닿은 ATT는 지워버리고
		SetMove(float4::Left * 20); //맞으면 밀려남(매끄럽게안밀려남) 방향에따른 설정도해야할듯

		if (1 == RESET)
		{
			MuliBoomHp = MuliBoomHp - Isaac::MainPlayer->GetTearDamage();
			RESET = 0;
			M_MuliBoomBody_Coll->Off();
			M_MuliBoom_Coll->Off();
		}
		if (0 >= MuliBoomHp)
		{
			//M_Blob->ChangeAnimation("M_fly_Dead");
			MuliBoomDeathcheck = true;
		}
	}
	if (true == M_MuliBoom_Coll->Collision(Check1, FCollisions) || true == M_MuliBoomBody_Coll->Collision(Check1, FCollisions))
	{
		M_MuliBoom->ChangeAnimation("M_MuliBoomDamaged");
		FCollisions[0]->GetActor()->Death();
		SetMove(float4::Right * 20);

		if (1 == RESET)
		{
			MuliBoomHp = MuliBoomHp - Isaac::MainPlayer->GetTearDamage();
			RESET = 0;
			M_MuliBoomBody_Coll->Off();
			M_MuliBoom_Coll->Off();
		}
		if (0 >= MuliBoomHp)
		{
			//M_Blob->ChangeAnimation("M_fly_Dead");
			MuliBoomDeathcheck = true;
		}
	}
	if (true == M_MuliBoom_Coll->Collision(Check2, FCollisions) || true == M_MuliBoomBody_Coll->Collision(Check2, FCollisions))
	{
		M_MuliBoom->ChangeAnimation("M_MuliBoomDamaged");
		FCollisions[0]->GetActor()->Death();
		SetMove(float4::Up * 20);

		if (1 == RESET)
		{
			MuliBoomHp = MuliBoomHp - Isaac::MainPlayer->GetTearDamage();
			RESET = 0;
			M_MuliBoomBody_Coll->Off();
			M_MuliBoom_Coll->Off();
		}
		if (0 >= MuliBoomHp)
		{
			//M_Blob->ChangeAnimation("M_fly_Dead");
			MuliBoomDeathcheck = true;
		}
	}
	if (true == M_MuliBoom_Coll->Collision(Check3, FCollisions) || true == M_MuliBoomBody_Coll->Collision(Check3, FCollisions))
	{
		M_MuliBoom->ChangeAnimation("M_MuliBoomDamaged");
		FCollisions[0]->GetActor()->Death();
		SetMove(float4::Down * 20);

		if (1 == RESET)
		{
			MuliBoomHp = MuliBoomHp - Isaac::MainPlayer->GetTearDamage();
			RESET = 0;
			M_MuliBoomBody_Coll->Off();
			M_MuliBoom_Coll->Off();
		}
		if (0 >= MuliBoomHp)
		{
			//M_Blob->ChangeAnimation("M_fly_Dead");
			MuliBoomDeathcheck = true;
		}
	}











	CollisionCheckParameter B_Check = { .TargetGroup = static_cast<int>(IsaacCollisionOrder::C_Isaac_Bomb), .TargetColType = CT_Rect, .ThisColType = CT_Rect };
	if (true == M_MuliBoom_Coll->Collision(B_Check, FCollisions) || true == M_MuliBoomBody_Coll->Collision(Check, FCollisions))
	{
		MuliBoomHp = MuliBoomHp - 5; //이것은 폭탄의 데미지여
		if (0 >= MuliBoomHp)
		{
			//M_Blob->ChangeAnimation("M_fly_Dead");
			MuliBoomDeathcheck = true;
		}
	}
}

void MuliBoom::Render(float _DeltaTime)
{
	//M_MuliBoom_Coll->DebugRender();
	//M_MuliBoomBody_Coll->DebugRender();
	//M_MuliBoomBodys_SetColl_R->DebugRender();
}