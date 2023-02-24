#include "CoinNumber.h"

#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineRender.h>

#include "IsaacEnum.h"

#include "Isaac.h"

CoinNumber* CoinNumber::P_CoinNumber = nullptr;

CoinNumber::CoinNumber()
{
}

CoinNumber::~CoinNumber()
{
}

void CoinNumber::Start()
{
	CoinRender = CreateRender("Number_UI.Bmp", IsaacOrder::R_Menu);
	CoinRender->CreateAnimation({ .AnimationName = "Coin_N_Render",  .ImageName = "Number_UI.bmp", .Start = 0, .End = 0 });
	CoinRender->SetPosition({ 20, 160 });
	CoinRender->SetScale({ 50, 50 });
	CoinRender->EffectCameraOff();
	CoinRender->ChangeAnimation("Coin_N_Render");



	N_CoinNumber.SetOwner(this);
	N_CoinNumber.SetImage("Number.Bmp", { 18, 25 }, 5, RGB(0, 255, 255), "Number_UI.bmp");
	N_CoinNumber.SetValue(CoinNumbers);
	N_CoinNumber.SetAlign(Align::Right);
	N_CoinNumber.SetNumOfDigits(2);
	N_CoinNumber.SetRenderPos({ 65, 160 });

}
void CoinNumber::Update(float _DeltaTime)
{
	GetCoinNumberSet();
	NumberSet();
}

void CoinNumber::GetCoinNumberSet()
{
	CoinNumbers = Isaac::MainPlayer->GetCoinCount();
}

void CoinNumber::NumberSet()
{
	N_CoinNumber.SetValue(CoinNumbers);
}



