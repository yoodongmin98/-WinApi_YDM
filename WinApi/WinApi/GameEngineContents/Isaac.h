#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include <GameEngineCore/GameEngineCollision.h>
#include <GameEngineCore/GameEngineResources.h>

enum class IsaacState
{
	IDLE,
	MOVE,
	PICK,
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
	
	
	GameEngineCollision* GetIsaacCollision()
	{
		return IsaacCollision;
	}
	
	/////////MonsterCount
	
	int GetMonsterCount()
	{
		return MonsterCount;
	}
	void SetMonsterCount(int _Count)
	{
		MonsterCount = _Count;
	}
	void MinusMonsterCount(int _DeathCount)
	{
		MonsterCount -= _DeathCount;
	}
	void PlusMOnsterCount(int _CreateCount)
	{
		MonsterCount += _CreateCount;
	}

	
	int GetIsCoinBombCount()
	{
		return IsCoinBombCount;
	}
	int GetIsCoinHeartCount()
	{
		return IsCoinHeartCount;
	}
	int GetIsCoinKeyCount()
	{
		return IsCoinKeyCount;
	}

	bool GetMomBossRenderValue()
	{
		return MomBossRenderValue;
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
	
	float DamagedTime = 0.0f;
	float PickUpTime = 0.0f;

	float PickTime = 0.0f;
	float FlickerTime =0.0f;
	float DeadTime = 0.0f;
	float CollTime = 0.0f;
	float ResetTime_T = 0.0f;
	float ResetTime_B = 0.0f;
	float MoveSpeed = 300.0f;
	float4 MoveDir = float4::Zero;
	float4 MoveRange = float4::Zero;

	////////Tear???? ??????,????,????,??????//////////

	
	float TearUseTime = 0.3f; 
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

	bool DeadIsaac = false; //?? ??????????? ?????????? ??????????????


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

	void PickStart();
	void PickUpdate(float _Time);
	void PickEnd();

	void DamagedStart();
	void DamagedUpdate(float _Time);
	void DamagedEnd();

	
	void DamageUpdate(float _Time);
	void TearsAttack(float _DeltaTime);




	int MonsterCount = 0;

	bool IsaacMapMove = true;


	int IsCoinBombCount = 1;
	int IsCoinHeartCount = 1;
	int IsCoinKeyCount = 1;

	bool MomBossRenderValue = false;

};

