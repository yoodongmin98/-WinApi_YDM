#pragma once
#include <GameEngineCore/GameEngineCore.h>

class IsaacCore : public GameEngineCore
{
public:
	// delete Function
	IsaacCore(const IsaacCore& _Other) = delete;
	IsaacCore(IsaacCore&& _Other) noexcept = delete;
	IsaacCore& operator=(const IsaacCore& _Other) = delete;
	IsaacCore& operator=(IsaacCore&& _Other) noexcept = delete;

	// 싱글톤
	static IsaacCore& GetInst()
	{
		return Core;
	}

	// 포인터로 만들시에는 중간에 삭제가 용이하다
	//static StudyGameCore& Destroy()
	//{
	//	delete Core;
	//}

protected:
	void Start() override;
	void Update() override;
	void End() override;


private:
	// 생성자를 막기
	IsaacCore();
	~IsaacCore();

	
	// 프로그램을 통틀어서 오직 1개의 객체
	// static StudyGameCore* Core; 이거랑같음
	static IsaacCore Core;

};

