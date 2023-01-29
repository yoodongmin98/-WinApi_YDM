#pragma once
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineRender.h>

enum class LoadOrder
{
	BackGround,
	Animation
};
class LoadLevel : public GameEngineLevel
{
public:
	LoadLevel();
	~LoadLevel();

	LoadLevel(const LoadLevel& _Other) = delete;
	LoadLevel(LoadLevel&& _Other)noexcept = delete;
	LoadLevel operator=(LoadLevel&& _Other) = delete;
	LoadLevel operator=(const LoadLevel& _Other) noexcept= delete;
protected:

	void Loading() override;
	void Update(float _DeltaTime) override;

	void LevelChangeEnd(GameEngineLevel* _NextLevel) override {}
	void LevelChangeStart(GameEngineLevel* _PrevLevel) override {}

private:
	GameEngineRender* LoadIsaac = nullptr;

	float NowTime = 0.0f;
	float NextLevelTime = 5.f;
};

