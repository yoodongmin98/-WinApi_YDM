#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include <GameEngineCore/GameEngineCollision.h>
#include <GameEngineCore/GameEngineResources.h>


class Leo : public GameEngineActor
{
public:
	Leo();
	~Leo();

	Leo(const Leo& _Other) = delete;
	Leo(Leo&& _Other) noexcept = delete;
	Leo& operator=(const Leo& _Other) = delete;
	Leo& operator=(Leo&& _Other) noexcept = delete;

	void ImageLoad();
protected:

	void Start() override;
	void Update(float _DeltaTime) override;
	void Render(float _DeltaTime) override;

private:
	GameEngineRender* LeoRender = nullptr;
	GameEngineCollision* LeoCollision = nullptr;

};
