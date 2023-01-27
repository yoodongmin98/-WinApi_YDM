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

const float IsaacIntro::AllAnimeTime = 15.f; //추후애니메이션시간을 더할예정


void IsaacIntro::Loading()
{
	GameEngineDirectory Dir;
	Dir.MoveParentToDirectory("ContentsResources");
	Dir.Move("ContentsResources");
	Dir.Move("Image");
	Dir.Move("Intro");

	// 이미지 로드
	{
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Intro_BlackGround.BMP"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Intro_BackGround.BMP"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("intro_frontpaper.BMP"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("intro_Gameby.BMP"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("intro_Nicalis.BMP"))->Cut(2, 1);
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Intro_Presents.BMP"))->Cut(2, 1);
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Intro_human.BMP"))->Cut(5, 1);
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Intro_Millen.BMP"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Intro_Isaac.BMP"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Intro_mother.BMP"));
		////////////////////////intro//////////////////////////
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Intro_1.BMP"))->Cut(2, 1);
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("intro_2.BMP"))->Cut(2, 1);
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("intro_3.BMP"))->Cut(2, 1);
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("intro_4.BMP"))->Cut(2, 1);
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("intro_5.BMP"))->Cut(2, 1);
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("intro_6.BMP"))->Cut(2, 1);
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("intro_7.BMP"))->Cut(2, 1);
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("intro_8.BMP"))->Cut(2, 1);
		// 이미지크기 512x256(나중에함수로만들기위함)
	}

	AllBack* Image=CreateActor<AllBack>();

	Black=Image->CreateRender("Intro_BlackGround.BMP", IntroOrder::BLACKRENDER); //배경전 검은화면
	
	Image->CreateRender("Intro_BackGround.BMP", IntroOrder::BackGround); //배경

	FirstPaper=Image->CreateRender("intro_frontpaper.BMP", IntroOrder::FrontPaper); //인트로 앞 페이퍼
	FirstPaper->SetScale({900,450});

	//presents
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

	//Game by
	Made = Image->CreateRender("intro_Gameby.BMP", IntroOrder::Trans); 
	Made->SetScale({ 500,400});
	Made->Off();

	//Nicalis
	Nicalis = Image->CreateRender("Intro_Nicalis.BMP", IntroOrder::Trans);
	Nicalis->Off();
	Nicalis->SetScale({ 500,300 });
	Nicalis->SetPosition(Nicalis->GetPosition()+float4::Up*70);
	Nicalis->CreateAnimation({
		.AnimationName = "Nicalis",
		.ImageName = "Intro_Nicalis.BMP",
		.Start = 0,
		.End = 1,
		.InterTime = .1f
		});
	Nicalis->ChangeAnimation("Nicalis");

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

	Intro_1 = IntroRender("Intro_1.BMP", "intro1", Intro_1);
	Intro_2 = IntroRender("Intro_2.BMP", "Intro2", Intro_2);
	Intro_3 = IntroRender("Intro_3.BMP", "Intro3", Intro_3);
	Intro_4 = IntroRender("Intro_4.BMP", "Intro4", Intro_4);
	Intro_5 = IntroRender("Intro_5.BMP", "Intro5", Intro_5);
	Intro_6 = IntroRender("Intro_6.BMP", "Intro6", Intro_6);
	Intro_7 = IntroRender("Intro_7.BMP", "Intro7", Intro_7);
	Intro_8 = IntroRender("Intro_8.BMP", "Intro8", Intro_8);
	
	
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
	if (6.5f < NowTime )
	{
		float4 FirstPaperPos = FirstPaper->GetPosition();
		FirstPaperPos += float4::Left * 3.f * NowTime;
		FirstPaper->SetPosition(FirstPaperPos);
	}
	NextintroRenderOff(Black, 0.5f);

	NextintroRenderOn(Presents,1.4f);
	NextintroRenderOff(Presents, 3.4f);

	NextintroRenderOn(Millen, 1.4f);
	NextintroRenderOff(Millen, 3.4f);
	
	NextintroRenderOn(Human, 1.7f);
	NextintroRenderOff(Human, 3.4f);
	
	NextintroRenderOn(Made, 4.5f);
	NextintroRenderOff(Made, 6.0f);

	NextintroRenderOn(Nicalis, 4.5f);
	NextintroRenderOff(Nicalis, 6.0f);
	
	////////////////여기서부터 음악(배경 나레이션)에 따라 시간조정해야하는 부분////////////////////

	NextintroRenderOn(Isaac, 9.0f);
	NextintroRenderOff(Isaac, 12.0f);

	NextintroRenderOn(Mother, 9.5f);
	NextintroRenderOff(Mother, 12.0f);
	
	//////////intro animation//////////
	NextintroRenderOn(Intro_1, 7.5f); 
	NextintroRenderOff(Intro_1, 12.f);
 	NextintroRenderOn(Intro_2, 12.f);
	NextintroRenderOff(Intro_2,16.f);
	NextintroRenderOn(Intro_3, 16.f);
	NextintroRenderOff(Intro_3, 20.f);
	NextintroRenderOn(Intro_4, 20.f);
	NextintroRenderOff(Intro_4, 24.f);
	NextintroRenderOn(Intro_5, 24.f);
	NextintroRenderOff(Intro_5, 28.f);
	NextintroRenderOn(Intro_6, 28.f);
	NextintroRenderOff(Intro_6, 32.f);
	NextintroRenderOn(Intro_7, 32.f);
	NextintroRenderOff(Intro_7, 36.f);
	NextintroRenderOn(Intro_8, 36.f);
	NextintroRenderOff(Intro_8, 40.f);

	
}
