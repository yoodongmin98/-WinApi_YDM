#include "Monster.h"
#include "IsaacEnum.h"
#include <GameEngineCore/GameEngineRender.h>
#include <GameEngineCore/GameEngineCollision.h>
#include <GameEngineCore/GameEngineLevel.h>
#include "Isaac.h"

Monster::Monster()
{
}

Monster::~Monster()
{
}


void Monster::Start()
{
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


}