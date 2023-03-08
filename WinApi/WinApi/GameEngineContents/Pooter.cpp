
#include <GameEngineBase/GameEngineDirectory.h>

#include <GameEnginePlatform/GameEngineInput.h>

#include <GameEngineCore/GameEngineRender.h>
#include <GameEngineCore/GameEngineResources.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCollision.h>


#include "Isaac.h"
#include "IsaacEnum.h"
#include "Pooter.h"
#include "BloodTear.h"


Pooter::Pooter()
{

}

Pooter::~Pooter()
{
}

bool PooterLoad = true;
void Pooter::ImageLoad()
{
	GameEngineDirectory Dir;
	Dir.MoveParentToDirectory("ContentsResources");
	Dir.Move("ContentsResources");
	Dir.Move("Image");
	Dir.Move("Play");
	Dir.Move("Monster");

	GameEngineImage* Monster12 = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("M_Pooter.BMP"));
	Monster12->Cut(4, 4);
	GameEngineImage* Monster123 = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("M_Pooter_L.BMP"));
	Monster123->Cut(4, 4);
	
}


void Pooter::Start()
{
	Isaac::MainPlayer->PlusMOnsterCount(1);
	if (true == PooterLoad)
	{
		ImageLoad();
		PooterLoad = false;
	}
	M_Pooter = CreateRender(IsaacOrder::R_Monster);
	M_Pooter->SetScale({ 80, 80 });

	M_PooterDead = CreateRender(IsaacOrder::R_MonsterDead);
	M_PooterDead->SetScale({ 80, 80 });

	M_Pooter->CreateAnimation({ .AnimationName = "M_Pooter_Idle",  .ImageName = "M_Pooter.bmp", .Start = 0, .End = 1, .InterTime = 0.1f });
	M_Pooter->CreateAnimation({ .AnimationName = "M_Pooter_Damage",  .ImageName = "M_Pooter.bmp", .Start = 14, .End = 15, .InterTime = 0.1f });
	M_Pooter->CreateAnimation({ .AnimationName = "M_Pooter_Shoot",  .ImageName = "M_Pooter.bmp", .Start = 2, .End = 11, .InterTime = 0.03f , .Loop = false });

	M_Pooter->CreateAnimation({ .AnimationName = "M_Pooter_L_Idle",  .ImageName = "M_Pooter_L.bmp", .Start = 0, .End = 1, .InterTime = 0.1f });
	M_Pooter->CreateAnimation({ .AnimationName = "M_Pooter_L_Damage",  .ImageName = "M_Pooter_L.bmp", .Start = 14, .End = 15, .InterTime = 0.1f });
	M_Pooter->CreateAnimation({ .AnimationName = "M_Pooter_L_Shoot",  .ImageName = "M_Pooter_L.bmp", .Start = 2, .End = 11, .InterTime = 0.03f , .Loop = false });
	M_Pooter->CreateAnimation({ .AnimationName = "M_Pooter_Dead",  .ImageName = "M_fly_Dead.bmp", .Start = 0, .End = 11, .InterTime = 0.03f, .Loop = false });
	M_Pooter->ChangeAnimation("M_Pooter_Idle");


	M_PooterDead->CreateAnimation({ .AnimationName = "PooterDead",  .ImageName = "M_Blood.bmp", .Start = 5, .End = 5, .InterTime = 0.1f });
	M_PooterDead->ChangeAnimation("PooterDead");
	M_PooterDead->Off();

	{

		M_fly_Pooter = CreateCollision(IsaacCollisionOrder::C_Monster);
		M_fly_Pooter->SetScale({ 35, 35 });
		M_fly_Pooter->On();
		M_fly_Pooter->SetDebugRenderType(CollisionType::CT_Rect);

		M_fly_Pooter_Set = CreateCollision(IsaacCollisionOrder::C_Moster_Set);
		M_fly_Pooter_Set->SetScale({ 800, 800 });
		M_fly_Pooter_Set->SetPosition({ 400,0 });
		M_fly_Pooter_Set->On();
		M_fly_Pooter_Set->SetDebugRenderType(CollisionType::CT_Rect);

		
	}

}


void Pooter::Update(float _DeltaTime)
{
	if (true == PooterDeathcheck) //hp�� �������� Ȯ�εǸ�
	{
		if (true == Countbool)
		{
			Isaac::MainPlayer->MinusMonsterCount(1);
			Countbool = false;
		}
		M_Pooter->ChangeAnimation("M_Pooter_Dead");
		if (true == M_Pooter->IsAnimationEnd())
		{
			M_PooterDead->On();
			M_Pooter->Death();
		}
		M_fly_Pooter->Death(); //���ش�
		M_fly_Pooter_Set->Death();
	}
	PooterAttTime += _DeltaTime;
	if (PooterAttTime > 3.0f)
	{
		PooterAttTime = 0.0f;
		if (false == PooterDeathcheck)
		{

			if (true == M_fly_Pooter_Set->Collision({ .TargetGroup = static_cast<int>(IsaacCollisionOrder::C_Player), .TargetColType = CT_Rect, .ThisColType = CT_Rect }))
			{
				M_Pooter->ChangeAnimation("M_Pooter_Shoot");
				float4 PlayerPos_P = Isaac::MainPlayer->GetPos() - GetPos();
				BloodTear* PooterAtt = GetLevel()->CreateActor<BloodTear>();
				PooterAtt->SetBloodMoveDir(PlayerPos_P);
				PooterAtt->SetPos(GetPos());
			}
			else
			{
				M_Pooter->ChangeAnimation("M_Pooter_L_Shoot");
				float4 PlayerPos_P1 = Isaac::MainPlayer->GetPos()-GetPos();
				BloodTear* PooterAtt1 = GetLevel()->CreateActor<BloodTear>();
				PooterAtt1->SetBloodMoveDir(PlayerPos_P1);
				PooterAtt1->SetPos(GetPos());
			}
		}
	}
	if (true == M_Pooter->IsAnimationEnd())
	{
		if (true == M_fly_Pooter_Set->Collision({ .TargetGroup = static_cast<int>(IsaacCollisionOrder::C_Player), .TargetColType = CT_Rect, .ThisColType = CT_Rect }))
		{
			M_Pooter->ChangeAnimation("M_Pooter_Idle"); //�ٽ� idle�ιٲٰ�
		}
		else
		{
			M_Pooter->ChangeAnimation("M_Pooter_L_Idle");
		}
	}
	
	Movecalculation(_DeltaTime);
	CollisionCheck(_DeltaTime);
}

void Pooter::Movecalculation(float _DeltaTime)
{
	float4 M_Move = Isaac::MainPlayer->GetPos() - GetPos();
	M_Move.Normalize();
	if (true == PooterDeathcheck)
	{
		M_Move = float4::Zero;
	}

	SetMove(M_Move * 15.0f * _DeltaTime); //�ȵ���ٴϰ��Ҷ��� M_Move�� �ٸ��Լ����ϸ�ɵ� >>�����̴� ����pos�� BackGround_CS�� �ؾ���
}


void Pooter::CollisionCheck(float _DeltaTime)
{
	NowTime += _DeltaTime;
	
	if (NowTime >= 0.5f) //������ȣ�ۿ��� �Ƿ��� �̸�ŭ�� �ð��� �귯���Ѵ�(���Ͱ� �״¾ִϸ��̼ǽð����ٴ� ������)
	{
		NowTime = 0.0f;
		M_fly_Pooter->On();  //�ð��������� �ٽ�collision��Ų��
		RESET = 1;
		
	}
	
	std::vector<GameEngineCollision*> FCollisions;
	CollisionCheckParameter Check = { .TargetGroup = static_cast<int>(IsaacCollisionOrder::C_PlayerAtt_L), .TargetColType = CT_Rect, .ThisColType = CT_Rect };
	CollisionCheckParameter Check1 = { .TargetGroup = static_cast<int>(IsaacCollisionOrder::C_PlayerAtt_R), .TargetColType = CT_Rect, .ThisColType = CT_Rect };
	CollisionCheckParameter Check2 = { .TargetGroup = static_cast<int>(IsaacCollisionOrder::C_PlayerAtt_U), .TargetColType = CT_Rect, .ThisColType = CT_Rect };
	CollisionCheckParameter Check3 = { .TargetGroup = static_cast<int>(IsaacCollisionOrder::C_PlayerAtt_D), .TargetColType = CT_Rect, .ThisColType = CT_Rect };

	//�Լ�© �ð��� �׳� �������ϰڳ��
	if (true == M_fly_Pooter->Collision(Check, FCollisions)) //PlayerAtt�� �������
	{
		M_Pooter->ChangeAnimation("M_Pooter_Damage");
		FCollisions[0]->GetActor()->Death(); //���� ATT�� ����������
		SetMove(float4::Left * 20); //������ �з���(�Ų����Ծȹз���) ���⿡���� �������ؾ��ҵ�

		if (1 == RESET)
		{
			PooterHp = PooterHp - Isaac::MainPlayer->GetTearDamage();
			RESET = 0;
			M_fly_Pooter->Off(); //�¾Ƶ� �����ð����� ��ȣ�ۿ��̾ȵȴ�.
		}
		if (0 >= PooterHp)
		{
			PooterDeathcheck = true;
		}
	}
	if (true == M_fly_Pooter->Collision(Check1, FCollisions))
	{
		M_Pooter->ChangeAnimation("M_Pooter_Damage");
		FCollisions[0]->GetActor()->Death();
		SetMove(float4::Right * 20);

		if (1 == RESET)
		{
			PooterHp = PooterHp - Isaac::MainPlayer->GetTearDamage();
			RESET = 0;
			M_fly_Pooter->Off();
		}
		if (0 >= PooterHp)
		{
			M_Pooter->ChangeAnimation("M_Pooter_Dead");
			PooterDeathcheck = true;
		}
	}
	if (true == M_fly_Pooter->Collision(Check2, FCollisions))
	{
		M_Pooter->ChangeAnimation("M_Pooter_Damage");
		FCollisions[0]->GetActor()->Death();
		SetMove(float4::Up * 20);

		if (1 == RESET)
		{
			PooterHp = PooterHp - Isaac::MainPlayer->GetTearDamage();
			RESET = 0;
			M_fly_Pooter->Off();
		}
		if (0 >= PooterHp)
		{
			M_Pooter->ChangeAnimation("M_Pooter_Dead");
			PooterDeathcheck = true;
		}
	}
	if (true == M_fly_Pooter->Collision(Check3, FCollisions))
	{
		M_Pooter->ChangeAnimation("M_Pooter_Damage");
		FCollisions[0]->GetActor()->Death();
		SetMove(float4::Down * 20);

		if (1 == RESET)
		{
			PooterHp = PooterHp - Isaac::MainPlayer->GetTearDamage();
			RESET = 0;
			M_fly_Pooter->Off();
		}
		if (0 >= PooterHp)
		{
			M_Pooter->ChangeAnimation("M_Pooter_Dead");
			PooterDeathcheck = true;
		}
	}


	CollisionCheckParameter B_Check = { .TargetGroup = static_cast<int>(IsaacCollisionOrder::C_Isaac_Bomb), .TargetColType = CT_Rect, .ThisColType = CT_Rect };
	if (true == M_fly_Pooter->Collision(B_Check, FCollisions))
	{
		PooterHp = PooterHp - 5; //�̰��� ��ź�� ��������
		if (0 >= PooterHp)
		{
			M_Pooter->ChangeAnimation("M_Pooter_Dead");
			PooterDeathcheck = true;
		}
	}
}

void Pooter::Render(float _DeltaTime)
{
	//M_fly_Pooter->DebugRender();
	//M_fly_Pooter_Set->DebugRender();
}