#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include <GameEnginePlatform/GameEngineImage.h>
#include <GameEngineCore/GameEngineResources.h>


class NextLevelDoor : public GameEngineActor
{
public:
	NextLevelDoor();
	~NextLevelDoor();


	NextLevelDoor(const NextLevelDoor& _Other) = delete;
	NextLevelDoor(NextLevelDoor&& _Other) noexcept = delete;
	NextLevelDoor& operator=(const NextLevelDoor& _Other) = delete;
	NextLevelDoor& operator=(NextLevelDoor&& _Other) noexcept = delete;

	void SoundLoad();
	void ImageLoad();
protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void Render(float _DeltaTime);
	void CollisionCheck(float _DeltaTime);

private:
	GameEngineRender* R_NextLevelDoor = nullptr;
	GameEngineCollision* NextLevelDoor_Coll = nullptr;

	float NowTime = 0.0f;
};

