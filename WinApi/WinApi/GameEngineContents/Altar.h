#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include <GameEngineCore/GameEngineCollision.h>
#include <GameEngineCore/GameEngineResources.h>


class Altar : public GameEngineActor
{
public:
	Altar();
	~Altar();

	Altar(const Altar& _Other) = delete;
	Altar(Altar&& _Other) noexcept = delete;
	Altar& operator=(const Altar& _Other) = delete;
	Altar& operator=(Altar&& _Other) noexcept = delete;

	void ImageLoad();
protected:
	
	void Start() override;
	void Update(float _DeltaTime) override;
	void Render(float _DeltaTime) override;

private:
	GameEngineRender*AltarRender = nullptr;
	
};
