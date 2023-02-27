
#include <GameEngineBase/GameEngineDirectory.h>

#include <GameEnginePlatform/GameEngineInput.h>


#include <GameEngineCore/GameEngineActor.h>
#include <GameEngineCore/GameEngineRender.h>
#include <GameEngineCore/GameEngineResources.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCollision.h>

#include "Isaac.h"
#include "IsaacEnum.h"
#include "Rock.h"




Rock::Rock()
{

}

Rock::~Rock()
{
}


void Rock::ImageLoad()
{
	GameEngineDirectory Dir;
	Dir.MoveParentToDirectory("ContentsResources");
	Dir.Move("ContentsResources");
	Dir.Move("Image");
	Dir.Move("Play");


	GameEngineImage* Rocks = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Rock.bmp"));
	Rocks->Cut(4, 8);

}

bool LoadRock = true;
void Rock::Start()
{
	if (true == LoadRock)
	{
		ImageLoad();
		LoadRock = false;
	}
	R_Rock = CreateRender(IsaacOrder::R_Wall);
	R_Rock->SetScale({ 70, 70 });


	R_Rock->CreateAnimation({ .AnimationName = "Rock_On",  .ImageName = "Rock.bmp", .Start = 0, .End = 0, .InterTime = 1.0f , .Loop = false });
	R_Rock->CreateAnimation({ .AnimationName = "Rock_Break",  .ImageName = "Rock.bmp", .Start = 3, .End = 3, .InterTime = 1.0f , .Loop = false });



	R_Rock->ChangeAnimation("Rock_On");

	{

		Rock_Coll = CreateCollision(IsaacCollisionOrder::C_Wall);
		Rock_Coll->SetScale({ 50, 50 });
		Rock_Coll->On();
		Rock_Coll->SetDebugRenderType(CollisionType::CT_Rect);
	}
}


void Rock::Update(float _DeltaTime)
{
	Render(_DeltaTime);
	CollisionCheck(_DeltaTime);
}

void Rock::CollisionCheck(float _DeltaTime)
{
	std::vector<GameEngineCollision*> RCollisions;
	CollisionCheckParameter CheckR = { .TargetGroup = static_cast<int>(IsaacCollisionOrder::C_Isaac_Bomb), .TargetColType = CT_Rect, .ThisColType = CT_Rect };
	CollisionCheckParameter CheckR_PA = { .TargetGroup = static_cast<int>(IsaacCollisionOrder::C_PlayerAtt_L), .TargetColType = CT_Rect, .ThisColType = CT_Rect };
	CollisionCheckParameter CheckR_PA1 = { .TargetGroup = static_cast<int>(IsaacCollisionOrder::C_PlayerAtt_R), .TargetColType = CT_Rect, .ThisColType = CT_Rect };
	CollisionCheckParameter CheckR_PA2 = { .TargetGroup = static_cast<int>(IsaacCollisionOrder::C_PlayerAtt_U), .TargetColType = CT_Rect, .ThisColType = CT_Rect };
	CollisionCheckParameter CheckR_PA3 = { .TargetGroup = static_cast<int>(IsaacCollisionOrder::C_PlayerAtt_D), .TargetColType = CT_Rect, .ThisColType = CT_Rect };

	if (true == Rock_Coll->Collision(CheckR, RCollisions)) //ÆøÅº¿¡´êÀ¸¸é
	{
		R_Rock->ChangeAnimation("Rock_Break");
		Rock_Coll->Off();
	}
	if (true == Rock_Coll->Collision(CheckR_PA, RCollisions) ||
		true == Rock_Coll->Collision(CheckR_PA1, RCollisions) ||
		true == Rock_Coll->Collision(CheckR_PA2, RCollisions) ||
		true == Rock_Coll->Collision(CheckR_PA3, RCollisions)) //ÇÃ·¹ÀÌ¾î°ø°ÝÀÌ´êÀ¸¸é
	{
		RCollisions[0]->GetActor()->Death();
	}
}

void Rock::Render(float _DeltaTime)
{
	//Rock_Coll->DebugRender();
}