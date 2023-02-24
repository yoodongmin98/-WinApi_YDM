
#include <GameEngineBase/GameEngineDirectory.h>

#include <GameEnginePlatform/GameEngineInput.h>


#include <GameEngineCore/GameEngineActor.h>
#include <GameEngineCore/GameEngineRender.h>
#include <GameEngineCore/GameEngineResources.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCollision.h>

#include "Isaac.h"
#include "IsaacEnum.h"

#include "Coin.h"



Coin::Coin()
{

}

Coin::~Coin()
{
}


void Coin::ImageLoad()
{
	GameEngineDirectory Dir;
	Dir.MoveParentToDirectory("ContentsResources");
	Dir.Move("ContentsResources");
	Dir.Move("Image");
	Dir.Move("Play");


	GameEngineImage* Coins = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Coin.bmp"));
	Coins->Cut(4, 3);

}

bool LoadCoin = true;
void Coin::Start()
{
	if (true == LoadCoin)
	{
		ImageLoad();
		LoadCoin = false;
	}
	R_Coin = CreateRender(IsaacOrder::R_Wall);
	R_Coin->SetScale({ 100, 100 });

	R_Coin->CreateAnimation({ .AnimationName = "CoinLoad",  .ImageName = "Coin.bmp", .Start = 8, .End = 11, .InterTime = 0.03f, .Loop=false});
	R_Coin->CreateAnimation({ .AnimationName = "Coin",  .ImageName = "Coin.bmp", .Start = 0, .End = 5, .InterTime = 0.15f});
	R_Coin->ChangeAnimation("CoinLoad");
	{
		Coin_Coll = CreateCollision(IsaacCollisionOrder::C_Coin);
		Coin_Coll->SetScale({ 5, 5 });
		Coin_Coll->On();
		Coin_Coll->SetDebugRenderType(CollisionType::CT_Rect);
	}
}

void Coin::Update(float _DeltaTime)
{
	CoinLoadTime += _DeltaTime;
	if (CoinLoadTime > 0.13f)
	{
		R_Coin->ChangeAnimation("Coin");
	}
}

void Coin::Render(float _DeltaTime)
{
	Coin_Coll->DebugRender();
}