#pragma once
#include <GameEngineCore/GameEngineActor.h>

class IntroPhoto :public GameEngineActor
{
public:
	IntroPhoto();
	~IntroPhoto();

	IntroPhoto(const IntroPhoto& _Other) = delete;
	IntroPhoto(IntroPhoto&& _Other)noexcept = delete;
	IntroPhoto operator=(IntroPhoto&& _Other) = delete;
	IntroPhoto operator=(const IntroPhoto& _Other) noexcept= delete;
protected:
	
	void Start() override; //actor의virtual함수->자식쪽실행 ㅇㅇ


private:
};

