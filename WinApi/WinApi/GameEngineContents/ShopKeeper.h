#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include <GameEnginePlatform/GameEngineImage.h>


class ShopKeeper : public GameEngineActor
{
public:
	ShopKeeper();
	~ShopKeeper();


	ShopKeeper(const ShopKeeper& _Other) = delete;
	ShopKeeper(ShopKeeper&& _Other) noexcept = delete;
	ShopKeeper& operator=(const ShopKeeper& _Other) = delete;
	ShopKeeper& operator=(ShopKeeper&& _Other) noexcept = delete;


	void ImageLoad();


protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void Render(float _DeltaTime);
	void CollisionCheck(float _DeltaTime);

private:
	GameEngineRender* R_ShopKeeper = nullptr;
	GameEngineRender* R_Coin3 = nullptr;
	GameEngineRender* R_Coin5 = nullptr;
	GameEngineRender* R_Coin7 = nullptr;

	GameEngineCollision* ShopKeeper_Coll = nullptr;
};

