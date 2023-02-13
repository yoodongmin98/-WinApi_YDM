#include "Isaaclevel.h"

// ������Ʈ ������ ���� ����
#include <GameEngineBase/GameEngineDirectory.h>
#include <GameEnginePlatform/GameEngineInput.h>

#include <GameEnginePlatform/GameEngineWindow.h>

#include <GameEngineCore/GameEngineResources.h>
#include <GameEngineCore/GameEngineCore.h>

// ���� ���� ����� �����
#include "Isaac.h"
#include "BackGround.h"
#include "Monster.h"


IsaacLevel::IsaacLevel()
{
}

IsaacLevel::~IsaacLevel()
{
}

void IsaacLevel::Loading()
{
	// ����� Ž��
	GameEngineDirectory Dir;
	Dir.MoveParentToDirectory("ContentsResources");
	Dir.Move("ContentsResources");
	Dir.Move("Image");
	Dir.Move("Play");

	// Level Image Load
	{
		GameEngineImage* head = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Isaac_Face.BMP"));
		head->Cut(10, 4);
		GameEngineImage* Back = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("BackGround.BMP"));
		GameEngineImage* Back_C = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("BackGround_CS.BMP"));
		GameEngineImage* Back_B = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Play_BlackGround.BMP"));
		GameEngineImage* Setting = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Play_Settingmenu.BMP"));
		
	}
	// ���� ����
	{
		CreateActor<Isaac>();
		CreateActor<BackGround>();
		CreateActor<Monster>();
	}	
	//Isaac::MainPlayer->SetPos({210,360}); //>>Collision MAX value=1090,600
}


void IsaacLevel::Update(float _DeltaTime)
{
	MapMoveUpdate();
	SettingMenuUpdate();
	if (true == Map_Move)
	{
		P_Time += _DeltaTime * MapMoveSpeed;
	}
}

