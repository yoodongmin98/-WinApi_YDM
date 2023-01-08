#include "Isaac.h"
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineBase/GameEnginePath.h>

Isaac::Isaac()
{
}

Isaac::~Isaac()
{
}

void Isaac::Start()
{
	SetMove(GameEngineWindow::GetScreenSize().half());
}

void Isaac::Update() //위치 업데이트
{
	SetMove(float4::Left * 0.0001f);
}

void Isaac::Render()
{
	float4 PlayerPos = GetPos();

	//GameEnginePath Path;

	//std::string PathText = Path.GetPathToString();

	// TextOutA(GameEngineWindow::GetDrawHdc(), 0, 0, PathText.c_str(), PathText.size());


	Rectangle(
		GameEngineWindow::GetDrawHdc(),
		PlayerPos.ix() - 50,
		PlayerPos.iy() - 50,
		PlayerPos.ix() + 50,
		PlayerPos.iy() + 50
	);

}