#include "Isaac_Bomb.h"

#include <GameEngineBase/GameEngineDirectory.h>
#include <GameEngineCore/GameEngineResources.h>

Isaac_Bomb::Isaac_Bomb()
{

}
Isaac_Bomb::~Isaac_Bomb()
{

}

// �����ϱ����� ���� �غ��ؾ��Ұ��� ������ ���⼭ �ض�.
void Isaac_Bomb::Start()
{
	static bool Load = false;
	if (false == Load)
	{
		GameEngineDirectory Dir;
		Dir.MoveParentToDirectory("ContentsResources");
		Dir.Move("ContentsResources");
		Dir.Move("Image");
		Dir.Move("etc");
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Tropy.bmp"));
		Load = true;
	}
	
}
// Ű�Է��� �ްų� �ΰ������� ������ ����ϰų� �ϴ� �͵��� ���⼭ ó��
void Isaac_Bomb::Update(float _DeltaTime)
{

}

// ������ ���� �Լ��� �ѹ� �������ϰ� 
void Isaac_Bomb::LateUpdate(float _DeltaTime)
{

}

// ȭ�鿡 �׷����� ��ɵ��� ���⼭ ó��
void Isaac_Bomb::Render(float _DeltaTime)
{

}

