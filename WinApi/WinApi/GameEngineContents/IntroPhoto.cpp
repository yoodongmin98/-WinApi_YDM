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
		.AnimationName="AnimationPhoto",
		.ImageName="intro_fullphoto.BMP",
		.Start = 0,
		.End = 1,
		.InterTime = 0.3f });

	/*float4 ScreenSize = GameEngineWindow::GetScreenSize();
	Rd->SetScale({ ScreenSize.x * 0.12f, ScreenSize.y * 0.18f });
	SetPos({ ScreenSize.x * 0.5f, ScreenSize.y * 0.9f });
	*/
	Rd->ChangeAnimation("AnimationPhoto");





}