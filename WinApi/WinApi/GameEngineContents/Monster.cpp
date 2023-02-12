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

		GameEngineImage* Monster = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Monster.BMP"));
		Monster->Cut(2, 1);
		GameEngineImage* MonsterD = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("MonsterDead.BMP"));
		MonsterD->Cut(5, 3);
}

void Monster::Start()
{
	ImageLoad();
	MonsterRender = CreateRender(IsaacOrder::R_Monster);
	MonsterRender->SetScale({ 150, 150 });
	
	
	MonsterRender->CreateAnimation({ .AnimationName = "Monster_Idle",  .ImageName = "Monster.bmp", .Start = 0, .End = 1, .InterTime = 0.1f });
	MonsterRender->CreateAnimation({ .AnimationName = "Monster_Dead",  .ImageName = "MonsterDead.bmp", .Start = 0, .End = 10, .InterTime = 0.03f, .Loop = false });
	//ó���� �׳� ���ƴٴϰ�
	MonsterRender->ChangeAnimation("Monster_Idle");

	//�ݸ����׽�Ʈ�� ���߿�
	{
		BodyCollision = CreateCollision(IsaacCollisionOrder::C_Monster);
		BodyCollision->SetScale({ 50, 50 });
		BodyCollision->On();
	}
}


void Monster::Update(float _DeltaTime)
{
	NowTime += _DeltaTime;
	float4 M_Move = Isaac::MainPlayer->GetPos() - GetPos(); //��Ÿ��� and �����Ǽ���
	
	M_Move.Normalize();
	SetMove(M_Move * 200.0f * _DeltaTime); //�ȵ���ٴϰ��Ҷ��� M_Move�� �ٸ��Լ����ϸ�ɵ� >>�����̴� ����pos�� BackGround_CS�� �ؾ��ҵ�

	if (true == BodyCollision->Collision({.TargetGroup = static_cast<int>(IsaacCollisionOrder::C_Player)}))
	{
		MonsterRender->ChangeAnimation("Monster_Dead");
		if (MonsterDeadTime < NowTime)
		{
			MonsterRender->Death(); //����μ��� �ѹ������ �ִϸ��̼�������ǰ� �Ǵ����� Death�� ����Ǵ¹��(�Ѿ˷� �����ϸ�ɵ�)
		}
	}
	//std::vector<GameEngineCollision*> Collision;
	//if (true == BodyCollision->Collision({ .TargetGroup = static_cast<int>(BubbleCollisionOrder::Player) }, Collision))
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