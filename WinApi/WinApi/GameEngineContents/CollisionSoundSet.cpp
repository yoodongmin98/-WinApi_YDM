#include "IsaacLevel.h"
#include "Isaac.h"
#include "Monstro.h"
#include "IsaacEnum.h"
#include "MonstroHpBar.h"
#include "NextLevelDoor.h"
#include "MomsHeart.h"
#include "MomsHeartHpbar.h"

#include <GameEngineCore/GameEngineCore.h>
#include <GameEngineCore/GameEngineCollision.h>


////////////////깔아놓은 Collision에대한 사운드세팅은 여기서/////////////////////
bool LoopBool = true;
void IsaacLevel::CollisionSoundSet(float _DeltaTime)
{
	//보스소환용
	LevelUpdateTime += _DeltaTime;
	if (true == BossLoadBool &&
		true == Isaac::MainPlayer->GetIsaacCollision()->Collision({ .TargetGroup = static_cast<int>(IsaacCollisionOrder::Room8), .TargetColType = CT_Rect, .ThisColType = CT_Rect }))
	{
		BossLoadBool = false;
		Isaac::MainPlayer->SetMonsterCount(1);
		LevelUpdateTime = 0.0f;
		GameEngineCore::GetInst()->ChangeLevel("BossLoad");
		PLAYBGMPLAYER.PauseOn();

	}
	if (LevelUpdateTime > 0.2f && false == BossLoadBool && true == BossSoundBool)
	{
		BossSoundBool = false;
		PLAYBGMBOSS.PauseOff();
		Monstro* BossMonstro = CreateActor<Monstro>();
		BossMonstro->SetPos({ 5120 + 1280 + 900,720 + 300 });
		BossHpbar* BossHpbars = CreateActor<BossHpbar>();
		BossHpbars->SetPos({ 5120 + 1280 + 640,720 + 100 });
	}
	
	if (false == BossLoadBool && 0 == Isaac::MainPlayer->GetMonsterCount())
	{
		if (true == LoopBool)
		{
			BOSSDEATH = GameEngineResources::GetInst().SoundPlayToControl("deathburstsmall3.wav"); 
			BOSSDEATH.Volume(0.3f);
			BOSSDEATH.LoopCount(1);
			LoopBool = false;
		}
		PLAYBGMBOSS.Stop(); //죽으면노래멈추기
	}
}

void IsaacLevel::CollisionSoundSetBoss(float _DeltaTime)
{
	MomSoundUpdateTime += _DeltaTime;
	if (true == BossEnterBool &&
		true == Isaac::MainPlayer->GetIsaacCollision()->Collision({ .TargetGroup = static_cast<int>(IsaacCollisionOrder::Room10), .TargetColType = CT_Rect, .ThisColType = CT_Rect }))
	{
		BossEnterBool = false;
		Isaac::MainPlayer->SetMonsterCount(1);
		MomSoundUpdateTime = 0.0f;
		GameEngineCore::GetInst()->ChangeLevel("MomBossLoad");
	}
	if (MomSoundUpdateTime > 0.2f && false == BossEnterBool && true == MomBossSoundBool)
	{
		MomBossSoundBool = false;
		PLAYMOMBOSS.PauseOff();

		MomsHeart* NewMomsHeart = CreateActor<MomsHeart>();
		NewMomsHeart->SetPos({ 5120 + 2560 + 1000,720 + 200 });
		MomsHpbar* MomsHpbars = CreateActor<MomsHpbar>();
		MomsHpbars->SetPos({ 5120 + 1280 + 1280 + 640,720 + 100 });
	}
	if (false == BossEnterBool && 0 == Isaac::MainPlayer->GetMonsterCount())
	{
		PLAYMOMBOSS.Stop(); //죽으면노래멈추기
	}

}


void IsaacLevel::CollisionSoundSet2(float _DeltaTime)
{
	/////배경음악 바꾸기용
	if (true == ShopSoundBool &&
		true == Isaac::MainPlayer->GetIsaacCollision()->Collision({ .TargetGroup = static_cast<int>(IsaacCollisionOrder::Room9), .TargetColType = CT_Rect, .ThisColType = CT_Rect }))
	{
		ShopSoundBool = false;
		PLAYBGMPLAYER.PauseOn();
		PLAYBGMSHOP.PauseOff();

	}
}

void IsaacLevel::CollisionSoundSet3(float _DeltaTime)
{
	if (false == ShopSoundBool &&
		true == Isaac::MainPlayer->GetIsaacCollision()->Collision({ .TargetGroup = static_cast<int>(IsaacCollisionOrder::Room8_2), .TargetColType = CT_Rect, .ThisColType = CT_Rect }))
	{
		ShopSoundBool = true;
		PLAYBGMPLAYER.PauseOff();
		PLAYBGMSHOP.PauseOn();

	}
}


void IsaacLevel::CollisionSoundSet4(float _DeltaTime)
{
	if (true == ItemRoomBool &&
		true == Isaac::MainPlayer->GetIsaacCollision()->Collision({ .TargetGroup = static_cast<int>(IsaacCollisionOrder::Room4), .TargetColType = CT_Rect, .ThisColType = CT_Rect }))
	{
		ItemRoomBool = false;
		PLAYBGMPLAYER.PauseOn();
		PLAYBGMITEMROOM.PauseOff();

	}
}


void IsaacLevel::CollisionSoundSet5(float _DeltaTime)
{
	if (false == ItemRoomBool &&
		true == Isaac::MainPlayer->GetIsaacCollision()->Collision({ .TargetGroup = static_cast<int>(IsaacCollisionOrder::Room3), .TargetColType = CT_Rect, .ThisColType = CT_Rect }))
	{
		ItemRoomBool = true;
		PLAYBGMPLAYER.PauseOff();
		PLAYBGMITEMROOM.PauseOn();

	}
}







void IsaacLevel::ALLCollisionSoundSet(float _DeltaTime)
{
	CollisionSoundSet(_DeltaTime);
	CollisionSoundSet2(_DeltaTime);
	CollisionSoundSet3(_DeltaTime);
	CollisionSoundSet4(_DeltaTime);
	CollisionSoundSet5(_DeltaTime);
	CollisionSoundSetBoss(_DeltaTime);
	
}