#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include <GameEnginePlatform/GameEngineImage.h>


class Bomb : public GameEngineActor
{
public:
	Bomb();
	~Bomb();


	Bomb(const Bomb& _Other) = delete;
	Bomb(Bomb&& _Other) noexcept = delete;
	Bomb& operator=(const Bomb& _Other) = delete;
	Bomb& operator=(Bomb&& _Other) noexcept = delete;
	void ImageLoad();

	void FlikerSet(float _DeltaTime);
protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void Render(float _DeltaTime);
	void CollisionCheck(float _DeltaTime);

	GameEngineSoundPlayer BoomPlayer;
	
private:
	GameEngineRender* R_Bomb = nullptr;
	GameEngineRender* R_Bomb_Dead = nullptr;
	GameEngineCollision* Bomb_Coll = nullptr;

	float NowTime = 0.0f;

	float FTime = 0.0f;
	bool BoomSoundLoad = true;
	bool IsaacBombDeathCheck = false;
	
};

