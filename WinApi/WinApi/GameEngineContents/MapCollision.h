#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include <GameEnginePlatform/GameEngineImage.h>


class MapCollision : public GameEngineActor
{
public:
	MapCollision();
	~MapCollision();


	MapCollision(const MapCollision& _Other) = delete;
	MapCollision(MapCollision&& _Other) noexcept = delete;
	MapCollision& operator=(const MapCollision& _Other) = delete;
	MapCollision& operator=(MapCollision&& _Other) noexcept = delete;
protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void Render(float _DeltaTime);
private:

	GameEngineCollision* Room1Collision = nullptr;
	GameEngineCollision* Room2Collision = nullptr;
	GameEngineCollision* Room3Collision = nullptr;
	GameEngineCollision* Room4Collision = nullptr;
	GameEngineCollision* Room5Collision = nullptr;
	GameEngineCollision* Room6Collision = nullptr;


	

};

