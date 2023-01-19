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
	GameEngineDirectory Dir;
	Dir.MoveParentToDirectory("ContentsResources");
	Dir.Move("ContentsResources");
	Dir.Move("Image");
	Dir.Move("Play");

	{
		GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("IsaacBase.BMP"));
		Image->Cut(2,2);
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

