#include "TitleChapter.h"
#include "TitleLevel.h"

#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEnginePlatform/GameEngineWindow.h>




TitleChapter* TitleChapter::MainChapter;

TitleChapter::TitleChapter()
{

}
TitleChapter::~TitleChapter()
{

}

void TitleChapter::Start()
{
	MainChapter = this;
	SetMove(GameEngineWindow::GetScreenSize().half());
}
void TitleChapter::Update(float _DeltaTime)
{
	if (false == GameEngineInput::IsKey("test"))
	{
		GameEngineInput::CreateKey("test", 'Q');
	}
	if (true == GameEngineInput::IsPress("test"))
	{
		GetLevel()->SetCameraMove(float4::Down * 5);
	}

}