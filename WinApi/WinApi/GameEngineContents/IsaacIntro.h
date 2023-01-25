#pragma once
#include <GameEngineCore/GameEngineLevel.h>

enum class IntroOrder
{
	BackGround,
	FrontPaper
};
// ���� :
class IsaacIntro : public GameEngineLevel
{
public:
	// constrcuter destructer
	IsaacIntro();
	~IsaacIntro();

	// delete Function
	IsaacIntro(const IsaacIntro& _Other) = delete;
	IsaacIntro(IsaacIntro&& _Other) noexcept = delete;
	IsaacIntro& operator=(const IsaacIntro& _Other) = delete;
	IsaacIntro& operator=(IsaacIntro&& _Other) noexcept = delete;

protected:
	// ������ ����ħ ���� fm��� ����� �մϴ�.
	void Loading() override;
	void Update(float _DeltaTime) override;

	void LevelChangeEnd(GameEngineLevel* _NextLevel) override {}
	void LevelChangeStart(GameEngineLevel* _PrevLevel) override {}

private:
	GameEngineRender* FirstPaper = nullptr;

	float NowTime = 0.0f;
	static const float FirstPapertime;
	
};

