#include "TitleLevel.h"
#include "AllBack.h"

#include <GameEngineBase/GameEngineDirectory.h>

#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEnginePlatform/GameEngineWindow.h>


#include <GameEngineCore/GameEngineCore.h>
#include <GameEngineCore/GameEngineResources.h>





TitleLevel::TitleLevel()
{

}
TitleLevel::~TitleLevel()
{

}



void TitleLevel::Loading()
{
	GameEngineDirectory Dir;
	Dir.MoveParentToDirectory("ContentsResources");
	Dir.Move("ContentsResources");
	Dir.Move("Image");
	Dir.Move("Title");

	//�̹����ε�
	{
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Title_BackGround.BMP"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Title_TitleLogo.BMP"))->Cut(4, 4);
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Title_Isaac.BMP"))->Cut(2, 1);
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Title_Start.BMP"))->Cut(2, 1);
	}

	AllBack* Render = CreateActor<AllBack>();
	Render->CreateRender("Title_BackGround.BMP", TitleOrder::BackGround); //���
	{
		Logo = Render->CreateRender("Title_TitleLogo.BMP", TitleOrder::Logo);//�ΰ�
		Logo->SetScale({ 1500,1200 });
		Logo->SetPosition(Logo->GetPosition() + float4::Up * 200);
		Logo->CreateAnimation({
			.AnimationName = "Logo",
			.ImageName = "Title_TitleLogo.BMP",
			.Start = 0,
			.End = 15,
			.InterTime = .1f
			});
		Logo->ChangeAnimation("Logo");
	}
	{
		Isaac = Render->CreateRender("Title_Isaac.BMP", TitleOrder::Logo);//������
		Isaac->SetScale({800,800});
		Isaac->SetPosition(Isaac->GetPosition() + float4::Down * 50);
		Isaac->CreateAnimation({
			.AnimationName = "Isaac",
			.ImageName = "Title_Isaac.BMP",
			.Start = 0,
			.End = 1,
			.InterTime = .1f
			});
		Isaac->ChangeAnimation("Isaac");

		Start= Render->CreateRender("Title_Start.BMP", TitleOrder::Logo);
		Start->SetScale({ 820,460 });
		Start->SetPosition(Start->GetPosition() + float4::Down * 220);
		Start->CreateAnimation({
			.AnimationName = "Start",
			.ImageName = "Title_Start.BMP",
			.Start = 0,
			.End = 1,
			.InterTime = .1f
			});
		Start->ChangeAnimation("Start");
	}



	
}
void TitleLevel::Update(float _DeltaTime)
{
	float4 ScreenSize = GameEngineWindow::GetScreenSize();
	float4 Screenmove = float4::Zero;
	


	/*if (false == GameEngineInput::IsKey("NextScreen"))
	{
		GameEngineInput::CreateKey("NextScreen", 'R');
	}
	if (true == GameEngineInput::IsDown("NextScreen"))
	{
		SetMove(float4::Left * MoveSpeed * _Time);
		GetLevel()->SetCameraMove(float4::Left * _Time * MoveSpeed);
	}*/




	if (false == GameEngineInput::IsKey("NextLevel"))
	{
		GameEngineInput::CreateKey("NextLevel",VK_SPACE);
	}
	if (true == GameEngineInput::IsDown("NextLevel"))
	{
		GameEngineCore::GetInst()->ChangeLevel("Loading");
	}
	

	

}
