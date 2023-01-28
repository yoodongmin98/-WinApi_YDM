#pragma once
#include <GameEngineCore/GameEngineActor.h>


class TitleChapter :public GameEngineActor
{
public:
	static TitleChapter* MainChapter;

	TitleChapter();
	~TitleChapter();

	TitleChapter(const TitleChapter& _Other) = delete;
	TitleChapter(TitleChapter&& _Other)noexcept = delete;
	TitleChapter operator=(TitleChapter&& _Other) = delete;
	TitleChapter operator=(const TitleChapter& _Other) noexcept= delete;
protected:
	void Start() override;
	void Update(float _DeltaTime) override;
private:
};

