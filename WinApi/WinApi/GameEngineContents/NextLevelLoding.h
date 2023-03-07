#pragma once
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineRender.h>
#include <GameEnginePlatform/GameEngineSound.h>
#include <GameEngineCore/GameEngineResources.h>

enum class NextLevelOrder
{
	BackGround,
	Balloon,
	BalloonBack,
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
	GameEngineRender* Isaac_NextLevel = nullptr;
	GameEngineRender* Balloon1 = nullptr;
	GameEngineRender* Balloon2 = nullptr;
	GameEngineRender* Balloon3 = nullptr;

	GameEngineRender* Box1 = nullptr;
	GameEngineRender* Box2 = nullptr;
	GameEngineRender* Box3 = nullptr;

	GameEngineRender* Line1 = nullptr;

	GameEngineRender* MiniIsaac = nullptr;

	GameEngineRender* BalloonBack = nullptr;

	GameEngineRender* HappyIsaac = nullptr;
	GameEngineRender* DamagedIsaac = nullptr;
	GameEngineRender* SickIsaac = nullptr;

	GameEngineRender* ThrowBall = nullptr;



	float NowTime = 0.0f;
};

