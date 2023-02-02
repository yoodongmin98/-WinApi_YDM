#pragma once
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineRender.h>

enum class TitleOrder
{
	BackGround,
	Logo,
	TestDefalut,

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

	
	void CursorSet();
	float4 CursorPosSet();
private:
	GameEngineActor* test = nullptr;

	GameEngineRender* Logo = nullptr;
	GameEngineRender* Isaac = nullptr;
	GameEngineRender* Start = nullptr;
	GameEngineRender* Cursor = nullptr;
	GameEngineRender* Cursor2 = nullptr;
	
	float Time = 0.0f;
	float4 TitleStart = float4::Zero;
	float4 TitleEnd = float4::Zero;

	float4 Chapter2Pos = { 0,720 }; //¡ﬂæ”±‚¡ÿ¿”
	float4 Chapter3Pos = { 0,1440};
	float4 Chapter4Pos = { 0,2160 };
	float4 CursorPos = float4::Zero;

	
	
};

