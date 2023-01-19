#pragma once
#include <GameEngineCore/GameEngineActor.h>

enum class IssacState
{
	IDLE,
	MOVE,
};

// 설명 :
class Issac : public GameEngineActor
{
public:
	static Issac* MainPlayer;

	// constrcuter destructer
	Issac();
	~Issac();

	// delete Function
	Issac(const Issac& _Other) = delete;
	Issac(Issac&& _Other) noexcept = delete;
	Issac& operator=(const Issac& _Other) = delete;
	Issac& operator=(Issac&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void Render(float _Time) override;


private:
	float AccTime = 0.0f;
	int StartFrame = 0;
	float MoveSpeed = 100.0f;

	std::string DirString = "Right_";
	IssacState StateValue = IssacState::IDLE;

	GameEngineRender* AnimationRender = nullptr;


	void DirCheck(const std::string_view& _AnimationName);

	// State
	void ChangeState(IssacState _State);
	void UpdateState(float _Time);

	// FSM 내가 어떤일을 할때 이동하면서 가만히 있을수 없다.
	void IdleStart();
	void IdleUpdate(float _Time);
	void IdleEnd();

	void MoveStart();
	void MoveUpdate(float _Time);
	void MoveEnd();

};

