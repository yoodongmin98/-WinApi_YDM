#include "HP.h"

#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineRender.h>

#include "IsaacEnum.h"

#include "Isaac.h"

HP::HP()
{
}

HP::~HP()
{
}

void HP::Start()
{
	HpRender1 = CreateRender("Hp.Bmp", IsaacOrder::R_Menu);
	HpRender1->CreateAnimation({ .AnimationName = "Hp0",  .ImageName = "Hp.bmp", .Start = 2, .End = 2 });
	HpRender1->CreateAnimation({ .AnimationName = "Hp1",  .ImageName = "Hp.bmp", .Start = 1, .End = 1 });
	HpRender1->CreateAnimation({ .AnimationName = "Hp2",  .ImageName = "Hp.bmp", .Start = 0, .End = 0 });
	HpRender1->SetPosition({ 140, 40 });
	HpRender1->SetScale({ 50, 50 });
	HpRender1->EffectCameraOff();
	HpRender1->ChangeAnimation("Hp2");

	HpRender2 = CreateRender("Hp.Bmp", IsaacOrder::R_Menu);
	HpRender2->CreateAnimation({ .AnimationName = "Hp0",  .ImageName = "Hp.bmp", .Start = 2, .End = 2 });
	HpRender2->CreateAnimation({ .AnimationName = "Hp1",  .ImageName = "Hp.bmp", .Start = 1, .End = 1 });
	HpRender2->CreateAnimation({ .AnimationName = "Hp2",  .ImageName = "Hp.bmp", .Start = 0, .End = 0 });
	HpRender2->SetPosition({ 190, 40 });
	HpRender2->SetScale({ 50, 50 });
	HpRender2->EffectCameraOff();
	HpRender2->ChangeAnimation("Hp2");

	HpRender3 = CreateRender("Hp.Bmp", IsaacOrder::R_Menu);
	HpRender3->CreateAnimation({ .AnimationName = "Hp0",  .ImageName = "Hp.bmp", .Start = 2, .End = 2 });
	HpRender3->CreateAnimation({ .AnimationName = "Hp1",  .ImageName = "Hp.bmp", .Start = 1, .End = 1 });
	HpRender3->CreateAnimation({ .AnimationName = "Hp2",  .ImageName = "Hp.bmp", .Start = 0, .End = 0 });
	HpRender3->SetPosition({ 240, 40 });
	HpRender3->SetScale({ 50, 50 });
	HpRender3->EffectCameraOff();
	HpRender3->ChangeAnimation("Hp2");
}
void HP::Update(float _DeltaTime)
{
	GetandSetIsaacHP();
	
	HpSet(IsaacHP);
}

void HP::GetandSetIsaacHP()
{
	IsaacHP = Isaac::MainPlayer->GetPlayerHP();
}

void HP::HpSet(int _PlayerHP)
{
	if (6 == _PlayerHP)
	{
		HpRender1->ChangeAnimation("Hp2");
		HpRender2->ChangeAnimation("Hp2");
		HpRender3->ChangeAnimation("Hp2");
	}
	else if (5 == _PlayerHP)
	{
		HpRender1->ChangeAnimation("Hp2");
		HpRender2->ChangeAnimation("Hp2");
		HpRender3->ChangeAnimation("Hp1");
	}
	else if (4 == _PlayerHP)
	{
		HpRender1->ChangeAnimation("Hp2");
		HpRender2->ChangeAnimation("Hp2");
		HpRender3->ChangeAnimation("Hp0");
	}
	else if (3 == _PlayerHP)
	{
		HpRender1->ChangeAnimation("Hp2");
		HpRender2->ChangeAnimation("Hp1");
		HpRender3->ChangeAnimation("Hp0");
	}
	else if (2 == _PlayerHP)
	{
		HpRender1->ChangeAnimation("Hp2");
		HpRender2->ChangeAnimation("Hp0");
		HpRender3->ChangeAnimation("Hp0");
	}
	else if (1 == _PlayerHP)
	{
		HpRender1->ChangeAnimation("Hp1");
		HpRender2->ChangeAnimation("Hp0");
		HpRender3->ChangeAnimation("Hp0");
	}
	else if (0 == _PlayerHP)
	{
		HpRender1->ChangeAnimation("Hp0");
		HpRender2->ChangeAnimation("Hp0");
		HpRender3->ChangeAnimation("Hp0");
	}
}



