#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include <GameEnginePlatform/GameEngineImage.h>


class Key : public GameEngineActor
{
public:
	Key();
	~Key();


	Key(const Key& _Other) = delete;
	Key(Key&& _Other) noexcept = delete;
	Key& operator=(const Key& _Other) = delete;
	Key& operator=(Key&& _Other) noexcept = delete;


	void ImageLoad();


protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void Render(float _DeltaTime);
	void CollisionCheck(float _DeltaTime);

private:
	GameEngineRender* R_Key = nullptr;
	GameEngineCollision* Key_Coll = nullptr;
};

