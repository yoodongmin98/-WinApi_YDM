#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include <GameEnginePlatform/GameEngineImage.h>


class Monster_Fly : public GameEngineActor
{
public:
	Monster_Fly();
	~Monster_Fly();


	Monster_Fly(const Monster_Fly& _Other) = delete;
	Monster_Fly(Monster_Fly&& _Other) noexcept = delete;
	Monster_Fly& operator=(const Monster_Fly& _Other) = delete;
	Monster_Fly& operator=(Monster_Fly&& _Other) noexcept = delete;
	void ImageLoad();

	
protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void Render(float _DeltaTime);
	void Movecalculation(float _DeltaTime);

private:
	GameEngineRender* M_fly = nullptr;
	GameEngineCollision* M_fly_Coll = nullptr;

	float NowTime = 0.0f;
	int FlyHp = 3;
	int RESET = 1;
};

