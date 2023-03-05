#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include <GameEnginePlatform/GameEngineImage.h>


class MuliBoom : public GameEngineActor
{
public:
	MuliBoom();
	~MuliBoom();


	MuliBoom(const MuliBoom& _Other) = delete;
	MuliBoom(MuliBoom&& _Other) noexcept = delete;
	MuliBoom& operator=(const MuliBoom& _Other) = delete;
	MuliBoom& operator=(MuliBoom&& _Other) noexcept = delete;
	void ImageLoad();
	void CollisionCheck(float _DeltaTime);

protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void Render(float _DeltaTime);
	void Movecalculation(float _DeltaTime);
	void HpCheck(float _DeltaTime);

private:
	GameEngineRender* M_MuliBoom = nullptr;
	GameEngineRender* M_MuliBoomBodys = nullptr;

	GameEngineCollision* M_MuliBoom_Coll = nullptr;
	GameEngineCollision* M_MuliBoomBody_Coll = nullptr;
	GameEngineCollision* M_MuliBoomBodys_SetColl_R = nullptr;

	
	float NowTime = 0.0f;
	int MuliBoomHp = 6;
	int RESET = 1;
	bool MuliBoomDeathcheck = false;
	bool Countbool = true;
};

