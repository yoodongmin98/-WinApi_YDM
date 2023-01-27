#pragma once
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineRender.h>
#include "AllBack.h"

enum class IntroOrder
{
	BackGround,
	Anime,
	FrontPaper,
	Trans,
	BLACKRENDER,
};
// ���� :
class IsaacIntro : public GameEngineLevel
{
	
public:
	IsaacIntro();
	~IsaacIntro();
	

	IsaacIntro(const IsaacIntro& _Other) = delete;
	IsaacIntro(IsaacIntro&& _Other) noexcept = delete;
	IsaacIntro& operator=(const IsaacIntro& _Other) = delete;
	IsaacIntro& operator=(IsaacIntro&& _Other) noexcept = delete; 

	GameEngineRender* IntroRender(const std::string_view& _Imagename,
							      const std::string_view& _Animename,
								  GameEngineRender* _introname       )
	{
		AllBack* IntroAni = CreateActor<AllBack>();
		_introname = IntroAni->CreateRender(_Imagename, IntroOrder::Trans);
		_introname->Off();
		_introname->SetScale({ 850,700 });
		_introname->CreateAnimation({
			.AnimationName = _Animename,
			.ImageName = _Imagename,
			.Start = 0,
			.End = 1,
			.InterTime = .1f
			});
		_introname->ChangeAnimation(_Animename);
		
		return _introname;
	}

	void NextintroRenderOn(GameEngineRender* _NextintroName, const float _NextTime)
	{
		if (_NextTime < NowTime)
		{
		   	_NextintroName->On();
		}	
	}
	void NextintroRenderOff(GameEngineRender* _NextintroName, const float _PlusTime)
	{
		if (_PlusTime < NowTime)
		{
			_NextintroName->Off();
		}
	}
protected:

	void Loading() override;
	void Update(float _DeltaTime) override;

	void LevelChangeEnd(GameEngineLevel* _NextLevel) override {}
	void LevelChangeStart(GameEngineLevel* _PrevLevel) override {}

private:
	GameEngineRender* Black = nullptr;
	GameEngineRender* FirstPaper = nullptr;
	GameEngineRender* Presents = nullptr;
	GameEngineRender* Human = nullptr;
	GameEngineRender* Made = nullptr;
	GameEngineRender* Millen = nullptr;
	GameEngineRender* Isaac = nullptr;
	GameEngineRender* Mother= nullptr;
	GameEngineRender* Nicalis= nullptr;
	
	
	float NextintroTime=0.0f;
	float NowTime = 0.0f;
	
	static const float AllAnimeTime;

	////////////intro image////////////
	
	GameEngineRender* Intro_1 = nullptr;
	GameEngineRender* Intro_2 = nullptr;
	GameEngineRender* Intro_3 = nullptr;
	GameEngineRender* Intro_4 = nullptr;
	GameEngineRender* Intro_5 = nullptr;
	GameEngineRender* Intro_6 = nullptr;
	GameEngineRender* Intro_7 = nullptr;
	GameEngineRender* Intro_8 = nullptr;
	GameEngineRender* Intro_9 = nullptr;
	GameEngineRender* Intro_10 = nullptr;
	GameEngineRender* Intro_11 = nullptr;

	

	

	
};

