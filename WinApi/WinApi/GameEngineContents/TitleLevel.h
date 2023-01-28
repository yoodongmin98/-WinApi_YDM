#pragma once
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineRender.h>

enum class TitleOrder
{
	BackGround,
	Logo,

};
class TitleLevel : public GameEngineLevel
{
public:
	TitleLevel();
	~TitleLevel();

	TitleLevel(const TitleLevel& _Other) = delete;
	TitleLevel(TitleLevel&& _Other)noexcept = delete;
	TitleLevel operator=(TitleLevel&& _Other) = delete;
	TitleLevel operator=(const TitleLevel& _Other) noexcept= delete;

	
protected:

	void Loading() override;
	void Update(float _DeltaTime) override;

	void LevelChangeEnd(GameEngineLevel* _NextLevel) override {}
	void LevelChangeStart(GameEngineLevel* _PrevLevel) override {}

	
private:
	GameEngineRender* Logo = nullptr;

	
};

