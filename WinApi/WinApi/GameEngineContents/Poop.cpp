
#include <GameEngineBase/GameEngineDirectory.h>

#include <GameEnginePlatform/GameEngineInput.h>


#include <GameEngineCore/GameEngineActor.h>
#include <GameEngineCore/GameEngineRender.h>
#include <GameEngineCore/GameEngineResources.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCollision.h>

#include "Isaac.h"
#include "IsaacEnum.h"
#include "Poop.h"
#include "Heart.h"



Poop::Poop()
{

}

Poop::~Poop()
{
}


void Poop::ImageLoad()
{
	GameEngineDirectory Dir;
	Dir.MoveParentToDirectory("ContentsResources");
	Dir.Move("ContentsResources");
	Dir.Move("Image");
	Dir.Move("Play");


	GameEngineImage* Poop = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Poop.bmp"));
	Poop->Cut(5, 1);
	
}

bool LoadPoop = true;
void Poop::Start()
{
	if (true == LoadPoop)
	{
		ImageLoad();
		LoadPoop = false;
	}
	R_Poop = CreateRender(IsaacOrder::R_Wall);
	R_Poop->SetScale({ 70, 70 });
	R_Poop->SetPosition({ 180,160 });


	R_Poop->CreateAnimation({ .AnimationName = "Poop4",  .ImageName = "Poop.bmp", .Start = 0, .End = 0, .InterTime = 1.0f , .Loop = false });
	R_Poop->CreateAnimation({ .AnimationName = "Poop3",  .ImageName = "Poop.bmp", .Start = 1, .End = 1, .InterTime = 1.0f , .Loop = false });
	R_Poop->CreateAnimation({ .AnimationName = "Poop2",  .ImageName = "Poop.bmp", .Start = 2, .End = 2, .InterTime = 1.0f , .Loop = false });
	R_Poop->CreateAnimation({ .AnimationName = "Poop1",  .ImageName = "Poop.bmp", .Start = 3, .End = 3, .InterTime = 1.0f , .Loop = false });
	R_Poop->CreateAnimation({ .AnimationName = "Poop0",  .ImageName = "Poop.bmp", .Start = 4, .End = 4, .InterTime = 1.0f , .Loop = false });
	


	R_Poop->ChangeAnimation("Poop4");

	{

		Poop_Coll = CreateCollision(IsaacCollisionOrder::C_Wall);
		Poop_Coll->SetScale({ 50, 50 });
		Poop_Coll->SetPosition({ 180,160 });
		Poop_Coll->On();
		Poop_Coll->SetDebugRenderType(CollisionType::CT_Rect);
	}
	
}


void Poop::Update(float _DeltaTime)
{
	
	CollisionCheck(_DeltaTime);
}

void Poop::CollisionCheck(float _DeltaTime)
{
	std::vector<GameEngineCollision*> PCollisions;
	CollisionCheckParameter CheckP = { .TargetGroup = static_cast<int>(IsaacCollisionOrder::C_PlayerAtt_L), .TargetColType = CT_Rect, .ThisColType = CT_Rect };
	CollisionCheckParameter CheckP1 = { .TargetGroup = static_cast<int>(IsaacCollisionOrder::C_PlayerAtt_R), .TargetColType = CT_Rect, .ThisColType = CT_Rect };
	CollisionCheckParameter CheckP2 = { .TargetGroup = static_cast<int>(IsaacCollisionOrder::C_PlayerAtt_U), .TargetColType = CT_Rect, .ThisColType = CT_Rect };
	CollisionCheckParameter CheckP3 = { .TargetGroup = static_cast<int>(IsaacCollisionOrder::C_PlayerAtt_D), .TargetColType = CT_Rect, .ThisColType = CT_Rect };

	if (true == Poop_Coll->Collision(CheckP, PCollisions)&&
		true == Poop_Coll->Collision(CheckP1, PCollisions)&&
		true == Poop_Coll->Collision(CheckP2, PCollisions)&&
		true == Poop_Coll->Collision(CheckP3, PCollisions)) //PlayerAtt에 닿았을때
	{
		PCollisions[0]->GetActor()->Death(); //닿은 ATT는 지워버리고
		
		PoopHp -= 1;
		if (4 == PoopHp)
		{
			R_Poop->ChangeAnimation("Poop4");
		}
		if (3 == PoopHp)
		{
			R_Poop->ChangeAnimation("Poop3");
		}
		if (2 == PoopHp)
		{
			R_Poop->ChangeAnimation("Poop2");
		}
		if (1 == PoopHp)
		{
			R_Poop->ChangeAnimation("Poop1");
		}
		if (0 == PoopHp)
		{
			R_Poop->ChangeAnimation("Poop0");
			Poop_Coll->Off();
		}
	}
}


void Poop::Render(float _DeltaTime)
{
	//Poop_Coll->DebugRender();
}