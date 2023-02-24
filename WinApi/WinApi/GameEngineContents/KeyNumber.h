#pragma once

#include <GameEngineCore/GameEngineActor.h>
#include <GameEngineCore/NumberRenderObject.h>


class KeyNumber : public GameEngineActor
{
public:
	static KeyNumber* P_KeyNumber;
	// constrcuter destructer
	KeyNumber();
	~KeyNumber();

	// delete Function
	KeyNumber(const KeyNumber& _Other) = delete;
	KeyNumber(KeyNumber&& _Other) noexcept = delete;
	KeyNumber& operator=(const KeyNumber& _Other) = delete;
	KeyNumber operator=(KeyNumber&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime);

private:
	GameEngineRender* KeyRender = nullptr;


	NumberRenderObject N_KeyNumber;


	int KeyNumbers = 0;

	void GetKeyNumberSet();
	void NumberSet();
};

