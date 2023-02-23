#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include <GameEnginePlatform/GameEngineImage.h>


class Coin : public GameEngineActor
{
public:
	Coin();
	~Coin();


	Coin(const Coin& _Other) = delete;
	Coin(Coin&& _Other) noexcept = delete;
	Coin& operator=(const Coin& _Other) = delete;
	Coin& operator=(Coin&& _Other) noexcept = delete;

	void ImageLoad();
protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void Render(float _DeltaTime);

private:
	GameEngineRender* R_Coin = nullptr;
	GameEngineCollision* Coin_Coll = nullptr;

	float CoinLoadTime = 0.0f;
};

