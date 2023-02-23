
#include <GameEngineBase/GameEngineDirectory.h>

#include <GameEnginePlatform/GameEngineInput.h>


#include <GameEngineCore/GameEngineActor.h>
#include <GameEngineCore/GameEngineRender.h>
#include <GameEngineCore/GameEngineResources.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCollision.h>

#include "Isaac.h"
#include "IsaacEnum.h"

#include "Key.h"



Key::Key()
{

}

Key::~Key()
{
}


void Key::ImageLoad()
{
	GameEngineDirectory Dir;
	Dir.MoveParentToDirectory("ContentsResources");
	Dir.Move("ContentsResources");
	Dir.Move("Image");
	Dir.Move("Play");


	GameEngineImage* Key = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Key.bmp"));
	Key->Cut(2, 2);

}

bool LoadKey = true;
void Key::Start()
{
	if (true == LoadKey)
	{
		ImageLoad();
		LoadKey = false;
	}
	R_Key = CreateRender(IsaacOrder::R_Wall);
	R_Key->SetScale({ 70, 70 });

	R_Key->CreateAnimation({ .AnimationName = "Key",  .ImageName = "Key.bmp", .Start = 0, .End = 0, .InterTime = 1.0f , .Loop = false });
	R_Key->ChangeAnimation("Key");
	{
		Key_Coll = CreateCollision(IsaacCollisionOrder::C_Key);
		Key_Coll->SetScale({ 15, 15 });
		Key_Coll->On();
		Key_Coll->SetDebugRenderType(CollisionType::CT_Rect);
	}
}

void Key::Update(float _DeltaTime)
{

}

void Key::Render(float _DeltaTime)
{
	//Key_Coll->DebugRender();
}