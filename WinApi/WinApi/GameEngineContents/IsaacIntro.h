#pragma once
#include <GameEngineCore/GameEngineLevel.h>

enum class IntroOrder
{
	BackGround,
	FrontPaper,
	Photo1
};
// Ό³Έν :
class IsaacIntro : public GameEngineLevel
{
public:
	IsaacIntro();
	~IsaacIntro();

	IsaacIntro(const IsaacIntro& _Other) = delete;
	IsaacIntro(IsaacIntro&& _Other) noexcept = delete;
	IsaacIntro& operator=(const IsaacIntro& _Other) = delete;
	IsaacIntro& operator=(IsaacIntro&& _Other) noexcept = delete;

protected:

	void Loading() override;
	void Update(float _DeltaTime) override;

	void LevelChangeEnd(GameEngineLevel* _NextLevel) override {}
	void LevelChangeStart(GameEngineLevel* _PrevLevel) override {}

private:
	GameEngineRender* FirstPaper = nullptr;

	float NowTime = 0.0f;
	static const float FirstPapertime;
	
};

