#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include <GameEnginePlatform/GameEngineImage.h>


class Monstro : public GameEngineActor
{
public:
	static Monstro* MainMonstro;
	Monstro();
	~Monstro();


	Monstro(const Monstro& _Other) = delete;
	Monstro(Monstro&& _Other) noexcept = delete;
	Monstro& operator=(const Monstro& _Other) = delete;
	Monstro& operator=(Monstro&& _Other) noexcept = delete;
	void ImageLoad();
	void CollisionCheck(float _DeltaTime);

	int GetMonstroHp()
	{
		return MonstroHp;
	}
protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void Render(float _DeltaTime);
	void Movecalculation(float _DeltaTime);


	void Attack1();

private:
	GameEngineRender* M_Monstro = nullptr;
	
	GameEngineCollision* M_Monstro_Coll = nullptr;
	GameEngineCollision* M_Monstro_SetColl_R = nullptr;

	float NowTime = 0.0f;
	float PatternTime = 0.0f;
	float AttackTime = 0.0f;
	float JumpCheckTime = 0.0f;


	int MonstroHp = 33;
	int RESET = 1;
	bool MonstroDeathcheck = false;
	bool AttackBool = true;
	bool Countbool = true;

	bool MonsterLoad = true;
};

