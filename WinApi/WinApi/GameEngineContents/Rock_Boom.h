#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include <GameEnginePlatform/GameEngineImage.h>


class Rock_Boom : public GameEngineActor
{
public:
	Rock_Boom();
	~Rock_Boom();


	Rock_Boom(const Rock_Boom& _Other) = delete;
	Rock_Boom(Rock_Boom&& _Other) noexcept = delete;
	Rock_Boom& operator=(const Rock_Boom& _Other) = delete;
	Rock_Boom& operator=(Rock_Boom&& _Other) noexcept = delete;


	void ImageLoad();


protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void Render(float _DeltaTime);
	void CollisionCheck(float _DeltaTime);

private:
	GameEngineRender* R_Rock_Boom = nullptr;
	GameEngineCollision* Rock_Boom_Coll = nullptr;
};

