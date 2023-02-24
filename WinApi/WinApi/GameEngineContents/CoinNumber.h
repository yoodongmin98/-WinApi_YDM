#pragma once

#include <GameEngineCore/GameEngineActor.h>
#include <GameEngineCore/NumberRenderObject.h>


class CoinNumber : public GameEngineActor
{
public:
	static CoinNumber* P_CoinNumber;
	// constrcuter destructer
	CoinNumber();
	~CoinNumber();

	// delete Function
	CoinNumber(const CoinNumber& _Other) = delete;
	CoinNumber(CoinNumber&& _Other) noexcept = delete;
	CoinNumber& operator=(const CoinNumber& _Other) = delete;
	CoinNumber operator=(CoinNumber&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime);

private:
	GameEngineRender* CoinRender = nullptr;


	NumberRenderObject N_CoinNumber;


	int CoinNumbers = 0;

	void GetCoinNumberSet();
	void NumberSet();
};

