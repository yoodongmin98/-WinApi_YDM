#include "BombNumber.h"

#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineRender.h>

#include "IsaacEnum.h"

#include "Isaac.h"

BombNumber* BombNumber::P_BombNumber = nullptr;

BombNumber::BombNumber()
{
}

BombNumber::~BombNumber()
{
}

void BombNumber::Start()
{
	BombRender = CreateRender("Number_UI.Bmp", IsaacOrder::R_Menu);
	BombRender->CreateAnimation({ .AnimationName = "Bomb_N_Render",  .ImageName = "Number_UI.bmp", .Start = 3, .End = 3 });
	BombRender->SetPosition({ 20, 240 });
	BombRender->SetScale({ 50, 50 });
	BombRender->EffectCameraOff();
	BombRender->ChangeAnimation("Bomb_N_Render");

	N_BombNumber.SetOwner(this);
	N_BombNumber.SetImage("Number.Bmp", { 18, 25 }, 5, RGB(0, 255, 255), "Number_UI.bmp");
	N_BombNumber.SetValue(BombNumbers);
	N_BombNumber.SetAlign(Align::Right);
	N_BombNumber.SetNumOfDigits(2);
	N_BombNumber.SetRenderPos({ 65, 240 });

}
void BombNumber::Update(float _DeltaTime)
{
	GetBombNumberSet();
	NumberSet();
}

void BombNumber::GetBombNumberSet()
{
	BombNumbers = Isaac::MainPlayer->GetBombCount();
}

void BombNumber::NumberSet()
{
	N_BombNumber.SetValue(BombNumbers);
}



