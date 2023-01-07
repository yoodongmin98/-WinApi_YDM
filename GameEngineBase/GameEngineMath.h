#pragma once
class GameEngineMath
{
public:
	GameEngineMath();
	~GameEngineMath();

	GameEngineMath(const GameEngineMath& _Other) = delete;
	GameEngineMath(GameEngineMath&& _Other)noexcept = delete;
	GameEngineMath operator=(GameEngineMath&& _Other) = delete;
	GameEngineMath operator=(const GameEngineMath& _Other) noexcept= delete;
protected:

private:
};

