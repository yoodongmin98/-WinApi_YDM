#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include <GameEnginePlatform/GameEngineImage.h>


class Clot : public GameEngineActor
{
public:
	Clot();
	~Clot();


	Clot(const Clot& _Other) = delete;
	Clot(Clot&& _Other) noexcept = delete;
	Clot& operator=(const Clot& _Other) = delete;
	Clot& operator=(Clot&& _Other) noexcept = delete;
	void ImageLoad();
	void CollisionCheck(float _DeltaTime);

protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void Render(float _DeltaTime);
	void Movecalculation(float _DeltaTime);

private:
	GameEngineRender* M_Clot = nullptr;
	GameEngineRender* DeadRender_Clot = nullptr;
	GameEngineCollision* M_Clot_Coll = nullptr;
	GameEngineCollision* M_Clot_SetColl_R = nullptr;

	float ClotAttTime = 0.0f;
	float NowTime = 0.0f;
	int ClotHp = 3;
	int RESET = 1;

	bool ClotDeathcheck = false;
	bool Countbool = true;
};

