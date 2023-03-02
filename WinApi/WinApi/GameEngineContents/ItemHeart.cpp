#include "ItemHeart.h"
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEnginePlatform/GameEngineImage.h>
#include <GameEnginePlatform/GameEngineInput.h>

#include<GameEngineBase/GameEngineDirectory.h>
#include <GameEngineCore/GameEngineRender.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCollision.h>
#include <GameEngineCore/GameEngineResources.h>

#include "IsaacEnum.h"
#include "isaac.h"



ItemHeart::ItemHeart()
{

}

ItemHeart::~ItemHeart()
{

}

bool ItemHeartLoad = true;
void ItemHeart::ImageLoad()
{
	GameEngineDirectory Dir;
	Dir.MoveParentToDirectory("ContentsResources");
	Dir.Move("ContentsResources");
	Dir.Move("Image");
	Dir.Move("Play");
	Dir.Move("Item");

	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Item_Heart.BMP"));
}

void ItemHeart::Start()
{
	if (true == ItemHeartLoad)
	{
		ImageLoad();
		ItemHeartLoad = false;
	}
	// 兄希 持失
	{
		ItemHeartRender = CreateRender(IsaacOrder::R_Item);
		ItemHeartRender->SetScale({ 60, 60 });
		ItemHeartRender->SetImage("Item_Heart.BMP");
	}
	//Colliison持失
	{
		ItemHeartCollision = CreateCollision(IsaacCollisionOrder::C_Item_Heart);
		ItemHeartCollision->SetScale({ 30,30 });
		ItemHeartCollision->SetDebugRenderType(CollisionType::CT_Rect);
	}
}

void ItemHeart::Update(float _DeltaTime)
{

}


void ItemHeart::Render(float _DeltaTime)
{
	//LeoCollision->DebugRender();
}
