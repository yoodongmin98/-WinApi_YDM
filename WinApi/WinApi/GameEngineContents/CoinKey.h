#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include <GameEnginePlatform/GameEngineImage.h>


class CoinKey : public GameEngineActor
{
public:
	CoinKey();
	~CoinKey();


	CoinKey(const CoinKey& _Other) = delete;
	CoinKey(CoinKey&& _Other) noexcept = delete;
	CoinKey& operator=(const CoinKey& _Other) = delete;
	CoinKey& operator=(CoinKey&& _Other) noexcept = delete;


	void ImageLoad();


protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void Render(float _DeltaTime);

private:
	GameEngineRender* R_CoinKey = nullptr;
	GameEngineCollision* CoinKey_Coll = nullptr;
};

