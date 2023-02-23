
#include <GameEngineBase/GameEngineDirectory.h>

#include <GameEnginePlatform/GameEngineInput.h>


#include <GameEngineCore/GameEngineActor.h>
#include <GameEngineCore/GameEngineRender.h>
#include <GameEngineCore/GameEngineResources.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCollision.h>

#include "Isaac.h"
#include "IsaacEnum.h"

#include "ItemBomb.h"



ItemBomb::ItemBomb()
{

}

ItemBomb::~ItemBomb()
{
}


void ItemBomb::ImageLoad()
{
	GameEngineDirectory Dir;
	Dir.MoveParentToDirectory("ContentsResources");
	Dir.Move("ContentsResources");
	Dir.Move("Image");
	Dir.Move("Play");


	GameEngineImage* ItemBomb = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("ItemBomb.bmp"));
	ItemBomb->Cut(6,6);

}

bool Loadib = true;
void ItemBomb::Start()
{
	if (true == Loadib)
	{
		ImageLoad();
		Loadib = false;
	}
	R_ItemBomb = CreateRender(IsaacOrder::R_Wall);
	R_ItemBomb->SetScale({ 65, 65 });

	R_ItemBomb->CreateAnimation({ .AnimationName = "ItemBomb",  .ImageName = "ItemBomb.bmp", .Start = 0, .End = 0, .InterTime = 1.0f , .Loop = false });
	R_ItemBomb->ChangeAnimation("ItemBomb");
	{
		ItemBomb_Coll = CreateCollision(IsaacCollisionOrder::C_ItemBomb);
		ItemBomb_Coll->SetScale({ 5, 5 });
		ItemBomb_Coll->On();
		ItemBomb_Coll->SetDebugRenderType(CollisionType::CT_Rect);
	}
}

void ItemBomb::Update(float _DeltaTime)
{

}

void ItemBomb::Render(float _DeltaTime)
{
	//ItemBomb_Coll->DebugRender();
}