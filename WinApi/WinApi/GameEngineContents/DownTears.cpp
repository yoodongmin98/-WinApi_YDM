#include "DownTears.h"
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEnginePlatform/GameEngineImage.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineRender.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCollision.h>
#include <GameEngineCore/GameEngineResources.h>

#include "IsaacEnum.h"

int DownTears::TearNumber = 0;

DownTears::DownTears()
{
	DownTears::TearNumber++;
}

DownTears::~DownTears()
{
	DownTears::TearNumber--;
}

void DownTears::Start()
{
	// ���� ����
	{
		AnimationRender = CreateRender(IsaacOrder::R_Player);
		AnimationRender->SetScale({ 64, 64 });
		AnimationRender->SetPosition({ 0,-20 });
		AnimationRender->CreateAnimation({ .AnimationName = "Base", .ImageName = "Tear.BMP", .Start = 5, .End = 5, .InterTime = 0.1f });
	}
	AnimationRender->ChangeAnimation("Base");

	// Collision ����
	{
		Collision = CreateCollision(IsaacCollisionOrder::C_PlayerAtt);
		Collision->SetScale({ 8, 8 });
		Collision->SetPosition({ 0, 0 });
		Collision->SetDebugRenderType(CollisionType::CT_Rect);
	}
}

void DownTears::Update(float _DeltaTime)
{
	//���Ϳ� ��ҳ�? ���Ϳ� ��ҳ�? ���Ϳ� ��ҳ�? ���Ϳ� ��ҳ�? 
	std::vector<GameEngineCollision*> C_Tear;
	CollisionCheckParameter Check = { .TargetGroup = static_cast<int>(IsaacCollisionOrder::C_Monster), .TargetColType = CT_Rect, .ThisColType = CT_Rect };
	if (true == Collision->Collision(Check, C_Tear))
	{
		C_Tear[0]->GetActor()->Death();
		Death();
	}
	MoveCalculation(_DeltaTime);
	//Render(_DeltaTime);
}

void DownTears::MoveCalculation(float _DeltaTime)
{
	if (true == GameEngineInput::IsDown("DownTears"))
	{
		MoveDir = float4::Down * 300;
	}
	// �̹� �����ӿ� �̵��� ��ġ
	float4 NextPos = GetPos() + MoveDir * _DeltaTime;
	//�浹üũ
	GameEngineImage* ColImage = GameEngineResources::GetInst().ImageFind("BackGround_CS.BMP");
	if (nullptr == ColImage)
	{
		MsgAssert("�浹�� �� �̹����� �����ϴ�.");
	}
	//// �� üũ
	if (RGB(0, 0, 0) == ColImage->GetPixelColor(NextPos, RGB(0, 0, 0)))
	{
		Death();
	}
	SetMove(MoveDir * _DeltaTime);
}

void DownTears::Render(float _DeltaTime)
{
	//Collision->DebugRender();
}
