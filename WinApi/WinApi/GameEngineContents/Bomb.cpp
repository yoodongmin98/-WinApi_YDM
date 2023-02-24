
#include <GameEngineBase/GameEngineDirectory.h>

#include <GameEnginePlatform/GameEngineInput.h>

#include <GameEngineCore/GameEngineRender.h>
#include <GameEngineCore/GameEngineResources.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCollision.h>

#include "Isaac.h"
#include "IsaacEnum.h"
#include "Bomb.h"



Bomb::Bomb()
{

}

Bomb::~Bomb()
{
}


void Bomb::ImageLoad()
{
	GameEngineDirectory Dir;
	Dir.MoveParentToDirectory("ContentsResources");
	Dir.Move("ContentsResources");
	Dir.Move("Image");
	Dir.Move("Play");
	

	GameEngineImage* Bomb = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Bomb.bmp"));
	Bomb->Cut(3, 1);
	GameEngineImage* Bomb_E = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Bomb_Effect.bmp"));
	Bomb_E->Cut(4, 3);
}

bool LoadBomb = true;
void Bomb::Start()
{
	if (true == LoadBomb)
	{
		ImageLoad();
		LoadBomb = false;
	}
	R_Bomb = CreateRender(IsaacOrder::R_Player);
	R_Bomb->SetScale({ 70, 70 });
	SetPos(Isaac::MainPlayer->GetPos()); //플레이어의 위치에 세팅


	R_Bomb->CreateAnimation({ .AnimationName = "Bomb",  .ImageName = "Bomb.bmp", .Start = 0, .End = 2, .InterTime = 0.5f , .Loop=false});
	R_Bomb->CreateAnimation({ .AnimationName = "Bomb_Effect",  .ImageName = "Bomb_Effect.bmp", .Start = 0, .End = 11, .InterTime = 0.02f , .Loop = false });
	R_Bomb->ChangeAnimation("Bomb");

	{
		Bomb_Coll = CreateCollision(IsaacCollisionOrder::C_Isaac_Bomb);
		Bomb_Coll->SetScale({ 30, 30 });
		Bomb_Coll->Off();
		Bomb_Coll->SetDebugRenderType(CollisionType::CT_Rect);
	}

}


void Bomb::Update(float _DeltaTime)
{
	NowTime += _DeltaTime;
	FlikerSet(_DeltaTime);
	CollisionCheck(_DeltaTime);
	if (NowTime > 2.0f)
	{
		Bomb_Coll->On();
		R_Bomb->SetScale({ 200, 200 });
		Bomb_Coll->SetScale({ 100, 100 });
		R_Bomb->ChangeAnimation("Bomb_Effect");
	}
	if (NowTime > 2.1f)
	{
		BoomPlayer = GameEngineResources::GetInst().SoundPlayToControl("explosions.wav");
		BoomPlayer.Volume(0.2);
		BoomPlayer.LoopCount(1);
		Death();
	}
}

void Bomb::CollisionCheck(float _DeltaTime)
{
	
}

void Bomb::FlikerSet(float _DeltaTime)
{
	FTime += _DeltaTime;


	if (FTime > 0.6f) { R_Bomb->Off(); }
	if (FTime > 0.65f) { R_Bomb->On(); }
	if (FTime > 0.7f) { R_Bomb->Off(); }
	if (FTime > 0.75f) { R_Bomb->On(); }
	if (FTime > 0.8f) { R_Bomb->Off(); }
	if (FTime > 0.85f) { R_Bomb->On(); }
	if (FTime > 0.9f) { R_Bomb->Off(); }
	if (FTime > 0.95f) { R_Bomb->On(); }
	if (FTime > 1.0f) { R_Bomb->Off(); }
	if (FTime > 1.05f) { R_Bomb->On(); }
	if (FTime > 1.1f) { R_Bomb->Off(); }
	if (FTime > 1.15f) { R_Bomb->On(); }
	if (FTime > 1.2f) { R_Bomb->Off(); }
	if (FTime > 1.25f) { R_Bomb->On(); }
	if (FTime > 1.3f) { R_Bomb->Off(); }
	if (FTime > 1.35f) { R_Bomb->On(); }
	if (FTime > 1.4f) { R_Bomb->Off(); }
	if (FTime > 1.45f) { R_Bomb->On(); }
	if (FTime > 1.5f) { R_Bomb->Off(); }
	if (FTime > 1.55f) { R_Bomb->On(); }
	if (FTime > 1.6f) { R_Bomb->Off(); }
	if (FTime > 1.65f) { R_Bomb->On(); }
	if (FTime > 1.7f) { R_Bomb->Off(); }
	if (FTime > 1.75f) { R_Bomb->On(); }
	if (FTime > 1.8f) { R_Bomb->Off(); }
	if (FTime > 1.85f) { R_Bomb->On(); }
	if (FTime > 1.9f) { R_Bomb->Off(); }
	if (FTime > 1.95f) { R_Bomb->On(); }
}

void Bomb::Render(float _DeltaTime)
{
	//Bomb_Coll->DebugRender();
}