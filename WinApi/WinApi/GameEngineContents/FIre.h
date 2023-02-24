#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include <GameEnginePlatform/GameEngineImage.h>
#include <GameEngineCore/GameEngineResources.h>


class Fire : public GameEngineActor
{
public:
	static Fire* MainFire;
	Fire();
	~Fire();


	Fire(const Fire& _Other) = delete;
	Fire(Fire&& _Other) noexcept = delete;
	Fire& operator=(const Fire& _Other) = delete;
	Fire& operator=(Fire&& _Other) noexcept = delete;

	void SoundLoad();
	void ImageLoad();
	int GetFireHp()
	{
		return FireHp;
	}

protected:
	GameEngineSoundPlayer FIRESOUND;
	void Start() override;
	void Update(float _DeltaTime) override;
	void Render(float _DeltaTime);
	void CollisionCheck(float _DeltaTime);

private:
	GameEngineRender* R_Fire = nullptr;
	GameEngineCollision* Fire_Coll = nullptr;

	
	int FireHp = 5;
};

