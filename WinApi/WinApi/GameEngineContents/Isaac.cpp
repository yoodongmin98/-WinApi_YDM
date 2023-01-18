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
		AnimationRender = CreateRender(IsaacOrder::BackGround);
		AnimationRender->SetScale({ 100, 100 });
		
	}
}

void Isaac::Update(float _DeltaTime)
{
	if (true == GameEngineInput::IsPress("LeftMove"))
	{
		SetMove(float4::Left * MoveSpeed * _DeltaTime);
	}

	if (true == GameEngineInput::IsPress("RightMove"))
	{
		SetMove(float4::Right * MoveSpeed * _DeltaTime);
	}

	if (true == GameEngineInput::IsPress("UpMove"))
	{
		SetMove(float4::Up * MoveSpeed * _DeltaTime);
	}

	if (true == GameEngineInput::IsPress("DownMove"))
	{
		SetMove(float4::Down * MoveSpeed * _DeltaTime);
	}

	
}

void Isaac::Render(float _DeltaTime)
{
	// µð¹ö±ë¿ë.
}