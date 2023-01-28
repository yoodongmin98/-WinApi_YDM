#include "TitleLevel.h"
#include "AllBack.h";

#include <GameEngineBase/GameEngineDirectory.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineCore.h>
#include <GameEngineCore/GameEngineRender.h>
#include <GameEngineCore/GameEngineResources.h>




TitleLevel::TitleLevel()
{

}
TitleLevel::~TitleLevel()
{

}



void TitleLevel::Loading()
{
	GameEngineDirectory Dir;
	Dir.MoveParentToDirectory("ContentsResources");
	Dir.Move("ContentsResources");
	Dir.Move("Image");
	Dir.Move("Title");

	//�̹����ε�
	{
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Title_BackGround.BMP"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Title_TitleLogo.BMP"))->Cut(4, 4);

	}

	AllBack* Render = CreateActor<AllBack>();
	Render->CreateRender("Title_BackGround.BMP", TitleOrder::BackGround); //���
	Logo= Render->CreateRender("Title_TitleLogo.BMP", TitleOrder::Logo);//�ΰ�
	Logo->SetScale({ 1500,1200 });
	Logo->SetPosition(Logo->GetPosition() + float4::Up * 200);
	Logo->CreateAnimation({
		.AnimationName = "Logo",
		.ImageName = "Title_TitleLogo.BMP",
		.Start = 0,
		.End = 15,
		.InterTime = .1f
		});
	Logo->ChangeAnimation("Logo");



	
}
void TitleLevel::Update(float _DeltaTime)
{
	if (true == GameEngineInput::IsAnyKey())
	{
		GameEngineCore::GetInst()->ChangeLevel("IsaacPlay");
	}

}
