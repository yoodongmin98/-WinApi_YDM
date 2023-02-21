#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include <GameEngineCore/GameEngineCollision.h>

class GameEngineImage;
class UpTears : public GameEngineActor
{
public:
	UpTears();
	~UpTears();

	UpTears(const UpTears& _Other) = delete;
	UpTears(UpTears&& _Other) noexcept = delete;
	UpTears& operator=(const UpTears& _Other) = delete;
	UpTears& operator=(UpTears&& _Other) noexcept = delete;

	static bool IsMaxTear()
	{
		return MaxTear <= TearNumber;
	}

protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void Render(float _DeltaTime) override;
	void MoveCalculation(float _DeltaTime);
private:

	GameEngineRender* AnimationRender = nullptr;
	GameEngineCollision* Collision = nullptr;

	static const int MaxTear = 4;
	static int TearNumber;

	float4 MoveDir = float4::Zero;
};
