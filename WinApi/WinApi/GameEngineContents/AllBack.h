#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include <map>
#include <string>
#include <vector>
#include <string_view>

//Level Render전용
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

protected:
	

private:

	std::vector<GameEngineRender*> AllRender;

};

