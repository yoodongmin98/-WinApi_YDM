#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include <GameEngineCore/GameEngineCollision.h>
#include <GameEngineCore/GameEngineResources.h>

enum class IsaacState
{
	IDLE,
	MOVE,
	DAMAGED,
};
class Isaac : public GameEngineActor
{
public:
	static Isaac* MainPlayer;

	Isaac();
	~Isaac();

	// delete Function
	Isaac(const Isaac& _Other) = delete;
	Isaac(Isaac&& _Other) noexcept = delete;
	Isaac& operator=(const Isaac& _Other) = delete;
	Isaac& operator=(Isaac&& _Other) noexcept = delete;

	void Movecalculation(float _DeltaTime);
	void CollisionCheck(float _DeltaTime);
	void DeathCheck(float _DeltaTime);
	void BombCheck(float _DeltaTime);

	int GetPlayerHP()
	{
		return HP;
	}
	int SetPlayerHP(int _HP)
	{
		return HP= _HP;
	}
	int GetKeyCount()
	{
		return KeyCount;
	}
	int GetBombCount()
	{
		return BombCount;
	}
	int GetCoinCount()
	{
		return CoinCount;
	}

	
protected:
	GameEngineSoundPlayer TEARSOUND;
	GameEngineSoundPlayer KEYDROPSOUND;
	GameEngineSoundPlayer ISAACHURT;
	GameEngineSoundPlayer COINDROP;
	
	
	void Start() override;
	void Update(float _DeltaTime) override;
	void Render(float _DeltaTime);
	void DebugSet();
	void TEARSOUNDS();

private:


	GameEngineRender* DeadMenu = nullptr;

	float DeadTime = 0.0f;
	float CollTime = 0.0f;
	float ResetTime_T = 0.0f;
	float ResetTime_B = 0.0f;
	float MoveSpeed = 300.0f;
	float4 MoveDir = float4::Zero;
	float4 MoveRange = float4::Zero;
	

	std::string DirString = "Right_";
	IsaacState StateValue = IsaacState::IDLE;

	GameEngineRender* Head = nullptr;

	GameEngineCollision* IsaacCollision = nullptr;

	
	int HP = 6;
	int MaxHP = 6;

	int KeyCount = 0;
	int BombCount = 0;
	int CoinCount = 0;


	bool DamagedIsaac = false;



	void DirCheck(const std::string_view& _AnimationName);

	// State
	void ChangeState(IsaacState _State);
	void UpdateState(float _Time);

	// FSM 내가 어떤일을 할때 이동하면서 가만히 있을수 없다.
	void IdleStart();
	void IdleUpdate(float _Time);
	void IdleEnd();

	void MoveStart();
	void MoveUpdate(float _Time);
	void MoveEnd();

	
	void DamageUpdate(float _Time);
	void TearsAttack(float _DeltaTime);
};

