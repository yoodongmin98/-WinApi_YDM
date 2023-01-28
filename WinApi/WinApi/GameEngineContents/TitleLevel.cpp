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

	//이미지로드
	{
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Title_BackGround.BMP"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Title_TitleLogo.BMP"))->Cut(4, 4);
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Title_Isaac.BMP"))->Cut(2, 1);

	}

	AllBack* Render = CreateActor<AllBack>();
	Render->CreateRender("Title_BackGround.BMP", TitleOrder::BackGround); //배경
	{
		Logo = Render->CreateRender("Title_TitleLogo.BMP", TitleOrder::Logo);//로고
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
	{
		Isaac = Render->CreateRender("Title_Isaac.BMP", TitleOrder::Logo);//아이작
		Isaac->SetScale({800,600});
		Isaac->SetPosition(Isaac->GetPosition() + float4::Down * 100);
		Isaac->CreateAnimation({
			.AnimationName = "Isaac",
			.ImageName = "Title_Isaac.BMP",
			.Start = 0,
			.End = 1,
			.InterTime = .1f
			});
		Isaac->ChangeAnimation("Isaac");
	}



	
}
void TitleLevel::Update(float _DeltaTime)
{
	if (true == GameEngineInput::IsAnyKey())
	{
		GameEngineCore::GetInst()->ChangeLevel("PlayIsaac");
	}

}
