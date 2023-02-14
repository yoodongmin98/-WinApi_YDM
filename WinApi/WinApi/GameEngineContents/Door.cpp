#include "Door.h"
#include "IsaacEnum.h"

#include <GameEngineCore/GameEngineRender.h>
#include <GameEngineBase/GameEngineDirectory.h>

#include <GameEnginePlatform/GameEngineInput.h>

#include <GameEngineCore/GameEngineResources.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCollision.h>

#include "Isaac.h"



Door::Door()
{
}

Door::~Door()
{
}


void Door::ImageLoad()
{
	GameEngineDirectory Dir;
	Dir.MoveParentToDirectory("ContentsResources");
	Dir.Move("ContentsResources");
	Dir.Move("Image");
	Dir.Move("Play");
	Dir.Move("Map");

	GameEngineImage* Door1 = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Map_Door_Right.BMP"));
	Door1->Cut(4, 1);
	
}

void Door::Start()
{
	ImageLoad();
	Door1 = CreateRender(IsaacOrder::R_Door);
	Door1->SetScale({ 350, 250 });
	SetPos({ 1180,430 });

	Door1->CreateAnimation({ .AnimationName = "Door_Idle",  .ImageName = "Map_Door_Right.bmp", .Start = 0, .End = 0, .InterTime = 0.1f });
	Door1->CreateAnimation({ .AnimationName = "Door_Open",  .ImageName = "Map_Door_Right.bmp", .Start = 0, .End = 3, .InterTime = 0.1f, .Loop = false });

	Door1->ChangeAnimation("Door_Idle");


	{
		Door1_C = CreateCollision(IsaacCollisionOrder::C_Monster);
		Door1_C->SetScale({ 200, 50 });
		Door1_C->On(); //처음엔 꺼놓는다(특정조건이 끝나면 콜리전을킴
	}
}


void Door::Update(float _DeltaTime)
{
	if (true == Door1_C->Collision({ .TargetGroup = static_cast<int>(IsaacCollisionOrder::C_Player) }))
	{
		Door1->ChangeAnimation("Door_Open");
	}

}

