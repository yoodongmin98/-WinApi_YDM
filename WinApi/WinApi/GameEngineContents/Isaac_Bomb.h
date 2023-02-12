#pragma once
#include <GameEngineCore/GameEngineActor.h>

class Isaac_Bomb : public GameEngineActor
{
public:
	Isaac_Bomb();
	~Isaac_Bomb();

	Isaac_Bomb(const Isaac_Bomb& _Other) = delete;
	Isaac_Bomb(Isaac_Bomb&& _Other)noexcept = delete;
	Isaac_Bomb operator=(Isaac_Bomb&& _Other) = delete;
	Isaac_Bomb operator=(const Isaac_Bomb& _Other) noexcept= delete;

	
protected:
	void Start() override;

	// 키입력을 받거나 인공지능을 점수를 계산하거나 하는 것들을 여기서 처리
	void Update(float _DeltaTime) override;

	// 순서를 제어 함수를 한번 더실행하고 
	void LateUpdate(float _DeltaTime) override;

	// 화면에 그려지는 기능들을 여기서 처리
	void Render(float _DeltaTime) override;
private:
	GameEngineRender* Bomb = nullptr;
};

