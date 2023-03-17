#pragma once
#include <GameEngineCore/GameEngineLevel.h>
#include <string_view>
#include <GameEngineCore/GameEngineResources.h>
// 설명 :
class IsaacLevel : public GameEngineLevel
{
public:
	// constrcuter destructer
	IsaacLevel();
	~IsaacLevel();

	// delete Function
	IsaacLevel(const IsaacLevel& _Other) = delete;
	IsaacLevel(IsaacLevel&& _Other) noexcept = delete;
	IsaacLevel& operator=(const IsaacLevel& _Other) = delete;
	IsaacLevel& operator=(IsaacLevel&& _Other) noexcept = delete;

	void BaseMentUpdate(float _DeltaTime);

	void ALLCollisionSoundSet(float _DeltaTime);
	void CollisionSoundSet(float _DeltaTime);
	void CollisionSoundSet2(float _DeltaTime);
	void CollisionSoundSet3(float _DeltaTime);
	void CollisionSoundSet4(float _DeltaTime);
	void CollisionSoundSet5(float _DeltaTime);
	void CollisionSoundSetBoss(float _DeltaTime);


	void SettingMenuUpdate();
	void DoorAnimationSetandUpdate();
	void DoorRenderUpdate();

	void MapMoveUpdate();

	void SoundLoad();
	void ImageLoad();
	void KeyLoad();

	void Room1Set();
	void Room2Set();
	void Room3Set();
	void Room4Set();
	void Room5Set();
	void Room6Set();
	void Room7Set();
	void Room8Set();
	void Room9Set();


protected:
	void Loading() override;
	void Update(float _DeltaTime) override;

	void LevelChangeEnd(GameEngineLevel* _NextLevel) override {};
	void LevelChangeStart(GameEngineLevel* _PrevLevel) override;

	GameEngineSoundPlayer PLAYBGMPLAYER;
	GameEngineSoundPlayer PLAYBGMBOSS;
	GameEngineSoundPlayer PLAYMOMBOSS;
	GameEngineSoundPlayer PLAYBGMSHOP;
	GameEngineSoundPlayer PLAYBGMITEMROOM;
	GameEngineSoundPlayer BOSSDEATH;
	
private:
	GameEngineRender* SettingMenu = nullptr;
	GameEngineRender* SettingMenuCursor1 = nullptr;
	GameEngineRender* BackDrop = nullptr;
	GameEngineRender* BaseMent = nullptr;


	GameEngineRender* Room0door = nullptr;
	GameEngineRender* Room1door = nullptr;
	GameEngineRender* Room2door = nullptr;
	GameEngineRender* Room3door = nullptr;
	GameEngineRender* Room4door = nullptr;
	GameEngineRender* Room5door = nullptr;
	GameEngineRender* Room6door = nullptr;
	GameEngineRender* Room7door = nullptr;
	GameEngineRender* Room8door = nullptr;
	GameEngineRender* Room9door = nullptr;
	GameEngineRender* Room10door = nullptr;
	GameEngineRender* Room11door = nullptr;
	GameEngineRender* Room12door = nullptr;
	GameEngineRender* Room13door = nullptr;
	GameEngineRender* Room14door = nullptr;
	GameEngineRender* Room15door = nullptr;
	GameEngineRender* Room16door = nullptr;
	GameEngineRender* Room17door = nullptr;
	GameEngineRender* Room18door = nullptr;



	int SettingValue = 2;


	bool Map_Move = false;
	bool BossLoadBool = true;
	bool BossSoundBool = true;
	bool MomBossSoundBool = true;
	bool ShopSoundBool = true;
	bool ItemRoomBool = true;

	bool BossEnterBool = true;
	bool BossinBool = true;


	
	float4 MapS = float4::Zero;
	float4 MapE = float4::Zero;

	float P_Time = 0.0f;
	float LevelUpdateTime = 0.0f;
	float MomSoundUpdateTime = 0.0f;

	float MapMaxXvalue = 1050.f;

	float MiddieYValue = 400.0f;
	float MiddieXValue = 640.0f;

	float MapMoveSpeed = 4.0f;


	//Collision에따라 설정해줘야하는값(Isacc을 문앞으로 위치시키는값)
	float LeftSetValue=150.0f;
	float RightSetValue = 1130.0f;
	float DownSetValue = 600.0f;
	float UpSetValue = 130.0f;

	void CreateRoom(int _X, int _Y, int _MapKey);

};

