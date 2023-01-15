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
	// ����� Ž��
	GameEngineDirectory Dir;
	Dir.MoveParentToDirectory("ContentsResources");
	Dir.Move("ContentsResources");
	Dir.Move("Image");
	Dir.Move("Play");

	// �̹��� �ε�
	{
		GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Heros.BMP"));
		Image->Cut({ 2, 12 }, { 949,38 }, 32, 1);
	}

	// ���� ����
	CreateActor<Isaac>();

	if (false == GameEngineInput::IsKey("PlayerOff"))
	{
		GameEngineInput::CreateKey("PlayerOff", 'R');
	}
}

void IsaacPlay::Update(float _DeltaTime)
{
	if (GameEngineInput::IsDown("PlayerOff"))
	{
		Isaac::MainPlayer->OnOffSwtich();
		
	}
}

