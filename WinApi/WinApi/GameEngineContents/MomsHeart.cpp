
#include <GameEngineBase/GameEngineDirectory.h>

#include <GameEnginePlatform/GameEngineInput.h>

#include <GameEngineCore/GameEngineRender.h>
#include <GameEngineCore/GameEngineResources.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCollision.h>
#include <GameEngineCore/GameEngineCore.h>



#include "Isaac.h"
#include "IsaacEnum.h"
#include "MomsHeart.h"

#include "BloodTear.h"
#include "NextLevelDoor.h"

#include "Pooter.h"

#include "Clotty.h"

#include "Target.h"




#include<iostream>
#include<cstdlib>
#include<ctime>

MomsHeart* MomsHeart::MainMomsHeart;

MomsHeart::MomsHeart()
{

}

MomsHeart::~MomsHeart()
{
}

bool MomsHeartLoad = true;
void MomsHeart::ImageLoad()
{
	GameEngineDirectory Dir;
	Dir.MoveParentToDirectory("ContentsResources");
	Dir.Move("ContentsResources");
	Dir.Move("Image");
	Dir.Move("Play");
	Dir.Move("BossMonster");

	GameEngineImage* MomsHeartss = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("MomsHeart.BMP"));
	MomsHeartss->Cut(2, 3);

}

void MomsHeart::Start()
{
	MainMomsHeart = this;
	
	if (true == MomsHeartLoad)
	{
		ImageLoad();
		MomsHeartLoad = false;
	}
	M_MomsHeart = CreateRender(IsaacOrder::R_Monster);
	M_MomsHeart->SetScale({ 300, 400 });

	M_MomsHeart->CreateAnimation({ .AnimationName = "M_MomsHeart_Idle",  .ImageName = "MomsHeart.bmp", .Start = 2, .End = 3, .InterTime = 0.15f , });
	M_MomsHeart->CreateAnimation({ .AnimationName = "M_MomsHeart_Stop",  .ImageName = "MomsHeart.bmp", .Start = 0, .End = 0, .InterTime = 0.15f , });
	M_MomsHeart->CreateAnimation({ .AnimationName = "M_MomsHeart_Attack",  .ImageName = "MomsHeart.bmp", .Start = 0, .End = 4, .InterTime = 0.1f });
	M_MomsHeart->CreateAnimation({ .AnimationName = "M_Monstro_Attack",  .ImageName = "MomsHeart.bmp", .Start = 3, .End = 3, .InterTime = 0.5f });
	M_MomsHeart->ChangeAnimation("M_MomsHeart_Idle");
	{
		M_MomsHeart_Coll = CreateCollision(IsaacCollisionOrder::C_Monster);
		M_MomsHeart_Coll->SetScale({ 100, 180 });
		M_MomsHeart_Coll->SetPosition({ 0, 50 });
		M_MomsHeart_Coll->On();
		M_MomsHeart_Coll->SetDebugRenderType(CollisionType::CT_Rect);
	}
	CALLISAAC = GameEngineResources::GetInst().SoundPlayToControl("Callisaac.wav");
	CALLISAAC.Volume(0.1f);
	CALLISAAC.LoopCount(1);
}

bool MonsterSoundBool = true;

void MomsHeart::Update(float _DeltaTime)
{
	if (true == MomsHeartDeathcheck)
	{
		if (true == asdasdasdasd)
		{
			Isaac::MainPlayer->MinusMonsterCount(1);
			
			asdasdasdasd =false;
		}
		//여기에요!
		//GameEngineCore::GetInst()->ChangeLevel("TitleLevel");
		Death();
	}





	UpdateTime += _DeltaTime;
	if (UpdateTime > 30.0f)
	{
		Pattern1Bool = false;
		UpdateTime = 0.0f;
	}
	MonsterSet(_DeltaTime);

	if (true == Pattern1Bool)
	{
		Pattern1(_DeltaTime);
	}
	else
	{
		Pattern2EndTime += _DeltaTime;
		PatternTime2 += _DeltaTime;
		M_MomsHeart->ChangeAnimation("M_MomsHeart_Stop");
		M_MomsHeart_Coll->Off();
		if (PatternTime2 > 0.5f)
		{
			Target* TestTarget = GetLevel()->CreateActor<Target>();
			srand((unsigned int)time(NULL));
			float num = rand()%10;
			TestTarget->SetPos(GetPos() - float4{ num * (num*10),-(num * (num*4)) });
			PatternTime2 = 0.0f;
		}
		if (Pattern2EndTime > 10.0f)
		{
			Pattern1Bool = true;
			M_MomsHeart_Coll->On();
			Pattern2EndTime = 0.0f;
		}
	}
	


	CollisionCheck(_DeltaTime);
}
bool LaughLoadBool = true;
void MomsHeart::Pattern1(float _DeltaTime)
{
	
	PatternTime1 += _DeltaTime;
	AttackTime += _DeltaTime;
	if (AttackTime > 0.5f)
	{
		MomsAttackBool1 = true;
		AttackTime = 0.0f;
	}
	if (PatternTime1 > 3.0f)
	{
		if (true == LaughLoadBool)
		{
			LAUGHMOM = GameEngineResources::GetInst().SoundPlayToControl("evillaugh.wav");
			LAUGHMOM.Volume(0.1f);
			LAUGHMOM.LoopCount(1);
			LaughLoadBool = false;
		}
		M_MomsHeart->ChangeAnimation("M_MomsHeart_Attack");
		Attack1();
		MomsAttackBool1 = false;

		if (PatternTime1 > 5.0f)
		{
			M_MomsHeart->ChangeAnimation("M_MomsHeart_Idle");

			PatternTime1 = 0.0f;
			LaughLoadBool = true;
		}
	}
}




void MomsHeart::MonsterSet(float _DeltaTime)
{
	NewMonsterTime += _DeltaTime;

	if (NewMonsterTime > 5.0f)
	{
		MonsterSoundBool = true;
	}
	if (NewMonsterTime > 10.0f)
	{
		if (true == MonsterSoundBool)
		{
			DEATHBURST = GameEngineResources::GetInst().SoundPlayToControl("deathburstsmall2.wav");
			DEATHBURST.Volume(0.3f);
			DEATHBURST.LoopCount(1);
			MonsterSoundBool = false;
		}

		NewMonsterTime = 0.0f;
		Clotty* MomClotty1 = GetLevel()->CreateActor<Clotty>();
		MomClotty1->SetPos(GetPos() + float4::Left * 70);
		Clotty* MomClotty2 = GetLevel()->CreateActor<Clotty>();
		MomClotty2->SetPos(GetPos() + float4::Down * 150);
	}
}



void MomsHeart::CollisionCheck(float _DeltaTime)
{
	NowTime += _DeltaTime;

	if (NowTime >= 0.1f)
	{
		NowTime = 0.0f;
		M_MomsHeart_Coll->On();  //시간이지나면 다시collision을킨다
		RESET = 1;
	}

	std::vector<GameEngineCollision*> FCollisions;
	CollisionCheckParameter Check = { .TargetGroup = static_cast<int>(IsaacCollisionOrder::C_PlayerAtt_L), .TargetColType = CT_Rect, .ThisColType = CT_Rect };
	CollisionCheckParameter Check1 = { .TargetGroup = static_cast<int>(IsaacCollisionOrder::C_PlayerAtt_R), .TargetColType = CT_Rect, .ThisColType = CT_Rect };
	CollisionCheckParameter Check2 = { .TargetGroup = static_cast<int>(IsaacCollisionOrder::C_PlayerAtt_U), .TargetColType = CT_Rect, .ThisColType = CT_Rect };
	CollisionCheckParameter Check3 = { .TargetGroup = static_cast<int>(IsaacCollisionOrder::C_PlayerAtt_D), .TargetColType = CT_Rect, .ThisColType = CT_Rect };

	//함수짤 시간에 그냥 복붙을하겠노라
	if (true == M_MomsHeart_Coll->Collision(Check, FCollisions))
	{
		FCollisions[0]->GetActor()->Death();

		if (1 == RESET)
		{
			MomsHeartHp = MomsHeartHp - Isaac::MainPlayer->GetTearDamage();
			RESET = 0;
			M_MomsHeart_Coll->Off();
		}
		if (0 >= MomsHeartHp)
		{
			MomsHeartDeathcheck = true;
		}
	}
	if (true == M_MomsHeart_Coll->Collision(Check1, FCollisions))
	{
		FCollisions[0]->GetActor()->Death();
		if (1 == RESET)
		{
			MomsHeartHp = MomsHeartHp - Isaac::MainPlayer->GetTearDamage();
			RESET = 0;
			M_MomsHeart_Coll->Off();
		}
		if (0 >= MomsHeartHp)
		{
			MomsHeartDeathcheck = true;
		}
	}
	if (true == M_MomsHeart_Coll->Collision(Check2, FCollisions))
	{
		FCollisions[0]->GetActor()->Death();
		if (1 == RESET)
		{
			MomsHeartHp = MomsHeartHp - Isaac::MainPlayer->GetTearDamage();
			RESET = 0;
			M_MomsHeart_Coll->Off();
		}
		if (0 >= MomsHeartHp)
		{
			MomsHeartDeathcheck = true;
		}
	}
	if (true == M_MomsHeart_Coll->Collision(Check3, FCollisions))
	{
		FCollisions[0]->GetActor()->Death();
		if (1 == RESET)
		{
			MomsHeartHp = MomsHeartHp - Isaac::MainPlayer->GetTearDamage();
			RESET = 0;
			M_MomsHeart_Coll->Off();
		}
		if (0 >= MomsHeartHp)
		{
			MomsHeartDeathcheck = true;
		}
	}
	CollisionCheckParameter B_Check = { .TargetGroup = static_cast<int>(IsaacCollisionOrder::C_Isaac_Bomb), .TargetColType = CT_Rect, .ThisColType = CT_Rect };
	if (true == M_MomsHeart_Coll->Collision(B_Check, FCollisions))
	{
		MomsHeartHp = MomsHeartHp - 5;
		if (0 >= MomsHeartHp)
		{
			MomsHeartDeathcheck = true;
		}
	}
}



void MomsHeart::Attack1()
{
	float4 PlayerPos = Isaac::MainPlayer->GetPos() - GetPos();

	if (true == MomsAttackBool1)
	{
		BloodTear* Tear1 = GetLevel()->CreateActor<BloodTear>();
		Tear1->SetBloodMoveDir(PlayerPos + float4::Up * 10);
		Tear1->SetPos(GetPos());
		BloodTear* Tear2 = GetLevel()->CreateActor<BloodTear>();
		Tear2->SetBloodMoveDir(PlayerPos + float4::Up * 60);
		Tear2->SetPos(GetPos());
		BloodTear* Tear3 = GetLevel()->CreateActor<BloodTear>();
		Tear3->SetBloodMoveDir(PlayerPos + float4::Down * 60);
		Tear3->SetPos(GetPos());
		BloodTear* Tear4 = GetLevel()->CreateActor<BloodTear>();
		Tear4->SetBloodMoveDir(PlayerPos + float4::Down * 30);
		Tear4->SetPos(GetPos());
		BloodTear* Tear5 = GetLevel()->CreateActor<BloodTear>();
		Tear5->SetBloodMoveDir(PlayerPos + float4::Up * 110);
		Tear5->SetPos(GetPos());
		BloodTear* Tear6 = GetLevel()->CreateActor<BloodTear>();
		Tear6->SetBloodMoveDir(PlayerPos + float4::Up * 160);
		Tear6->SetPos(GetPos());
		BloodTear* Tear7 = GetLevel()->CreateActor<BloodTear>();
		Tear7->SetBloodMoveDir(PlayerPos + float4::Down * 105);
		Tear7->SetPos(GetPos());
		BloodTear* Tear8 = GetLevel()->CreateActor<BloodTear>();
		Tear8->SetBloodMoveDir(PlayerPos + float4::Up * 210);
		Tear8->SetPos(GetPos());
		BloodTear* Tear9 = GetLevel()->CreateActor<BloodTear>();
		Tear9->SetBloodMoveDir(PlayerPos + float4::Down * 45);
		Tear9->SetPos(GetPos());
		BloodTear* Tear10 = GetLevel()->CreateActor<BloodTear>();
		Tear10->SetBloodMoveDir(PlayerPos + float4::Up * 260);
		Tear10->SetPos(GetPos());

	}
}




void MomsHeart::Render(float _DeltaTime)
{
	//M_MomsHeart_Coll->DebugRender();
}
