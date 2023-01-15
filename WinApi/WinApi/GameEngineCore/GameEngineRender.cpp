#include "GameEngineRender.h"
#include <GameEngineCore/GameEngineResources.h>
#include "GameEngineActor.h"
#include "GameEngineLevel.h"
#include <GameEnginePlatform/GameEngineWindow.h>

GameEngineRender::GameEngineRender()
{
}

GameEngineRender::~GameEngineRender()
{
}

void GameEngineRender::SetImage(const std::string_view& _ImageName)
{
	Image = GameEngineResources::GetInst().ImageFind(_ImageName);
}

void GameEngineRender::SetOrder(int _Order)
{
	Order = _Order;
	Owner->GetLevel()->PushRender(this);
}

void GameEngineRender::SetFrame(int _Frame)
{
	if (nullptr == Image)
	{
		MsgAssert("�̹����� �������� �ʴ� �������� �������� �����Ϸ��� �߽��ϴ�.");
	}

	if (false == Image->IsImageCutting())
	{
		MsgAssert("�߷��ִ� �̹����� �������� �������� �� �ֽ��ϴ�.");
	}

	if (false == Image->IsCutIndexValid(_Frame))
	{
		MsgAssert("�������� ���� �̹����ε��� �Դϴ�.");
	}

	Frame = _Frame;
}

void GameEngineRender::Render(float _DeltaTime)
{
	float4 RenderPos = Owner->GetPos() + Position;

	if (true == Image->IsImageCutting())
	{
		GameEngineWindow::GetDoubleBufferImage()->TransCopy(Image, Frame, RenderPos, Scale);
	}
	else
	{
		GameEngineWindow::GetDoubleBufferImage()->TransCopy(Image, RenderPos, Scale, { 0, 0 }, Image->GetImageScale());
	}
}