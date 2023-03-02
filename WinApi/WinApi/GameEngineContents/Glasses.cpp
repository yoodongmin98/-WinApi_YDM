#include "Glasses.h"
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



Glasses::Glasses()
{

}

Glasses::~Glasses()
{

}

bool GlassesLoad = true;
void Glasses::ImageLoad()
{
	GameEngineDirectory Dir;
	Dir.MoveParentToDirectory("ContentsResources");
	Dir.Move("ContentsResources");
	Dir.Move("Image");
	Dir.Move("Play");
	Dir.Move("Item");

	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Item_Glasses.BMP"));
}

void Glasses::Start()
{
	if (true == GlassesLoad)
	{
		ImageLoad();
		GlassesLoad = false;
	}
	// 兄希 持失
	{
		GlassesRender = CreateRender(IsaacOrder::R_Item);
		GlassesRender->SetScale({ 60, 60 });
		GlassesRender->SetImage("Item_Glasses.BMP");
	}
	//Colliison持失
	{
		GlassesCollision = CreateCollision(IsaacCollisionOrder::C_Item_Glasses);
		GlassesCollision->SetScale({ 30,30 });
		GlassesCollision->SetDebugRenderType(CollisionType::CT_Rect);
	}
}

void Glasses::Update(float _DeltaTime)
{

}


void Glasses::Render(float _DeltaTime)
{
	//LeoCollision->DebugRender();
}
