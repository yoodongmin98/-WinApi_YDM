#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include <GameEnginePlatform/GameEngineImage.h>


class CoinBomb : public GameEngineActor
{
public:
	CoinBomb();
	~CoinBomb();


	CoinBomb(const CoinBomb& _Other) = delete;
	CoinBomb(CoinBomb&& _Other) noexcept = delete;
	CoinBomb& operator=(const CoinBomb& _Other) = delete;
	CoinBomb& operator=(CoinBomb&& _Other) noexcept = delete;


	void ImageLoad();


protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void Render(float _DeltaTime);

private:
	GameEngineRender* R_CoinBomb = nullptr;
	GameEngineCollision* CoinBomb_Coll = nullptr;
};

