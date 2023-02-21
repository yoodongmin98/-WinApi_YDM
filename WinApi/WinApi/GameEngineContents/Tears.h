#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include <GameEngineCore/GameEngineCollision.h>

class GameEngineImage;
class Tears : public GameEngineActor
{
public:
	Tears();
	~Tears();

	Tears(const Tears& _Other) = delete;
	Tears(Tears&& _Other) noexcept = delete;
	Tears& operator=(const Tears& _Other) = delete;
	Tears& operator=(Tears&& _Other) noexcept = delete;

	static bool IsMaxTear()
	{
		return MaxTear <= TearNumber;
	}

protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void Render(float _DeltaTime) override;
	void MoveCalculation(float _DeltaTime);
	void CheckHit(float _DeltaTime);
private:
	float DeadTime = 0.0f;
	GameEngineRender* AnimationRender = nullptr;
	GameEngineCollision* Collision = nullptr;
	
	static const int MaxTear = 4;
	static int TearNumber;

	float4 MoveDir = float4::Zero;
};
