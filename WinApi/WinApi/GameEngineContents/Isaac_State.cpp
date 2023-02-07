#include "Isaac.h"
#include <GameEngineBase/GameEnginePath.h>
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineResources.h>
#include <GameEngineCore/GameEngineRender.h>
#include <GameEngineCore/GameEngineLevel.h>

#include "IsaacEnum.h"



// State
void Isaac::ChangeState(IsaacState _State)
{
	IsaacState NextState = _State;
	IsaacState PrevState = StateValue;

	StateValue = NextState;

	switch (NextState)
	{
	case IsaacState::IDLE:
		IdleStart();
		break;
	case IsaacState::MOVE:
		MoveStart();
		break;
	default:
		break;
	}

	switch (PrevState)
	{
	case IsaacState::IDLE:
		IdleEnd();
		break;
	case IsaacState::MOVE:
		MoveEnd();
		break;
	default:
		break;
	}

}

void Isaac::UpdateState(float _Time)
{
	switch (StateValue)
	{
	case IsaacState::IDLE:
		IdleUpdate(_Time);
		break;
	case IsaacState::MOVE:
		MoveUpdate(_Time);
		break;
	default:
		break;
	}

}


void Isaac::IdleStart()
{
	DirCheck("Idle");
}
void Isaac::IdleUpdate(float _Time)
{
	DirCheck("Idle");
	if (GameEngineInput::IsPress("LeftMove") || GameEngineInput::IsPress("RightMove") || GameEngineInput::IsPress("DownMove") || GameEngineInput::IsPress("UpMove"))
	{
		ChangeState(IsaacState::MOVE);
		return;
	}
}
void Isaac::IdleEnd() {

}

void Isaac::MoveStart()
{
	DirCheck("Move");
}
void Isaac::MoveUpdate(float _Time)
{
	DirCheck("Move");
	if (
		false == GameEngineInput::IsPress("LeftMove") &&
		false == GameEngineInput::IsPress("RightMove") &&
		false == GameEngineInput::IsPress("DownMove") &&
		false == GameEngineInput::IsPress("UpMove")
		)
	{
		// 
		ChangeState(IsaacState::IDLE);
		return;
	}
	float4 MoveRange = float4::Zero;

	if (true == GameEngineInput::IsPress("LeftMove"))
	{
		MoveRange += float4::Left;
	}

	if (true == GameEngineInput::IsPress("RightMove"))
	{
		MoveRange += float4::Right;
	}

	if (true == GameEngineInput::IsPress("UpMove"))
	{
		MoveRange += float4::Up;
	}
	else if (true == GameEngineInput::IsPress("DownMove"))
	{
		MoveRange += float4::Down;
	}
	MoveDir = MoveRange * MoveSpeed;
	
}
void Isaac::MoveEnd() {

}
