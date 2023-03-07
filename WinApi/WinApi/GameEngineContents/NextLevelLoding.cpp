#include "NextLevelLoding.h"

#include "AllBack.h"
#include "IsaacEnum.h"

#include <GameEngineBase/GameEngineDirectory.h>

#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEnginePlatform/GameEngineWindow.h>


#include <GameEngineCore/GameEngineCore.h>
#include <GameEngineCore/GameEngineRender.h>






NextLevelLoding::NextLevelLoding()
{

}
NextLevelLoding::~NextLevelLoding()
{

}
///////////////////////////사운드관련///////////////////
//void NextLevelLoding::SoundLoad()
//{
//	GameEngineDirectory Dir;
//	Dir.MoveParentToDirectory("ContentsResources");
//	Dir.Move("ContentsResources");
//	Dir.Move("Sound");
//	{
//		GameEngineResources::GetInst().SoundLoad(Dir.GetPlusFileName("castleportcullis.wav"));
//	}
//}
//void NextLevelLoding::LevelChangeStart(GameEngineLevel* _PrevLevel)
//{
//	NextLevelLodingSOUND = GameEngineResources::GetInst().SoundPlayToControl("castleportcullis.wav");
//	NextLevelLodingSOUND.LoopCount(1);
//	NextLevelLodingSOUND.Volume(0.1f);
//}

//////////////////////////////////////////////////////

void NextLevelLoding::Loading()
{
	//SoundLoad();
	GameEngineDirectory Dir;
	Dir.MoveParentToDirectory("ContentsResources");
	Dir.Move("ContentsResources");
	Dir.Move("Image");
	Dir.Move("NextLevelLoading");

	//이미지로드
	{
		
	

	}

	AllBack* Render = CreateActor<AllBack>();
	BackGround = Render->CreateRender("bgblack.BMP", NextLevelOrder::BackGround);

}
void NextLevelLoding::Update(float _DeltaTime)
{
	NowTime += _DeltaTime;


	if (10.0f < NowTime)
	{
		GameEngineCore::GetInst()->ChangeLevel("PlayIsaac");
	}
}
