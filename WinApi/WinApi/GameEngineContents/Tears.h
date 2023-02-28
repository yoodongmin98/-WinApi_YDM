#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include <GameEngineCore/GameEngineCollision.h>
#include <GameEngineCore/GameEngineResources.h>

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

	void PlopSounds();

	void SetLeftMoveDir(float4 _MoveDir)
	{
		MoveDir = _MoveDir;
		MoveDir.Normalize();
	}
	
protected:
	GameEngineSoundPlayer PLOPSOUND;
	

	void Start() override;
	void Update(float _DeltaTime) override;
	void Render(float _DeltaTime) override;
	void MoveCalculation(float _DeltaTime);
	
private:
	float DeadTime = 0.0f;
	float GravityTime = 0.0f;
	GameEngineRender* AnimationRender = nullptr;
	GameEngineCollision* Collision = nullptr;
	
	float LTearfallValue = 0.3f;
	float4 MoveDir = float4::Zero;
};
