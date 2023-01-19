#include "Isaac.h"
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineBase/GameEnginePath.h>
#include <GameEngineCore/GameEngineResources.h>
#include <GameEngineCore/GameEngineRender.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include "ContentsEnums.h"

Isaac* Isaac::MainPlayer;

Isaac::Isaac()
{
}

Isaac::~Isaac()
{
}

void Isaac::Start()
{
	MainPlayer = this;

	SetMove(GameEngineWindow::GetScreenSize().half());


	if (false == GameEngineInput::IsKey("LeftMove"))
	{
		GameEngineInput::CreateKey("LeftMove", 'A');
		GameEngineInput::CreateKey("RightMove", 'D');
		GameEngineInput::CreateKey("DownMove", 'S');
		GameEngineInput::CreateKey("UpMove", 'W');
	}

	{
		AnimationRender = CreateRender(IsaacOrder::Player);
		AnimationRender->SetScale({ 100, 100});

		AnimationRender->CreateAnimation({ .AnimationName = "Right_Idle",  .ImageName = "IsaacBase.bmp", .Start = 0, .End = 1, .InterTime = 0.3f });
		AnimationRender->CreateAnimation({ .AnimationName = "Right_Move",  .ImageName = "IsaacBase.bmp", .Start = 2, .End = 3 });

		//AnimationRender->CreateAnimation({ .AnimationName = "Left_Idle",  .ImageName = "IsaacBase.bmp", .Start = 0, .End = 1, .InterTime = 0.3f });
		//AnimationRender->CreateAnimation({ .AnimationName = "Left_Move",  .ImageName = "IsaacBase.bmp", .Start = 2, .End = 3 });
	}

	ChangeState(IsaacState::IDLE);
}

void Isaac::Update(float _DeltaTime)
{
	UpdateState(_DeltaTime);
}

void Isaac::DirCheck(const std::string_view& _AnimationName)
{
	std::string PrevDirString = DirString;
	AnimationRender->ChangeAnimation(DirString + _AnimationName.data());

	if (GameEngineInput::IsPress("LeftMove"))
	{
		DirString = "Left_";
	}
	else if (GameEngineInput::IsPress("RightMove"))
	{
		DirString = "Right_";
	}

	if (PrevDirString != DirString)
	{
		AnimationRender->ChangeAnimation(DirString + _AnimationName.data());
	}
}

void Isaac::Render(float _DeltaTime)
{

}