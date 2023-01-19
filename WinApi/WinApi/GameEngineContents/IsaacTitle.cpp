#include "IsaacTitle.h"

#include <GameEngineBase/GameEngineDirectory.h>
#include <GameEngineCore/GameEngineResources.h>
#include <GameEngineCore/GameEngineCore.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include "TitleBack.h"
#include <GameEngineCore/GameEngineActor.cpp>
#include "ContentsEnums.h"


IsaacTitle::IsaacTitle()
{
}

IsaacTitle::~IsaacTitle()
{
}


void IsaacTitle::Loading()
{
	GameEngineDirectory Dir;
	Dir.MoveParentToDirectory("ContentsResources");
	Dir.Move("ContentsResources");
	Dir.Move("Image");
	Dir.Move("Title");

	// 이미지 로드
	{
		GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("IsaacTitleTest.BMP"));
		GameEngineImage* Image1 = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("BackTitle.BMP"));
	}




	if (false == GameEngineInput::IsKey("LevelChange"))
	{
		GameEngineInput::CreateKey("LevelChange", 'P');
	}

	CreateActor<TitleBack>();

}
void IsaacTitle::Update(float _DeltaTime)
{
	if (true == GameEngineInput::IsAnyKey())
	{
		GameEngineCore::GetInst()->ChangeLevel("IsaacPlay");
	}
}
