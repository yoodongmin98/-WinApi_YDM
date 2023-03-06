#pragma once

#include <GameEngineCore/GameEngineActor.h>


class BossHpbar : public GameEngineActor
{
public:
	// constrcuter destructer
	BossHpbar();
	~BossHpbar();

	// delete Function
	BossHpbar(const BossHpbar& _Other) = delete;
	BossHpbar(BossHpbar&& _Other) noexcept = delete;
	BossHpbar& operator=(const BossHpbar& _Other) = delete;
	BossHpbar& operator=(BossHpbar&& _Other) noexcept = delete;


	void BossHpbarRender(int _Hp);
	void GetandSetMonstroHP();
	void ImageLoad();
protected:
	void Start() override;
	void Update(float _DeltaTime);

private:
	GameEngineRender* BossHpbarRender100 = nullptr;
	GameEngineRender* BossHpbarBackRender100 = nullptr;
	

	

	int MonstroHp = 0;

};

