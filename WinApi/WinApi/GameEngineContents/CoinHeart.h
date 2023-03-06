#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include <GameEnginePlatform/GameEngineImage.h>


class CoinHeart : public GameEngineActor
{
public:
	CoinHeart();
	~CoinHeart();


	CoinHeart(const CoinHeart& _Other) = delete;
	CoinHeart(CoinHeart&& _Other) noexcept = delete;
	CoinHeart& operator=(const CoinHeart& _Other) = delete;
	CoinHeart& operator=(CoinHeart&& _Other) noexcept = delete;


	void ImageLoad();


protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void Render(float _DeltaTime);

private:
	GameEngineRender* R_CoinHeart = nullptr;
	GameEngineCollision* CoinHeart_Coll = nullptr;
};

