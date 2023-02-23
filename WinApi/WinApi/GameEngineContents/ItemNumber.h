#pragma once

#include <GameEngineCore/GameEngineActor.h>


class ItemNumber : public GameEngineActor
{
public:
	
	// constrcuter destructer
	ItemNumber();
	~ItemNumber();

	// delete Function
	ItemNumber(const ItemNumber& _Other) = delete;
	ItemNumber(ItemNumber&& _Other) noexcept = delete;
	ItemNumber& operator=(const ItemNumber& _Other) = delete;
	ItemNumber operator=(ItemNumber&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime);

private:

	int BombNumber = 0;
	int KeyNumber = 0;
	int CoinNumber= 0;

	void GetItemNumberSet();
};

