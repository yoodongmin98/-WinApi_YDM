#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include <GameEnginePlatform/GameEngineImage.h>


class Monster : public GameEngineActor
{
public:
	Monster();
	~Monster();


	Monster(const Monster& _Other) = delete;
	Monster(Monster&& _Other) noexcept = delete;
	Monster& operator=(const Monster& _Other) = delete;
	Monster& operator=(Monster&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime) override;

private:
	GameEngineRender* MonsterRender = nullptr;
	GameEngineCollision* BodyCollision = nullptr;

	float MonsterDeadTime = 3.0f;
	float NowTime = 0.0f;

};

