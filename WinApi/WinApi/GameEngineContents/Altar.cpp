#include "Altar.h"
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



Altar::Altar()
{

}

Altar::~Altar()
{

}

bool AltarLoad = true;
void Altar::ImageLoad()
{
	GameEngineDirectory Dir;
	Dir.MoveParentToDirectory("ContentsResources");
	Dir.Move("ContentsResources");
	Dir.Move("Image");
	Dir.Move("Play");
	Dir.Move("Item");

	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Item_Altar.BMP"));
}

void Altar::Start()
{
	if (true == AltarLoad)
	{
		ImageLoad();
		AltarLoad = false;
	}
	// ·»´õ »ý¼º
	{
		AltarRender = CreateRender(IsaacOrder::R_Item);
		AltarRender->SetScale({60, 60 });
		AltarRender->SetImage("Item_Altar.BMP");
	}
}

void Altar::Update(float _DeltaTime)
{

}


void Altar::Render(float _DeltaTime)
{
	//Collision->DebugRender();
}
