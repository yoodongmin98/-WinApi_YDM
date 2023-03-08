#include "MomsHeartHpbar.h"

#include <GameEngineBase/GameEngineDirectory.h>

#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEnginePlatform/GameEngineInput.h>


#include <GameEngineCore/GameEngineResources.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineRender.h>

#include "IsaacEnum.h"

#include "MomsHeart.h"

MomsHpbar::MomsHpbar()
{
}

MomsHpbar::~MomsHpbar()
{
}


void MomsHpbar::Start()
{
	
	BossHpbarRender1000 = CreateRender(IsaacOrder::R_Menu);
	BossHpbarRender1000->CreateAnimation({ .AnimationName = "EmptyHpBar",  .ImageName = "bosshealthbar.bmp", .Start = 1, .End = 1 });
	BossHpbarRender1000->SetScale({ 450, 96 });
	BossHpbarRender1000->ChangeAnimation("EmptyHpBar");

	BossHpbarBackRender1000 = CreateRender("bosshealthbar2.BMP", IsaacOrder::R_Menu);
	BossHpbarBackRender1000->SetScale({ 330, 96 });
	BossHpbarBackRender1000->SetPosition({ 5,0 });

}

void MomsHpbar::Update(float _DeltaTime)
{
	GetandSetMomsHP();
	BossHpbarRender(MomsHp);
}


void MomsHpbar::GetandSetMomsHP()
{
	MomsHp = MomsHeart::MainMomsHeart->GetMomsHeartHp();
}

void MomsHpbar::BossHpbarRender(int _Hp)
{
	if (MomsHp == 64)
	{
		BossHpbarBackRender1000->SetScale({ 320, 96 });
		BossHpbarBackRender1000->SetPosition({ -5 + 4,0 });
	}
	if (MomsHp == 62)
	{
		BossHpbarBackRender1000->SetScale({ 310, 96 });
		BossHpbarBackRender1000->SetPosition({ -10 + 4,0 });
	}
	if (MomsHp == 60)
	{
		BossHpbarBackRender1000->SetScale({ 300, 96 });
		BossHpbarBackRender1000->SetPosition({ -15 + 4,0 });
	}
	if (MomsHp == 58)
	{
		BossHpbarBackRender1000->SetScale({ 290, 96 });
		BossHpbarBackRender1000->SetPosition({ -20 + 4,0 });
	}
	if (MomsHp == 56)
	{
		BossHpbarBackRender1000->SetScale({ 280, 96 });
		BossHpbarBackRender1000->SetPosition({ -25 + 4,0 });
	}
	if (MomsHp == 54)
	{
		BossHpbarBackRender1000->SetScale({ 270, 96 });
		BossHpbarBackRender1000->SetPosition({ -30 + 4,0 });
	}
	if (MomsHp == 52)
	{
		BossHpbarBackRender1000->SetScale({ 260, 96 });
		BossHpbarBackRender1000->SetPosition({ -35 + 4,0 });
	}
	if (MomsHp == 50)
	{
		BossHpbarBackRender1000->SetScale({ 250, 96 });
		BossHpbarBackRender1000->SetPosition({ -40 + 4,0 });
	}
	if (MomsHp == 48)
	{
		BossHpbarBackRender1000->SetScale({ 240, 96 });
		BossHpbarBackRender1000->SetPosition({ -45 + 4,0 });
	}
	if (MomsHp == 46)
	{
		BossHpbarBackRender1000->SetScale({ 230, 96 });
		BossHpbarBackRender1000->SetPosition({ -50 + 4,0 });
	}
	if (MomsHp == 44)
	{
		BossHpbarBackRender1000->SetScale({ 220, 96 });
		BossHpbarBackRender1000->SetPosition({ -55 + 4,0 });
	}
	if (MomsHp == 42)
	{
		BossHpbarBackRender1000->SetScale({ 210, 96 });
		BossHpbarBackRender1000->SetPosition({ -60 + 4,0 });
	}
	if (MomsHp == 40)
	{
		BossHpbarBackRender1000->SetScale({ 200, 96 });
		BossHpbarBackRender1000->SetPosition({ -65 + 4,0 });
	}
	if (MomsHp == 38)
	{
		BossHpbarBackRender1000->SetScale({ 190, 96 });
		BossHpbarBackRender1000->SetPosition({ -70 + 4,0 });
	}
	if (MomsHp == 36)
	{
		BossHpbarBackRender1000->SetScale({ 180, 96 });
		BossHpbarBackRender1000->SetPosition({ -75 + 4,0 });
	}
	if (MomsHp == 34)
	{
		BossHpbarBackRender1000->SetScale({ 170, 96 });
		BossHpbarBackRender1000->SetPosition({ -80 + 4,0 });
	}
	if (MomsHp == 32)
	{
		BossHpbarBackRender1000->SetScale({ 160, 96 });
		BossHpbarBackRender1000->SetPosition({ -85 + 4,0 });
	}
	if (MomsHp == 30)
	{
		BossHpbarBackRender1000->SetScale({ 150, 96 });
		BossHpbarBackRender1000->SetPosition({ -90 + 4,0 });
	}
	if (MomsHp == 28)
	{
		BossHpbarBackRender1000->SetScale({ 140, 96 });
		BossHpbarBackRender1000->SetPosition({ -95 + 4,0 });
	}
	if (MomsHp == 26)
	{
		BossHpbarBackRender1000->SetScale({ 130, 96 });
		BossHpbarBackRender1000->SetPosition({ -100 + 4,0 });
	}
	if (MomsHp == 24)
	{
		BossHpbarBackRender1000->SetScale({ 120, 96 });
		BossHpbarBackRender1000->SetPosition({ -105 + 4,0 });
	}
	if (MomsHp == 22)
	{
		BossHpbarBackRender1000->SetScale({ 110, 96 });
		BossHpbarBackRender1000->SetPosition({ -110 + 4,0 });
	}
	if (MomsHp == 20)
	{
		BossHpbarBackRender1000->SetScale({ 100, 96 });
		BossHpbarBackRender1000->SetPosition({ -115 + 4,0 });
	}
	if (MomsHp == 18)
	{
		BossHpbarBackRender1000->SetScale({ 90, 96 });
		BossHpbarBackRender1000->SetPosition({ -120 + 4,0 });
	}
	if (MomsHp == 16)
	{
		BossHpbarBackRender1000->SetScale({ 80, 96 });
		BossHpbarBackRender1000->SetPosition({ -125 + 4,0 });
	}
	if (MomsHp == 14)
	{
		BossHpbarBackRender1000->SetScale({ 70, 96 });
		BossHpbarBackRender1000->SetPosition({ -130 + 4,0 });
	}
	if (MomsHp == 12)
	{
		BossHpbarBackRender1000->SetScale({ 60, 96 });
		BossHpbarBackRender1000->SetPosition({ -135 + 4,0 });
	}
	if (MomsHp == 10)
	{
		BossHpbarBackRender1000->SetScale({ 50, 96 });
		BossHpbarBackRender1000->SetPosition({ -140 + 4,0 });
	}
	if (MomsHp == 8)
	{
		BossHpbarBackRender1000->SetScale({ 40, 96 });
		BossHpbarBackRender1000->SetPosition({ -145 + 4,0 });
	}
	if (MomsHp == 6)
	{
		BossHpbarBackRender1000->SetScale({ 30, 96 });
		BossHpbarBackRender1000->SetPosition({ -150 + 4,0 });
	}
	if (MomsHp == 4)
	{
		BossHpbarBackRender1000->SetScale({ 20, 96 });
		BossHpbarBackRender1000->SetPosition({ -155 + 4,0 });
	}
	if (MomsHp == 2)
	{
		BossHpbarBackRender1000->SetScale({ 10, 96 });
		BossHpbarBackRender1000->SetPosition({ -160 + 4,0 });
	}
	if (MomsHp <= 0)
	{
		BossHpbarRender1000->Death();
		BossHpbarBackRender1000->Death();

	}
	else
	{
		return;
	}
}