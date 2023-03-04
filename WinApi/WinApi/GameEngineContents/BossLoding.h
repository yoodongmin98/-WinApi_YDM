//#pragma once
//#include <GameEngineCore/GameEngineLevel.h>
//#include <GameEngineCore/GameEngineRender.h>
//#include <GameEnginePlatform/GameEngineSound.h>
//#include <GameEngineCore/GameEngineResources.h>
//
//enum class BossLoadOrder
//{
//	BackGround,
//	Animation
//};
//class BossLoadLevel : public GameEngineLevel
//{
//public:
//	BossLoadLevel();
//	~BossLoadLevel();
//
//	BossLoadLevel(const BossLoadLevel& _Other) = delete;
//	BossLoadLevel(BossLoadLevel&& _Other)noexcept = delete;
//	BossLoadLevel operator=(BossLoadLevel&& _Other) = delete;
//	BossLoadLevel operator=(const BossLoadLevel& _Other) noexcept = delete;
//protected:
//	//void SoundLoad();
//	//GameEngineSoundPlayer BOSSLODINGSOUND;
//	void Loading() override;
//	void Update(float _DeltaTime) override;
//
//	//void LevelChangeEnd(GameEngineLevel* _NextLevel) override {};
//	//void LevelChangeStart(GameEngineLevel* _PrevLevel) override;
//
//private:
//	GameEngineRender* BackGround = nullptr;
//	GameEngineRender* CryIsaac = nullptr;
//	GameEngineRender* Boss = nullptr;
//
//	float NowTime = 0.0f;
//};
//
