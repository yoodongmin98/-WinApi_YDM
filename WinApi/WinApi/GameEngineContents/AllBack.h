#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include <map>
#include <string>
#include <vector>
#include <string_view>

// 설명 :
class AllBack : public GameEngineActor //object상속받은 actor를상속
{
public:
	// constrcuter destructer
	AllBack();
	~AllBack();

	GameEngineRender* CreateRender(const std::string_view& _Image, int _Order);

	// delete Function
	AllBack(const AllBack& _Other) = delete;
	AllBack(AllBack&& _Other) noexcept = delete;
	AllBack& operator=(const AllBack& _Other) = delete;
	AllBack& operator=(AllBack&& _Other) noexcept = delete;

	template <typename Enum>
	GameEngineRender* CreateRender(const std::string_view& _Image, Enum _Order)
	{
		return CreateRender(_Image, static_cast<int>(_Order));
		//이미지이름, enum타입받기
	}


	void Reserve(int _Capacity)
	{
		AllRender.reserve(_Capacity);
	}
protected:
	

private:

	std::vector<GameEngineRender*> AllRender;

};

