#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include <map>
#include <string>
#include <vector>
#include <string_view>

//Level Render����
class AllBack : public GameEngineActor //object��ӹ��� actor�����
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
		//�̹����̸�, enumŸ�Թޱ�
	}

protected:
	

private:

	std::vector<GameEngineRender*> AllRender;

};

