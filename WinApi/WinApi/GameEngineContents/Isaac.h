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
	////////////HP
	int GetPlayerHP()
	{
		return HP;
	}
	int SetPlayerHP(int _HP)
	{
		return HP= _HP;
	}
	////////////ITEM
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

	////////////   Tear   /////////////////
	float GetGravityValue()
	{
		return GravityValue;
	}
	float GetTearSpeed()
	{
		return TearSpeed;
	}
	float GetTearRange()
	{
		return TearRange;
	}
	int GetTearDamage()
	{
		return TearDamage;
	}
	float GetUpAcceleration()
	{
		return UpAcceleration;
	}
	float GetDownAcceleration()
	{
		return DownAcceleration;
	}
	float GetRightAcceleration()
	{
		return RightAcceleration;
	}
	float GetLeftAcceleration()
	{
		return LeftAcceleration;
	}
	
	GameEngineCollision* GetIsaacCollision()
	{
		return IsaacCollision;
	}

	
	///////////////////////////////////////
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


	
	float FlickerTime =0.0f;
	float DeadTime = 0.0f;
	float CollTime = 0.0f;
	float ResetTime_T = 0.0f;
	float ResetTime_B = 0.0f;
	float MoveSpeed = 300.0f;
	float4 MoveDir = float4::Zero;
	float4 MoveRange = float4::Zero;

	////////Tear관련 가속도,중력,속도,사거리//////////

	float UpAcceleration = 0.0f;
	float DownAcceleration = 0.0f;
	float RightAcceleration = 200.0f;
	float LeftAcceleration = 0.0f;
	float GravityValue = 0.4f;
	float TearSpeed = 400.0f;
	float TearRange = 0.8f;
	int TearDamage = 1;
	
	//////////Idle
	std::string DirString = "Right_";
	IsaacState StateValue = IsaacState::IDLE;


	//////// Isaac /////////
	GameEngineRender* Head = nullptr; 
	GameEngineCollision* IsaacCollision = nullptr;

	int HP = 6;
	int MaxHP = 6;

	bool DeadIsaac = false; //얘 왜만들었지? 내가써놓고 쓰임새를못찾음


	///////////Item Count
	int KeyCount = 0;
	int BombCount = 0;
	int CoinCount = 0;


	bool DamagedIsaac = false;



	void DirCheck(const std::string_view& _AnimationName);

	// State
	void ChangeState(IsaacState _State);
	void UpdateState(float _Time);

	void IdleStart();
	void IdleUpdate(float _Time);
	void IdleEnd();

	void MoveStart();
	void MoveUpdate(float _Time);
	void MoveEnd();

	
	void DamageUpdate(float _Time);
	void TearsAttack(float _DeltaTime);
};

