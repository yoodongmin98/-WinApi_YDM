#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include <GameEnginePlatform/GameEngineImage.h>
#include "Monster.h"


class Door : public GameEngineActor
{
public:
	Door();
	~Door();


	Door(const Door& _Other) = delete;
	Door(Door&& _Other) noexcept = delete;
	Door& operator=(const Door& _Other) = delete;
	Door& operator=(Door&& _Other) noexcept = delete;

	void ImageLoad();
protected:
	void Start() override;
	void Update(float _DeltaTime) override;

private:
	GameEngineRender* Door1 = nullptr;
	GameEngineCollision* Door1_C = nullptr;
	

};
