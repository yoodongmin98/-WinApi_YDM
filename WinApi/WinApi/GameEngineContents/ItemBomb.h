#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include <GameEnginePlatform/GameEngineImage.h>


class ItemBomb : public GameEngineActor
{
public:
	ItemBomb();
	~ItemBomb();


	ItemBomb(const ItemBomb& _Other) = delete;
	ItemBomb(ItemBomb&& _Other) noexcept = delete;
	ItemBomb& operator=(const ItemBomb& _Other) = delete;
	ItemBomb& operator=(ItemBomb&& _Other) noexcept = delete;

	void ImageLoad();
protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void Render(float _DeltaTime);

private:
	GameEngineRender* R_ItemBomb = nullptr;
	GameEngineCollision* ItemBomb_Coll = nullptr;
};

