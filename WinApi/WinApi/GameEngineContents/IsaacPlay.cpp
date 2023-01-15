#include "IsaacPlay.h"
#include "Isaac.h"

#include <GameEngineBase/GameEngineDirectory.h>
#include <GameEngineCore/GameEngineResources.h>
#include <GameEnginePlatform/GameEngineInput.h>

IsaacPlay::IsaacPlay()
{
}

IsaacPlay::~IsaacPlay()
{
}

void IsaacPlay::Loading()
{
	// 상대경로 탐색
	GameEngineDirectory Dir;
	Dir.MoveParentToDirectory("ContentsResources");
	Dir.Move("ContentsResources");
	Dir.Move("Image");
	Dir.Move("Play");

	// 이미지 로드
	{
		GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("TitleBack1.BMP"));
		Image->Cut({ 0, 0 }, { 63,64 }, 2,3);
	}

	// 액터 생성
	CreateActor<Isaac>();

	if (false == GameEngineInput::IsKey("PlayerOff"))
	{
		GameEngineInput::CreateKey("PlayerOff", 'R');
		GameEngineInput::CreateKey("Bomb", 'F');
	}
}

void IsaacPlay::Update(float _DeltaTime)
{
	if (GameEngineInput::IsDown("PlayerOff"))
	{
		Isaac::MainPlayer->OnOffSwtich();
		
	}
	if (GameEngineInput::IsDown("Bomb"))
	{
		Isaac::MainPlayer->OnOffSwtich();

	}
}

