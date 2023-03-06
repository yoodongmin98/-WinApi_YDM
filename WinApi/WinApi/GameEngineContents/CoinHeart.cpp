
#include <GameEngineBase/GameEngineDirectory.h>

#include <GameEnginePlatform/GameEngineInput.h>


#include <GameEngineCore/GameEngineActor.h>
#include <GameEngineCore/GameEngineRender.h>
#include <GameEngineCore/GameEngineResources.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCollision.h>

#include "Isaac.h"
#include "IsaacEnum.h"

#include "CoinHeart.h"



CoinHeart::CoinHeart()
{

}

CoinHeart::~CoinHeart()
{
}


void CoinHeart::ImageLoad()
{
	GameEngineDirectory Dir;
	Dir.MoveParentToDirectory("ContentsResources");
	Dir.Move("ContentsResources");
	Dir.Move("Image");
	Dir.Move("Play");
	Dir.Move("Shop");


	GameEngineImage* CoinHearts = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("CoinHeart.bmp"));
	CoinHearts->Cut(3, 6);

}

bool LoadCoinHeart = true;
void CoinHeart::Start()
{
	if (true == LoadCoinHeart)
	{
		ImageLoad();
		LoadCoinHeart = false;
	}
	R_CoinHeart = CreateRender(IsaacOrder::R_Wall);
	R_CoinHeart->SetScale({ 70, 70 });

	R_CoinHeart->CreateAnimation({ .AnimationName = "CoinHeart",  .ImageName = "CoinHeart.bmp", .Start = 8, .End = 8, .InterTime = 1.0f , .Loop = false });
	R_CoinHeart->ChangeAnimation("CoinHeart");
	{
		CoinHeart_Coll = CreateCollision(IsaacCollisionOrder::C_CoinHeart);
		CoinHeart_Coll->SetScale({ 10, 10 });
		CoinHeart_Coll->On();
		CoinHeart_Coll->SetDebugRenderType(CollisionType::CT_Rect);
	}
}

void CoinHeart::Update(float _DeltaTime)
{

}

void CoinHeart::Render(float _DeltaTime)
{
	//CoinHeart_Coll->DebugRender();
}