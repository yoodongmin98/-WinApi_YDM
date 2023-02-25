#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include <GameEngineCore/GameEngineCollision.h>
#include <GameEngineCore/GameEngineResources.h>

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

	float GravityTimeU = 0.0f;

	float4 MoveDir = float4::Zero;
};
