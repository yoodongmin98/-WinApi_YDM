#include "Isaac_Bomb.h"

#include "IsaacEnum.h"

#include <GameEngineBase/GameEngineDirectory.h>
#include <GameEngineCore/GameEngineResources.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineRender.h>

Isaac_Bomb::Isaac_Bomb()
{

}
Isaac_Bomb::~Isaac_Bomb()
{

}

// �����ϱ����� ���� �غ��ؾ��Ұ��� ������ ���⼭ �ض�.
void Isaac_Bomb::Start()
{
	GameEngineDirectory Dir;
	Dir.MoveParentToDirectory("ContentsResources");
	Dir.Move("ContentsResources");
	Dir.Move("Image");
	Dir.Move("Play");

	/*Bomb = CreateRender(IsaacOrder::Player);
	Bomb->Off();
		*/
		
	
	
}
// Ű�Է��� �ްų� �ΰ������� ������ ����ϰų� �ϴ� �͵��� ���⼭ ó��
void Isaac_Bomb::Update(float _DeltaTime)
{
	/*if (true == GameEngineInput::IsKey("Bomb"))
	{
		Bomb->On();
	}*/
}

// ������ ���� �Լ��� �ѹ� �������ϰ� 
void Isaac_Bomb::LateUpdate(float _DeltaTime)
{

}

// ȭ�鿡 �׷����� ��ɵ��� ���⼭ ó��
void Isaac_Bomb::Render(float _DeltaTime)
{

}

