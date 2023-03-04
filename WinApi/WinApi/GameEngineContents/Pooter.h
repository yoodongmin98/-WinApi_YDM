#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include <GameEnginePlatform/GameEngineImage.h>


class Pooter : public GameEngineActor
{
public:
	Pooter();
	~Pooter();


	Pooter(const Pooter& _Other) = delete;
	Pooter(Pooter&& _Other) noexcept = delete;
	Pooter& operator=(const Pooter& _Other) = delete;
	Pooter& operator=(Pooter&& _Other) noexcept = delete;
	void ImageLoad();
	void CollisionCheck(float _DeltaTime);

protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void Render(float _DeltaTime);
	void Movecalculation(float _DeltaTime);

private:
	GameEngineRender* M_Pooter = nullptr;
	GameEngineRender* M_PooterDead = nullptr;
	GameEngineCollision* M_fly_Pooter = nullptr;
	GameEngineCollision* M_fly_Pooter_Set = nullptr;

	float PooterAttTime = 0.0f;
	float NowTime = 0.0f;
	int PooterHp = 3;
	int RESET = 1;
	bool PooterDeathcheck = false;
};

