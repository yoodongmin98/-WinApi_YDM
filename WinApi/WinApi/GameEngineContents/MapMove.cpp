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
		PlayerXPos = PlayerXPos - (SizeValue * CountValue); //�÷��̾��������� SizeValue���ٳ��ٸ� SizeValue*CountValue(�����̵���Ƚ��)��ŭ
		//�����ذ��� ���� ��ġ�� ���½�Ų��.
	}
	float4 Pos = float4::LerpClamp(MapS, MapE, P_Time);
	if (P_Time >= 1.0f)
	{
		Map_Move = false;
		P_Time = 0.0f;
		MapS = Pos;
	}
	SetCameraPos(Pos);
	if (P_Time >= 1.0f) //1�ʸ�ŭ�� �ð��� ������ ���� �̵�����(MapPos)�� �����Ѵ�.
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