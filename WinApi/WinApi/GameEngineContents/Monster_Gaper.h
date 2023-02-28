#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include <GameEnginePlatform/GameEngineImage.h>


class Gaper : public GameEngineActor
{
public:
	Gaper();
	~Gaper();


	Gaper(const Gaper& _Other) = delete;
	Gaper(Gaper&& _Other) noexcept = delete;
	Gaper& operator=(const Gaper& _Other) = delete;
	Gaper& operator=(Gaper&& _Other) noexcept = delete;
	void ImageLoad();
	void CollisionCheck(float _DeltaTime);

protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void Render(float _DeltaTime);
	void Movecalculation(float _DeltaTime);
	void HpCheck(float _DeltaTime);

private:
	GameEngineRender* M_Gaper = nullptr;
	GameEngineRender* M_GaperBodys = nullptr;
	GameEngineCollision* M_Gaper_Coll = nullptr;
	GameEngineCollision* M_GaperBody_Coll = nullptr;
	GameEngineCollision* M_GaperBodys_SetColl_R = nullptr;

	float GaperSpeed = 100.0f;
	float NowTime = 0.0f;
	int GaperHp = 6;
	int RESET = 1;
};

