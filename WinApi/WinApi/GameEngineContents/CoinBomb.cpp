
#include <GameEngineBase/GameEngineDirectory.h>

#include <GameEnginePlatform/GameEngineInput.h>


#include <GameEngineCore/GameEngineActor.h>
#include <GameEngineCore/GameEngineRender.h>
#include <GameEngineCore/GameEngineResources.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCollision.h>

#include "Isaac.h"
#include "IsaacEnum.h"

#include "CoinBomb.h"



CoinBomb::CoinBomb()
{

}

CoinBomb::~CoinBomb()
{
}


void CoinBomb::ImageLoad()
{
	GameEngineDirectory Dir;
	Dir.MoveParentToDirectory("ContentsResources");
	Dir.Move("ContentsResources");
	Dir.Move("Image");
	Dir.Move("Play");
	Dir.Move("Shop");


	GameEngineImage* CoinBombs = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("CoinBomb.bmp"));
	CoinBombs->Cut(6, 6);

}

bool LoadCoinBomb = true;
void CoinBomb::Start()
{
	if (true == LoadCoinBomb)
	{
		ImageLoad();
		LoadCoinBomb = false;
	}
	R_CoinBomb = CreateRender(IsaacOrder::R_Wall);
	R_CoinBomb->SetScale({ 70, 70 });

	R_CoinBomb->CreateAnimation({ .AnimationName = "CoinBomb",  .ImageName = "CoinBomb.bmp", .Start = 1, .End = 1, .InterTime = 1.0f , .Loop = false });
	R_CoinBomb->ChangeAnimation("CoinBomb");
	{
		CoinBomb_Coll = CreateCollision(IsaacCollisionOrder::C_CoinBomb);
		CoinBomb_Coll->SetScale({ 10, 10 });
		CoinBomb_Coll->On();
		CoinBomb_Coll->SetDebugRenderType(CollisionType::CT_Rect);
	}
}

void CoinBomb::Update(float _DeltaTime)
{

}

void CoinBomb::Render(float _DeltaTime)
{
	//CoinBomb_Coll->DebugRender();
}