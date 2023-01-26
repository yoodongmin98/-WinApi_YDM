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

const float IsaacIntro::FirstPaperTime = 6.5f;
const float IsaacIntro::PresentsONTime = 1.4f;
const float IsaacIntro::PresentsOFFTime = 3.4f;
const float IsaacIntro::HumanONTime = 1.7f;
const float IsaacIntro::HumanOFFTime = 3.4f;
const float IsaacIntro::MadeONTime = 4.5f;
const float IsaacIntro::MadeOFFTime = 6.f;

const float IsaacIntro::AllAnimeTime = (FirstPaperTime); //���ľִϸ��̼ǽð��� ���ҿ���


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
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("intro_Gameby.BMP"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Intro_Presents.BMP"))->Cut(2, 1);
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Intro_human.BMP"))->Cut(5, 1);
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Intro_Millen.BMP"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Intro_Isaac.BMP"));
		//intro
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Intro_1.BMP"))->Cut(2, 1);
		// �̹���ũ�� 512x256(���߿��Լ��θ��������)
	}

	AllBack* Image=CreateActor<AllBack>();
	Image->SetReserve(3); //�̸� reserve. ���� ���Ŀ� �ø��� �Ǳ⶧����

	Image->CreateRender("Intro_BackGround.BMP", IntroOrder::BackGround); //���

	FirstPaper=Image->CreateRender("intro_frontpaper.BMP", IntroOrder::FrontPaper); //��Ʈ�� �� ������
	FirstPaper->SetScale({900,450});

	//�������̹���1
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

	////presents�����̳����»���
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

	Made = Image->CreateRender("intro_Gameby.BMP", IntroOrder::Trans); //������ �̹���2
	Made->SetScale({ 500,400});
	Made->Off();

	//Isaac����
	Isaac=Image->CreateRender("intro_Isaac.BMP", IntroOrder::Trans);
	Isaac->Off();
	Isaac->SetScale({ 300,200 });
	Isaac->SetPosition(Isaac->GetPosition() + float4::Left * 200 + float4::Up * 30);


	//intro�밡�ٽ���

	//�̰� �Լ��� �������ҵ�?
	Intro_1= Image->CreateRender("Intro_1.BMP", IntroOrder::Trans);
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
	Intro_1->ChangeAnimation("Intro1");
	
	
}


void IsaacIntro::Update(float _DeltaTime)
{

	//NowTime = _DeltaTime;
	
	
	NowTime += _DeltaTime; //�ð��� ���ؼ� �־��� 
	if (AllAnimeTime < NowTime) //������ �ִϸ��̼� �ð��� ������ ����title�� �Ѿ
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
		//FirstPaper->Off(); //false�ιٲ㼭 ����.
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
	if (FirstPaperTime+1.f < NowTime)
	{
		Intro_1->On();
		if (FirstPaperTime + 2.5f < NowTime)
		{
			Isaac->On();
		}
	}
}
