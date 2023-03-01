#include "Leo.h"
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



Leo::Leo()
{

}

Leo::~Leo()
{

}

bool LeoLoad = true;
void Leo::ImageLoad()
{
	GameEngineDirectory Dir;
	Dir.MoveParentToDirectory("ContentsResources");
	Dir.Move("ContentsResources");
	Dir.Move("Image");
	Dir.Move("Play");
	Dir.Move("Item");

	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Item_Leo.BMP"));
}

void Leo::Start()
{
	SetMove(GameEngineWindow::GetScreenSize().half());
	SetPos(GameEngineWindow::GetScreenSize().half());
	if (true == LeoLoad)
	{
		ImageLoad();
		LeoLoad = false;
	}
	// 兄希 持失
	{
		LeoRender = CreateRender(IsaacOrder::R_Item);
		LeoRender->SetScale({ 60, 60 });
		LeoRender->SetImage("Item_Leo.BMP");
	}
	//Colliison持失
	{
		LeoCollision = CreateCollision(IsaacCollisionOrder::C_Item_Leo);
		LeoCollision->SetScale({ 30,30 });
		LeoCollision->SetDebugRenderType(CollisionType::CT_Rect);
	}
}

void Leo::Update(float _DeltaTime)
{

}


void Leo::Render(float _DeltaTime)
{
	LeoCollision->DebugRender();
}
