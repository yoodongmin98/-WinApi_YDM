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
	DamageUpdate(_Time);
	if (GameEngineInput::IsPress("LeftMove") || GameEngineInput::IsPress("RightMove") || GameEngineInput::IsPress("DownMove") || GameEngineInput::IsPress("UpMove"))
	{
		ChangeState(IsaacState::MOVE);
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
		DamageUpdate(_Time);
		MoveRange += float4::Left;
	}

	if (true == GameEngineInput::IsPress("RightMove"))
	{
		DamageUpdate(_Time);
		MoveRange += float4::Right;
	}

	if (true == GameEngineInput::IsPress("UpMove"))
	{
		DamageUpdate(_Time);
		MoveRange += float4::Up;
	}
	else if (true == GameEngineInput::IsPress("DownMove"))
	{
		DamageUpdate(_Time);
		MoveRange += float4::Down;
	}
	MoveDir = MoveRange * MoveSpeed;

}
void Isaac::MoveEnd() {

}


//일단 생각하기귀찮으니까 노가다로 해놓자....ㅋㅋ
void Isaac::DamageUpdate(float _Time)
{
	if (true == DamagedIsaac)
	{
		CollTime += _Time;
		Head->Off();
		if (CollTime > 0.1f)
		{
			Head->On();
		}
		if (CollTime > 0.2f)
		{
			Head->Off();
		}
		if (CollTime > 0.3f)
		{
			Head->On();
		}
		if (CollTime > 0.4f)
		{
			Head->Off();
		}
		if (CollTime > 0.5f)
		{
			Head->On();
		}
		if (CollTime > 0.6f)
		{
			Head->Off();
		}
		if (CollTime > 0.7f)
		{
			Head->On();
		}
		if (CollTime > 0.8f)
		{
			Head->Off();
		}
		if (CollTime > 0.9f)
		{
			Head->On();
		}
		if (CollTime > 1.0f)
		{
			Head->Off();
		}
		if (CollTime > 1.1f)
		{
			Head->On();
		}
		if (CollTime > 1.2f)
		{
			Head->Off();
		}
		if (CollTime > 1.3f)
		{
			Head->On();
		}
		if (CollTime > 1.4f)
		{
			Head->Off();
		}
		if (CollTime > 1.5f)
		{
			Head->On();
		}
		if (CollTime > 1.6f)
		{
			Head->Off();
		}
		if (CollTime > 1.7f)
		{
			Head->On();
		}
		if (CollTime > 1.8f)
		{
			Head->Off();
		}
		if (CollTime > 1.9f)
		{
			Head->On();
		}
		if (CollTime > 2.0f)
		{
			Head->Off();
		}
		if (CollTime > 2.1f)
		{
			Head->On();
		}
		if (CollTime > 2.2f)
		{
			Head->Off();
		}
		if (CollTime > 2.3f)
		{
			Head->On();
		}
		if (CollTime > 2.4f)
		{
			Head->Off();
		}
		if (CollTime > 2.5f)
		{
			Head->On();
		}
		if (CollTime > 2.6f)
		{
			Head->Off();
		}
		if (CollTime > 2.7f)
		{
			Head->On();
		}
	}
}

