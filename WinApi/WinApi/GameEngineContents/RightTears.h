#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include <GameEngineCore/GameEngineCollision.h>
#include <GameEngineCore/GameEngineResources.h>

class GameEngineImage;
class RightTears : public GameEngineActor
{
public:
	RightTears();
	~RightTears();

	RightTears(const RightTears& _Other) = delete;
	RightTears(RightTears&& _Other) noexcept = delete;
	RightTears& operator=(const RightTears& _Other) = delete;
	RightTears& operator=(RightTears&& _Other) noexcept = delete;

	void SetRightMoveDir(float4 _MoveDir)
	{
		MoveDir = _MoveDir;
		MoveDir.Normalize();
	}
	void PlopSounds();
protected:
	GameEngineSoundPlayer PLOPSOUND;
	
	void Start() override;
	void Update(float _DeltaTime) override;
	void Render(float _DeltaTime) override;
	void MoveCalculation(float _DeltaTime);
private:

	GameEngineRender* AnimationRender = nullptr;
	GameEngineCollision* Collision = nullptr;

	float TearfallValue = 0.3f;
	float GravityTimeR = 0.0f;
	float4 MoveDir = float4::Zero;
};
