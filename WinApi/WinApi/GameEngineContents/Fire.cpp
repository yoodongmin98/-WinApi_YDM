
#include <GameEngineBase/GameEngineDirectory.h>

#include <GameEnginePlatform/GameEngineInput.h>


#include <GameEngineCore/GameEngineActor.h>
#include <GameEngineCore/GameEngineRender.h>
#include <GameEngineCore/GameEngineResources.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCollision.h>

#include "Isaac.h"
#include "IsaacEnum.h"

#include "FIre.h"


//Drop
#include "Heart.h"


Fire* Fire::MainFire;

Fire::Fire()
{

}

Fire::~Fire()
{
}

void Fire::SoundLoad()
{
	GameEngineDirectory Dir;
	Dir.MoveParentToDirectory("ContentsResources");
	Dir.Move("ContentsResources");
	Dir.Move("Sound");
	{
		GameEngineResources::GetInst().SoundLoad(Dir.GetPlusFileName("fireburning.wav"));
	}
	FIRESOUND = GameEngineResources::GetInst().SoundPlayToControl("fireburning.wav");
	FIRESOUND.Volume(0.5);
}
void Fire::ImageLoad()
{
	GameEngineDirectory Dir;
	Dir.MoveParentToDirectory("ContentsResources");
	Dir.Move("ContentsResources");
	Dir.Move("Image");
	Dir.Move("Play");

	GameEngineImage* Fires = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Fire.bmp"));
	Fires->Cut(8, 2);
}

bool LoadFire = true;
void Fire::Start()
{
	MainFire = this; //이것은 불 그 잡채

	if (true == LoadFire)
	{
		SoundLoad();
		ImageLoad();
		LoadFire = false;
	}
	R_Fire = CreateRender(IsaacOrder::R_Wall);
	R_Fire->SetScale({ 100, 120 });
	R_Fire->CreateAnimation({ .AnimationName = "Fire",  .ImageName = "Fire.bmp", .Start = 0, .End = 5, .InterTime = 0.1f });
	R_Fire->ChangeAnimation("Fire");
	{
		Fire_Coll = CreateCollision(IsaacCollisionOrder::C_Fire);
		Fire_Coll->SetScale({ 50, 50 });
		Fire_Coll->SetPosition(GetPos() + float4::Down * 10);
		Fire_Coll->On();
		Fire_Coll->SetDebugRenderType(CollisionType::CT_Rect);
	}
}


void Fire::Update(float _DeltaTime)
{
	CollisionCheck(_DeltaTime);
}

void Fire::CollisionCheck(float _DeltaTime)
{
	std::vector<GameEngineCollision*> FCollisions;
	CollisionCheckParameter CheckF = { .TargetGroup = static_cast<int>(IsaacCollisionOrder::C_PlayerAtt), .TargetColType = CT_Rect, .ThisColType = CT_Rect };

	if (true == Fire_Coll->Collision(CheckF, FCollisions)) //PlayerAtt에 닿았을때
	{
		FCollisions[0]->GetActor()->Death(); //닿은 ATT는 지워버리고

		FireHp -= 1;
		if (5 == FireHp)
		{
			R_Fire->SetScale({ 100, 120 });
			Fire_Coll->SetScale({ 50, 50 });
		}
		if (4 == FireHp)
		{
			R_Fire->SetScale({ 80, 100 });
			Fire_Coll->SetScale({ 45, 45 });
		}
		if (3 == FireHp)
		{
			R_Fire->SetScale({ 70, 90 });
			Fire_Coll->SetScale({ 40, 40 });
		}
		if (2 == FireHp)
		{
			R_Fire->SetScale({ 50, 70 });
			Fire_Coll->SetScale({ 30, 30 });
		}
		if (1 == FireHp)
		{
			R_Fire->SetScale({ 30, 50 });
			Fire_Coll->SetScale({ 25, 25 });
		}
		if (0 == FireHp)
		{
			FIRESOUND.Stop();
			Death();
		}
	}
}


void Fire::Render(float _DeltaTime)
{
	//Fire_Coll->DebugRender();
}