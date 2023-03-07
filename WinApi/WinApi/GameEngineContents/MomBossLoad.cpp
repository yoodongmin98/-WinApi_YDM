#include "MomBossLoad.h"

#include "AllBack.h"
#include "IsaacEnum.h"

#include <GameEngineBase/GameEngineDirectory.h>

#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEnginePlatform/GameEngineWindow.h>


#include <GameEngineCore/GameEngineCore.h>
#include <GameEngineCore/GameEngineRender.h>






MomBossLoadLevel::MomBossLoadLevel()
{

}
MomBossLoadLevel::~MomBossLoadLevel()
{

}
///////////////////////////사운드관련///////////////////
void MomBossLoadLevel::SoundLoad()
{
	GameEngineDirectory Dir;
	Dir.MoveParentToDirectory("ContentsResources");
	Dir.Move("ContentsResources");
	Dir.Move("Sound");
	{
		GameEngineResources::GetInst().SoundLoad(Dir.GetPlusFileName("castleportcullis.wav"));
	}
}
void MomBossLoadLevel::LevelChangeStart(GameEngineLevel* _PrevLevel)
{
	Mom_BOSSLODINGSOUND = GameEngineResources::GetInst().SoundPlayToControl("castleportcullis.wav");
	Mom_BOSSLODINGSOUND.LoopCount(1);
	Mom_BOSSLODINGSOUND.Volume(0.1f);
}

//////////////////////////////////////////////////////

void MomBossLoadLevel::Loading()
{
	//SoundLoad();
	GameEngineDirectory Dir;
	Dir.MoveParentToDirectory("ContentsResources");
	Dir.Move("ContentsResources");
	Dir.Move("Image");
	Dir.Move("Play");
	Dir.Move("BossLoad");

	//이미지로드
	{
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Mom.BMP"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Mom_M.BMP"));
	}

	AllBack* Render = CreateActor<AllBack>();
	Mom_BackGround = Render->CreateRender("bgblack.BMP", MomBossLoadOrder::BackGround);

	Mom_CryIsaac = Render->CreateRender("CryIsaac.bmp", MomBossLoadOrder::Animation);
	Mom_CryIsaac->SetScale({ 300,220 });
	Mom_CryIsaac->SetPosition({ -850,100 });

	Mom_Monstro = Render->CreateRender("Mom_M.bmp", MomBossLoadOrder::Animation);
	Mom_Monstro->SetScale({ 600,500 });
	Mom_Monstro->SetPosition({ 870,50 });

	Mom_fontIsaac = Render->CreateRender("Isaac.bmp", MomBossLoadOrder::Animation);
	Mom_fontIsaac->SetScale({ 550,220 });
	Mom_fontIsaac->SetPosition({ -850,-250 });

	Mom_fontMonstro = Render->CreateRender("Mom.bmp", MomBossLoadOrder::Animation);
	Mom_fontMonstro->SetScale({ 550,220 });
	Mom_fontMonstro->SetPosition({ 900,-250 });

	Mom_vs = Render->CreateRender("vs.bmp", MomBossLoadOrder::Animation);
	Mom_vs->SetScale({ 400,200 });
	Mom_vs->SetPosition({ -20,-250 });
	Mom_vs->Off();

	Mom_IsaacGround = Render->CreateRender("Basement.bmp", MomBossLoadOrder::Ground);
	Mom_IsaacGround->SetScale({ 500,150 });
	Mom_IsaacGround->SetPosition({ -850,200 });

	Mom_MonstroGround = Render->CreateRender("Basement.bmp", MomBossLoadOrder::Ground);
	Mom_MonstroGround->SetScale({ 730,180 });
	Mom_MonstroGround->SetPosition({ 850,220 });



}
void MomBossLoadLevel::Update(float _DeltaTime)
{
	float4 CryIsaacPos = Mom_CryIsaac->GetPosition();
	float4 fontIsaacPos = Mom_fontIsaac->GetPosition();
	float4 IsaacGroundPos = Mom_IsaacGround->GetPosition();
	CryIsaacPos += float4::Right * 15.0f * NowTime;
	fontIsaacPos += float4::Right * 15.0f * NowTime;
	IsaacGroundPos += float4::Right * 15.0f * NowTime;
	if (CryIsaacPos.x >= -350.0f)
	{
		CryIsaacPos = Mom_CryIsaac->GetPosition();
		fontIsaacPos = Mom_fontIsaac->GetPosition();
		IsaacGroundPos = Mom_IsaacGround->GetPosition();
	}
	Mom_CryIsaac->SetPosition(CryIsaacPos);
	Mom_fontIsaac->SetPosition(fontIsaacPos);
	Mom_IsaacGround->SetPosition(IsaacGroundPos);

	//////////Right
	float4 MonstroPos = Mom_Monstro->GetPosition();
	float4 fontMonstroPos = Mom_fontMonstro->GetPosition();
	float4 MonstroGroundPos = Mom_MonstroGround->GetPosition();
	MonstroPos += float4::Left * 15.0f * NowTime;
	fontMonstroPos += float4::Left * 15.0f * NowTime;
	MonstroGroundPos += float4::Left * 15.0f * NowTime;
	if (MonstroPos.x <= 350.0f)
	{
		MonstroPos = Mom_Monstro->GetPosition();
		fontMonstroPos = Mom_fontMonstro->GetPosition();
		MonstroGroundPos = Mom_MonstroGround->GetPosition();
	}
	Mom_Monstro->SetPosition(MonstroPos);
	Mom_fontMonstro->SetPosition(fontMonstroPos);
	Mom_MonstroGround->SetPosition(MonstroGroundPos);

	NowTime += _DeltaTime;
	if (0.65f < NowTime)
	{
		Mom_vs->On();
	}

	if (2.0f < NowTime)
	{
		GameEngineCore::GetInst()->ChangeLevel("PlayIsaac");
	}
}
