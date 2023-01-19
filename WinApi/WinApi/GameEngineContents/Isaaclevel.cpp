#include "Isaaclevel.h"

// 프로젝트 순서에 따라서 정렬
#include <GameEngineBase/GameEngineDirectory.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineResources.h>

// 나랑 같은 등급의 헤더들
#include "Isaac.h"
//#include "Map.h"
//#include "BackGround.h"

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

	// 이미지 로드
	{
		GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("IsaacBase.BMP"));
		Image->Cut(2, 2);
	}
	

	// 액터 생성
	/*{
		BackGround* Actor = CreateActor<BackGround>();
	}
	{
		Map* Actor = CreateActor<Map>();
	}*/
	{
		Isaac* Actor = CreateActor<Isaac>();
	}


	if (false == GameEngineInput::IsKey("PlayerOff"))
	{
		GameEngineInput::CreateKey("PlayerOff", 'R');
	}


	if (false == GameEngineInput::IsKey("CameraLeftMove"))
	{
		
		GameEngineInput::CreateKey("CameraLeftMove", VK_LEFT);
		GameEngineInput::CreateKey("CameraRightMove", VK_RIGHT);
		GameEngineInput::CreateKey("CameraDownMove", VK_DOWN);
		GameEngineInput::CreateKey("CameraUpMove", VK_UP);
	}
}

void IsaacLevel::Update(float _DeltaTime)
{
	if (GameEngineInput::IsDown("PlayerOff"))
	{
		Isaac::MainPlayer->OnOffSwtich();
	}

	float CameraMoveSpeed = 100.0f;

}