#pragma once
#include <GameEngineCore/GameEngineLevel.h>

// Ό³Έν :
class IsaacLevel : public GameEngineLevel
{
public:
	// constrcuter destructer
	IsaacLevel();
	~IsaacLevel();

	// delete Function
	IsaacLevel(const IsaacLevel& _Other) = delete;
	IsaacLevel(IsaacLevel&& _Other) noexcept = delete;
	IsaacLevel& operator=(const IsaacLevel& _Other) = delete;
	IsaacLevel& operator=(IsaacLevel&& _Other) noexcept = delete;

protected:
	void Loading() override;
	void Update(float _DeltaTime) override;

	void LevelChangeEnd(GameEngineLevel* _NextLevel) override {}
	void LevelChangeStart(GameEngineLevel* _PrevLevel) override {}

private:

};

