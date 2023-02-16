#pragma once
#include <GameEngineCore/GameEngineLevel.h>

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

	
	void MapMoveUpdate();
	void SettingMenuUpdate();
protected:
	void Loading() override;
	void Update(float _DeltaTime) override;

	void LevelChangeEnd(GameEngineLevel* _NextLevel) override {}
	void LevelChangeStart(GameEngineLevel* _PrevLevel) override;

private:
	GameEngineRender* SettingMenu = nullptr;
	GameEngineRender* SettingMenuCursor1 = nullptr;

	int SettingValue = 2;


	bool Map_Move = false;
	
	float4 MapS = float4::Zero;
	float4 MapE = float4::Zero;

	float P_Time = 0.0f;

	float MapMaxXvalue = 1050.f;

	float MiddieYValue = 400.0f;
	float MiddieXValue = 640.0f;

	float MapMoveSpeed = 4.0f;


	//Collision에따라 설정해줘야하는값(Isacc을 문앞으로 위치시키는값)
	float LeftSetValue=150.0f;
	float RightSetValue = 1150.0f;
	float DownSetValue = 610.0f;
	float UpSetValue = 120.0f;

	void CreateRoom(int _X, int _Y);
	void CreateDoor();

};

