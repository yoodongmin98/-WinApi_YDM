#include "LoadLevel.h"

#include "AllBack.h"
#include "IsaacEnum.h"

#include <GameEngineBase/GameEngineDirectory.h>

#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEnginePlatform/GameEngineWindow.h>


#include <GameEngineCore/GameEngineCore.h>






LoadLevel::LoadLevel()
{

}
LoadLevel::~LoadLevel()
{

}

void LoadLevel::SoundLoad()
{
	GameEngineDirectory Dir;
	Dir.MoveParentToDirectory("ContentsResources");
	Dir.Move("ContentsResources");
	Dir.Move("Sound");
	{
		GameEngineResources::GetInst().SoundLoad(Dir.GetPlusFileName("Loading.ogg"));
	}
	

}
void LoadLevel::Loading()
{
	SoundLoad();
	GameEngineDirectory Dir;
	Dir.MoveParentToDirectory("ContentsResources");
	Dir.Move("ContentsResources");
	Dir.Move("Image");
	Dir.Move("Loading");

	//이미지로드
	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("TitleLoading_Isaac.BMP"));

	AllBack* Render = CreateActor<AllBack>();
	LoadIsaac=Render->CreateRender("TitleLoading_Isaac.BMP", IsaacOrder::BackGround);


}
void LoadLevel::Update(float _DeltaTime)
{
	
	NowTime += _DeltaTime;

	if (NextLevelTime < NowTime)
	{
		GameEngineCore::GetInst()->ChangeLevel("PlayIsaac");
	}
}
void LoadLevel::LevelChangeStart(GameEngineLevel* _PrevLevel)
{
	LODINGSOUND= GameEngineResources::GetInst().SoundPlayToControl("Loading.ogg");
	LODINGSOUND.LoopCount(1);
	LODINGSOUND.Volume(0.2);
}