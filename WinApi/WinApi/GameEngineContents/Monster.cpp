#include "Monster.h"
#include "IsaacEnum.h"
#include <GameEngineCore/GameEngineRender.h>
#include <GameEngineBase/GameEngineDirectory.h>

#include <GameEnginePlatform/GameEngineInput.h>

#include <GameEngineCore/GameEngineResources.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCollision.h>

#include "Isaac.h"


Monster::Monster()
{
}

Monster::~Monster()
{
}


void Monster::ImageLoad()
{
		GameEngineDirectory Dir;
		Dir.MoveParentToDirectory("ContentsResources");
		Dir.Move("ContentsResources");
		Dir.Move("Image");
		Dir.Move("Play");
		Dir.Move("Monster");

		GameEngineImage* Monster1 = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("M_fly.BMP"));
		Monster1->Cut(2, 1);
		GameEngineImage* Monster1D = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("M_fly_Dead.BMP"));
		Monster1D->Cut(5, 3);
}

//void Monster::MonsterCountLoad()
//{
//	bool MonsterCountLoad = false;
//	if (false == MonsterCountLoad)
//	{
//		MonsterCount++;
//		MonsterCountLoad = true; //테스트용 MonsterCount를 딱 한개만 로드시켜보기(Door Test);
//	}
//}
void Monster::Start()
{
	ImageLoad();
//	MonsterCountLoad();
	M_fly = CreateRender(IsaacOrder::R_Monster);
	M_fly->SetScale({ 150, 150 });
	SetPos({ 200,200 });
	
	
	M_fly->CreateAnimation({ .AnimationName = "M_fly_Idle",  .ImageName = "M_fly.bmp", .Start = 0, .End = 1, .InterTime = 0.1f });
	M_fly->CreateAnimation({ .AnimationName = "M_fly_Dead",  .ImageName = "M_fly_Dead.bmp", .Start = 0, .End = 11, .InterTime = 0.03f, .Loop = false });
	//처음엔 그냥 날아다니게
	M_fly->ChangeAnimation("M_fly_Idle");
	
	//콜리전테스트는 나중에
	{
		M_fly_Coll = CreateCollision(IsaacCollisionOrder::C_Monster);
		M_fly_Coll->SetScale({ 50, 50 });
		M_fly_Coll->On();
	}
}


void Monster::Update(float _DeltaTime)
{
	NowTime += _DeltaTime;
	
	float4 M_Move = Isaac::MainPlayer->GetPos() - GetPos(); //피타고라스 and 벡터의성질
	
	
	
	M_Move.Normalize();
	SetMove(M_Move * 200.0f * _DeltaTime); //안따라다니게할때는 M_Move를 다르게설정하면될듯 >>움직이는 제한pos를 BackGround_CS로 해야할듯

	if (true == M_fly_Coll->Collision({.TargetGroup = static_cast<int>(IsaacCollisionOrder::C_Player)}))
	{
		ReloadTime;
		FlyHp = FlyHp - 1;
		

		if (0== FlyHp)
		{
			M_fly->ChangeAnimation("M_fly_Dead");
			//MonsterRender->Death(); //현재로서는 한번닿고나서 애니메이션이재생되고 또닿으면 Death가 진행되는방식(총알로 구현하면될듯)
		/*	MonsterCount -= 1;*/
		}
	}



	//std::vector<GameEngineCollision*> Collision;
	//if (true == M_fly_Coll->Collision({ .TargetGroup = static_cast<int>(IsaacCollisionOrder::C_Player) }, Collision))
	//{
	//	for (size_t i = 0; i < Collision.size(); i++)
	//	{
	//		// Monster* FindMonster = Collision[i]->GetOwner<Monster>();

	//		GameEngineActor* ColActor = Collision[i]->GetActor();


	//		int a = 0;
	//	}
	//}

	//std::vector<GameEngineActor*> Actors = GetLevel()->GetActors(BubbleRenderOrder::Player);

	//for (size_t i = 0; i < Actors.size(); i++)
	//{
	//	float4 Dir = Actors[i]->GetPos() - GetPos();
	//	if (Dir.Size() <= 100.0f)
	//	{
	//		int a = 0;
	//	}
	//}

}