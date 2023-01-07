#pragma once
#include <assert.h>

// Ό³Έν :
class GameEngineDebug
{
public:
	// constrcuter destructer

	// delete Function
	GameEngineDebug(const GameEngineDebug& _Other) = delete;
	GameEngineDebug(GameEngineDebug&& _Other) noexcept = delete;
	GameEngineDebug& operator=(const GameEngineDebug& _Other) = delete;
	GameEngineDebug& operator=(GameEngineDebug&& _Other) noexcept = delete;


	static void LeckCheck();
protected:
private:
	GameEngineDebug();
	~GameEngineDebug();

};

void LeckCheck();

//#define MessageBoxAssert(MsgText) MessageBoxA(nullptr, MsgText, "Error", MB_OK);	assert(false);