#include "IsaacIntro.h"

#include <GameEngineBase/GameEngineDirectory.h>
#include <GameEngineCore/GameEngineResources.h>
#include <GameEngineCore/GameEngineCore.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include "IntroBack.h"
#include <GameEngineCore/GameEngineActor.cpp>
#include "IsaacEnum.h"


IsaacIntro::IsaacIntro()
{
}

IsaacIntro::~IsaacIntro()
{
}


void IsaacIntro::Loading()
{
	GameEngineDirectory Dir;
	Dir.MoveParentToDirectory("ContentsResources");
	Dir.Move("ContentsResources");
	Dir.Move("Image");
	Dir.Move("Intro");

	// 이미지 로드
	{
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Intro_BackGround.BMP"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Intro_FrontPaper.BMP"));
	}

	IntroBack* Image=CreateActor<IntroBack>();
	Image->SetReserve(5); //미리 reserve

	Image->CreateRender("Intro_BackGround.BMP", IntroOrder::BackGround);
	//Image->CreateRender("Intro_FrontPaper.BMP", IntroOrder::FrontPaper);




	

}
void IsaacIntro::Update(float _DeltaTime)
{
	if (true == GameEngineInput::IsAnyKey())
	{
		GameEngineCore::GetInst()->ChangeLevel("IsaacPlay");
	}
}
