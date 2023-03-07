#pragma once
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineRender.h>
#include <GameEnginePlatform/GameEngineSound.h>
#include <GameEngineCore/GameEngineResources.h>

enum class NextLevelOrder
{
	BackGround,
	Ground,
	Animation,

};
class NextLevelLoding : public GameEngineLevel
{
public:
	NextLevelLoding();
	~NextLevelLoding();

	NextLevelLoding(const NextLevelLoding& _Other) = delete;
	NextLevelLoding(NextLevelLoding&& _Other)noexcept = delete;
	NextLevelLoding operator=(NextLevelLoding&& _Other) = delete;
	NextLevelLoding operator=(const NextLevelLoding& _Other) noexcept = delete;
protected:
	//void SoundLoad();

	GameEngineSoundPlayer NextLevelLodingSOUND;
	void Loading() override;
	void Update(float _DeltaTime) override;

	void LevelChangeEnd(GameEngineLevel* _NextLevel) override {};
	void LevelChangeStart(GameEngineLevel* _PrevLevel) override {};

private:
	GameEngineRender* BackGround = nullptr;

	float NowTime = 0.0f;
};

