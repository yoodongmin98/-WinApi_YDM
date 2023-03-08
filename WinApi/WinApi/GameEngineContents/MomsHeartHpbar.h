#pragma once

#include <GameEngineCore/GameEngineActor.h>


class MomsHpbar : public GameEngineActor
{
public:
	// constrcuter destructer
	MomsHpbar();
	~MomsHpbar();

	// delete Function
	MomsHpbar(const MomsHpbar& _Other) = delete;
	MomsHpbar(MomsHpbar&& _Other) noexcept = delete;
	MomsHpbar& operator=(const MomsHpbar& _Other) = delete;
	MomsHpbar& operator=(MomsHpbar&& _Other) noexcept = delete;


	void BossHpbarRender(int _Hp);
	void GetandSetMomsHP();
	
protected:
	void Start() override;
	void Update(float _DeltaTime);

private:
	GameEngineRender* BossHpbarRender1000 = nullptr;
	GameEngineRender* BossHpbarBackRender1000 = nullptr;




	int MomsHp = 0;

};

