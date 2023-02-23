#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include <GameEnginePlatform/GameEngineImage.h>


class Poop : public GameEngineActor
{
public:
	Poop();
	~Poop();


	Poop(const Poop& _Other) = delete;
	Poop(Poop&& _Other) noexcept = delete;
	Poop& operator=(const Poop& _Other) = delete;
	Poop& operator=(Poop&& _Other) noexcept = delete;


	void ImageLoad();
	

protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void Render(float _DeltaTime);
	void CollisionCheck(float _DeltaTime);

private:
	GameEngineRender* R_Poop = nullptr;
	GameEngineCollision* Poop_Coll = nullptr;

	int PoopHp = 4;
};

