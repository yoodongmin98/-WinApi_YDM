#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include <GameEngineCore/GameEngineCollision.h>
#include <GameEngineCore/GameEngineResources.h>


class BlackLotus : public GameEngineActor
{
public:
	BlackLotus();
	~BlackLotus();

	BlackLotus(const BlackLotus& _Other) = delete;
	BlackLotus(BlackLotus&& _Other) noexcept = delete;
	BlackLotus& operator=(const BlackLotus& _Other) = delete;
	BlackLotus& operator=(BlackLotus&& _Other) noexcept = delete;

	void ImageLoad();
protected:

	void Start() override;
	void Update(float _DeltaTime) override;
	void Render(float _DeltaTime) override;

private:
	GameEngineRender* BlackLotusRender = nullptr;
	GameEngineCollision* BlackLotusCollision = nullptr;

};
