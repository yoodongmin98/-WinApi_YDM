#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include <GameEnginePlatform/GameEngineImage.h>


class Spike : public GameEngineActor
{
public:
	Spike();
	~Spike();


	Spike(const Spike& _Other) = delete;
	Spike(Spike&& _Other) noexcept = delete;
	Spike& operator=(const Spike& _Other) = delete;
	Spike& operator=(Spike&& _Other) noexcept = delete;


	void ImageLoad();


protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void Render(float _DeltaTime);
	void CollisionCheck(float _DeltaTime);

private:
	GameEngineRender* Spikes = nullptr;
	GameEngineCollision* Spike_Coll = nullptr;

};

