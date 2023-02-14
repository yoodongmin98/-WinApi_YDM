#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include <GameEnginePlatform/GameEngineImage.h>


class Door;
class Monster : public GameEngineActor
{

	friend Door;
public:
	Monster();
	~Monster();


	Monster(const Monster& _Other) = delete;
	Monster(Monster&& _Other) noexcept = delete;
	Monster& operator=(const Monster& _Other) = delete;
	Monster& operator=(Monster&& _Other) noexcept = delete;
	void ImageLoad();

	int GetMonstertCount()
	{
		return MonsterCount;
	}
	
protected:
	void Start() override;
	void Update(float _DeltaTime) override;

private:
	GameEngineRender* M_fly = nullptr;
	GameEngineCollision* M_fly_Coll = nullptr;

	float ReloadTime = 3.0f;
	float NowTime = 0.0f;
	int FlyHp = 3;

	int MonsterCount=0;

};

