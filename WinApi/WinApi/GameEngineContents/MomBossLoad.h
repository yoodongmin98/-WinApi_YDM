#pragma once
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineRender.h>
#include <GameEnginePlatform/GameEngineSound.h>
#include <GameEngineCore/GameEngineResources.h>

enum class MomBossLoadOrder
{
	BackGround,
	Ground,
	Animation,

};
class MomBossLoadLevel : public GameEngineLevel
{
public:
	MomBossLoadLevel();
	~MomBossLoadLevel();

	MomBossLoadLevel(const MomBossLoadLevel& _Other) = delete;
	MomBossLoadLevel(MomBossLoadLevel&& _Other)noexcept = delete;
	MomBossLoadLevel operator=(MomBossLoadLevel&& _Other) = delete;
	MomBossLoadLevel operator=(const MomBossLoadLevel& _Other) noexcept = delete;
protected:
	void SoundLoad();
	GameEngineSoundPlayer Mom_BOSSLODINGSOUND;
	void Loading() override;
	void Update(float _DeltaTime) override;

	void LevelChangeEnd(GameEngineLevel* _NextLevel) override {};
	void LevelChangeStart(GameEngineLevel* _PrevLevel) override;

private:
	GameEngineRender* Mom_BackGround = nullptr;
	GameEngineRender* Mom_CryIsaac = nullptr;
	GameEngineRender* Mom_Monstro = nullptr;
	GameEngineRender* Mom_vs = nullptr;
	GameEngineRender* Mom_fontIsaac = nullptr;
	GameEngineRender* Mom_fontMonstro = nullptr;
					  
	GameEngineRender* Mom_IsaacGround = nullptr;
	GameEngineRender* Mom_MonstroGround = nullptr;






	float NowTime = 0.0f;
};

