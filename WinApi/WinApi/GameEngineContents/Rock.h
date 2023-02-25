#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include <GameEnginePlatform/GameEngineImage.h>


class Rock : public GameEngineActor
{
public:
	Rock();
	~Rock();


	Rock(const Rock& _Other) = delete;
	Rock(Rock&& _Other) noexcept = delete;
	Rock& operator=(const Rock& _Other) = delete;
	Rock& operator=(Rock&& _Other) noexcept = delete;


	void ImageLoad();


protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void Render(float _DeltaTime);
	void CollisionCheck(float _DeltaTime);

private:
	GameEngineRender* R_Rock = nullptr;
	GameEngineCollision* Rock_Coll = nullptr;
};

