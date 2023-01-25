#include "Isaaclevel.h"

// ������Ʈ ������ ���� ����
#include <GameEngineBase/GameEngineDirectory.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineResources.h>

// ���� ���� ����� �����
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
	// ����� Ž��
	GameEngineDirectory Dir;
	Dir.MoveParentToDirectory("ContentsResources");
	Dir.Move("ContentsResources");
	Dir.Move("Image");
	Dir.Move("Play");

	// �̹��� �ε�
	{
		GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Isaac_Face.BMP"));
		Image->Cut(8, 5);
		
		GameEngineImage* Image2 = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("BackGround.BMP"));
	}
	// ���� ����
	{
		Isaac* Actor = CreateActor<Isaac>();
		BackGround* Back = CreateActor<BackGround>();
	}

	/*{
		Map* Actor = CreateActor<Map>();
	}*/


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