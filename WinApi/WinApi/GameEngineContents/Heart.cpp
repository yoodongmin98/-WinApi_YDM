
#include <GameEngineBase/GameEngineDirectory.h>

#include <GameEnginePlatform/GameEngineInput.h>

#include <GameEngineCore/GameEngineRender.h>
#include <GameEngineCore/GameEngineResources.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCollision.h>

#include "Isaac.h"
#include "IsaacEnum.h"
#include "Heart.h"



Heart::Heart()
{

}

Heart::~Heart()
{
}

// 包访等扒 Isaac.cpp俊辑包府
void Heart::ImageLoad()
{
	GameEngineDirectory Dir;
	Dir.MoveParentToDirectory("ContentsResources");
	Dir.Move("ContentsResources");
	Dir.Move("Image");
	Dir.Move("Play");

	GameEngineImage* Heart = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Heart.bmp"));
	Heart->Cut(3, 6);
}

bool Load = true;
void Heart::Start()
{
	if (true == Load)
	{
		ImageLoad();
		Load = false;
	}
	R_Heart = CreateRender(IsaacOrder::R_Wall);
	R_Heart->SetScale({ 70, 70 });
	
	R_Heart->CreateAnimation({ .AnimationName = "Heart",  .ImageName = "Heart.bmp", .Start = 0, .End = 0, .InterTime = 1.0f , .Loop = false });
	R_Heart->CreateAnimation({ .AnimationName = "Heart_half",  .ImageName = "Heart.bmp", .Start = 1, .End = 1, .InterTime = 1.0f , .Loop = false });
	R_Heart->CreateAnimation({ .AnimationName = "Heart_Double",  .ImageName = "Heart.bmp", .Start = 8, .End = 8, .InterTime = 1.0f , .Loop = false });
	R_Heart->ChangeAnimation("Heart");

	{
		Heart_Coll = CreateCollision(IsaacCollisionOrder::C_Heart);
		Heart_Coll->SetScale({ 10, 10 });
		Heart_Coll->SetPosition({ -5,0 });
		Heart_Coll->On();
		Heart_Coll->SetDebugRenderType(CollisionType::CT_Rect);
	}
}

void Heart::Update(float _DeltaTime)
{
	
}

void Heart::Render(float _DeltaTime)
{
	//Heart_Coll->DebugRender();
}