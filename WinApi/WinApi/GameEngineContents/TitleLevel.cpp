#include "TitleLevel.h"
#include "AllBack.h"

#include <GameEngineBase/GameEngineDirectory.h>

#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEnginePlatform/GameEngineWindow.h>


#include <GameEngineCore/GameEngineCore.h>
#include <GameEngineCore/GameEngineResources.h>
#include "TitleChapter.h"





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

	//이미지로드
	{
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Title_BackGround.BMP"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Title_TitleLogo.BMP"))->Cut(4, 4);
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Title_Isaac.BMP"))->Cut(2, 1);
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Title_Start.BMP"))->Cut(2, 1);
	}

	TitleChapter* BackGround = CreateActor<TitleChapter>();

	AllBack* Render = CreateActor<AllBack>();
	{
		Logo = Render->CreateRender("Title_TitleLogo.BMP", TitleOrder::Logo);//로고
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
		Isaac = Render->CreateRender("Title_Isaac.BMP", TitleOrder::Logo);//아이작
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


	if (false == GameEngineInput::IsKey("LevelChange"))
	{
		
		GameEngineInput::CreateKey("TitleScrollRightDown", 'E');
		GameEngineInput::CreateKey("TitleScrollLeftUp", 'Q');
		GameEngineInput::CreateKey("TitleScrollUp", VK_ESCAPE);
		GameEngineInput::CreateKey("TitleScrollDown",VK_SPACE);
	}
	
}

bool Scroll = false;
void TitleLevel::Update(float _DeltaTime)
{
	
	if (false == Scroll)
	{
		if (true == GameEngineInput::IsDown("TitleScrollRightDown"))
		{
			TitleEnd = TitleStart + float4(GameEngineWindow::GetScreenSize().x, GameEngineWindow::GetScreenSize().y);
			Scroll = true;
		}
		else if (true == GameEngineInput::IsDown("TitleScrollLeftUp"))
		{
			TitleEnd = TitleStart + float4(-GameEngineWindow::GetScreenSize().x, -GameEngineWindow::GetScreenSize().y);
			Scroll = true;
		}
		else if (true == GameEngineInput::IsDown("TitleScrollUp"))
		{
			TitleEnd = TitleStart + float4(0.0f, -GameEngineWindow::GetScreenSize().y);
			Scroll = true;
		}
		else if (true == GameEngineInput::IsDown("TitleScrollDown"))
		{
			TitleEnd = TitleStart + float4(0.0f, GameEngineWindow::GetScreenSize().y);
			Scroll = true;
		}
	}


	if (true == Scroll)
	{
		// 시작에서 끝까지 이동하는데 1초가 걸리는 함수
		Time += _DeltaTime*3.0f;
		float4 Pos = float4::LerpClamp(TitleStart, TitleEnd, Time);
		if (Pos.y<0)
		{
			Scroll = false;
		}
		if (Pos.y > 2160)
		{
			if (false == GameEngineInput::IsKey("NextLevel"))
			{
				GameEngineInput::CreateKey("NextLevel", VK_SPACE);
			}
			if (true == GameEngineInput::IsDown("NextLevel"))
			{
				GameEngineCore::GetInst()->ChangeLevel("Loading");
			}
		}
		//if()
		SetCameraPos(Pos);
		if (Time >= 1.0f)
		{
			Scroll = false;
			Time = 0.0f;
			TitleStart = Pos;
		}
		
	}
	

}
