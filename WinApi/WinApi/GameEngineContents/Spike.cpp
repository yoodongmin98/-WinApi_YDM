
#include <GameEngineBase/GameEngineDirectory.h>

#include <GameEnginePlatform/GameEngineInput.h>


#include <GameEngineCore/GameEngineActor.h>
#include <GameEngineCore/GameEngineRender.h>
#include <GameEngineCore/GameEngineResources.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCollision.h>

#include "Isaac.h"
#include "IsaacEnum.h"
#include "Spike.h"




Spike::Spike()
{

}

Spike::~Spike()
{
}


void Spike::ImageLoad()
{
	GameEngineDirectory Dir;
	Dir.MoveParentToDirectory("ContentsResources");
	Dir.Move("ContentsResources");
	Dir.Move("Image");
	Dir.Move("Play");


	GameEngineImage* Spikes = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Spikes.bmp"));
	Spikes->Cut(4, 5);

}

bool LoadSpike = true;
void Spike::Start()
{
	if (true == LoadSpike)
	{
		ImageLoad();
		LoadSpike = false;
	}
	Spikes = CreateRender(IsaacOrder::R_Wall);
	Spikes->SetScale({ 70, 70 });
	


	Spikes->CreateAnimation({ .AnimationName = "Spike",  .ImageName = "Spikes.bmp", .Start = 0, .End = 0, .InterTime = 1.0f , .Loop = false });
	Spikes->ChangeAnimation("Spike");

	{

		Spike_Coll = CreateCollision(IsaacCollisionOrder::C_Monster);
		Spike_Coll->SetScale({ 50, 50 });
		Spike_Coll->On();
		Spike_Coll->SetDebugRenderType(CollisionType::CT_Rect);
	}

}


void Spike::Update(float _DeltaTime)
{
	//CollisionCheck(_DeltaTime);
}

void Spike::CollisionCheck(float _DeltaTime)
{

}


void Spike::Render(float _DeltaTime)
{
	//Spike_Coll->DebugRender();
}