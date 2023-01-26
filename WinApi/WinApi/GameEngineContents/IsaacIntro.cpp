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

const float IsaacIntro::FirstPaperTime = 7.f;
const float IsaacIntro::PresentsONTime = 1.4f;
const float IsaacIntro::HumanONTime = 1.7f;
const float IsaacIntro::PresentsOFFTime = 3.4f;
const float IsaacIntro::HumanOFFTime = 3.4f;
const float IsaacIntro::MadeONTime = 5.0f;
const float IsaacIntro::MadeOFFTime = 6.5f;

const float IsaacIntro::AllAnimeTime = (FirstPaperTime); //추후애니메이션시간을 더할예정


void IsaacIntro::Loading()
{
	GameEngineDirectory Dir;
	Dir.MoveParentToDirectory("ContentsResources");
	Dir.Move("ContentsResources");
	Dir.Move("Image");
	Dir.Move("Intro");

	// 이미지 로드
	{
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("intro_fullphoto.BMP"))->Cut(5,3); //애니메이션용

		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Intro_BackGround.BMP"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("intro_frontpaper.BMP"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("intro_Gameby.BMP"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Intro_Presents.BMP"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Intro_human.BMP"));
		
	}

	IntroBack* Image=CreateActor<IntroBack>();
	Image->SetReserve(3); //미리 reserve. 차피 추후에 늘리면 되기때문에

	Image->CreateRender("Intro_BackGround.BMP", IntroOrder::BackGround); //배경

	FirstPaper=Image->CreateRender("intro_frontpaper.BMP", IntroOrder::FrontPaper); //인트로전 페이퍼
	FirstPaper->SetScale({900,450});

	Presents=Image->CreateRender("Intro_Presents.BMP", IntroOrder::Trans);//페이퍼이미지1
	Presents->Off();
	Presents->SetScale({450,300});
	Presents->SetPosition(Presents->GetPosition()+float4::Left*150);

	Human=Image->CreateRender("Intro_human.BMP", IntroOrder::Trans);//presents랑같이나오는사진
	Human->Off();
	Human->SetScale({ 600,400 });
	Human->SetPosition(Human->GetPosition() + float4::Right * 150 +float4::Down*30);
	Made = Image->CreateRender("intro_Gameby.BMP", IntroOrder::Trans); //페이퍼 이미지2
	Made->SetScale({ 500,400});
	Made->Off();

	
	GameEngineActor* Photo = CreateActor<IntroPhoto>(); //애니메이션생성
}


void IsaacIntro::Update(float _DeltaTime)
{
	if (true == GameEngineInput::IsAnyKey())
	{
		GameEngineCore::GetInst()->ChangeLevel("IsaacPlay");
	}

	//NowTime = _DeltaTime;
	NowTime += _DeltaTime; //시간을 더해서 넣어줌 
	if (FirstPaperTime < NowTime ) 
	{
		float4 FirstPaperPos = FirstPaper->GetPosition();
		FirstPaperPos += float4::Left * 2.f * NowTime;
		FirstPaper->SetPosition(FirstPaperPos);
		//FirstPaper->Off(); //false로바꿔서 끈다.
	}

	if (PresentsONTime < NowTime) //Present
	{
		Presents->On();
		if (PresentsOFFTime < NowTime)
		{
			Presents->Off();
		}
	}

	if (HumanONTime < NowTime)//Human
	{
		Human->On();
		if (HumanOFFTime < NowTime)
		{
			Human->Off();
		}
	}

	if (MadeONTime < NowTime) //Made
	{
		Made->On();
		if (MadeOFFTime < NowTime) //Made
		{
			Made->Off();
		}
	}
}
