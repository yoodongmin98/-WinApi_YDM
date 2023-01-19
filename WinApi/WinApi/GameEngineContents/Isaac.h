#pragma once
#include <GameEngineCore/GameEngineActor.h>

enum class IsaacState
{
	IDLE,
	MOVE,
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

protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void Render(float _Time) override;

private:
	float AccTime = 0.0f;
	int StartFrame = 0;
	float MoveSpeed = 150.0f;
	Isaac* Bomb=nullptr;

	std::string DirString = "Right_";
	IsaacState StateValue = IsaacState::IDLE;

	GameEngineRender* AnimationRender = nullptr;

	void DirCheck(const std::string_view& _AnimationName);

	// State
	void ChangeState(IsaacState _State);
	void UpdateState(float _Time);

	// FSM ���� ����� �Ҷ� �̵��ϸ鼭 ������ ������ ����.
	void IdleStart();
	void IdleUpdate(float _Time);
	void IdleEnd();

	void MoveStart();
	void MoveUpdate(float _Time);
	void MoveEnd();

};

