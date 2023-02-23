#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include <GameEnginePlatform/GameEngineImage.h>


class FireWood : public GameEngineActor
{
public:
	FireWood();
	~FireWood();


	FireWood(const FireWood& _Other) = delete;
	FireWood(FireWood&& _Other) noexcept = delete;
	FireWood& operator=(const FireWood& _Other) = delete;
	FireWood& operator=(FireWood&& _Other) noexcept = delete;


	void ImageLoad();
	void GetFireHpSet();
	void WoodRender(int _FireHp);

protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void Render(float _DeltaTime);
	

private:
	GameEngineRender* R_FireWood = nullptr;
	
	int FireHp = 0;
};

