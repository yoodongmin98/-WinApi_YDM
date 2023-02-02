#pragma once
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineRender.h>
#include "AllBack.h"

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

	GameEngineRender* MyTitleRender(const std::string_view& _Imagename,
		const std::string_view& _Animename,
		GameEngineRender* _Titlename)
	{
		AllBack* IntroAni = CreateActor<AllBack>();
		_Titlename = IntroAni->CreateRender(_Imagename, TitleOrder::Logo);
		_Titlename->Off();
		_Titlename->SetScale({ 550,550 });
		_Titlename->CreateAnimation({
			.AnimationName = _Animename,
			.ImageName = _Imagename,
			.Start = 0,
			.End = 1,
			.InterTime = .1f
			});
		_Titlename->ChangeAnimation(_Animename);

		return _Titlename;
	}
	
private:
	
	GameEngineRender* Logo = nullptr;
	GameEngineRender* Isaac = nullptr;
	GameEngineRender* Start = nullptr;
	GameEngineRender* Cursor = nullptr;
	GameEngineRender* Cursor2 = nullptr;

	GameEngineRender* Isaac_File1 = nullptr;
	GameEngineRender* Isaac_File2 = nullptr;
	GameEngineRender* Isaac_File3 = nullptr;
	
	float Time = 0.0f;
	float4 TitleStart = float4::Zero;
	float4 TitleEnd = float4::Zero;

	float4 Chapter2Pos = { 0,720 }; //¡ﬂæ”±‚¡ÿ¿”
	float4 Chapter3Pos = { 0,1440};
	float4 Chapter4Pos = { 0,2160 };
	float4 CursorPos = float4::Zero;

	GameEngineRender* Isaacselect1 = nullptr;
	GameEngineRender* Isaacselect2 = nullptr;
	GameEngineRender* Isaacselect3 = nullptr;

	
	
};

