#include "IntroPhoto.h"
#include <GameEngineBase/GameEngineTime.h>
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
	GameEngineRender* Rd = CreateRender("intro_fullphoto.BMP", IntroOrder::Anime);
	Rd->CreateAnimation({
		.AnimationName="Anime",
		.ImageName="intro_fullphoto.BMP",
		.Start = 0,
		.End = 13,
		.InterTime = .2f });
	
	float4 ScreenSize = GameEngineWindow::GetScreenSize();
	Rd->SetScale({ ScreenSize.x * .4f, ScreenSize.y * .6f });
	SetPos({ ScreenSize.x * .5f, ScreenSize.y * 0.5f });
	
	Rd->ChangeAnimation("Anime");

	

	

}

void IntroPhoto::Update(float _deltatime)
{
	



}