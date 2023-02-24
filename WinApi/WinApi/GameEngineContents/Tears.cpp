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



Tears::Tears() 
{
	
}

Tears::~Tears() 
{
	
}
bool TearLoad = true;
void Tears::SoundLoad()
{
	if (true == TearLoad)
	{
		GameEngineDirectory Dir;
		Dir.MoveParentToDirectory("ContentsResources");
		Dir.Move("ContentsResources");
		Dir.Move("Sound");
		{
			GameEngineResources::GetInst().SoundLoad(Dir.GetPlusFileName("tearfire.wav"));
			GameEngineResources::GetInst().SoundLoad(Dir.GetPlusFileName("plop.wav"));
		}

		
	}

}
void Tears::Start()
{
	// ���� ����
	{
		AnimationRender = CreateRender(IsaacOrder::R_Player);
		AnimationRender->SetScale({ 64, 64 });
		AnimationRender->SetPosition({ 0,-20 });
		AnimationRender->CreateAnimation({ .AnimationName = "Base", .ImageName = "Tear.BMP", .Start = 5, .End = 5, .InterTime = 0.1f });
		AnimationRender->CreateAnimation({ .AnimationName = "Pop", .ImageName = "Tear_Pop.BMP", .Start = 0, .End = 15, .InterTime = 0.03f , .Loop = false });
	}
	AnimationRender->ChangeAnimation("Base");

	// Collision ����
	{
		Collision = CreateCollision(IsaacCollisionOrder::C_PlayerAtt);
		Collision->SetScale({ 20, 20 });
		Collision->SetPosition({ 0, -20 });
		Collision->SetDebugRenderType(CollisionType::CT_Rect);
	}
	TEARSOUND = GameEngineResources::GetInst().SoundPlayToControl("tearfire.ogg");
	TEARSOUND.Volume(0.5);
}

void Tears::Update(float _DeltaTime)
{
	
	MoveCalculation(_DeltaTime);
	SetMove(MoveDir * _DeltaTime);
}

void Tears::MoveCalculation(float _DeltaTime)
{
	if (true == GameEngineInput::IsDown("LeftTears"))
	{
		MoveDir = float4::Left * 300;
	}
	float4 NextPos = GetPos() + MoveDir * _DeltaTime;
	
	GameEngineImage* ColImage = GameEngineResources::GetInst().ImageFind("BackGround_CS.BMP");
	if (nullptr == ColImage)
	{
		MsgAssert("�浹�� �� �̹����� �����ϴ�.");
	}
	
	if (RGB(0, 0, 0) == ColImage->GetPixelColor(NextPos, RGB(0, 0, 0)))
	{
		TEARSOUND = GameEngineResources::GetInst().SoundPlayToControl("Plop.wav");
		TEARSOUND.Volume(0.5);
		AnimationRender->ChangeAnimation("Pop");
		MoveDir = float4::Zero;
		if (true == AnimationRender->IsAnimationEnd())
		{
			Death();
		}
	}
}

void Tears::Render(float _DeltaTime)
{
	//Collision->DebugRender();
}