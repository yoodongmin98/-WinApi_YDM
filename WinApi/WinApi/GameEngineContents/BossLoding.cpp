#include "BossLoding.h"

#include "AllBack.h"
#include "IsaacEnum.h"

#include <GameEngineBase/GameEngineDirectory.h>

#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEnginePlatform/GameEngineWindow.h>


#include <GameEngineCore/GameEngineCore.h>
#include <GameEngineCore/GameEngineRender.h>






BossLoadLevel::BossLoadLevel()
{

}
BossLoadLevel::~BossLoadLevel()
{

}
///////////////////////////사운드관련///////////////////
void BossLoadLevel::SoundLoad()
{
	GameEngineDirectory Dir;
	Dir.MoveParentToDirectory("ContentsResources");
	Dir.Move("ContentsResources");
	Dir.Move("Sound");
	{
		GameEngineResources::GetInst().SoundLoad(Dir.GetPlusFileName("castleportcullis.wav"));
	}
}
void BossLoadLevel::LevelChangeStart(GameEngineLevel* _PrevLevel)
{
	BOSSLODINGSOUND = GameEngineResources::GetInst().SoundPlayToControl("castleportcullis.wav");
	BOSSLODINGSOUND.LoopCount(1);
	BOSSLODINGSOUND.Volume(0.1f);
}

//////////////////////////////////////////////////////

void BossLoadLevel::Loading()
{
	SoundLoad();
	GameEngineDirectory Dir;
	Dir.MoveParentToDirectory("ContentsResources");
	Dir.Move("ContentsResources");
	Dir.Move("Image");
	Dir.Move("Play");
	Dir.Move("BossLoad");

	//이미지로드
	{
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("bgblack.BMP"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("CryIsaac.BMP"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Isaac.BMP"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Monstro.BMP"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("vs.BMP"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Monstro_M.BMP"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Basement.BMP"));

	}

	AllBack* Render = CreateActor<AllBack>();
	BackGround = Render->CreateRender("bgblack.BMP", BossLoadOrder::BackGround);

	CryIsaac = Render->CreateRender("CryIsaac.bmp",BossLoadOrder::Animation);
	CryIsaac->SetScale({300,220});
	CryIsaac->SetPosition({-850,100});

	Monstro = Render->CreateRender("Monstro_M.bmp", BossLoadOrder::Animation);
	Monstro->SetScale({ 600,500 });
	Monstro->SetPosition({ 850,100 });

	fontIsaac=Render->CreateRender("Isaac.bmp", BossLoadOrder::Animation);
	fontIsaac->SetScale({ 550,220 });
	fontIsaac->SetPosition({ -850,-250 });

	fontMonstro = Render->CreateRender("Monstro.bmp", BossLoadOrder::Animation);
	fontMonstro->SetScale({ 550,220 });
	fontMonstro->SetPosition({ 900,-250 });

	vs = Render->CreateRender("vs.bmp", BossLoadOrder::Animation);
	vs->SetScale({ 400,200 });
	vs->SetPosition({ -20,-250 });
	vs->Off();

	IsaacGround = Render->CreateRender("Basement.bmp", BossLoadOrder::Ground);
	IsaacGround->SetScale({ 500,150 });
	IsaacGround->SetPosition({ -850,200 });

	MonstroGround = Render->CreateRender("Basement.bmp", BossLoadOrder::Ground);
	MonstroGround->SetScale({ 730,180 });
	MonstroGround->SetPosition({ 850,220 });
	


}
void BossLoadLevel::Update(float _DeltaTime)
{
	float4 CryIsaacPos = CryIsaac->GetPosition();
	float4 fontIsaacPos = fontIsaac->GetPosition();
	float4 IsaacGroundPos = IsaacGround->GetPosition();
	CryIsaacPos += float4::Right * 15.0f * NowTime;
	fontIsaacPos += float4::Right * 15.0f * NowTime;
	IsaacGroundPos += float4::Right * 15.0f * NowTime;
	if (CryIsaacPos.x >= -350.0f)
	{
		CryIsaacPos = CryIsaac->GetPosition();
		fontIsaacPos = fontIsaac->GetPosition();
		IsaacGroundPos = IsaacGround->GetPosition();
	}
	CryIsaac->SetPosition(CryIsaacPos);
	fontIsaac->SetPosition(fontIsaacPos);
	IsaacGround->SetPosition(IsaacGroundPos);

	//////////Right
	float4 MonstroPos = Monstro->GetPosition();
	float4 fontMonstroPos = fontMonstro->GetPosition();
	float4 MonstroGroundPos = MonstroGround->GetPosition();
	MonstroPos += float4::Left * 15.0f * NowTime;
	fontMonstroPos += float4::Left * 15.0f * NowTime;
	MonstroGroundPos += float4::Left * 15.0f * NowTime;
	if (MonstroPos.x <= 350.0f)
	{
		MonstroPos = Monstro->GetPosition();
		fontMonstroPos = fontMonstro->GetPosition();
		MonstroGroundPos = MonstroGround->GetPosition();
	}
	Monstro->SetPosition(MonstroPos);
	fontMonstro->SetPosition(fontMonstroPos);
	MonstroGround->SetPosition(MonstroGroundPos);

	NowTime += _DeltaTime;
	if (0.65f < NowTime)
	{
		vs->On();
	}

	if (2.0f < NowTime)
	{
		GameEngineCore::GetInst()->ChangeLevel("PlayIsaac");
	}
}
