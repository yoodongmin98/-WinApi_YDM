#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include <GameEngineCore/GameEngineCollision.h>
#include <GameEngineCore/GameEngineResources.h>


class Glasses : public GameEngineActor
{
public:
	Glasses();
	~Glasses();

	Glasses(const Glasses& _Other) = delete;
	Glasses(Glasses&& _Other) noexcept = delete;
	Glasses& operator=(const Glasses& _Other) = delete;
	Glasses& operator=(Glasses&& _Other) noexcept = delete;

	void ImageLoad();
protected:

	void Start() override;
	void Update(float _DeltaTime) override;
	void Render(float _DeltaTime) override;

private:
	GameEngineRender* GlassesRender = nullptr;
	GameEngineCollision* GlassesCollision = nullptr;

};
