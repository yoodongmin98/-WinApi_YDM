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
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Title_Select2.BMP"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Title_Select3.BMP"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Title_Select4.BMP"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Title_Setting0.BMP"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Title_Setting1.BMP"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Title_Setting2.BMP"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Title_Setting3.BMP"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Title_Setting4.BMP"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Title_Setting5.BMP"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Title_Setting6.BMP"));

	}

	CreateActor<TitleChapter>();

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
			.InterTime = .15f
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
		Isaacselect2 = Render->CreateRender("Title_Select2.BMP", TitleOrder::Logo);
		Isaacselect2->SetScaleToImage();
		Isaacselect2->SetPosition(Chapter4Pos);
		Isaacselect2->Off();
		Isaacselect3 = Render->CreateRender("Title_Select3.BMP", TitleOrder::Logo);
		Isaacselect3->SetScaleToImage();
		Isaacselect3->SetPosition(Chapter4Pos);
		Isaacselect3->Off();
		Isaacselect4 = Render->CreateRender("Title_Select4.BMP", TitleOrder::Logo);
		Isaacselect4->SetScaleToImage();
		Isaacselect4->SetPosition(Chapter4Pos);
		Isaacselect4->Off();
	}
	{
		IsaacSetting0 = Render->CreateRender("Title_Setting0.BMP", TitleOrder::Logo);
		IsaacSetting0->SetScale({150,40});
		IsaacSetting0->SetPosition(Chapter4SPos+float4::Up*140);
		IsaacSetting0->On();
		IsaacSetting1 = Render->CreateRender("Title_Setting1.BMP", TitleOrder::Logo);
		IsaacSetting1->SetScale({ 150,40 });
		IsaacSetting1->SetPosition(Chapter4SPos + float4::Up * 140);
		IsaacSetting1->Off();
		IsaacSetting2 = Render->CreateRender("Title_Setting2.BMP", TitleOrder::Logo);
		IsaacSetting2->SetScale({ 150,40 });
		IsaacSetting2->SetPosition(Chapter4SPos + float4::Up * 140);
		IsaacSetting2->Off();
		IsaacSetting3 = Render->CreateRender("Title_Setting3.BMP", TitleOrder::Logo);
		IsaacSetting3->SetScale({ 150,40 });
		IsaacSetting3->SetPosition(Chapter4SPos + float4::Up * 140);
		IsaacSetting3->Off();
		IsaacSetting4 = Render->CreateRender("Title_Setting4.BMP", TitleOrder::Logo);
		IsaacSetting4->SetScale({ 150,40 });
		IsaacSetting4->SetPosition(Chapter4SPos + float4::Up * 140);
		IsaacSetting4->Off();
		IsaacSetting5 = Render->CreateRender("Title_Setting5.BMP", TitleOrder::Logo);
		IsaacSetting5->SetScale({ 150,40 });
		IsaacSetting5->SetPosition(Chapter4SPos + float4::Up * 140);
		IsaacSetting5->Off();
		IsaacSetting6 = Render->CreateRender("Title_Setting6.BMP", TitleOrder::Logo);
		IsaacSetting6->SetScale({ 150,40 });
		IsaacSetting6->SetPosition(Chapter4SPos + float4::Up * 140);
		IsaacSetting6->Off();
		
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

bool SelectIsaac = true;
bool SelectMacdalena = false;
bool SelectKain = false;
bool Selectnone = false;

void TitleLevel::Update(float _DeltaTime)
{
	float4 Pos = float4::LerpClamp(TitleStart, TitleEnd, T_Time);
	SetCameraPos(Pos);
	if (T_Time >= 1.0f)
	{
		Scroll = false;
		T_Time = 0.0f;
		TitleStart = Pos;
	}
	if (false == Scroll)
	{
		if (true == GameEngineInput::IsDown("TitleScrollRightDown")&& 100<=CursorPos.y)
		{
			PageSound();
			CursorPosSet();
			TitleEnd = TitleStart + float4(GameEngineWindow::GetScreenSize().x, GameEngineWindow::GetScreenSize().y);
			Scroll = true;
		}
		else if (true == GameEngineInput::IsDown("TitleScrollLeftUp")&& Pos.x> ChapterSettingXvalue)
		{
			PageSound();
			CursorSet();
			CursorPosSet();
			TitleEnd = TitleStart + float4(-GameEngineWindow::GetScreenSize().x, -GameEngineWindow::GetScreenSize().y);
			Scroll = true;
			CursorPos + Defaultvalue;
		}
		else if (true == GameEngineInput::IsDown("TitleScrollUp") && Pos.x< ChapterSettingXvalue &&Pos.y>100)
		{
			PageSound();
			CursorSet();
			CursorPosSet();
			TitleEnd = TitleStart + float4(0.0f, -GameEngineWindow::GetScreenSize().y);
			Scroll = true;
		}
		else if (true == GameEngineInput::IsDown("TitleScrollDown") && Pos.x < ChapterSettingXvalue)
		{
			PageSound();
			CursorSet();
			CursorPosSet();
			TitleEnd = TitleStart + float4(0.0f, GameEngineWindow::GetScreenSize().y);
			Scroll = true;
			if (Pos.y > Chapter3MaxYvalue)
			{
				PAGESOUND.Stop();
			}
		}
	}
	
	if (true == Scroll)
	{
		T_Time += _DeltaTime*3.0f;
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
		RightSound();
		Isaac_File1->Off();
		Isaac_File2->On();
		FirstPaper = false;
		SecondPaper = true;

	}
	else if (true == GameEngineInput::IsDown("Selectright") && Pos.y > Chapter2MinYvalue && Pos.y < Chapter2MaxYvalue && true == SecondPaper)
	{
		RightSound();
		Isaac_File2->Off();
		Isaac_File3->On();
		SecondPaper = false;
		ThirdPaper = true;
	}
	//Left
	if (true == GameEngineInput::IsDown("Selectleft") && Pos.y > Chapter2MinYvalue && Pos.y < Chapter2MaxYvalue && true == SecondPaper)
	{
		RightSound();
		Isaac_File1->On();
		Isaac_File2->Off();
		FirstPaper = true;
		SecondPaper = false;	
		
	}
	else if (true == GameEngineInput::IsDown("Selectleft") && Pos.y > Chapter2MinYvalue && Pos.y < Chapter2MaxYvalue && true==ThirdPaper)
	{
		RightSound();
		Isaac_File2->On();
		Isaac_File3->Off();
		SecondPaper = true;
		ThirdPaper = false;
		
	}
	////////////////////////////////////////////////////////////////////////Chapter3 key////////////////
	if (true == GameEngineInput::IsDown("Selectup")&&Pos.y> Chapter2MaxYvalue && Pos.y < Chapter3MaxYvalue)
	{
		RightSound();
		CursorPosSet();
		Cursor->On();
		Cursor2->Off();
		
	}
 	if (true == GameEngineInput::IsDown("Selectdown") && Pos.y > Chapter2MaxYvalue &&Pos.y< Chapter3MaxYvalue)
	{
		RightSound();
		CursorPosSet();
		Cursor->Off();
		Cursor2->On();
		CursorPos = CursorPos + Defaultvalue;
	}

	////////////////////////////////////////////////////////////////////////Chapter4 key////////////////

	/////Right
	if (true == GameEngineInput::IsDown("Selectright") && Pos.y > Chapter3MaxYvalue && true == SelectIsaac)
	{
		RightSound();
		Isaacselect1->Off();
		Isaacselect2->On();
		SelectIsaac = false;
		SelectMacdalena = true;
	}
	else if (true == GameEngineInput::IsDown("Selectright") && Pos.y > Chapter3MaxYvalue&& true == SelectMacdalena)
	{
		RightSound();
		Isaacselect2->Off();
		Isaacselect3->On();
		SelectMacdalena = false;
		SelectKain = true;
	}
	else if (true == GameEngineInput::IsDown("Selectright") && Pos.y > Chapter3MaxYvalue && true == SelectKain)
	{
		RightSound();
		Isaacselect3->Off();
		Isaacselect4->On();
		SelectKain = false;
		Selectnone = true;
	}
	else if (true == GameEngineInput::IsDown("Selectright") && Pos.y > Chapter3MaxYvalue && true == Selectnone)
	{
		RightSound();
		Isaacselect4->Off();
		Isaacselect1->On();
		Selectnone = false;
		SelectIsaac = true;
	}
	/////Left
	if (true == GameEngineInput::IsDown("Selectleft") && Pos.y > Chapter3MaxYvalue && true == SelectIsaac)
	{
		LeftSound();
		Isaacselect1->Off();
		Isaacselect4->On();
		SelectIsaac = false;
		Selectnone = true;
	}
	else if (true == GameEngineInput::IsDown("Selectleft") && Pos.y > Chapter3MaxYvalue && true == SelectMacdalena)
	{
		LeftSound();
		Isaacselect2->Off();
		Isaacselect1->On();
		SelectMacdalena = false;
		SelectIsaac = true;
	}
	else if (true == GameEngineInput::IsDown("Selectleft") && Pos.y > Chapter3MaxYvalue && true == SelectKain)
	{
		LeftSound();
		Isaacselect3->Off();
		Isaacselect2->On();
		SelectKain = false;
		SelectMacdalena = true;
	}
	else if (true == GameEngineInput::IsDown("Selectleft") && Pos.y > Chapter3MaxYvalue && true == Selectnone)
	{
		LeftSound();
		Isaacselect4->Off();
		Isaacselect3->On();
		Selectnone = false;
		SelectKain = true;
	}
	///////////////////////////////////////////////////////////SettingKey//////////////////////////
	if (true == GameEngineInput::IsDown("Selectright") && Pos.y > Chapter3MaxYvalue && Pos.x > ChapterSettingXvalue && true == sound0)
	{
		IsaacSetting0->Off();
		IsaacSetting1->On();
		sound0 = false;
		sound1 = true;
	}
	else if (true == GameEngineInput::IsDown("Selectright") && Pos.y > Chapter3MaxYvalue && Pos.x > ChapterSettingXvalue && true == sound1)
	{
		IsaacSetting1->Off();
		IsaacSetting2->On();
		sound1 = false;
		sound2 = true;
	}
	else if (true == GameEngineInput::IsDown("Selectright") && Pos.y > Chapter3MaxYvalue && Pos.x > ChapterSettingXvalue && true == sound2)
	{
		IsaacSetting2->Off();
		IsaacSetting3->On();
		sound2 = false;
		sound3 = true;
	}
	else if (true == GameEngineInput::IsDown("Selectright") && Pos.y > Chapter3MaxYvalue && Pos.x > ChapterSettingXvalue && true == sound3)
	{
		IsaacSetting3->Off();
		IsaacSetting4->On();
		sound3 = false;
		sound4 = true;
	}
	else if (true == GameEngineInput::IsDown("Selectright") && Pos.y > Chapter3MaxYvalue && Pos.x > ChapterSettingXvalue && true == sound4)
	{
		IsaacSetting4->Off();
		IsaacSetting5->On();
		sound4 = false;
		sound5 = true;
	}
	else if (true == GameEngineInput::IsDown("Selectright") && Pos.y > Chapter3MaxYvalue && Pos.x > ChapterSettingXvalue && true == sound5)
	{
		IsaacSetting5->Off();
		IsaacSetting6->On();
		sound5 = false;
		sound6 = true;
	}
	//////////////////////////////////Left
	else if (true == GameEngineInput::IsDown("Selectleft") && Pos.y > Chapter3MaxYvalue && Pos.x > ChapterSettingXvalue && true == sound6)
	{
		IsaacSetting6->Off();
		IsaacSetting5->On();
		sound6 = false;
		sound5 = true;
	}
	else if (true == GameEngineInput::IsDown("Selectleft") && Pos.y > Chapter3MaxYvalue && Pos.x > ChapterSettingXvalue && true == sound5)
	{
		IsaacSetting5->Off();
		IsaacSetting4->On();
		sound5 = false;
		sound4 = true;
	}
	else if (true == GameEngineInput::IsDown("Selectleft") && Pos.y > Chapter3MaxYvalue && Pos.x > ChapterSettingXvalue && true == sound4)
	{
		IsaacSetting4->Off();
		IsaacSetting3->On();
		sound4 = false;
		sound3 = true;
	}
	else if (true == GameEngineInput::IsDown("Selectleft") && Pos.y > Chapter3MaxYvalue && Pos.x > ChapterSettingXvalue && true == sound3)
	{
		IsaacSetting3->Off();
		IsaacSetting2->On();
		sound3 = false;
		sound2 = true;
	}
	else if (true == GameEngineInput::IsDown("Selectleft") && Pos.y > Chapter3MaxYvalue && Pos.x > ChapterSettingXvalue && true == sound2)
	{
		IsaacSetting2->Off();
		IsaacSetting1->On();
		sound2 = false;
		sound1 = true;
	}
	else if (true == GameEngineInput::IsDown("Selectleft") && Pos.y > Chapter3MaxYvalue && Pos.x > ChapterSettingXvalue && true == sound1)
	{
		IsaacSetting1->Off();
		IsaacSetting0->On();
		sound1 = false;
		sound0 = true;
	}

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

////////////////////////////////////Sound
void TitleLevel::SoundLoad()
{
	GameEngineDirectory Dir;
	Dir.MoveParentToDirectory("ContentsResources");
	Dir.Move("ContentsResources");
	Dir.Move("Sound");
	{
		GameEngineResources::GetInst().SoundLoad(Dir.GetPlusFileName("regenesis.ogg"));
		GameEngineResources::GetInst().SoundLoad(Dir.GetPlusFileName("characterselectleft.wav"));
		GameEngineResources::GetInst().SoundLoad(Dir.GetPlusFileName("characterselectright.wav"));
		GameEngineResources::GetInst().SoundLoad(Dir.GetPlusFileName("bookpageturn.wav"));

	}
	TITLEBGMPLAYER = GameEngineResources::GetInst().SoundPlayToControl("regenesis.ogg");
	TITLEBGMPLAYER.Volume(0.05f);

}

void TitleLevel::LevelChangeStart(GameEngineLevel* _PrevLevel)
{
	SoundLoad();
}
void TitleLevel::LevelChangeEnd(GameEngineLevel* _PrevLevel)
{
	TITLEBGMPLAYER.Stop();
}
void TitleLevel::RightSound()
{
	SELECTRIGHT = GameEngineResources::GetInst().SoundPlayToControl("characterselectright.wav");
	SELECTRIGHT.LoopCount(1);
	SELECTRIGHT.Volume(0.2);
}
void TitleLevel::LeftSound()
{
	SELECTLEFT = GameEngineResources::GetInst().SoundPlayToControl("characterselectleft.wav");
	SELECTLEFT.LoopCount(1);
	SELECTLEFT.Volume(0.2);
}
void TitleLevel::PageSound()
{
	PAGESOUND= GameEngineResources::GetInst().SoundPlayToControl("bookpageturn.wav");
	PAGESOUND.LoopCount(1);
	PAGESOUND.Volume(0.2);
}



