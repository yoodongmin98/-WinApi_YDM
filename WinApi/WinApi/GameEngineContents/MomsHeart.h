#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include <GameEnginePlatform/GameEngineImage.h>
#include <GameEngineCore/GameEngineResources.h>


class MomsHeart : public GameEngineActor
{
public:
	static MomsHeart* MainMomsHeart;
	MomsHeart();
	~MomsHeart();


	MomsHeart(const MomsHeart& _Other) = delete;
	MomsHeart(MomsHeart&& _Other) noexcept = delete;
	MomsHeart& operator=(const MomsHeart& _Other) = delete;
	MomsHeart& operator=(MomsHeart&& _Other) noexcept = delete;
	void ImageLoad();
	void CollisionCheck(float _DeltaTime);

	int GetMomsHeartHp()
	{
		return MomsHeartHp;
	}
protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void Render(float _DeltaTime);
	
	void MonsterSet(float _DeltaTime);

	void Pattern1(float _Time);
	

	void Attack1();
	GameEngineSoundPlayer CALLISAAC;
	GameEngineSoundPlayer LAUGHMOM;
	GameEngineSoundPlayer DEATHBURST;
	

private:
	GameEngineRender* M_MomsHeart = nullptr;

	GameEngineCollision* M_MomsHeart_Coll = nullptr;
	GameEngineCollision* M_MomsHeart_SetColl_R = nullptr;

	float NowTime = 0.0f;
	float AttackTime = 0.0f;
	float NewMonsterTime = 0.0f;
	
	float UpdateTime = 0.0f;


	int MomsHeartHp = 66;
	int RESET = 1;
	bool MomsHeartDeathcheck = false;
	bool Countbool = true;
	bool asdasdasdasd = true;
	bool MonsterLoad = true;




	float PatternTime1 = 0.0f;
	float PatternTime2 = 0.0f;
	float Pattern2EndTime = 0.0f;

	bool MomsAttackBool1 = true;
	bool Pattern1Bool = true;
	bool Pattern2Bool = false;
	bool Pattern3Bool = false;
};

