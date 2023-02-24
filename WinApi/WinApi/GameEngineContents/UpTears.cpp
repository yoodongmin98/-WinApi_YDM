#include "UpTears.h"
#include<GameEngineBase/GameEngineDirectory.h>
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEnginePlatform/GameEngineImage.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineRender.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCollision.h>
#include <GameEngineCore/GameEngineResources.h>

#include "IsaacEnum.h"



UpTears::UpTears()
{
}

UpTears::~UpTears()
{
}

void UpTears::Start()
{
	// 렌더 생성
	{
		AnimationRender = CreateRender(IsaacOrder::R_Player);
		AnimationRender->SetScale({ 64, 64 });
		AnimationRender->SetPosition({ 0,-20 });
		AnimationRender->CreateAnimation({ .AnimationName = "Base", .ImageName = "Tear.BMP", .Start = 5, .End = 5, .InterTime = 0.1f });
		AnimationRender->CreateAnimation({ .AnimationName = "Pop", .ImageName = "Tear_Pop.BMP", .Start = 0, .End = 15, .InterTime = 0.03f , .Loop = false });
	}
	AnimationRender->ChangeAnimation("Base");

	// Collision 생성
	{
		Collision = CreateCollision(IsaacCollisionOrder::C_PlayerAtt);
		Collision->SetScale({ 20, 20 });
		Collision->SetPosition({ 0, -20 });
		Collision->SetDebugRenderType(CollisionType::CT_Rect);
	}

}

void UpTears::Update(float _DeltaTime)
{
	MoveCalculation(_DeltaTime);
	SetMove(MoveDir * _DeltaTime);
}

void UpTears::MoveCalculation(float _DeltaTime)
{
	if (true == GameEngineInput::IsDown("UpTears"))
	{
		MoveDir = float4::Up * 300;
	}
	float4 NextPos = GetPos() + MoveDir * _DeltaTime;

	GameEngineImage* ColImage = GameEngineResources::GetInst().ImageFind("BackGround_CS.BMP");
	if (nullptr == ColImage)
	{
		MsgAssert("충돌용 맵 이미지가 없습니다.");
	}

	if (RGB(0, 0, 0) == ColImage->GetPixelColor(NextPos, RGB(0, 0, 0)))
	{
		
		AnimationRender->ChangeAnimation("Pop");
		MoveDir = float4::Zero;
		if (true == AnimationRender->IsAnimationEnd())
		{
			Death();
		}
	}
}

void UpTears::PlopSounds()
{
	PLOPSOUND = GameEngineResources::GetInst().SoundPlayToControl("Plop.wav");
	PLOPSOUND.Volume(0.2);
	PLOPSOUND.LoopCount(1);
}

void UpTears::Render(float _DeltaTime)
{
	//Collision->DebugRender();
}
