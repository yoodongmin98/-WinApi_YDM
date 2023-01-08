#pragma once
#include <GameEngineCore/GameEngineLevel.h>

// Ό³Έν :
class IsaacOpenning : public GameEngineLevel
{
public:
	// constrcuter destructer
	IsaacOpenning();
	~IsaacOpenning();

	// delete Function
	IsaacOpenning(const IsaacOpenning& _Other) = delete;
	IsaacOpenning(IsaacOpenning&& _Other) noexcept = delete;
	IsaacOpenning& operator=(const IsaacOpenning& _Other) = delete;
	IsaacOpenning& operator=(IsaacOpenning&& _Other) noexcept = delete;

protected:
	void Loading() override;
	void Update() override;

private:

};

