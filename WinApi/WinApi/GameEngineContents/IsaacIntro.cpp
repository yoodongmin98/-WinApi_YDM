#include "IsaacIntro.h"

#include <GameEngineBase/GameEngineDirectory.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineResources.h>
#include <GameEngineCore/GameEngineCore.h>
#include <GameEngineCore/GameEngineActor.cpp>
#include <GameEnginePlatform/GameEngineSound.h>


#include "AllBack.h"
#include "IsaacEnum.h"




IsaacIntro::IsaacIntro()
{
}

IsaacIntro::~IsaacIntro()
{
}

const float IsaacIntro::AllAnimeTime = 75.f; //추후애니메이션시간을 더할예정
//void  IsaacIntro::SoundLoad()
//{
//	GameEngineDirectory Dir;
//	Dir.MoveParentToDirectory("ContentsResources");
//	Dir.Move("ContentsResources");
//	Dir.Move("Sound");
//	{
//		GameEngineResources::GetInst().SoundLoad(Dir.GetPlusFileName("introvoiceover.ogg"));
//		
//	}
//	
//	INTROBGMPLAYER=GameEngineResources::GetInst().SoundPlayToControl("introvoiceover.ogg");
//	INTROBGMPLAYER.Volume(0.5);
//	
//}


void IsaacIntro::Loading()
{
	//SoundLoad();
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
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Intro_Door.BMP"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Intro_Door2.BMP"));

		/////////////////////////////////////////intro////////////////////////////

		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Intro_1.BMP"))->Cut(2, 1);
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("intro_2.BMP"))->Cut(2, 1);
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("intro_3.BMP"))->Cut(2, 1);
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("intro_4.BMP"))->Cut(2, 1);
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("intro_5.BMP"))->Cut(2, 1);
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("intro_6.BMP"))->Cut(2, 1);
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("intro_7.BMP"))->Cut(2, 1);
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("intro_8.BMP"))->Cut(2, 1);
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("intro_9.BMP"))->Cut(2, 1);
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("intro_10.BMP"))->Cut(2, 1);
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("intro_11.BMP"))->Cut(5, 5);
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("intro_12.BMP"))->Cut(2, 1);
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("intro_13.BMP"))->Cut(2, 1);
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("intro_14.BMP"))->Cut(3, 2);
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("intro_15.BMP"))->Cut(2, 1);
		// 이미지크기 512x256(나중에함수로만들기위함)
	}

	AllBack* Image=CreateActor<AllBack>();

	//배경전 검은화면
	Black=Image->CreateRender("Intro_BlackGround.BMP", IntroOrder::BeforeRender); 

	//배경
	Image->CreateRender("Intro_BackGround.BMP", IntroOrder::BackGround); 

	//인트로 앞 페이퍼
	FirstPaper=Image->CreateRender("intro_frontpaper.BMP", IntroOrder::FrontPaper); 
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
	//intro Door
	Door1 = Image->CreateRender("intro_Door.BMP", IntroOrder::Trans);
	Door1->Off();
	Door1->SetScale({ 850,700 });
	Door2 = Image->CreateRender("intro_Door2.BMP", IntroOrder::Trans);
	Door2->Off();
	Door2->SetScale({ 850,700 });
	///////////////////////////intro노가다시작

	Intro_1 = MyIntroRender("Intro_1.BMP", "intro1", Intro_1);
	Intro_2 = MyIntroRender("Intro_2.BMP", "Intro2", Intro_2);
	Intro_3 = MyIntroRender("Intro_3.BMP", "Intro3", Intro_3);
	Intro_4 = MyIntroRender("Intro_4.BMP", "Intro4", Intro_4);
	Intro_5 = MyIntroRender("Intro_5.BMP", "Intro5", Intro_5);
	Intro_6 = MyIntroRender("Intro_6.BMP", "Intro6", Intro_6);
	Intro_7 = MyIntroRender("Intro_7.BMP", "Intro7", Intro_7);
	Intro_8 = MyIntroRender("Intro_8.BMP", "Intro8", Intro_8);
	Intro_9 = MyIntroRender("Intro_9.BMP", "Intro9", Intro_9);
	Intro_10 = MyIntroRender("Intro_10.BMP", "Intro10", Intro_10);
	Intro_11= Image->CreateRender("Intro_11.BMP", IntroOrder::Trans);
	Intro_11->Off();
	Intro_11->SetScale({ 850,700 });
	Intro_11->CreateAnimation({
		.AnimationName = "Intro11",
		.ImageName = "Intro_11.BMP",
		.Start = 0,
		.End = 21,
		.InterTime = .1f, 
		});
	Intro_11->ChangeAnimation("Intro11");
	Intro_12 = MyIntroRender("Intro_12.BMP", "Intro12", Intro_12);
	Intro_13 = MyIntroRender("Intro_13.BMP", "Intro13", Intro_13);
	Intro_14 = Image->CreateRender("Intro_14.BMP", IntroOrder::Trans);
	Intro_14->Off();
	Intro_14->SetScale({ 850,700 });
	Intro_14->CreateAnimation({
		.AnimationName = "Intro14",
		.ImageName = "Intro_14.BMP",
		.Start = 0,
		.End = 5,
		.InterTime = 0.03f
		});
	Intro_14->ChangeAnimation("Intro14");
	Intro_15 = MyIntroRender("Intro_15.BMP", "Intro15", Intro_15);
	
}


void IsaacIntro::Update(float _DeltaTime)
{
	NowTime += _DeltaTime; //시간을 더해서 넣어줌

	//지정한 애니메이션 시간이 지나야 다음title로 넘어감
	//또는 스페이스바를 눌렀을때
	
	if (false == GameEngineInput::IsKey("NextLevel"))
	{
		GameEngineInput::CreateKey("NextLevel", VK_SPACE);
	}
	if (AllAnimeTime <NowTime || true == GameEngineInput::IsDown("NextLevel"))
	{ 
		GameEngineCore::GetInst()->ChangeLevel("TitleLevel");
		//INTROBGMPLAYER.Stop();
		

	}

	
	if (6.0f < NowTime )
	{
		float4 FirstPaperPos = FirstPaper->GetPosition();
		FirstPaperPos += float4::Left * 3.f * NowTime;
		FirstPaper->SetPosition(FirstPaperPos);
	}
	NextintroRenderOff(Black, 0.8f);

	NextintroRenderOn(Presents,1.4f);
	NextintroRenderOff(Presents, 3.4f);

	NextintroRenderOn(Millen, 1.4f);
	NextintroRenderOff(Millen, 3.4f);
	
	NextintroRenderOn(Human, 1.7f);
	NextintroRenderOff(Human, 3.4f);
	
	NextintroRenderOn(Made, 4.5f);
	NextintroRenderOff(Made, 5.5f);

	NextintroRenderOn(Nicalis, 4.5f);
	NextintroRenderOff(Nicalis, 5.5f);
	
	////////////////여기서부터 음악(배경 나레이션)에 따라 시간조정해야하는 부분////////////////////

	NextintroRenderOn(Isaac, 7.5f);
	NextintroRenderOff(Isaac, 10.f);

	NextintroRenderOn(Mother, 8.0f);
	NextintroRenderOff(Mother, 10.f);
	 
	////////intro animation//////////
	NextintroRenderOn(Intro_1, 6.5f); //Isaac mom
	NextintroRenderOff(Intro_1, 10.f);

 	NextintroRenderOn(Intro_2, 10.f);//house
	NextintroRenderOff(Intro_2,13.f);

	NextintroRenderOn(Intro_3, 13.f);//little isaac
	NextintroRenderOff(Intro_3, 18.f);

	NextintroRenderOn(Intro_4, 18.f);//tv mom
	NextintroRenderOff(Intro_4, 22.f);

	NextintroRenderOn(Intro_5, 22.f);//isaac mom
	NextintroRenderOff(Intro_5, 31.f);

	NextintroRenderOn(Intro_6, 31.f);//voice stop
	NextintroRenderOff(Intro_6, 33.f);

	NextintroRenderOn(Intro_7, 33.f);//voice
	NextintroRenderOff(Intro_7, 40.f);
	 
	NextintroRenderOn(Intro_8, 40.f);//answer
	NextintroRenderOff(Intro_8, 43.f);

	NextintroRenderOn(Intro_9, 43.f);// alone Isaac
	NextintroRenderOff(Intro_9, 45.f);

	NextintroRenderOn(Intro_10, 45.f);
	NextintroRenderOff(Intro_10, 47.f);	

	NextintroRenderOn(Intro_11, 47.0f);  //intro11=3.3animation time      
	NextintroRenderOff(Intro_11, 49.1f);

	NextintroRenderOn(Intro_12, 49.1f);
	NextintroRenderOff(Intro_12, 50.0f);

	NextintroRenderOn(Intro_13, 50.0f);
	NextintroRenderOff(Intro_13, 53.5f);


	NextintroRenderOn(Intro_7, 53.5f);
	NextintroRenderOff(Intro_7, 63.0f);
	NextintroRenderOn(Intro_8, 63.0f);
	NextintroRenderOff(Intro_8, 68.0f);

	NextintroRenderOn(Door1, 68.0f);
	NextintroRenderOff(Door1, 69.f);
	NextintroRenderOn(Intro_14, 69.0f);
	NextintroRenderOff(Intro_14, 69.18f);
	NextintroRenderOn(Door2, 69.18f);
	NextintroRenderOff(Door2, 71.0f);
	NextintroRenderOn(Intro_15, 71.0f);
	NextintroRenderOff(Intro_15, 76.0f);

	
}
