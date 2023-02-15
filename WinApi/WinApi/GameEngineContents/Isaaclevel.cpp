#include "Isaaclevel.h"

// 프로젝트 순서에 따라서 정렬
#include <GameEngineBase/GameEngineDirectory.h>
#include <GameEnginePlatform/GameEngineInput.h>

#include <GameEnginePlatform/GameEngineWindow.h>

#include <GameEngineCore/GameEngineResources.h>
#include <GameEngineCore/GameEngineCore.h>
#include <GameEngineCore/GameEngineRender.h>

// 나랑 같은 등급의 헤더들
#include "Isaac.h"
#include "Room.h"
#include "Monster.h"
#include "Door.h"



IsaacLevel::IsaacLevel()
{
	
}

IsaacLevel::~IsaacLevel()
{
}

void IsaacLevel::Loading()
{
	// 상대경로 탐색
	GameEngineDirectory Dir;
	Dir.MoveParentToDirectory("ContentsResources");
	Dir.Move("ContentsResources");
	Dir.Move("Image");
	Dir.Move("Play");

	// Level Image Load
	{
		GameEngineImage* head = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Isaac_Face.BMP"));
		head->Cut(10, 4);
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Room.BMP"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("BackGround_CS.BMP"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Play_BlackGround.BMP"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Play_Settingmenu.BMP"));
	}
	// 액터 생성
	{
		CreateActor<Isaac>();
		CreateActor<Room>();
		CreateActor<Monster>();
		CreateActor<Door>();
	}	
	//>>Collision MAX value=1090,600
	if (false == GameEngineInput::IsKey("LoadMenu"))
	{
		GameEngineInput::CreateKey("LoadMenu", VK_ESCAPE);
	}
	
}


void IsaacLevel::Update(float _DeltaTime)
{
	MapMoveUpdate();
	
	if (true == Map_Move)
	{
		P_Time += _DeltaTime * MapMoveSpeed;
	}
	
	if (true == GameEngineInput::IsDown("LoadMenu"))
	{
		if (2 == SettingValue)
		{
			SettingMenu->On();
			SettingValue = SettingValue - 1;
		}
		else
		{
			SettingMenu->Off();
			SettingValue = SettingValue + 1;
		}
	}
	/*if (1 == SettingValue && true == GameEngineInput::IsDown("LoadMenuTitle"))
	{
		GameEngineCore::GetInst()->ChangeLevel("TitleLevel");
	}*/ //버그가 너무많아서 이건 나중에하자
}
void IsaacLevel::LevelChangeStart(GameEngineLevel* _PrevLevel)
{
	SettingMenuUpdate();
	SettingMenu->Off();
}

