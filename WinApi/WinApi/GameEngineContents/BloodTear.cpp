#include "BloodTear.h"
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



BloodTear::BloodTear()
{

}

BloodTear::~BloodTear()
{

}

bool BloodTearLoad = true;
void BloodTear::ImageLoad()
{
	GameEngineDirectory Dir;
	Dir.MoveParentToDirectory("ContentsResources");
	Dir.Move("ContentsResources");
	Dir.Move("Image");
	Dir.Move("Play");
	Dir.Move("Monster");

	GameEngineImage* BloodTear = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("M_BloodTear.BMP"));
	BloodTear->Cut(4, 4);
}

void BloodTear::Start()
{
	if (true == BloodTearLoad)
	{
		ImageLoad();
		BloodTearLoad = false;
	}
	// 렌더 생성
	{
		BloodTearRender = CreateRender(IsaacOrder::R_Player);
		BloodTearRender->SetScale({ 90, 90 });
		BloodTearRender->CreateAnimation({ .AnimationName = "Base", .ImageName = "M_BloodTear.BMP", .Start = 0, .End = 0, .InterTime = 0.1f });
		BloodTearRender->CreateAnimation({ .AnimationName = "Pop", .ImageName = "M_BloodTear.BMP", .Start = 1, .End = 15, .InterTime = 0.03f , .Loop = false });
	}
	BloodTearRender->ChangeAnimation("Base");

	// Collision 생성
	{
		BloodTearCollision = CreateCollision(IsaacCollisionOrder::C_Monster);
		BloodTearCollision->SetScale({ 20, 20 });
		BloodTearCollision->SetDebugRenderType(CollisionType::CT_Rect);
	}

}

void BloodTear::Update(float _DeltaTime)
{
	TearRangeTime += _DeltaTime;
	if (TearRangeTime > 2.0f)
	{
		BloodTearRender->ChangeAnimation("Pop");

		MoveDir = float4::Zero;
		if (true == BloodTearRender->IsAnimationEnd())
		{
			Death();
		}
	}
	MoveCalculation(_DeltaTime);
	SetMove(MoveDir * 300.0f * _DeltaTime);
}

void BloodTear::MoveCalculation(float _DeltaTime)
{
	float4 NextPos = GetPos() + MoveDir * _DeltaTime;

	GameEngineImage* ColImage = GameEngineResources::GetInst().ImageFind("BackGround_CS.BMP");
	if (nullptr == ColImage)
	{
		MsgAssert("충돌용 맵 이미지가 없습니다.");
	}

	if (RGB(0, 0, 0) == ColImage->GetPixelColor(NextPos, RGB(0, 0, 0)))
	{
		BloodTearRender->ChangeAnimation("Pop");

		MoveDir = float4::Zero;
		if (true == BloodTearRender->IsAnimationEnd())
		{
			Death();
		}
	}
}

void BloodTear::Render(float _DeltaTime)
{
	//Collision->DebugRender();
}
