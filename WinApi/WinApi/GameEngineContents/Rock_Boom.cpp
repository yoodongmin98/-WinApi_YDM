
#include <GameEngineBase/GameEngineDirectory.h>

#include <GameEnginePlatform/GameEngineInput.h>

#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineActor.h>
#include <GameEngineCore/GameEngineRender.h>
#include <GameEngineCore/GameEngineResources.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCollision.h>

#include "Isaac.h"
#include "IsaacEnum.h"
#include "Rock_Boom.h"

#include "ItemBomb.h"




Rock_Boom::Rock_Boom()
{

}

Rock_Boom::~Rock_Boom()
{
}


void Rock_Boom::ImageLoad()
{
	GameEngineDirectory Dir;
	Dir.MoveParentToDirectory("ContentsResources");
	Dir.Move("ContentsResources");
	Dir.Move("Image");
	Dir.Move("Play");


	GameEngineImage* Rock_Boom = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Rock.bmp"));
	Rock_Boom->Cut(4, 8);

}

bool LoadRock_B = true;
void Rock_Boom::Start()
{
	if (true == LoadRock_B)
	{
		//ImageLoad();
		LoadRock_B = false;
	}
	R_Rock_Boom = CreateRender(IsaacOrder::R_Wall);
	R_Rock_Boom->SetScale({ 70, 70 });


	R_Rock_Boom->CreateAnimation({ .AnimationName = "Rock_Ons",  .ImageName = "Rock.bmp", .Start = 8, .End = 8, .InterTime = 1.0f , .Loop = false });
	R_Rock_Boom->CreateAnimation({ .AnimationName = "Rock_Breaks",  .ImageName = "Rock.bmp", .Start = 3, .End = 3, .InterTime = 1.0f , .Loop = false });
	



	R_Rock_Boom->ChangeAnimation("Rock_Ons");

	{

		Rock_Boom_Coll = CreateCollision(IsaacCollisionOrder::C_Wall);
		Rock_Boom_Coll->SetScale({ 50, 50 });
		Rock_Boom_Coll->On();
		Rock_Boom_Coll->SetDebugRenderType(CollisionType::CT_Rect);
	}
}


void Rock_Boom::Update(float _DeltaTime)
{
	Render(_DeltaTime);
	CollisionCheck(_DeltaTime);
}

bool DropBool = true;
void Rock_Boom::CollisionCheck(float _DeltaTime)
{
	std::vector<GameEngineCollision*> RCollisions;
	CollisionCheckParameter CheckR_B = { .TargetGroup = static_cast<int>(IsaacCollisionOrder::C_Isaac_Bomb), .TargetColType = CT_Rect, .ThisColType = CT_Rect };
	CollisionCheckParameter CheckR_PA_B = { .TargetGroup = static_cast<int>(IsaacCollisionOrder::C_PlayerAtt_L), .TargetColType = CT_Rect, .ThisColType = CT_Rect };
	CollisionCheckParameter CheckR_PA_B1 = { .TargetGroup = static_cast<int>(IsaacCollisionOrder::C_PlayerAtt_R), .TargetColType = CT_Rect, .ThisColType = CT_Rect };
	CollisionCheckParameter CheckR_PA_B2 = { .TargetGroup = static_cast<int>(IsaacCollisionOrder::C_PlayerAtt_U), .TargetColType = CT_Rect, .ThisColType = CT_Rect };
	CollisionCheckParameter CheckR_PA_B3 = { .TargetGroup = static_cast<int>(IsaacCollisionOrder::C_PlayerAtt_D), .TargetColType = CT_Rect, .ThisColType = CT_Rect };

	if (true == Rock_Boom_Coll->Collision(CheckR_B, RCollisions)) //ÆøÅº¿¡´êÀ¸¸é
	{
		if (true == DropBool)
		{
			R_Rock_Boom->ChangeAnimation("Rock_Breaks");
			ItemBomb* RockItem = GetLevel()->CreateActor<ItemBomb>(IsaacOrder::R_Wall);
			RockItem->SetPos(GetPos());
			Rock_Boom_Coll->Off();
			DropBool = false;
		}
	}
	if (true == Rock_Boom_Coll->Collision(CheckR_PA_B, RCollisions) ||
		true == Rock_Boom_Coll->Collision(CheckR_PA_B1, RCollisions) ||
		true == Rock_Boom_Coll->Collision(CheckR_PA_B2, RCollisions) ||
		true == Rock_Boom_Coll->Collision(CheckR_PA_B3, RCollisions)) //ÇÃ·¹ÀÌ¾î°ø°ÝÀÌ´êÀ¸¸é
	{
		RCollisions[0]->GetActor()->Death();
	}
}

void Rock_Boom::Render(float _DeltaTime)
{
	if (GameEngineInput::IsPress("MapCollisionSwitch"))
	{
		Rock_Boom_Coll->DebugRender();
	}
	//Rock_Boom_Coll->DebugRender();
}