#include "KeyNumber.h"

#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineRender.h>

#include "IsaacEnum.h"

#include "Isaac.h"

KeyNumber* KeyNumber::P_KeyNumber = nullptr;

KeyNumber::KeyNumber()
{
}

KeyNumber::~KeyNumber()
{
}

void KeyNumber::Start()
{
	KeyRender = CreateRender("Number_UI.Bmp", IsaacOrder::R_Menu);
	KeyRender->CreateAnimation({ .AnimationName = "Key_N_Render",  .ImageName = "Number_UI.bmp", .Start = 1, .End = 1 });
	KeyRender->SetPosition({ 20, 200 });
	KeyRender->SetScale({ 50, 50 });
	KeyRender->EffectCameraOff();
	KeyRender->ChangeAnimation("Key_N_Render");



	N_KeyNumber.SetOwner(this);
	N_KeyNumber.SetImage("Number.Bmp", { 18, 25 }, 5, RGB(0, 255, 255), "Number_UI.bmp");
	N_KeyNumber.SetValue(KeyNumbers);
	N_KeyNumber.SetAlign(Align::Right);
	N_KeyNumber.SetNumOfDigits(2);
	N_KeyNumber.SetRenderPos({ 65, 200 });

}
void KeyNumber::Update(float _DeltaTime)
{
	GetKeyNumberSet();
	NumberSet();
}

void KeyNumber::GetKeyNumberSet()
{
	KeyNumbers = Isaac::MainPlayer->GetKeyCount();
}

void KeyNumber::NumberSet()
{
	N_KeyNumber.SetValue(KeyNumbers);
}



