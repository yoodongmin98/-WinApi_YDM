#include "IsaacPlay.h"
//#include "Isaac.h"
#include <GameEngineBase/GameEngineDirectory.h>

IsaacPlay::IsaacPlay()
{
}

IsaacPlay::~IsaacPlay()
{
}

void IsaacPlay::Loading()
{
	// �̷� ��θ� ���� ���.
	// "D:\Project\AR45\WINAPI\APIApp\ContentsResources\Iamge\Heros.bmp";

	// std::string Text = "D:\Project\AR45\WINAPI\APIApp\ContentsResources\Iamge\Heros.bmp";

	GameEngineDirectory Dir;

	Dir.MoveParentToDirectory("ContentsResources");
	Dir.Move("ContentsResources");
	Dir.Move("Image");

	Dir.GetPlusFileName("Heros.BMP");




	//if (true == Path.IsExistsToPlusString("\\Heros.bmp"))
	//{
	//	int a = 0;
	//}

	//bool Result = false;
	//Result = Path.IsExistsToPlusString("\\ContentsResources");
	//Path.MoveParent();
	//Result = Path.IsExistsToPlusString("\\ContentsResources");
	//Path.MoveParent();
	//Result = Path.IsExistsToPlusString("\\ContentsResources");
	//Path.MoveParent();
	//Result = Path.IsExistsToPlusString("\\ContentsResources");
	//Path.MoveParent();


	// �������� �͵��� ����� ������ Loading�����Դϴ�.
	//CreateActor<Isaac>();
}

void IsaacPlay::Update()
{

}
