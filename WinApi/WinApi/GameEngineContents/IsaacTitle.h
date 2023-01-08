#pragma once
#include <GameEngineCore/GameEngineLevel.h>
class IsaacTitle : public GameEngineLevel
{
public:
	IsaacTitle();
	~IsaacTitle();

	IsaacTitle(const IsaacTitle& _Other) = delete;
	IsaacTitle(IsaacTitle&& _Other)noexcept = delete;
	IsaacTitle operator=(IsaacTitle&& _Other) = delete;
	IsaacTitle operator=(const IsaacTitle& _Other) noexcept= delete;
protected:
							
	void Loading() override;
	void Update() override;

private:
};

