#pragma once
#include <GameEngineCore/GameEngineCore.h>

class IsaacCore : public GameEngineCore
{
public:
	IsaacCore(const IsaacCore& _Other) = delete;
	IsaacCore(IsaacCore&& _Other) noexcept = delete;
	IsaacCore& operator=(const IsaacCore& _Other) = delete;
	IsaacCore& operator=(IsaacCore&& _Other) noexcept = delete;


	static IsaacCore& GetInst()
	{
		return Core;
	}


protected:
	void Start() override;
	void Update() override;
	void End() override;


private:
	IsaacCore();
	~IsaacCore();
	static IsaacCore Core;

};

