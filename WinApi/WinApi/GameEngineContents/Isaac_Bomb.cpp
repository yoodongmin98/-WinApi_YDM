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

// 시작하기전에 뭔가 준비해야할것이 있으면 여기서 해라.
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
// 키입력을 받거나 인공지능을 점수를 계산하거나 하는 것들을 여기서 처리
void Isaac_Bomb::Update(float _DeltaTime)
{
	/*if (true == GameEngineInput::IsKey("Bomb"))
	{
		Bomb->On();
	}*/
}

// 순서를 제어 함수를 한번 더실행하고 
void Isaac_Bomb::LateUpdate(float _DeltaTime)
{

}

// 화면에 그려지는 기능들을 여기서 처리
void Isaac_Bomb::Render(float _DeltaTime)
{

}

