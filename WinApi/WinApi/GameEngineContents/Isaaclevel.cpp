#include "Isaaclevel.h"

// ������Ʈ ������ ���� ����
#include <GameEngineBase/GameEngineDirectory.h>
#include <GameEnginePlatform/GameEngineInput.h>

#include <GameEnginePlatform/GameEngineWindow.h>

#include <GameEngineCore/GameEngineResources.h>
#include <GameEngineCore/GameEngineCore.h>

// ���� ���� ����� �����
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
	// ����� Ž��
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
		//GameEngineImage* Back_C = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("BackGround_CS.BMP"));
		
	}
	// ���� ����
	{
		CreateActor<Isaac>();
		CreateActor<BackGround>();
		CreateActor<Monster>();
	}	
	//Isaac::MainPlayer->SetPos({1090,600}); //>>Collision MAX value=1090,600
}

int CountValue = 0;
void IsaacLevel::Update(float _DeltaTime)
{
	float PlayerXPos = Isaac::MainPlayer->GetPos().x;
	float SizeValue = GameEngineWindow::GetScreenSize().x;
	if (PlayerXPos > SizeValue)
	{
		PlayerXPos = PlayerXPos-SizeValue*CountValue;
	}
	
	float4 Pos = float4::LerpClamp(MapS, MapE, P_Time);
	if(P_Time>=1.0f)
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
	if (false == Map_Move)
	{
		if (PlayerXPos> SizeValue -(191.0f) && GameEngineInput::IsPress("RightMove"))
		{
			MapE = MapS + float4(SizeValue, 0);
			Map_Move = true;
			CountValue = CountValue + 1;
			Isaac::MainPlayer->SetPos({ 310.f + (SizeValue * (float)CountValue),MiddieYValue });
			
		}
	}
	if (true == Map_Move)
	{
		P_Time += _DeltaTime * 0.5f;
	}
	
	
}