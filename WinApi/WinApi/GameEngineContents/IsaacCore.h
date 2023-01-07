#pragma once
#include <GameEngineCore/GameEngineCore.h>

// 이렇게 클래스를 만드는 방식 그자체를 싱글톤이라고 합니다.

// 설명 :
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
protected:
	//GameEngineCore 상속받아서
	void Start() override; //오버라이딩되는 함수라는걸 명시적으로 적어주기.
	void Update() override;
	void End() override;


private:
	// 생성자를 막아 -> 단 한개밖에 존재할수밖에없게한다.
	IsaacCore();
	~IsaacCore();

	// 자기를 자신이 가지면
	// 프로그램을 통틀어서 오직 1개의 객체만 만들어진다
	// static StudyGameCore* Core;
	static IsaacCore Core;

};

//싱글톤 >>생성자를막고 프로그램내에서 딱 1개만 존재할수있게한다
//static이랑 별 다를건 없따...
