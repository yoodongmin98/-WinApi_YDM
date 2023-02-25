#include "Tears.h"
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



Tears::Tears() 
{
	
}

Tears::~Tears() 
{
	
}

void Tears::Start()
{
	// 렌더 생성
	{
		AnimationRender = CreateRender(IsaacOrder::R_Player);
		AnimationRender->SetScale({ 64, 64 });
		AnimationRender->SetPosition({ 0,-20 });
		AnimationRender->CreateAnimation({ .AnimationName = "Base", .ImageName = "Tear.BMP", .Start = 6, .End = 6, .InterTime = 0.1f });
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

void Tears::Update(float _DeltaTime)
{
	GravityTime += _DeltaTime;
	if (GravityTime > Isaac::MainPlayer->GetTearRange())
	{
		MoveDir = float4::Left * 300.0f + float4::Down*(Isaac::MainPlayer->GetGravityValue());
	}
	if (GravityTime > Isaac::MainPlayer->GetTearRange()+0.1f)
	{
		AnimationRender->ChangeAnimation("Pop");

		MoveDir = float4::Zero;
		if (true == AnimationRender->IsAnimationEnd())
		{
			Death();
		}
	}
	MoveCalculation(_DeltaTime);
	SetMove(MoveDir * _DeltaTime);
}

void Tears::MoveCalculation(float _DeltaTime)
{
	if (true == GameEngineInput::IsDown("LeftTears"))
	{
		MoveDir = float4::Left * (Isaac::MainPlayer->GetTearSpeed());
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

//아직미사용
void Tears::PlopSounds()
{
	PLOPSOUND = GameEngineResources::GetInst().SoundPlayToControl("Plop.wav");
	PLOPSOUND.Volume(0.2f);
	PLOPSOUND.LoopCount(1);
}
void Tears::Render(float _DeltaTime)
{
	//Collision->DebugRender();
}
