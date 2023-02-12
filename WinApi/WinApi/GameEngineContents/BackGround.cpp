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
	/*{
		GameEngineRender* Render1 = CreateRender("BackGround_Cs.BMP", IsaacOrder::BackGround_CS);
		Render1->SetPosition(Render1->GetImage()->GetImageScale().half());
		Render1->SetScaleToImage();
	}*/
}