#pragma once
#include <GameEngineCore/GameEngineLevel.h>

// Ό³Έν :
class IsaacPlay : public GameEngineLevel
{
public:
	// constrcuter destructer
	IsaacPlay();
	~IsaacPlay();

	// delete Function
	IsaacPlay(const IsaacPlay& _Other) = delete;
	IsaacPlay(IsaacPlay&& _Other) noexcept = delete;
	IsaacPlay& operator=(const IsaacPlay& _Other) = delete;
	IsaacPlay& operator=(IsaacPlay&& _Other) noexcept = delete;

protected:
	void Loading() override;
	void Update() override;

private:

};

