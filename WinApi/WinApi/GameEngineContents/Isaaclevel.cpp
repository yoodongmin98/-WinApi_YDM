#include "Isaaclevel.h"

// 프로젝트 순서에 따라서 정렬
#include <GameEngineBase/GameEngineDirectory.h>
#include <GameEnginePlatform/GameEngineInput.h>

#include <GameEnginePlatform/GameEngineWindow.h>

#include <GameEngineCore/GameEngineResources.h>
#include <GameEngineCore/GameEngineCore.h>

// 나랑 같은 등급의 헤더들
#include "Isaac.h"
#include "BackGround.h"
#include "Monster.h"


IsaacLevel::IsaacLevel()
{
}

IsaacLevel::~IsaacLevel()
{
}

void IsaacLevel::Loading()
{
	// 상대경로 탐색
	GameEngineDirectory Dir;
	Dir.MoveParentToDirectory("ContentsResources");
	Dir.Move("ContentsResources");
	Dir.Move("Image");
	Dir.Move("Play");

	// Level Image Load
	{
		GameEngineImage* head = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Isaac_Face.BMP"));
		head->Cut(10, 4);
		GameEngineImage* Back = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("BackGround.BMP"));
		GameEngineImage* Back_C = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("BackGround_CS.BMP"));
		GameEngineImage* Back_B = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Play_BlackGround.BMP"));
		
	}
	// 액터 생성
	{
		CreateActor<Isaac>();
		CreateActor<BackGround>();
		CreateActor<Monster>();
	}	
	//Isaac::MainPlayer->SetPos({210,360}); //>>Collision MAX value=1090,600
}

int CountValue = 0;
void IsaacLevel::Update(float _DeltaTime)
{
	MapMoveUpdate();
	if (true == Map_Move)
	{
		P_Time += _DeltaTime * MapMoveSpeed;
	}
}

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