#include "BackGround.h"
#include"IsaacEnum.h"
#include<GameEnginePlatform/GameEngineWindow.h>
#include<GameEnginePlatform/GameEngineInput.h>
#include<GameEngineCore/GameEngineRender.h>
#include "Isaaclevel.h"

BackGround::BackGround()
{

}
BackGround::~BackGround()
{

}

void BackGround::Start()
{
	{
		GameEngineRender* Render = CreateRender("BackGround.BMP", IsaacOrder::R_BackGround);
		Render->SetPosition(Render->GetImage()->GetImageScale().half());
		Render->SetScaleToImage();
	}
	{
		/*GameEngineRender* Render1 = CreateRender("Play_BlackGround.BMP", IsaacOrder::R_BackGround_Black);
		Render1->SetPosition(Render1->GetImage()->GetImageScale().half());
		Render1->SetScale({5000,5000});*/
		//�ڿ� ��ġ�� ����� �� �̹����� ������ �ݿ��Ǿ��־���ϴµ�..?
	}
}