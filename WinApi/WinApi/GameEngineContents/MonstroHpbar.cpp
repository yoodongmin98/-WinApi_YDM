#include "MonstroHpBar.h"

#include <GameEngineBase/GameEngineDirectory.h>

#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEnginePlatform/GameEngineInput.h>


#include <GameEngineCore/GameEngineResources.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineRender.h>

#include "IsaacEnum.h"

#include "Monstro.h"

BossHpbar::BossHpbar()
{
}

BossHpbar::~BossHpbar()
{
}
void BossHpbar::ImageLoad()
{
	GameEngineDirectory Dir;
	Dir.MoveParentToDirectory("ContentsResources");
	Dir.Move("ContentsResources");
	Dir.Move("Image");
	Dir.Move("Play");
	Dir.Move("BossMonster");

	GameEngineImage* LoadHpbar=GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("bosshealthbar.BMP"));
	LoadHpbar->Cut(1,2);
	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("bosshealthbar2.BMP"));

}
bool BossHpbarbool = true;
void BossHpbar::Start()
{
	if (true == BossHpbarbool)
	{
		ImageLoad();
		BossHpbarbool = false;
	}
	BossHpbarRender100 = CreateRender(IsaacOrder::R_Menu);
	BossHpbarRender100->CreateAnimation({ .AnimationName = "EmptyHpBar",  .ImageName = "bosshealthbar.bmp", .Start = 1, .End = 1 });
	BossHpbarRender100->SetScale({ 450, 96 });
	BossHpbarRender100->ChangeAnimation("EmptyHpBar");

	BossHpbarBackRender100 = CreateRender("bosshealthbar2.BMP",IsaacOrder::R_Menu);
	BossHpbarBackRender100->SetScale({ 330, 96 });
	BossHpbarBackRender100->SetPosition({ 5,0 });
	
}

void BossHpbar::Update(float _DeltaTime)
{
	GetandSetMonstroHP();
	BossHpbarRender(MonstroHp);
}


void BossHpbar::GetandSetMonstroHP()
{
	MonstroHp = Monstro::MainMonstro->GetMonstroHp();
}

void BossHpbar::BossHpbarRender(int _Hp)
{
	if (MonstroHp == 32)
	{
		BossHpbarBackRender100->SetScale({ 320, 96 });
		BossHpbarBackRender100->SetPosition({ -5+4,0 });
	}
	if (MonstroHp == 31)
	{
		BossHpbarBackRender100->SetScale({ 310, 96 });
		BossHpbarBackRender100->SetPosition({ -10 + 4,0 });
	}
	if (MonstroHp == 30)
	{
		BossHpbarBackRender100->SetScale({ 300, 96 });
		BossHpbarBackRender100->SetPosition({ -15 + 4,0 });
	}
	if (MonstroHp == 29)
	{
		BossHpbarBackRender100->SetScale({ 290, 96 });
		BossHpbarBackRender100->SetPosition({ -20 + 4,0 });
	}
	if (MonstroHp == 28)
	{
		BossHpbarBackRender100->SetScale({ 280, 96 });
		BossHpbarBackRender100->SetPosition({ -25 + 4,0 });
	}
	if (MonstroHp == 27)
	{
		BossHpbarBackRender100->SetScale({ 270, 96 });
		BossHpbarBackRender100->SetPosition({ -30 + 4,0 });
	}
	if (MonstroHp == 26)
	{
		BossHpbarBackRender100->SetScale({ 260, 96 });
		BossHpbarBackRender100->SetPosition({ -35 + 4,0 });
	}
	if (MonstroHp == 25)
	{
		BossHpbarBackRender100->SetScale({ 250, 96 });
		BossHpbarBackRender100->SetPosition({ -40 + 4,0 });
	}
	if (MonstroHp == 24)
	{
		BossHpbarBackRender100->SetScale({ 240, 96 });
		BossHpbarBackRender100->SetPosition({ -45 + 4,0 });
	}
	if (MonstroHp == 23)
	{
		BossHpbarBackRender100->SetScale({ 230, 96 });
		BossHpbarBackRender100->SetPosition({ -50 + 4,0 });
	}
	if (MonstroHp == 22)
	{
		BossHpbarBackRender100->SetScale({ 220, 96 });
		BossHpbarBackRender100->SetPosition({ -55 + 4,0 });
	}
	if (MonstroHp == 21)
	{
		BossHpbarBackRender100->SetScale({ 210, 96 });
		BossHpbarBackRender100->SetPosition({ -60 + 4,0 });
	}
	if (MonstroHp == 20)
	{
		BossHpbarBackRender100->SetScale({ 200, 96 });
		BossHpbarBackRender100->SetPosition({ -65 + 4,0 });
	}
	if (MonstroHp == 19)
	{
		BossHpbarBackRender100->SetScale({ 190, 96 });
		BossHpbarBackRender100->SetPosition({ -70 + 4,0 });
	}
	if (MonstroHp == 18)
	{
		BossHpbarBackRender100->SetScale({ 180, 96 });
		BossHpbarBackRender100->SetPosition({ -75 + 4,0 });
	}
	if (MonstroHp == 17)
	{
		BossHpbarBackRender100->SetScale({ 170, 96 });
		BossHpbarBackRender100->SetPosition({ -80 + 4,0 });
	}
	if (MonstroHp == 16)
	{
		BossHpbarBackRender100->SetScale({ 160, 96 });
		BossHpbarBackRender100->SetPosition({ -85 + 4,0 });
	}
	if (MonstroHp == 15)
	{
		BossHpbarBackRender100->SetScale({ 150, 96 });
		BossHpbarBackRender100->SetPosition({ -90 + 4,0 });
	}
	if (MonstroHp == 14)
	{
		BossHpbarBackRender100->SetScale({ 140, 96 });
		BossHpbarBackRender100->SetPosition({ -95 + 4,0 });
	}
	if (MonstroHp == 13)
	{
		BossHpbarBackRender100->SetScale({ 130, 96 });
		BossHpbarBackRender100->SetPosition({ -100 + 4,0 });
	}
	if (MonstroHp == 12)
	{
		BossHpbarBackRender100->SetScale({ 120, 96 });
		BossHpbarBackRender100->SetPosition({ -105 + 4,0 });
	}
	if (MonstroHp == 11)
	{
		BossHpbarBackRender100->SetScale({ 110, 96 });
		BossHpbarBackRender100->SetPosition({ -110 + 4,0 });
	}
	if (MonstroHp == 10)
	{
		BossHpbarBackRender100->SetScale({ 100, 96 });
		BossHpbarBackRender100->SetPosition({ -115 + 4,0 });
	}
	if (MonstroHp == 9)
	{
		BossHpbarBackRender100->SetScale({ 90, 96 });
		BossHpbarBackRender100->SetPosition({ -120 + 4,0 });
	}
	if (MonstroHp == 8)
	{
		BossHpbarBackRender100->SetScale({ 80, 96 });
		BossHpbarBackRender100->SetPosition({ -125 + 4,0 });
	}
	if (MonstroHp == 7)
	{
		BossHpbarBackRender100->SetScale({ 70, 96 });
		BossHpbarBackRender100->SetPosition({ -130 + 4,0 });
	}
	if (MonstroHp == 6)
	{
		BossHpbarBackRender100->SetScale({ 60, 96 });
		BossHpbarBackRender100->SetPosition({ -135 + 4,0 });
	}
	if (MonstroHp == 5)
	{
		BossHpbarBackRender100->SetScale({ 50, 96 });
		BossHpbarBackRender100->SetPosition({ -140 + 4,0 });
	}
	if (MonstroHp == 4)
	{
		BossHpbarBackRender100->SetScale({ 40, 96 });
		BossHpbarBackRender100->SetPosition({ -145 + 4,0 });
	}
	if (MonstroHp == 3)
	{
		BossHpbarBackRender100->SetScale({ 30, 96 });
		BossHpbarBackRender100->SetPosition({ -150 + 4,0 });
	}
	if (MonstroHp == 2)
	{
		BossHpbarBackRender100->SetScale({ 20, 96 });
		BossHpbarBackRender100->SetPosition({ -155 + 4,0 });
	}
	if (MonstroHp == 1)
	{
		BossHpbarBackRender100->SetScale({ 10, 96 });
		BossHpbarBackRender100->SetPosition({ -160 + 4,0 });
	}
	if (MonstroHp <= 0)
	{
		BossHpbarRender100->Death();
		BossHpbarBackRender100->Death();

	}
}