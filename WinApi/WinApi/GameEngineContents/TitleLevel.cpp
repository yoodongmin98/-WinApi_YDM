#include "TitleLevel.h"


#include <GameEngineBase/GameEngineDirectory.h>

#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEnginePlatform/GameEngineWindow.h>


#include <GameEngineCore/GameEngineCore.h>
#include <GameEngineCore/GameEngineResources.h>
#include "TitleChapter.h"




bool Scroll = false;

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
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Title_Cursor.BMP"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Title_Cursor2.BMP"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Title_IsaacFile1.BMP"))->Cut(2, 1);
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Title_IsaacFile2.BMP"))->Cut(2, 1);
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Title_IsaacFile3.BMP"))->Cut(2, 1);
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Title_Select1.BMP"));
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
	{
		//커서
		Cursor = Render->CreateRender("Title_Cursor.BMP", TitleOrder::Logo);
		Cursor->SetScale({ 25,35 });
		Cursor->SetPosition(Chapter3Pos + float4{ -150,-180 });
		Cursor->On();
		Cursor2 = Render->CreateRender("Title_Cursor2.BMP", TitleOrder::Logo);
		Cursor2->SetScale({ 25,35 });
		Cursor2->SetPosition(Chapter3Pos + float4{ -70,200 });
		Cursor2->Off();
	}
	{
		Isaac_File1 = MyTitleRender("Title_IsaacFile1.BMP", "IsaacFile1", Isaac_File1);
		Isaac_File1->SetPosition({-400,670});
		Isaac_File1->On(); //첫번째거는 미리켜놓음
		Isaac_File2 = MyTitleRender("Title_IsaacFile2.BMP", "IsaacFile2", Isaac_File2);
		Isaac_File2->SetPosition({0,670});
		Isaac_File3 = MyTitleRender("Title_IsaacFile3.BMP", "IsaacFile3", Isaac_File3);
		Isaac_File3->SetPosition({400,670});
		
	}
	{
		Isaacselect1 = Render->CreateRender("Title_Select1.BMP", TitleOrder::Logo);
		Isaacselect1->SetScaleToImage();
		Isaacselect1->SetPosition(Chapter4Pos);
		Isaacselect1->On();
	}
	
	if (false == GameEngineInput::IsKey("LevelChange"))
	{
		
		GameEngineInput::CreateKey("TitleScrollRightDown", VK_SPACE);
		GameEngineInput::CreateKey("TitleScrollLeftUp", VK_ESCAPE);
		GameEngineInput::CreateKey("TitleScrollUp", VK_ESCAPE);
		GameEngineInput::CreateKey("TitleScrollDown",VK_SPACE);

		GameEngineInput::CreateKey("Selectup", VK_UP);
		GameEngineInput::CreateKey("Selectdown", VK_DOWN);
		GameEngineInput::CreateKey("Selectleft", VK_LEFT);
		GameEngineInput::CreateKey("Selectright", VK_RIGHT);

	}
}

///////////////////////////////////////UPDATE////////////////////////////////////
bool FirstPaper = true;
bool SecondPaper = false;
bool ThirdPaper = false;
void TitleLevel::Update(float _DeltaTime)
{
	float4 Pos = float4::LerpClamp(TitleStart, TitleEnd, Time);
	SetCameraPos(Pos);
	if (Time >= 1.0f)
	{
		Scroll = false;
		Time = 0.0f;
		TitleStart = Pos;
	}
	if (false == Scroll)
	{
		if (true == GameEngineInput::IsDown("TitleScrollRightDown")&& 100<=CursorPos.y)
		{
			CursorPosSet();
			TitleEnd = TitleStart + float4(GameEngineWindow::GetScreenSize().x, GameEngineWindow::GetScreenSize().y);
			Scroll = true;
		}
		else if (true == GameEngineInput::IsDown("TitleScrollLeftUp")&& Pos.x> ChapterSettingXvalue)
		{
			CursorSet();
			CursorPosSet();
			TitleEnd = TitleStart + float4(-GameEngineWindow::GetScreenSize().x, -GameEngineWindow::GetScreenSize().y);
			Scroll = true;
			CursorPos + Defaultvalue;
		}
		else if (true == GameEngineInput::IsDown("TitleScrollUp") && Pos.x< ChapterSettingXvalue &&Pos.y>100)
		{
			CursorSet();
			CursorPosSet();
			TitleEnd = TitleStart + float4(0.0f, -GameEngineWindow::GetScreenSize().y);
			Scroll = true;
		}
		else if (true == GameEngineInput::IsDown("TitleScrollDown") && Pos.x < ChapterSettingXvalue)
		{
			
			CursorSet();
			CursorPosSet();
			TitleEnd = TitleStart + float4(0.0f, GameEngineWindow::GetScreenSize().y);
			Scroll = true;
		}
	}
	
	if (true == Scroll)
	{
		Time += _DeltaTime*3.0f;
		if (Pos.y > Chapter3MaxYvalue && Pos.x <= 0)
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
	}
	////////////////////////////////////////////////////////////////////////Chapter2 key////////////////
	//Right
	if (true == GameEngineInput::IsDown("Selectright") && Pos.y > Chapter2MinYvalue && Pos.y < Chapter2MaxYvalue && true==FirstPaper)
	{
		Isaac_File1->Off();
		Isaac_File2->On();
		FirstPaper = false;
		SecondPaper = true;
	}
	else if (true == GameEngineInput::IsDown("Selectright") && Pos.y > Chapter2MinYvalue && Pos.y < Chapter2MaxYvalue && true == SecondPaper)
	{
		Isaac_File2->Off();
		Isaac_File3->On();
		SecondPaper = false;
		ThirdPaper = true;
	}
	//Left
	if (true == GameEngineInput::IsDown("Selectleft") && Pos.y > Chapter2MinYvalue && Pos.y < Chapter2MaxYvalue && true == SecondPaper)
	{
		Isaac_File1->On();
		Isaac_File2->Off();
		FirstPaper = true;
		SecondPaper = false;	
	}
	else if (true == GameEngineInput::IsDown("Selectleft") && Pos.y > Chapter2MinYvalue && Pos.y < Chapter2MaxYvalue && true==ThirdPaper)
	{
		Isaac_File2->On();
		Isaac_File3->Off();
		SecondPaper = true;
		ThirdPaper = false;
	}
	////////////////////////////////////////////////////////////////////////Chapter3 key////////////////
	if (true == GameEngineInput::IsDown("Selectup")&&Pos.y> Chapter2MaxYvalue && Pos.y < Chapter3MaxYvalue)
	{
		CursorPosSet();
		Cursor->On();
		Cursor2->Off();
		
	}
 	if (true == GameEngineInput::IsDown("Selectdown") && Pos.y > Chapter2MaxYvalue &&Pos.y< Chapter3MaxYvalue)
	{
		CursorPosSet();
		Cursor->Off();
		Cursor2->On();
		CursorPos = CursorPos + Defaultvalue;
	}
	////////////////////////////////////////////////////////////////////////Chapter4 key////////////////



	
}
///////////////////////Cursor Function
void TitleLevel::CursorSet()
{
	Cursor->On();
	Cursor2->Off();
}
float4 TitleLevel::CursorPosSet()
{
	CursorPos = float4::Zero;
	return CursorPos;
}