#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include <GameEnginePlatform/GameEngineImage.h>
#include <GameEngineCore/GameEngineResources.h>


class Target : public GameEngineActor
{
public:
	Target();
	~Target();


	Target(const Target& _Other) = delete;
	Target(Target&& _Other) noexcept = delete;
	Target& operator=(const Target& _Other) = delete;
	Target& operator=(Target&& _Other) noexcept = delete;
	void ImageLoad();


	GameEngineSoundPlayer SHOOTSOUND;

protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	
	

private:
	GameEngineRender* M_Target = nullptr;
	
	float TargetAttTime = 0.0f;
	

	bool TearBool = true;
};

