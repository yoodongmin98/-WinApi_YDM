#include "IsaacLevel.h"
#include "Isaac.h"
#include "Monstro.h"
#include "IsaacEnum.h"




#include <GameEngineCore/GameEngineCore.h>
#include <GameEngineCore/GameEngineCollision.h>


////////////////��Ƴ��� Collision������ ���弼���� ���⼭/////////////////////

void IsaacLevel::CollisionSoundSet(float _DeltaTime)
{
	//������ȯ��
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
	}

	
}


void IsaacLevel::CollisionSoundSet2(float _DeltaTime)
{
	/////������� �ٲٱ��
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
}