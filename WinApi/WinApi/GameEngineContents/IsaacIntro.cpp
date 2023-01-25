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

const float IsaacIntro::FirstPapertime = 15.f;


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
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("intro_frontpaper.BMP"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("intro_fullphoto.BMP"))->Cut(2,1);
		
	}

	IntroBack* Image=CreateActor<IntroBack>();
	Image->SetReserve(8); //미리 reserve. 차피 추후에 늘리면 되기때문에

	Image->CreateRender("Intro_BackGround.BMP", IntroOrder::BackGround);
	FirstPaper=Image->CreateRender("intro_frontpaper.BMP", IntroOrder::FrontPaper);
	FirstPaper->SetScale({10,20});

	GameEngineActor* Photo = CreateActor<IntroPhoto>();

	
	



	

}


void IsaacIntro::Update(float _DeltaTime)
{
	if (true == GameEngineInput::IsAnyKey())
	{
		GameEngineCore::GetInst()->ChangeLevel("IsaacPlay");
	}

	//NowTime = _DeltaTime;
	NowTime += _DeltaTime; //시간을 더해서 넣어줌 
	if (FirstPaper->IsUpdate() && FirstPapertime < NowTime ) //포인터firstpaper가 살아있고(부모도) 정해진 시간이 경과하면(지정해준시간보다 현재시간이 넘어가면)
	{
		FirstPaper->Off(); //false로바꿔서 끈다.
	}
	
}
