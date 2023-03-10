#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include <GameEnginePlatform/GameEngineImage.h>
#include <GameEngineCore/GameEngineResources.h>


class MapCollision : public GameEngineActor
{
public:
	MapCollision();
	~MapCollision();


	MapCollision(const MapCollision& _Other) = delete;
	MapCollision(MapCollision&& _Other) noexcept = delete;
	MapCollision& operator=(const MapCollision& _Other) = delete;
	MapCollision& operator=(MapCollision&& _Other) noexcept = delete;

	void DoorSoundSet();
protected:
	GameEngineSoundPlayer DOOROPEN;
	GameEngineSoundPlayer DOORCLOSE;
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
	GameEngineCollision* Room7Collision = nullptr;
	GameEngineCollision* Room8Collision = nullptr;
	GameEngineCollision* Room8Collision2 = nullptr;
	GameEngineCollision* Room9Collision = nullptr;
	GameEngineCollision* Room10Collision = nullptr;
	GameEngineCollision* Room11Collision = nullptr;




	GameEngineCollision* Door = nullptr;



	bool Room1 = true;
	bool Room2 = true;
	bool Room5 = true;
	bool Room6 = true;
	bool Room7 = true;
	bool Room8 = true;

};

