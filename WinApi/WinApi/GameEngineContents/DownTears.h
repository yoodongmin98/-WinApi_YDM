#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include <GameEngineCore/GameEngineCollision.h>
#include <GameEngineCore/GameEngineResources.h>

class GameEngineImage;
class DownTears : public GameEngineActor
{
public:
	DownTears();
	~DownTears();

	DownTears(const DownTears& _Other) = delete;
	DownTears(DownTears&& _Other) noexcept = delete;
	DownTears& operator=(const DownTears& _Other) = delete;
	DownTears& operator=(DownTears&& _Other) noexcept = delete;


	void SetDownMoveDir(float4 _MoveDir)
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

	float GravityTimeD = 0.0f;

	float4 MoveDir = float4::Zero;
};
