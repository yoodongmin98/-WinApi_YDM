#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include <GameEnginePlatform/GameEngineImage.h>


class Boil : public GameEngineActor
{
public:
	Boil();
	~Boil();


	Boil(const Boil& _Other) = delete;
	Boil(Boil&& _Other) noexcept = delete;
	Boil& operator=(const Boil& _Other) = delete;
	Boil& operator=(Boil&& _Other) noexcept = delete;
	void ImageLoad();
	void CollisionCheck(float _DeltaTime);

protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void Render(float _DeltaTime);
	void HpCheck(float _DeltaTime);

private:
	GameEngineRender* M_Boil = nullptr;
	
	GameEngineCollision* M_Boil_Coll = nullptr;

	float BoilAttTime = 0.0f;
	float HpPlusTime = 0.0f;
	float NowTime = 0.0f;

	int MaxBoilHp = 10;
	int BoilHp = 1;
	int RESET = 1;
};

