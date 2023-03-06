
#include <GameEngineBase/GameEngineDirectory.h>

#include <GameEnginePlatform/GameEngineInput.h>


#include <GameEngineCore/GameEngineActor.h>
#include <GameEngineCore/GameEngineRender.h>
#include <GameEngineCore/GameEngineResources.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCollision.h>

#include "Isaac.h"
#include "IsaacEnum.h"

#include "CoinKey.h"



CoinKey::CoinKey()
{

}

CoinKey::~CoinKey()
{
}


void CoinKey::ImageLoad()
{
	GameEngineDirectory Dir;
	Dir.MoveParentToDirectory("ContentsResources");
	Dir.Move("ContentsResources");
	Dir.Move("Image");
	Dir.Move("Play");
	Dir.Move("Shop");


	GameEngineImage* CoinKeys = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("CoinKey.bmp"));
	CoinKeys->Cut(2, 2);

}

bool LoadCoinKey = true;
void CoinKey::Start()
{
	if (true == LoadCoinKey)
	{
		ImageLoad();
		LoadCoinKey = false;
	}
	R_CoinKey = CreateRender(IsaacOrder::R_Wall);
	R_CoinKey->SetScale({ 70, 70 });
	  
	R_CoinKey->CreateAnimation({ .AnimationName = "CoinKey",  .ImageName = "CoinKey.bmp", .Start = 1, .End = 1, .InterTime = 1.0f , .Loop = false });
	R_CoinKey->ChangeAnimation("CoinKey");
	{
		CoinKey_Coll = CreateCollision(IsaacCollisionOrder::C_CoinKey);
		CoinKey_Coll->SetScale({ 10, 10 });
		CoinKey_Coll->On();
		CoinKey_Coll->SetDebugRenderType(CollisionType::CT_Rect);
	}
}

void CoinKey::Update(float _DeltaTime)
{

}

void CoinKey::Render(float _DeltaTime)
{
	//CoinKey_Coll->DebugRender();
}