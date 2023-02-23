
#include <GameEngineBase/GameEngineDirectory.h>

#include <GameEnginePlatform/GameEngineInput.h>

#include <GameEngineCore/GameEngineRender.h>
#include <GameEngineCore/GameEngineResources.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCollision.h>

#include "Isaac.h"
#include "IsaacEnum.h"
#include "FireWood.h"
//��������۵�
#include "Heart.h"



FireWood::FireWood()
{

}

FireWood::~FireWood()
{
}

// ���õȰ� Isaac.cpp��������
void FireWood::ImageLoad()
{
	GameEngineDirectory Dir;
	Dir.MoveParentToDirectory("ContentsResources");
	Dir.Move("ContentsResources");
	Dir.Move("Image");
	Dir.Move("Play");

	GameEngineImage* Heart = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Fire_Wood.bmp"));
	Heart->Cut(4,4);
}

bool WoodLoad = true;
void FireWood::Start()
{
	if (true == WoodLoad)
	{
		ImageLoad();
		WoodLoad = false;
	}
	R_FireWood = CreateRender(IsaacOrder::R_Door);
	R_FireWood->SetScale({ 80, 80 });

	R_FireWood->CreateAnimation({ .AnimationName = "Fire_Wood",  .ImageName = "Fire_Wood.bmp", .Start = 0, .End = 0, .InterTime = 1.0f , .Loop = false });
	R_FireWood->CreateAnimation({ .AnimationName = "Fire_Wood_Done",  .ImageName = "Fire_Wood.bmp", .Start = 1, .End = 1, .InterTime = 1.0f , .Loop = false });
	R_FireWood->ChangeAnimation("Fire_Wood");

}

void FireWood::Update(float _DeltaTime)
{

}

void FireWood::Render(float _DeltaTime)
{
	//Heart_Coll->DebugRender();
}