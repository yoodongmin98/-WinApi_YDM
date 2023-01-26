#pragma once
#include <GameEngineCore/GameEngineLevel.h>

enum class IntroOrder
{
	BackGround,
	Anime,
	FrontPaper,
	Trans,
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
	GameEngineRender* Presents = nullptr;
	GameEngineRender* Human = nullptr;
	GameEngineRender* Made = nullptr;
	GameEngineRender* Millen = nullptr;
	

	float NowTime = 0.0f;
	static const float FirstPaperTime;
	static const float PresentsONTime;
	static const float PresentsOFFTime;
	static const float HumanONTime;
	static const float HumanOFFTime;
	static const float MadeONTime;
	static const float MadeOFFTime;

	static const float AllAnimeTime;

	//intro image
	GameEngineRender* Intro_1 = nullptr;

	
};

