//#include "BossLoding.h"
//
//#include "AllBack.h"
//#include "IsaacEnum.h"
//
//#include <GameEngineBase/GameEngineDirectory.h>
//
//#include <GameEnginePlatform/GameEngineInput.h>
//#include <GameEnginePlatform/GameEngineWindow.h>
//
//
//#include <GameEngineCore/GameEngineCore.h>
//
//
//
//
//
//
//BossLoadLevel::BossLoadLevel()
//{
//
//}
//BossLoadLevel::~BossLoadLevel()
//{
//
//}
/////////////////////////////사운드관련///////////////////
////void BossLoadLevel::SoundLoad()
////{
////	GameEngineDirectory Dir;
////	Dir.MoveParentToDirectory("ContentsResources");
////	Dir.Move("ContentsResources");
////	Dir.Move("Sound");
////	{
////		GameEngineResources::GetInst().SoundLoad(Dir.GetPlusFileName("Loading.ogg"));
////	}
////}
////void BossLoadLevel::LevelChangeStart(GameEngineLevel* _PrevLevel)
////{
////	LODINGSOUND = GameEngineResources::GetInst().SoundPlayToControl("Loading.ogg");
////	LODINGSOUND.LoopCount(1);
////	LODINGSOUND.Volume(0.2f);
////}
//
////////////////////////////////////////////////////////
//
//void BossLoadLevel::Loading()
//{
//	//SoundLoad();
//	GameEngineDirectory Dir;
//	Dir.MoveParentToDirectory("ContentsResources");
//	Dir.Move("ContentsResources");
//	Dir.Move("Image");
//	Dir.Move("Loading");
//
//	//이미지로드
//	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("TitleLoading_Isaac.BMP"));
//
//	AllBack* Render = CreateActor<AllBack>();
//	BackGround = Render->CreateRender("TitleLoading_Isaac.BMP", BossLoadOrder::BackGround);
//
//
//}
//void BossLoadLevel::Update(float _DeltaTime)
//{
//
//	NowTime += _DeltaTime;
//
//	if (3.0f < NowTime)
//	{
//		GameEngineCore::GetInst()->ChangeLevel("PlayIsaac");
//	}
//}
