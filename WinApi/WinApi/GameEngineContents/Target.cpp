
#include <GameEngineBase/GameEngineDirectory.h>

#include <GameEnginePlatform/GameEngineInput.h>

#include <GameEngineCore/GameEngineRender.h>
#include <GameEngineCore/GameEngineResources.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCollision.h>




#include "BloodTear.h"

#include "Isaac.h"
#include "IsaacEnum.h"
#include "Target.h"


Target::Target()
{

}

Target::~Target()
{
}

bool TargetLoad = true;
void Target::ImageLoad()
{
	GameEngineDirectory Dir;
	Dir.MoveParentToDirectory("ContentsResources");
	Dir.Move("ContentsResources");
	Dir.Move("Image");
	Dir.Move("Play");
	Dir.Move("Monster");

	GameEngineImage* Targets = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("target.BMP"));

}


void Target::Start()
{
	if (true == TargetLoad)
	{
		ImageLoad();
		TargetLoad = false;
	}

	M_Target = CreateRender("target.BMP",IsaacOrder::R_Monster);
	M_Target->SetScale({ 70, 70 });

	SHOOTSOUND = GameEngineResources::GetInst().SoundPlayToControl("deathburstsmall1.wav");
	SHOOTSOUND.Volume(0.4f);
	SHOOTSOUND.LoopCount(1);
}


void Target::Update(float _DeltaTime)
{
	TargetAttTime += _DeltaTime;
	if (TargetAttTime > 0.3f)
	{
		if (true == TearBool)
		{
			float4 PlayerPos = Isaac::MainPlayer->GetPos() - GetPos();
			BloodTear* NewBloodTear = GetLevel()->CreateActor<BloodTear>();
			NewBloodTear->SetBloodMoveDir(PlayerPos);
			NewBloodTear->SetPos(GetPos());
			TearBool = false;
		}
	}
	
	if (TargetAttTime > 1.2f)
	{
		Death();
	}
}
		

