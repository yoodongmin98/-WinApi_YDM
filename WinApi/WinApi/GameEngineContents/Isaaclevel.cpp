#include "Isaaclevel.h"

// 프로젝트 순서에 따라서 정렬
#include <GameEngineBase/GameEngineDirectory.h>
#include <GameEnginePlatform/GameEngineInput.h>

#include <GameEngineCore/GameEngineResources.h>
#include <GameEngineCore/GameEngineCore.h>

// 나랑 같은 등급의 헤더들
#include "Isaac.h"
#include "BackGround.h"
//#include "Map.h"


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
		GameEngineImage* head = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Isaac_Face.BMP"));
		head->Cut(10, 4);
		GameEngineImage* Back = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("BackGround.BMP"));
		GameEngineImage* Back_C = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("BackGround_CS.BMP"));
	}
	// 액터 생성
	{
		CreateActor<Isaac>();
		CreateActor<BackGround>();
	}	
}

void IsaacLevel::Update(float _DeltaTime)
{
	

}