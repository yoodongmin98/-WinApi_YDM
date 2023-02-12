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

	// Ű�Է��� �ްų� �ΰ������� ������ ����ϰų� �ϴ� �͵��� ���⼭ ó��
	void Update(float _DeltaTime) override;

	// ������ ���� �Լ��� �ѹ� �������ϰ� 
	void LateUpdate(float _DeltaTime) override;

	// ȭ�鿡 �׷����� ��ɵ��� ���⼭ ó��
	void Render(float _DeltaTime) override;
private:
	GameEngineRender* Bomb = nullptr;
};

