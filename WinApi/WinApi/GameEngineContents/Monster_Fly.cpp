
#include <GameEngineBase/GameEngineDirectory.h>

#include <GameEnginePlatform/GameEngineInput.h>

#include <GameEngineCore/GameEngineRender.h>
#include <GameEngineCore/GameEngineResources.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCollision.h>


#include "Isaac.h"
#include "IsaacEnum.h"
#include "Monster_Fly.h"


Monster_Fly::Monster_Fly()
{
	
}

Monster_Fly::~Monster_Fly()
{
}


void Monster_Fly::ImageLoad()
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


void Monster_Fly::Start()
{
	ImageLoad();
	M_fly = CreateRender(IsaacOrder::R_Monster);
	M_fly->SetScale({ 150, 150 });
	SetPos({ 200,200 });
	
	
	M_fly->CreateAnimation({ .AnimationName = "M_fly_Idle",  .ImageName = "M_fly.bmp", .Start = 0, .End = 1, .InterTime = 0.1f });
	M_fly->CreateAnimation({ .AnimationName = "M_fly_Dead",  .ImageName = "M_fly_Dead.bmp", .Start = 0, .End = 11, .InterTime = 0.03f, .Loop = false});
	//ó���� �׳� ���ƴٴϰ�
	M_fly->ChangeAnimation("M_fly_Idle");
	
	{
		
		M_fly_Coll = CreateCollision(IsaacCollisionOrder::C_Monster);
		M_fly_Coll->SetScale({ 35, 35});
		M_fly_Coll->On();
		M_fly_Coll->SetDebugRenderType(CollisionType::CT_Rect);
	}
	
}

bool Deathcheck = false;
void Monster_Fly::Update(float _DeltaTime)
{
	Movecalculation(_DeltaTime);
	CollisionCheck(_DeltaTime);
}

void Monster_Fly::Movecalculation(float _DeltaTime)
{
	float4 M_Move = Isaac::MainPlayer->GetPos() - GetPos();
	M_Move.Normalize();

	SetMove(M_Move * 100.0f * _DeltaTime); //�ȵ���ٴϰ��Ҷ��� M_Move�� �ٸ��Լ����ϸ�ɵ� >>�����̴� ����pos�� BackGround_CS�� �ؾ���
}


void Monster_Fly::CollisionCheck(float _DeltaTime)
{
	NowTime += _DeltaTime;
	if (NowTime >= 0.5f) //������ȣ�ۿ��� �Ƿ��� �̸�ŭ�� �ð��� �귯���Ѵ�(���Ͱ� �״¾ִϸ��̼ǽð����ٴ� ������)
	{
		NowTime = 0.0f;
		M_fly_Coll->On();  //�ð��������� �ٽ�collision��Ų��
		RESET = 1;
		if (true == Deathcheck) //hp�� �������� Ȯ�εǸ�
		{
			Death(); //���ش�
		}
	}

	std::vector<GameEngineCollision*> FCollisions;
	CollisionCheckParameter Check = { .TargetGroup = static_cast<int>(IsaacCollisionOrder::C_PlayerAtt), .TargetColType = CT_Rect, .ThisColType = CT_Rect };

	if (true == M_fly_Coll->Collision(Check, FCollisions)) //PlayerAtt�� �������
	{
		FCollisions[0]->GetActor()->Death(); //���� ATT�� ����������

		if (1 == RESET)
		{
			SetMove(float4::Left * 10); //������ �з���(�Ų����Ծȹз���) ���⿡���� �������ؾ��ҵ�
			FlyHp = FlyHp - 1;
			RESET = 0;
			M_fly_Coll->Off(); //�¾Ƶ� �����ð����� ��ȣ�ۿ��̾ȵȴ�.
		}
		if (0 >= FlyHp)
		{
			M_fly->ChangeAnimation("M_fly_Dead");
			Deathcheck = true;
		}
	}
	
	CollisionCheckParameter B_Check = { .TargetGroup = static_cast<int>(IsaacCollisionOrder::C_Bomb), .TargetColType = CT_Rect, .ThisColType = CT_Rect };
	if (true == M_fly_Coll->Collision(B_Check, FCollisions))
	{
		FlyHp = FlyHp - 5; //�̰��� ��ź�� ��������
		if (0 >= FlyHp)
		{
			M_fly->ChangeAnimation("M_fly_Dead");
			Deathcheck = true;
		}
	}
}

void Monster_Fly::Render(float _DeltaTime)
{
	//M_fly_Coll->DebugRender();
}