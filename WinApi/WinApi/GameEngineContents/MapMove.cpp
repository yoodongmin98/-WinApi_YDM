#include "IsaacLevel.h"
#include "Isaac.h"


#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineCollision.h>
#include "IsaacEnum.h"





int CountX = 0;
int CountY = 0;

void IsaacLevel::MapMoveUpdate()
{
	float PlayerXPos = Isaac::MainPlayer->GetPos().x;
	float PlayerYPos = Isaac::MainPlayer->GetPos().y;
	float SizeValue = GameEngineWindow::GetScreenSize().x;
	float SizeValueY = GameEngineWindow::GetScreenSize().y;
	if (PlayerXPos > SizeValue)
	{
		PlayerXPos = PlayerXPos - (SizeValue * CountX);
		//플레이어의포스가 SizeValue보다높다면 SizeValue*CountX(X축으로방을이동한횟수)만큼
		//곱해준값을 빼서 위치를 리셋시킨다.
	}
	if (PlayerYPos > SizeValueY)
	{
		PlayerYPos = PlayerYPos - (SizeValueY * CountY);
	}
	
	float4 Pos = float4::LerpClamp(MapS, MapE, P_Time);
	if (P_Time >= 1.0f)
	{
		Map_Move = false;
		P_Time = 0.0f;
		MapS = Pos;
	}
	SetCameraPos(Pos);
	//////////////////////////Map Move
	if (false == Map_Move)
	{
		if (PlayerXPos > RightSetValue && GameEngineInput::IsPress("RightMove"))
		{
			MapE = MapS + float4(SizeValue, 0);
			Map_Move = true;
			CountX = CountX + 1;
			Isaac::MainPlayer->SetPos({ LeftSetValue + (SizeValue * (float)CountX) ,MiddieYValue+(SizeValueY * (float)CountY) });
		}
		if (PlayerXPos < LeftSetValue && GameEngineInput::IsPress("LeftMove"))
		{
			MapE = MapS + float4(-SizeValue, 0);
			Map_Move = true;
			CountX = CountX - 1;
			Isaac::MainPlayer->SetPos({ RightSetValue + (SizeValue * (float)CountX),MiddieYValue+(SizeValueY * (float)CountY) });
		}
		if (PlayerYPos > DownSetValue && GameEngineInput::IsPress("DownMove"))
		{
			MapE = MapS + float4(0, SizeValueY);
			Map_Move = true;
			CountY = CountY + 1;
			Isaac::MainPlayer->SetPos({ MiddieXValue+ (SizeValue * (float)CountX),UpSetValue + (SizeValueY * (float)CountY) });
		}
		if (PlayerYPos < UpSetValue && GameEngineInput::IsPress("UpMove"))
		{
			MapE = MapS + float4(0, -SizeValueY);
			Map_Move = true;
			CountY = CountY - 1;
			Isaac::MainPlayer->SetPos({ MiddieXValue+ (SizeValue * (float)CountX),DownSetValue + (SizeValueY * (float)CountY) });
		}
	}
}