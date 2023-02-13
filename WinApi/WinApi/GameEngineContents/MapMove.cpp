#include "IsaacLevel.h"
#include "Isaac.h"

#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEnginePlatform/GameEngineWindow.h>







int CountValue = 0;


void IsaacLevel::MapMoveUpdate()
{
	float PlayerXPos = Isaac::MainPlayer->GetPos().x;
	float SizeValue = GameEngineWindow::GetScreenSize().x;
	if (PlayerXPos > SizeValue)
	{
		PlayerXPos = PlayerXPos - (SizeValue * CountValue); //플레이어의포스가 SizeValue보다높다면 SizeValue*CountValue(방을이동한횟수)만큼
		//곱해준값을 빼서 위치를 리셋시킨다.
	}
	float4 Pos = float4::LerpClamp(MapS, MapE, P_Time);
	if (P_Time >= 1.0f)
	{
		Map_Move = false;
		P_Time = 0.0f;
		MapS = Pos;
	}
	SetCameraPos(Pos);
	if (P_Time >= 1.0f) //1초만큼의 시간이 지나야 다음 이동연결(MapPos)이 동작한다.
	{
		Map_Move = false;
		P_Time = 0.0f;
		MapS = Pos;
	}
	//////////////////////////Map Move
	if (false == Map_Move)
	{
		if (PlayerXPos > RightSetValue && GameEngineInput::IsPress("RightMove"))
		{
			MapE = MapS + float4(SizeValue, 0);
			Map_Move = true;
			CountValue = CountValue + 1;
			Isaac::MainPlayer->SetPos({ LeftSetValue + (SizeValue * (float)CountValue),MiddieYValue });
		}
		if (PlayerXPos < LeftSetValue && GameEngineInput::IsPress("LeftMove"))
		{
			MapE = MapS + float4(-SizeValue, 0);
			Map_Move = true;
			CountValue = CountValue - 1;
			Isaac::MainPlayer->SetPos({ RightSetValue + (SizeValue * (float)CountValue),MiddieYValue });
		}
	}
}