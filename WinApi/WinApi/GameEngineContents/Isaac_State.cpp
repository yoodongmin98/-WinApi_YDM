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

// FSM 내가 어떤일을 할때 이동하면서 가만히 있을수 없다.
void Isaac::IdleStart()
{
	DirCheck("Idle");
}
void Isaac::IdleUpdate(float _Time)
{
	if (GameEngineInput::IsPress("LeftMove") || GameEngineInput::IsPress("RightMove")|| GameEngineInput::IsPress("UpMove") || GameEngineInput::IsPress("DownMove"))
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
	if (
		false == GameEngineInput::IsPress("LeftMove") &&
		false == GameEngineInput::IsPress("RightMove") &&
		false == GameEngineInput::IsPress("UpMove") &&
		false == GameEngineInput::IsPress("DownMove")
		)
	{
		// 
		ChangeState(IsaacState::IDLE);
		return;
	}

	if (true == GameEngineInput::IsPress("LeftMove"))
	{
		SetMove(float4::Left * MoveSpeed * _Time);
		GetLevel()->SetCameraMove(float4::Left * _Time * MoveSpeed);
	}
	else if (true == GameEngineInput::IsPress("RightMove"))
	{
		SetMove(float4::Right * MoveSpeed * _Time);
	}
	else if (true == GameEngineInput::IsPress("UpMove"))
	{
		SetMove(float4::Up * MoveSpeed * _Time);
	}
	else if (true == GameEngineInput::IsPress("DownMove"))
	{
		SetMove(float4::Down * MoveSpeed * _Time);
	}

	DirCheck("Move");
}
void Isaac::MoveEnd() {

}
