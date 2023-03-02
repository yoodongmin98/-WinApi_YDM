#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include <GameEngineCore/GameEngineCollision.h>
#include <GameEngineCore/GameEngineResources.h>

class GameEngineImage;
class BloodTear : public GameEngineActor
{
public:
	BloodTear();
	~BloodTear();

	BloodTear(const BloodTear& _Other) = delete;
	BloodTear(BloodTear&& _Other) noexcept = delete;
	BloodTear& operator=(const BloodTear& _Other) = delete;
	BloodTear& operator=(BloodTear&& _Other) noexcept = delete;

	void ImageLoad();

	void SetBloodMoveDir(float4 _MoveDir)
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
	float TearRangeTime = 0.0f;

	GameEngineRender* BloodTearRender = nullptr;
	GameEngineCollision* BloodTearCollision = nullptr;

	
	float4 MoveDir = float4::Zero;
};
