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
		
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("bglight.BMP"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Loading_01_isaac.BMP"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("LoadingBubble1.BMP"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("LoadingBubble2.BMP"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("LoadingBubble3.BMP"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("LoadingMap.BMP"))->Cut(4, 6);
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("nightmare_5_1.BMP"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("nightmare_5_2.BMP"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("nightmare_5_3.BMP"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("nightmare_5_4.BMP"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("nightmare_5_7.BMP"));

	}

	AllBack* Render = CreateActor<AllBack>();
	BackGround = Render->CreateRender("bglight.BMP", NextLevelOrder::BackGround);

	Isaac_NextLevel = Render->CreateRender("Loading_01_isaac.BMP", NextLevelOrder::BackGround);
	Isaac_NextLevel->SetScaleToImage();
	Isaac_NextLevel->SetPosition({ 0,200 });

	Balloon1 = Render->CreateRender("LoadingBubble1.BMP", NextLevelOrder::Balloon);
	Balloon1->SetScaleToImage();
	Balloon1->SetPosition({ -50,150 });
	Balloon1->Off();

	Balloon2 = Render->CreateRender("LoadingBubble2.BMP", NextLevelOrder::Balloon);
	Balloon2->SetScaleToImage();
	Balloon2->SetPosition({ -120,120 });
	Balloon2->Off();


	Balloon3 = Render->CreateRender("LoadingBubble3.BMP", NextLevelOrder::BackGround);
	Balloon3->SetScaleToImage();
	Balloon3->SetPosition({ 0,-50 });
	Balloon3->Off();


	Box1 = Render->CreateRender("LoadingMap.BMP", NextLevelOrder::Balloon);
	Box1->CreateAnimation({ .AnimationName = "Idle",  .ImageName = "LoadingMap.bmp", .Start = 8, .End = 8 , .InterTime = 0.1f });
	Box1->SetScale({100,100});
	Box1->ChangeAnimation("Idle");
	Box1->SetPosition({ -100,-300 });

	Box2 = Render->CreateRender("LoadingMap.BMP", NextLevelOrder::Balloon);
	Box2->CreateAnimation({ .AnimationName = "Idle",  .ImageName = "LoadingMap.bmp", .Start = 12, .End = 12 , .InterTime = 0.1f });
	Box2->SetScale({ 100,100 });
	Box2->ChangeAnimation("Idle");
	Box2->SetPosition({ 0,-300 });

	Box3 = Render->CreateRender("LoadingMap.BMP", NextLevelOrder::Balloon);
	Box3->CreateAnimation({ .AnimationName = "Idle",  .ImageName = "LoadingMap.bmp", .Start = 6, .End = 6 , .InterTime = 0.1f });
	Box3->SetScale({ 100,100 });
	Box3->ChangeAnimation("Idle");
	Box3->SetPosition({ 100,-270 });

	Line1 = Render->CreateRender("LoadingMap.BMP", NextLevelOrder::BackGround);
	Line1->CreateAnimation({ .AnimationName = "Idle",  .ImageName = "LoadingMap.bmp", .Start = 4, .End = 4 , .InterTime = 0.1f });
	Line1->SetScale({ 100,100 });
	Line1->ChangeAnimation("Idle");
	Line1->SetPosition({ -50,-295 });

	MiniIsaac = Render->CreateRender("LoadingMap.BMP", NextLevelOrder::Balloon);
	MiniIsaac->CreateAnimation({ .AnimationName = "Idle",  .ImageName = "LoadingMap.bmp", .Start = 5, .End = 5 , .InterTime = 0.1f });
	MiniIsaac->SetScale({ 100,100 });
	MiniIsaac->ChangeAnimation("Idle");
	MiniIsaac->SetPosition({ -100,-300 });
	

	BalloonBack = Render->CreateRender("nightmare_5_1.BMP", NextLevelOrder::BalloonBack);
	BalloonBack->SetScaleToImage();
	BalloonBack->SetPosition({ 0,-50 });
	BalloonBack->Off();

	HappyIsaac = Render->CreateRender("nightmare_5_2.BMP", NextLevelOrder::Animation);
	HappyIsaac->SetScaleToImage();
	HappyIsaac->SetPosition({ 30,-10 });
	HappyIsaac->Off();

	DamagedIsaac = Render->CreateRender("nightmare_5_3.BMP", NextLevelOrder::Animation);
	DamagedIsaac->SetScaleToImage();
	DamagedIsaac->SetPosition({ 70,-10 });
	DamagedIsaac->Off();

	SickIsaac = Render->CreateRender("nightmare_5_4.BMP", NextLevelOrder::Animation);
	SickIsaac->SetScaleToImage();
	SickIsaac->SetPosition({ 100,20 });
	SickIsaac->Off();

	ThrowBall = Render->CreateRender("nightmare_5_7.BMP", NextLevelOrder::Animation);
	ThrowBall->SetScaleToImage();
	ThrowBall->SetPosition({ -300,-40 });
	ThrowBall->Off();



}
void NextLevelLoding::Update(float _DeltaTime)
{
	NowTime += _DeltaTime;

	float4 MiniIsaacPos = float4{ -100,-300 }+ float4::Right * 60.f * NowTime;
	MiniIsaac->SetPosition(MiniIsaacPos);
	if (MiniIsaacPos.x >= 0)
	{
		MiniIsaac->SetPosition(float4{0,-300} + float4::Zero);
	}
	
	if (NowTime > 0.3f)
	{
		Balloon1->On();
	}
	if (NowTime > 0.6f)
	{
		Balloon2->On();
	}
	if (NowTime > 0.9f)
	{
		Balloon3->On();
	}
	if (NowTime > 1.0f)
	{
		BalloonBack->On();
		HappyIsaac->On();
		ThrowBall->On();

		float4 ThrowBallPos = float4{ -300,-40 } + float4::Right * 200.f * NowTime;
		ThrowBall->SetPosition(ThrowBallPos);
		if (ThrowBallPos.x >= -60.0f)
		{
			float4 ThrowBallPos =((float4::Left * 50.f) +(float4::Up*50))* 2*NowTime;
			ThrowBall->SetPosition( ThrowBallPos);
		}
	}
	if (NowTime > 1.35f)
	{
		HappyIsaac->Off();
		DamagedIsaac->On();
	}
	if (NowTime > 1.6f)
	{
		DamagedIsaac->Off();
		SickIsaac->On();
		ThrowBall->Off();
	}
	if (NowTime > 2.5f)
	{
		GameEngineCore::GetInst()->ChangeLevel("PlayIsaac");
	}
}
