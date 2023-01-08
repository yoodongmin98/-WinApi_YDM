#pragma once
#include <GameEngineCore/GameEngineActor.h>


class Isaac : public GameEngineActor
{
public:
	Isaac();
	~Isaac();

	Isaac(const Isaac& _Other) = delete;
	Isaac(Isaac&& _Other) noexcept = delete;
	Isaac& operator=(const Isaac& _Other) = delete;
	Isaac& operator=(Isaac&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update() override;
	void Render() override;

private:

};

