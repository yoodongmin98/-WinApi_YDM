#include "RightTears.h"
#include<GameEngineBase/GameEngineDirectory.h>
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEnginePlatform/GameEngineImage.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineRender.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCollision.h>
#include <GameEngineCore/GameEngineResources.h>

#include "IsaacEnum.h"
#include "isaac.h"



RightTears::RightTears()
{
	
}

RightTears::~RightTears()
{
	
}

void RightTears::Start()
{
	
	// 兄希 持失
	{
		AnimationRender = CreateRender(IsaacOrder::R_Player);
		AnimationRender->SetScale({ 64, 64 });
		AnimationRender->SetPosition({ 0,-20 });
		AnimationRender->CreateAnimation({ .AnimationName = "Base", .ImageName = "Tear.BMP", .Start = 6, .End = 6, .InterTime = 0.1f });
		AnimationRender->CreateAnimation({ .AnimationName = "Pop", .ImageName = "Tear_Pop.BMP", .Start = 0, .End = 15, .InterTime = 0.03f , .Loop = false });
	}
	AnimationRender->ChangeAnimation("Base");

	// Collision 持失
	{
		Collision = CreateCollision(IsaacCollisionOrder::C_PlayerAtt_R);
		Collision->SetScale({ 20, 20 });
		Collision->SetPosition({ 0, -20 });
		Collision->SetDebugRenderType(CollisionType::CT_Rect);
	}

}

void RightTears::Update(float _DeltaTime)
{
	GravityTimeR += _DeltaTime;
	if (GravityTimeR > Isaac::MainPlayer->GetTearRange())
	{
		MoveDir = float4::Right * TearfallValue + float4::Down * (Isaac::MainPlayer->GetGravityValue());
	}
	if (GravityTimeR > Isaac::MainPlayer->GetTearRange() + 0.1f)
	{
		AnimationRender->ChangeAnimation("Pop");

		MoveDir = float4::Zero;
		if (true == AnimationRender->IsAnimationEnd())
		{
			Death();
		}
	}
	MoveCalculation(_DeltaTime);
	SetMove(MoveDir * Isaac::MainPlayer->GetTearSpeed()* _DeltaTime);
}

void RightTears::MoveCalculation(float _DeltaTime)
{
	float4 NextPos = GetPos() - GetLevel()->GetCameraPos() + MoveDir * _DeltaTime;

	GameEngineImage* ColImage = GameEngineResources::GetInst().ImageFind("BackGround_CS.BMP");
	if (nullptr == ColImage)
	{
		MsgAssert("中宜遂 己 戚耕走亜 蒸柔艦陥.");
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

void RightTears::PlopSounds()
{
	PLOPSOUND = GameEngineResources::GetInst().SoundPlayToControl("Plop.wav");
	PLOPSOUND.Volume(0.2f);
	PLOPSOUND.LoopCount(1);
}

void RightTears::Render(float _DeltaTime)
{
	//Collision->DebugRender();
}
