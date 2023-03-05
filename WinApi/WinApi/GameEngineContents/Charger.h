#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include <GameEnginePlatform/GameEngineImage.h>


class Charger : public GameEngineActor
{
public:
	Charger();
	~Charger();


	Charger(const Charger& _Other) = delete;
	Charger(Charger&& _Other) noexcept = delete;
	Charger& operator=(const Charger& _Other) = delete;
	Charger& operator=(Charger&& _Other) noexcept = delete;
	void ImageLoad();
	void CollisionCheck(float _DeltaTime);

protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void Render(float _DeltaTime);
	void Movecalculation(float _DeltaTime);

private:
	GameEngineRender* M_Charger = nullptr;
	GameEngineRender* DeadCharger = nullptr;
	GameEngineCollision* M_Charger_Coll = nullptr;

	GameEngineCollision* M_Charger_SetColl_U = nullptr;
	GameEngineCollision* M_Charger_SetColl_D = nullptr;
	GameEngineCollision* M_Charger_SetColl_L = nullptr;
	GameEngineCollision* M_Charger_SetColl_R = nullptr;


	float4 MoveDir = float4::Zero;

	float SetTime = 0.0f;

	int RandomMove = 0;
	float RandomTime = 0.0f;
	float NowTime = 0.0f;
	int ChargerHp = 3;
	int RESET = 1;

	bool ChargerDeathcheck = false;
	bool Countbool = true;
};

