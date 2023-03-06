
#include <GameEngineBase/GameEngineDirectory.h>

#include <GameEnginePlatform/GameEngineInput.h>


#include <GameEngineCore/GameEngineActor.h>
#include <GameEngineCore/GameEngineRender.h>
#include <GameEngineCore/GameEngineResources.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCollision.h>

#include "Isaac.h"
#include "IsaacEnum.h"
#include "ShopKeeper.h"




ShopKeeper::ShopKeeper()
{

}

ShopKeeper::~ShopKeeper()
{
}


void ShopKeeper::ImageLoad()
{
	GameEngineDirectory Dir;
	Dir.MoveParentToDirectory("ContentsResources");
	Dir.Move("ContentsResources");
	Dir.Move("Image");
	Dir.Move("Play");
	Dir.Move("Shop");


	GameEngineImage* ShopKeepers = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("ShopKeeper.bmp"));
	ShopKeepers->Cut(4, 4);
	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("3Coin.bmp"));
	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("5Coin.bmp"));
	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("7Coin.bmp"));


}

bool LoadShopKeeper = true;
void ShopKeeper::Start()
{
	if (true == LoadShopKeeper)
	{
		ImageLoad();
		LoadShopKeeper = false;
	}
	R_ShopKeeper = CreateRender(IsaacOrder::R_Wall);
	R_ShopKeeper->SetScale({ 150, 150 });

	R_Coin3 = CreateRender(IsaacOrder::R_Wall);
	R_Coin3->SetScale({ 70, 70 });
	R_Coin3->SetImage("3Coin.bmp");
	R_Coin3->SetPosition({ -100,80 });

	R_Coin5 = CreateRender(IsaacOrder::R_Wall);
	R_Coin5->SetScale({ 70, 70 });
	R_Coin5->SetImage("5Coin.bmp");
	R_Coin5->SetPosition({ 0,80 });


	R_Coin7 = CreateRender(IsaacOrder::R_Wall);
	R_Coin7->SetScale({ 70, 70 });
	R_Coin7->SetImage("7Coin.bmp");
	R_Coin7->SetPosition({ 100,80 });




	R_ShopKeeper->CreateAnimation({ .AnimationName = "ShopkeeperIdle",  .ImageName = "Shopkeeper.bmp", .Start = 0, .End = 0, .InterTime = 0.1f });
	R_ShopKeeper->CreateAnimation({ .AnimationName = "ShopkeeperCry",  .ImageName = "Shopkeeper.bmp", .Start = 10, .End = 10, .InterTime = 5.0f , .Loop = false });
	R_ShopKeeper->CreateAnimation({ .AnimationName = "ShopkeeperDead",  .ImageName = "Shopkeeper.bmp", .Start = 11, .End = 13, .InterTime = 0.1f, .Loop = false });
	
	R_ShopKeeper->ChangeAnimation("ShopkeeperIdle");

	{

		ShopKeeper_Coll = CreateCollision(IsaacCollisionOrder::C_Wall);
		ShopKeeper_Coll->SetScale({ 50, 50 });
		ShopKeeper_Coll->On();
		ShopKeeper_Coll->SetDebugRenderType(CollisionType::CT_Rect);
	}

}


void ShopKeeper::Update(float _DeltaTime)
{
	CollisionCheck(_DeltaTime);
}


void ShopKeeper::CollisionCheck(float _DeltaTime)
{
	std::vector<GameEngineCollision*> PCollisions;
	CollisionCheckParameter CheckP = { .TargetGroup = static_cast<int>(IsaacCollisionOrder::C_PlayerAtt_L), .TargetColType = CT_Rect, .ThisColType = CT_Rect };
	CollisionCheckParameter CheckP1 = { .TargetGroup = static_cast<int>(IsaacCollisionOrder::C_PlayerAtt_R), .TargetColType = CT_Rect, .ThisColType = CT_Rect };
	CollisionCheckParameter CheckP2 = { .TargetGroup = static_cast<int>(IsaacCollisionOrder::C_PlayerAtt_U), .TargetColType = CT_Rect, .ThisColType = CT_Rect };
	CollisionCheckParameter CheckP3 = { .TargetGroup = static_cast<int>(IsaacCollisionOrder::C_PlayerAtt_D), .TargetColType = CT_Rect, .ThisColType = CT_Rect };
	CollisionCheckParameter CheckB = { .TargetGroup = static_cast<int>(IsaacCollisionOrder::C_Isaac_Bomb), .TargetColType = CT_Rect, .ThisColType = CT_Rect };

	if (true == ShopKeeper_Coll->Collision(CheckP, PCollisions) ||
		true == ShopKeeper_Coll->Collision(CheckP1, PCollisions) ||
		true == ShopKeeper_Coll->Collision(CheckP2, PCollisions) ||
		true == ShopKeeper_Coll->Collision(CheckP3, PCollisions))
	{
		R_ShopKeeper->ChangeAnimation("ShopkeeperCry");
		PCollisions[0]->GetActor()->Death();
	}
	if (true == ShopKeeper_Coll->Collision(CheckB, PCollisions))
	{
		
		if (R_ShopKeeper->IsAnimationEnd())
		{
			R_ShopKeeper->ChangeAnimation("ShopkeeperDead");
		}
	}

}

void ShopKeeper::Render(float _DeltaTime)
{
	//ShopKeeper_Coll->DebugRender();
}