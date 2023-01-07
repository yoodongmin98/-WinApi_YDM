#pragma once
#include "GameEngineImage.h"
#include <map>
#include <string>

// ���� �̹��� ���δ� �̳༮�� �����ϰڽ��ϴ�.

// ���� :
class GameEngineResources
{
public:
	GameEngineResources(const GameEngineResources& _Other) = delete;
	GameEngineResources(GameEngineResources&& _Other) noexcept = delete;
	GameEngineResources& operator=(const GameEngineResources& _Other) = delete;
	GameEngineResources& operator=(GameEngineResources&& _Other) noexcept = delete;

	GameEngineResources& GetInst()
	{
		return Inst;
	}

protected:
	// 
	void ImageLoad(const std::string_view& _Path);

private:
	static GameEngineResources Inst;

	GameEngineResources();
	~GameEngineResources();

	//        xxxx.bmp
	std::map<std::string, GameEngineImage*> AllImage;

};

