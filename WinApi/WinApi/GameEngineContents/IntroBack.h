#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include <map>
#include <string>
#include <vector>
#include <string_view>

// ���� :
class IntroBack : public GameEngineActor //object��ӹ��� actor�����
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
		//�̹����̸�, enumŸ�Թޱ�
	}
	
	void SetReserve(int _C)
	{
		BackRender.reserve(_C); //����reserve���̸��Ҵ��Ű��
	}


protected:
	

private:

	std::vector<GameEngineRender*> BackRender;

};

