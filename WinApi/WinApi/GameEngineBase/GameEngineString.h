#pragma once
class GameEngineString
{
public:

	GameEngineString(const GameEngineString& _Other) = delete;
	GameEngineString(GameEngineString&& _Other)noexcept = delete;
	GameEngineString operator=(GameEngineString&& _Other) = delete;
	GameEngineString operator=(const GameEngineString& _Other) noexcept= delete;
protected:

private:
	GameEngineString();
	~GameEngineString();
};

