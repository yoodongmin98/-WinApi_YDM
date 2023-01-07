#pragma once
class GameEngineWindow
{
public:
	GameEngineWindow();
	~GameEngineWindow();

	GameEngineWindow(const GameEngineWindow& _Other) = delete;
	GameEngineWindow(GameEngineWindow&& _Other)noexcept = delete;
	GameEngineWindow operator=(GameEngineWindow&& _Other) = delete;
	GameEngineWindow operator=(const GameEngineWindow& _Other) noexcept= delete;
protected:

private:
};

