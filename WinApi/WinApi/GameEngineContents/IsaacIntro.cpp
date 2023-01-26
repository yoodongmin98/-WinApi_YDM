#include "IsaacIntro.h"

#include <GameEngineBase/GameEngineDirectory.h>
#include <GameEngineCore/GameEngineResources.h>
#include <GameEngineCore/GameEngineCore.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include "IntroBack.h"
#include <GameEngineCore/GameEngineActor.cpp>
#include "IsaacEnum.h"
#include "IntroPhoto.h"


IsaacIntro::IsaacIntro()
{
}

IsaacIntro::~IsaacIntro()
{
}

const float IsaacIntro::FirstPapertime = 5.f;


void IsaacIntro::Loading()
{
	GameEngineDirectory Dir;
	Dir.MoveParentToDirectory("ContentsResources");
	Dir.Move("ContentsResources");
	Dir.Move("Image");
	Dir.Move("Intro");

	// �̹��� �ε�
	{
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Intro_BackGround.BMP"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("intro_frontpaper.BMP"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("intro_fullphoto.BMP"))->Cut(5,3);
		
	}

	IntroBack* Image=CreateActor<IntroBack>();
	Image->SetReserve(8); //�̸� reserve. ���� ���Ŀ� �ø��� �Ǳ⶧����

	Image->CreateRender("Intro_BackGround.BMP", IntroOrder::BackGround);
	FirstPaper=Image->CreateRender("intro_frontpaper.BMP", IntroOrder::FrontPaper);
	FirstPaper->SetScale({1000,500});
	GameEngineActor* Photo = CreateActor<IntroPhoto>();

	
	



	

}


void IsaacIntro::Update(float _DeltaTime)
{
	if (true == GameEngineInput::IsAnyKey())
	{
		GameEngineCore::GetInst()->ChangeLevel("IsaacPlay");
	}

	//NowTime = _DeltaTime;
	NowTime += _DeltaTime; //�ð��� ���ؼ� �־��� 
	if (FirstPapertime < NowTime ) 
	{
		float4 FirstPaperPos = FirstPaper->GetPosition();
		FirstPaperPos += float4::Left * 2.f * NowTime;
		FirstPaper->SetPosition(FirstPaperPos);
		//FirstPaper->Off(); //false�ιٲ㼭 ����.
	}
	
	
}
