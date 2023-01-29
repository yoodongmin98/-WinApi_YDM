#include "Isaac.h"
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineBase/GameEnginePath.h>
#include <GameEngineCore/GameEngineResources.h>
#include <GameEngineCore/GameEngineRender.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include "IsaacEnum.h"
#include "IsaacIntro.h"

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
		AnimationRender = CreateRender(IsaacOrder::PlayerHead);
		
		AnimationRender->SetScale({ 135,120});

		

		AnimationRender->CreateAnimation({ .AnimationName = "Right_Idle",  .ImageName = "Isaac_Face.bmp", .Start = 0, .End = 1, .InterTime = 0.3f });
		AnimationRender->CreateAnimation({ .AnimationName = "Right_Move",  .ImageName = "Isaac_Face.bmp", .Start = 2, .End = 3, .InterTime = 0.3f });

		AnimationRender->CreateAnimation({ .AnimationName = "Left_Idle",  .ImageName = "Isaac_Face.bmp", .Start = 0, .End = 1, .InterTime = 0.3f });
		AnimationRender->CreateAnimation({ .AnimationName = "Left_Move",  .ImageName = "Isaac_Face.bmp", .Start = 6, .End = 7 , .InterTime = 0.3f });
		//위		위 위
		AnimationRender->CreateAnimation({ .AnimationName = "Up_Idle",  .ImageName = "Isaac_Face.bmp", .Start = 0, .End = 1, .InterTime = 0.3f });
		AnimationRender->CreateAnimation({ .AnimationName = "Up_Move",  .ImageName = "Isaac_Face.bmp", .Start = 4, .End = 5 , .InterTime = 0.3f });
		//    아래		  아래
		AnimationRender->CreateAnimation({ .AnimationName = "Down_Idle",  .ImageName = "Isaac_Face.bmp", .Start = 0, .End = 1, .InterTime = 0.3f });
		AnimationRender->CreateAnimation({ .AnimationName = "Down_Move",  .ImageName = "Isaac_Face.bmp", .Start = 0, .End = 0 , .InterTime = 0.3f });

		
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
