#pragma once

#include <GameEngineCore/GameEngineActor.h>
#include <GameEngineCore/NumberRenderObject.h>


class BombNumber : public GameEngineActor
{
public:
	static BombNumber* P_BombNumber;
	// constrcuter destructer
	BombNumber();
	~BombNumber();

	// delete Function
	BombNumber(const BombNumber& _Other) = delete;
	BombNumber(BombNumber&& _Other) noexcept = delete;
	BombNumber& operator=(const BombNumber& _Other) = delete;
	BombNumber operator=(BombNumber&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime);

private:
	GameEngineRender* BombRender = nullptr;

	NumberRenderObject N_BombNumber;
	

	int BombNumbers = 0;

	void GetBombNumberSet();
	void NumberSet();
};

