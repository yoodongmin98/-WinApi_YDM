
#include <GameEngineBase/GameEngineDirectory.h>

#include <GameEnginePlatform/GameEngineInput.h>

#include <GameEngineCore/GameEngineRender.h>
#include <GameEngineCore/GameEngineResources.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCollision.h>


#include "Isaac.h"
#include "IsaacEnum.h"
#include "Monster_Blob.h"


Monster_Blob::Monster_Blob()
{

}

Monster_Blob::~Monster_Blob()
{
}


void Monster_Blob::ImageLoad()
{
	GameEngineDirectory Dir;
	Dir.MoveParentToDirectory("ContentsResources");
	Dir.Move("ContentsResources");
	Dir.Move("Image");
	Dir.Move("Play");
	Dir.Move("Monster");

	GameEngineImage* L_Blob = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("M_Blob_L.BMP"));
	L_Blob->Cut(4, 3);
	GameEngineImage* R_Blob = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("M_Blob_R.BMP"));
	R_Blob->Cut(4, 3);
}


void Monster_Blob::Start()
{
	ImageLoad();
	M_Blob = CreateRender(IsaacOrder::R_Monster);
	M_Blob->SetScale({ 100, 100 });


	M_Blob->CreateAnimation({ .AnimationName = "M_Blob_Idle_L",  .ImageName = "M_Blob_L.bmp", .Start = 0, .End = 7, .InterTime = 0.15f });
	M_Blob->CreateAnimation({ .AnimationName = "M_Blob_Damage",  .ImageName = "M_Blob_L.bmp", .Start = 10, .End = 11, .InterTime = 0.1f });
	M_Blob->CreateAnimation({ .AnimationName = "M_Blob_Idle_R",  .ImageName = "M_Blob_R.bmp", .Start = 0, .End = 7, .InterTime = 0.15f });
	//M_Blob->CreateAnimation({ .AnimationName = "M_Blob_Idle",  .ImageName = "M_fly_Dead.bmp", .Start = 0, .End = 11, .InterTime = 0.03f, .Loop = false });

	M_Blob->ChangeAnimation("M_Blob_Idle_L");

	{

		M_Blob_Coll = CreateCollision(IsaacCollisionOrder::C_Monster);
		M_Blob_Coll->SetScale({ 35, 35 });
		M_Blob_Coll->On();
		M_Blob_Coll->SetDebugRenderType(CollisionType::CT_Rect);

		M_Blob_SetColl_R = CreateCollision(IsaacCollisionOrder::C_Moster_Set);
		M_Blob_SetColl_R->SetScale({ 1000, 800 });
		M_Blob_SetColl_R->SetPosition({ 500,0 });
		M_Blob_SetColl_R->On();
		M_Blob_SetColl_R->SetDebugRenderType(CollisionType::CT_Rect);
	}				   

}

bool BlobDeathcheck = false;
void Monster_Blob::Update(float _DeltaTime)
{
	Movecalculation(_DeltaTime);
	CollisionCheck(_DeltaTime);
}

void Monster_Blob::Movecalculation(float _DeltaTime)
{
	float4 M_Move = Isaac::MainPlayer->GetPos() - GetPos();
	M_Move.Normalize();

	SetMove(M_Move * 70.0f * _DeltaTime); 
}


void Monster_Blob::CollisionCheck(float _DeltaTime)
{
	NowTime += _DeltaTime;
	
	if (NowTime >= 0.5f)
	{
		if (true == M_Blob_SetColl_R->Collision({ .TargetGroup = static_cast<int>(IsaacCollisionOrder::C_Player), .TargetColType = CT_Rect, .ThisColType = CT_Rect }))
		{
			M_Blob->ChangeAnimation("M_Blob_Idle_R"); //�ٽ� idle�ιٲٰ�
		}
		else
		{
			M_Blob->ChangeAnimation("M_Blob_Idle_L");
		}
		NowTime = 0.0f;
		M_Blob_Coll->On();  //�ð��������� �ٽ�collision��Ų��
		RESET = 1;
		if (true == BlobDeathcheck)
		{
			Death();
		}
	}

	std::vector<GameEngineCollision*> FCollisions;
	CollisionCheckParameter Check = { .TargetGroup = static_cast<int>(IsaacCollisionOrder::C_PlayerAtt_L), .TargetColType = CT_Rect, .ThisColType = CT_Rect };
	CollisionCheckParameter Check1 = { .TargetGroup = static_cast<int>(IsaacCollisionOrder::C_PlayerAtt_R), .TargetColType = CT_Rect, .ThisColType = CT_Rect };
	CollisionCheckParameter Check2 = { .TargetGroup = static_cast<int>(IsaacCollisionOrder::C_PlayerAtt_U), .TargetColType = CT_Rect, .ThisColType = CT_Rect };
	CollisionCheckParameter Check3 = { .TargetGroup = static_cast<int>(IsaacCollisionOrder::C_PlayerAtt_D), .TargetColType = CT_Rect, .ThisColType = CT_Rect };

	//�Լ�© �ð��� �׳� �������ϰڳ��
	if (true == M_Blob_Coll->Collision(Check, FCollisions)) //PlayerAtt�� �������
	{
		M_Blob->ChangeAnimation("M_Blob_Damage");
		FCollisions[0]->GetActor()->Death(); //���� ATT�� ����������
		SetMove(float4::Left * 20); //������ �з���(�Ų����Ծȹз���) ���⿡���� �������ؾ��ҵ�

		if (1 == RESET)
		{
			BlobHp = BlobHp - Isaac::MainPlayer->GetTearDamage();
			RESET = 0;
			M_Blob_Coll->Off(); //�¾Ƶ� �����ð����� ��ȣ�ۿ��̾ȵȴ�.
		}
		if (0 >= BlobHp)
		{
			//M_Blob->ChangeAnimation("M_fly_Dead");
			BlobDeathcheck = true;
		}
	}
	if (true == M_Blob_Coll->Collision(Check1, FCollisions))
	{
		M_Blob->ChangeAnimation("M_Blob_Damage");
		FCollisions[0]->GetActor()->Death();
		SetMove(float4::Right * 20);

		if (1 == RESET)
		{
			BlobHp = BlobHp - Isaac::MainPlayer->GetTearDamage();
			RESET = 0;
			M_Blob_Coll->Off();
		}
		if (0 >= BlobHp)
		{
			//M_Blob->ChangeAnimation("M_fly_Dead");
			BlobDeathcheck = true;
		}
	}
	if (true == M_Blob_Coll->Collision(Check2, FCollisions))
	{
		M_Blob->ChangeAnimation("M_Blob_Damage");
		FCollisions[0]->GetActor()->Death();
		SetMove(float4::Up * 20);

		if (1 == RESET)
		{
			BlobHp = BlobHp - Isaac::MainPlayer->GetTearDamage();
			RESET = 0;
			M_Blob_Coll->Off();
		}
		if (0 >= BlobHp)
		{
			//M_Blob->ChangeAnimation("M_fly_Dead");
			BlobDeathcheck = true;
		}
	}
	if (true == M_Blob_Coll->Collision(Check3, FCollisions))
	{
		M_Blob->ChangeAnimation("M_Blob_Damage");
		FCollisions[0]->GetActor()->Death();
		SetMove(float4::Down * 20);

		if (1 == RESET)
		{
			BlobHp = BlobHp - Isaac::MainPlayer->GetTearDamage();
			RESET = 0;
			M_Blob_Coll->Off();
		}
		if (0 >= BlobHp)
		{
			//M_Blob->ChangeAnimation("M_fly_Dead");
			BlobDeathcheck = true;
		}
	}














	CollisionCheckParameter B_Check = { .TargetGroup = static_cast<int>(IsaacCollisionOrder::C_Isaac_Bomb), .TargetColType = CT_Rect, .ThisColType = CT_Rect };
	if (true == M_Blob_Coll->Collision(B_Check, FCollisions))
	{
		BlobHp = BlobHp - 5; //�̰��� ��ź�� ��������
		if (0 >= BlobHp)
		{
			//M_Blob->ChangeAnimation("M_fly_Dead");
			BlobDeathcheck = true;
		}
	}
}

void Monster_Blob::Render(float _DeltaTime)
{
	//M_Blob_SetColl_R->DebugRender();
}