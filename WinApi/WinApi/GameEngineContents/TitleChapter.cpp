#include "TitleChapter.h"
#include "TitleLevel.h"
#include "IsaacEnum.h"

#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEnginePlatform/GameEngineWindow.h>






TitleChapter::TitleChapter()
{

}
TitleChapter::~TitleChapter()
{

}

void TitleChapter::Start()
{
	//¹è°æ
	GameEngineRender* Render = CreateRender("Title_BackGround.BMP", IsaacOrder::BackGround);
	Render->SetPosition(Render->GetImage()->GetImageScale().half());
	Render->SetScaleToImage();
}
void TitleChapter::Update(float _DeltaTime)
{
	

}