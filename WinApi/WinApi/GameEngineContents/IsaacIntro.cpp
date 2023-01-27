#include "IsaacIntro.h"

#include <GameEngineBase/GameEngineDirectory.h>
#include <GameEngineCore/GameEngineResources.h>
#include <GameEngineCore/GameEngineCore.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include "AllBack.h"
#include <GameEngineCore/GameEngineActor.cpp>
#include "IsaacEnum.h"
#include "IntroPhoto.h"



IsaacIntro::IsaacIntro()
{
}

IsaacIntro::~IsaacIntro()
{
}
const float IsaacIntro::IntrostartTime = 7.5f;

const float IsaacIntro::FirstPaperTime = 6.5f;
const float IsaacIntro::PresentsONTime = 1.4f;
const float IsaacIntro::PresentsOFFTime = 3.4f;
const float IsaacIntro::HumanONTime = 1.7f;
const float IsaacIntro::HumanOFFTime = 3.4f;
const float IsaacIntro::MadeONTime = 4.5f;
const float IsaacIntro::MadeOFFTime = 6.f;

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
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Intro_BackGround.BMP"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("intro_frontpaper.BMP"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("intro_Gameby.BMP"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Intro_Presents.BMP"))->Cut(2, 1);
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Intro_human.BMP"))->Cut(5, 1);
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Intro_Millen.BMP"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Intro_Isaac.BMP"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Intro_mother.BMP"));
		////intro
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Intro_1.BMP"))->Cut(2, 1);
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("intro_2.BMP"))->Cut(5,3);
		// 이미지크기 512x256(나중에함수로만들기위함)
	}

	AllBack* Image=CreateActor<AllBack>();


	Image->CreateRender("Intro_BackGround.BMP", IntroOrder::BackGround); //배경

	FirstPaper=Image->CreateRender("intro_frontpaper.BMP", IntroOrder::FrontPaper); //인트로 앞 페이퍼
	FirstPaper->SetScale({900,450});

	//페이퍼이미지1
	Presents=Image->CreateRender("Intro_Presents.BMP", IntroOrder::Trans);
	Presents->Off();
	Presents->SetScale({200,200});
	Presents->SetPosition(Presents->GetPosition() + float4::Left * 150 + float4::Down * 100);
	Presents->CreateAnimation({
		.AnimationName = "Presents",
		.ImageName = "Intro_Presents.BMP",
		.Start = 0,
		.End = 1,
		.InterTime = .1f
		});
	Presents->ChangeAnimation("Presents");
	//Millen
	Millen=Image->CreateRender("Intro_Millen.BMP", IntroOrder::Trans);
	Millen->Off();
	Millen->SetScale({ 300,250 });
	Millen->SetPosition(Millen->GetPosition() + float4::Left * 120 + float4::Up * 30);

	////presents랑같이나오는사진
	Human=Image->CreateRender("Intro_human.BMP", IntroOrder::Trans);
	Human->Off();
	Human->SetScale({ 600,400 });
	Human->SetPosition(Human->GetPosition() + float4::Right * 150 + float4::Down * 100);
	Human->CreateAnimation({
		.AnimationName = "Human",
		.ImageName = "Intro_human.BMP",
		.Start = 0,
		.End = 1,
		.InterTime = .1f
		});
	Human->ChangeAnimation("Human");

	Made = Image->CreateRender("intro_Gameby.BMP", IntroOrder::Trans); //페이퍼 이미지2
	Made->SetScale({ 500,400});
	Made->Off();

	//Isaac글자
	Isaac=Image->CreateRender("intro_Isaac.BMP", IntroOrder::Trans);
	Isaac->Off();
	Isaac->SetScale({ 300,200 });
	Isaac->SetPosition(Isaac->GetPosition() + float4::Left * 200 + float4::Up * 30);

	//mother글자
	Mother = Image->CreateRender("intro_mother.BMP", IntroOrder::Trans);
	Mother->Off();
	Mother->SetScale({ 300,200 });
	Mother->SetPosition(Mother->GetPosition() + float4::Right * 250 + float4::Up * 130);

	//intro노가다시작

	//이건 함수로 만들어야할듯? ->만듬

	/*Intro_1= Image->CreateRender("Intro_1.BMP", IntroOrder::Trans);
	Intro_1->Off();
	Intro_1->SetScale({ 1000,800 });
	Intro_1->SetPosition(Intro_1->GetPosition() + float4::Down * 200);
	Intro_1->CreateAnimation({
		.AnimationName = "intro1",
		.ImageName = "Intro_1.BMP",
		.Start = 0,
		.End = 1,
		.InterTime = .1f
		});
	Intro_1->ChangeAnimation("Intro1");*/

	Intro_1=IntroRender("Intro_1.BMP", "intro1", Intro_1);
	Intro_2=IntroRender("Intro_2.BMP", "Intro2", Intro_2);
	
	
}


void IsaacIntro::Update(float _DeltaTime)
{

	//NowTime = _DeltaTime;
	
	
	NowTime += _DeltaTime; //시간을 더해서 넣어줌 
	if (AllAnimeTime < NowTime) //지정한 애니메이션 시간이 지나야 다음title로 넘어감
	{
		if (true == GameEngineInput::IsAnyKey())
		{
			GameEngineCore::GetInst()->ChangeLevel("IsaacPlay");
		}
	}


	if (FirstPaperTime < NowTime ) 
	{
		float4 FirstPaperPos = FirstPaper->GetPosition();
		FirstPaperPos += float4::Left * 3.f * NowTime;
		FirstPaper->SetPosition(FirstPaperPos);
		//FirstPaper->Off(); //false로바꿔서 끈다.
	}

	if (PresentsONTime < NowTime) //Present
	{
		Presents->On();
		Millen->On();
		if (PresentsOFFTime < NowTime)
		{
			Presents->Off();
			Millen->Off();
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
	////////////////여기서부터 음악(배경 나레이션)에 따라 시간조정해야하는 부분////////////////////

	if (9.f < NowTime)
	{
		Isaac->On();
	}
	if (13.f < NowTime)
	{
		Isaac->Off();
	}

	if (9.5f < NowTime)
	{
		Mother->On();
	}
	if (13.f < NowTime)
	{
		Mother->Off();
	}
	
	/////intro animation
	
	NextintroRenderOn(Intro_1, 8.f); 
	NextintroRenderOff(Intro_1, 13.f);

 	NextintroRenderOn(Intro_2, 13.f);
	NextintroRenderOff(Intro_2,20.f);
	
}
