#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include <GameEngineCore/GameEngineCollision.h>

enum class IsaacState
{
	IDLE,
	MOVE,
	DAMAGE,
};
class Isaac : public GameEngineActor
{
public:
	static Isaac* MainPlayer;

	// constrcuter destructer
	Isaac();
	~Isaac();

	// delete Function
	Isaac(const Isaac& _Other) = delete;
	Isaac(Isaac&& _Other) noexcept = delete;
	Isaac& operator=(const Isaac& _Other) = delete;
	Isaac& operator=(Isaac&& _Other) noexcept = delete;

	void Movecalculation(float _DeltaTime);
	
protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	

private:
	float AccTime = 0.0f;
	float ResetTime = 0.0f;
	float MoveSpeed = 400.0f;
	float4 MoveDir = float4::Zero;
	float4 MoveRange = float4::Zero;
	

	std::string DirString = "Right_";
	IsaacState StateValue = IsaacState::IDLE;

	GameEngineRender* Head = nullptr;
	GameEngineRender* Bomb = nullptr;

	
	

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

	void DamageStart();
	void DamageUpdate(float _Time);
	void DamageEnd();

	void TearsAttack(float _DeltaTime);
	GameEngineCollision* IsaacCollision = nullptr;
};

