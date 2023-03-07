
#include <GameEngineBase/GameEngineDirectory.h>

#include <GameEnginePlatform/GameEngineInput.h>


#include <GameEngineCore/GameEngineActor.h>
#include <GameEngineCore/GameEngineRender.h>
#include <GameEngineCore/GameEngineResources.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCollision.h>

#include "Isaac.h"
#include "IsaacEnum.h"

#include "NextLevelDoor.h"




NextLevelDoor::NextLevelDoor()
{

}

NextLevelDoor::~NextLevelDoor()
{
}


void NextLevelDoor::ImageLoad()
{
	GameEngineDirectory Dir;
	Dir.MoveParentToDirectory("ContentsResources");
	Dir.Move("ContentsResources");
	Dir.Move("Image");
	Dir.Move("Play");
	Dir.Move("BossMonster");

	GameEngineImage* secrettrapdoors = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("secrettrapdoor.bmp"));
	secrettrapdoors->Cut(3, 2);
}

bool LoadNextLevelDoor = true;
void NextLevelDoor::Start()
{

	if (true == LoadNextLevelDoor)
	{
		ImageLoad();
		LoadNextLevelDoor = false;
	}
	R_NextLevelDoor = CreateRender(IsaacOrder::R_Wall);
	R_NextLevelDoor->SetScale({ 120, 120 });
	R_NextLevelDoor->CreateAnimation({ .AnimationName = "Open",  .ImageName = "secrettrapdoor.bmp", .Start = 1, .End = 2, .InterTime = 0.2f });
	R_NextLevelDoor->CreateAnimation({ .AnimationName = "Idle",  .ImageName = "secrettrapdoor.bmp", .Start = 0, .End = 0, .InterTime = 0.5f });
	R_NextLevelDoor->ChangeAnimation("Open");
	{
		NextLevelDoor_Coll = CreateCollision(IsaacCollisionOrder::NextLevel);
		NextLevelDoor_Coll->SetScale({ 30, 30 });
		NextLevelDoor_Coll->SetPosition(GetPos());
		NextLevelDoor_Coll->On();
		NextLevelDoor_Coll->SetDebugRenderType(CollisionType::CT_Rect);
	}

}

void NextLevelDoor::Update(float _DeltaTime)
{
	NowTime += _DeltaTime;
	
	if (NowTime > 2.0f)
	{
		R_NextLevelDoor->ChangeAnimation("Idle");
	}

}

void NextLevelDoor::Render(float _DeltaTime)
{
	//NextLevelDoor_Coll->DebugRender();
}