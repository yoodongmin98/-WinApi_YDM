#include "BlackLotus.h"
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



BlackLotus::BlackLotus()
{

}

BlackLotus::~BlackLotus()
{

}

bool BlackLotusLoad = true;
void BlackLotus::ImageLoad()
{
	GameEngineDirectory Dir;
	Dir.MoveParentToDirectory("ContentsResources");
	Dir.Move("ContentsResources");
	Dir.Move("Image");
	Dir.Move("Play");
	Dir.Move("Item");

	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Item_Blacklotus.BMP"));
}

void BlackLotus::Start()
{
	if (true == BlackLotusLoad)
	{
		ImageLoad();
		BlackLotusLoad = false;
	}
	// 兄希 持失
	{
		BlackLotusRender = CreateRender(IsaacOrder::R_Item);
		BlackLotusRender->SetScale({ 60, 60 });
		BlackLotusRender->SetImage("Item_Blacklotus.BMP");
	}
	//Colliison持失
	{
		BlackLotusCollision = CreateCollision(IsaacCollisionOrder::C_Item_Blacklotus);
		BlackLotusCollision->SetScale({ 30,30 });
		BlackLotusCollision->SetDebugRenderType(CollisionType::CT_Rect);
	}
}

void BlackLotus::Update(float _DeltaTime)
{

}


void BlackLotus::Render(float _DeltaTime)
{
	//LeoCollision->DebugRender();
}
