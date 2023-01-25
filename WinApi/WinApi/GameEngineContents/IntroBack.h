#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include <map>
#include <string>
#include <vector>
#include <string_view>

// 설명 :
class IntroBack : public GameEngineActor //object상속받은 actor를상속
{
public:
	// constrcuter destructer
	IntroBack();
	~IntroBack();

	GameEngineRender* CreateRender(const std::string_view& _Image, int _Order);

	// delete Function
	IntroBack(const IntroBack& _Other) = delete;
	IntroBack(IntroBack&& _Other) noexcept = delete;
	IntroBack& operator=(const IntroBack& _Other) = delete;
	IntroBack& operator=(IntroBack&& _Other) noexcept = delete;

	template <typename Enum>
	GameEngineRender* CreateRender(const std::string_view& _Image, Enum _Order)
	{
		return CreateRender(_Image, static_cast<int>(_Order));
		//이미지이름, enum타입받기
	}
	
	void SetReserve(int _C)
	{
		BackRender.reserve(_C); //벡터reserve값미리할당시키기
	}


protected:
	

private:

	std::vector<GameEngineRender*> BackRender;

};

