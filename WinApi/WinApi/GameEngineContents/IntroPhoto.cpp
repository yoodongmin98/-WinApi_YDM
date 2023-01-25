#include "IntroPhoto.h"
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineRender.h>
#include "IsaacIntro.h"

IntroPhoto::IntroPhoto()
{

}
IntroPhoto::~IntroPhoto()
{

}

void IntroPhoto::Start()
{
	GameEngineRender* Rd = CreateRender("intro_fullphoto.BMP", IntroOrder::Photo1);
	Rd->CreateAnimation({
		.AnimationName="Photo",
		.ImageName="intro_fullphoto.BMP",
		.Start = 0,
		.End = 1,
		.InterTime = 0.3f });

	float4 ScreenSize = GameEngineWindow::GetScreenSize();
	Rd->SetScale({ ScreenSize.x * .4f, ScreenSize.y * .6f });
	SetPos({ ScreenSize.x * .5f, ScreenSize.y * 0.5f });
	
	Rd->ChangeAnimation("Photo");





}