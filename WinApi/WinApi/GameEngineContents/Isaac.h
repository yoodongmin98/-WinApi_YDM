#pragma once
#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
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
	float MoveSpeed = 100.0f;
	Isaac* Bomb;

	GameEngineRender* AnimationRender;

};

