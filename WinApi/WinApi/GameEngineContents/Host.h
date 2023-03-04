#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include <GameEnginePlatform/GameEngineImage.h>


class Host : public GameEngineActor
{
public:
	Host();
	~Host();


	Host(const Host& _Other) = delete;
	Host(Host&& _Other) noexcept = delete;
	Host& operator=(const Host& _Other) = delete;
	Host& operator=(Host&& _Other) noexcept = delete;
	void ImageLoad();
	void CollisionCheck(float _DeltaTime);

protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void Render(float _DeltaTime);
	

private:
	GameEngineRender* M_Host = nullptr;
	GameEngineRender* DeadHost = nullptr;
	GameEngineCollision* M_Host_Coll = nullptr;

	float NowTime = 0.0f;
	int HostHp = 5;
	int RESET = 1;
	bool HostDeathcheck = false;
};

