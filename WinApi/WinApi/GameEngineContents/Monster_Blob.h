#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include <GameEnginePlatform/GameEngineImage.h>


class Monster_Blob : public GameEngineActor
{
public:
	Monster_Blob();
	~Monster_Blob();


	Monster_Blob(const Monster_Blob& _Other) = delete;
	Monster_Blob(Monster_Blob&& _Other) noexcept = delete;
	Monster_Blob& operator=(const Monster_Blob& _Other) = delete;
	Monster_Blob& operator=(Monster_Blob&& _Other) noexcept = delete;
	void ImageLoad();
	void CollisionCheck(float _DeltaTime);

protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void Render(float _DeltaTime);
	void Movecalculation(float _DeltaTime);

private:
	GameEngineRender* M_Blob = nullptr;
	GameEngineRender* DeadRender_Blob = nullptr;
	GameEngineCollision* M_Blob_Coll = nullptr;
	GameEngineCollision* M_Blob_SetColl_R = nullptr;

	float NowTime = 0.0f;
	int BlobHp = 3;
	int RESET = 1;
};

