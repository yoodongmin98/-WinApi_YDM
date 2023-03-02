#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include <GameEngineCore/GameEngineCollision.h>
#include <GameEngineCore/GameEngineResources.h>


class ItemHeart : public GameEngineActor
{
public:
	ItemHeart();
	~ItemHeart();

	ItemHeart(const ItemHeart& _Other) = delete;
	ItemHeart(ItemHeart&& _Other) noexcept = delete;
	ItemHeart& operator=(const ItemHeart& _Other) = delete;
	ItemHeart& operator=(ItemHeart&& _Other) noexcept = delete;

	void ImageLoad();
protected:

	void Start() override;
	void Update(float _DeltaTime) override;
	void Render(float _DeltaTime) override;

private:
	GameEngineRender* ItemHeartRender = nullptr;
	GameEngineCollision* ItemHeartCollision = nullptr;

};
