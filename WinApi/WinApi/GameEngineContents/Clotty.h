#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include <GameEnginePlatform/GameEngineImage.h>


class Clotty : public GameEngineActor
{
public:
	Clotty();
	~Clotty();


	Clotty(const Clotty& _Other) = delete;
	Clotty(Clotty&& _Other) noexcept = delete;
	Clotty& operator=(const Clotty& _Other) = delete;
	Clotty& operator=(Clotty&& _Other) noexcept = delete;
	void ImageLoad();
	void CollisionCheck(float _DeltaTime);

protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void Render(float _DeltaTime);
	void Movecalculation(float _DeltaTime);

private:
	GameEngineRender* M_Clotty = nullptr;
	GameEngineRender* DeadRender_Clotty = nullptr;
	GameEngineCollision* M_Clotty_Coll = nullptr;
	GameEngineCollision* M_Clotty_SetColl_R = nullptr;

	float ClottyAttTime = 0.0f;
	float NowTime = 0.0f;
	int ClottyHp = 4;
	int RESET = 1;
	bool ClottyDeathcheck = false;
	bool Countbool = true;
};

