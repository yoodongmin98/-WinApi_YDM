
#include <GameEngineBase/GameEngineDirectory.h>

#include <GameEnginePlatform/GameEngineInput.h>

#include <GameEngineCore/GameEngineRender.h>
#include <GameEngineCore/GameEngineResources.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCollision.h>


#include "Isaac.h"
#include "IsaacEnum.h"
#include "Monstro.h"

#include "BloodTear.h"
#include "NextLevelDoor.h"

Monstro* Monstro::MainMonstro;

Monstro::Monstro()
{

}

Monstro::~Monstro()
{
}

bool MonstroLoad = true;
void Monstro::ImageLoad()
{
	GameEngineDirectory Dir;
	Dir.MoveParentToDirectory("ContentsResources");
	Dir.Move("ContentsResources");
	Dir.Move("Image");
	Dir.Move("Play");
	Dir.Move("BossMonster");

	GameEngineImage* L_Ms = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Monstro_Left.BMP"));
	L_Ms->Cut(5, 2);
	GameEngineImage* R_Ms = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Monstro_Right.BMP"));
	R_Ms->Cut(5, 2);
}


void Monstro::Start()
{
	MainMonstro = this;
	if (true == MonstroLoad)
	{
		ImageLoad();
		MonstroLoad = false;
	}
	M_Monstro = CreateRender(IsaacOrder::R_Monster);
	M_Monstro->SetScale({ 200, 200 });

	

	M_Monstro->CreateAnimation({ .AnimationName = "M_Monstro_Idle_L",  .ImageName = "Monstro_Left.bmp", .Start = 2, .End = 2, .InterTime = 0.15f ,});
	M_Monstro->CreateAnimation({ .AnimationName = "M_Monstro_Idle_R",  .ImageName = "Monstro_Right.bmp", .Start = 2, .End = 2, .InterTime = 0.15f });

	M_Monstro->CreateAnimation({ .AnimationName = "M_Monstro_Move_L",  .ImageName = "Monstro_Left.bmp", .Start = 5, .End = 8, .InterTime = 0.25f });
	M_Monstro->CreateAnimation({ .AnimationName = "M_Monstro_Move_R",  .ImageName = "Monstro_Right.bmp", .Start = 5, .End = 8, .InterTime = 0.25f });

	M_Monstro->CreateAnimation({ .AnimationName = "M_Monstro_Attack_L",  .ImageName = "Monstro_Left.bmp", .Start = 3, .End = 3, .InterTime = 0.5f });
	M_Monstro->CreateAnimation({ .AnimationName = "M_Monstro_Attack_R",  .ImageName = "Monstro_Right.bmp", .Start = 3, .End = 3, .InterTime = 0.5f });



	M_Monstro->ChangeAnimation("M_Monstro_Idle_L");



	{

		M_Monstro_Coll = CreateCollision(IsaacCollisionOrder::C_Monster);
		M_Monstro_Coll->SetScale({ 100, 100 });
		M_Monstro_Coll->SetPosition({ 0, 30 });
		M_Monstro_Coll->On();
		M_Monstro_Coll->SetDebugRenderType(CollisionType::CT_Rect);

		M_Monstro_SetColl_R = CreateCollision(IsaacCollisionOrder::C_Moster_Set);
		M_Monstro_SetColl_R->SetScale({ 1000, 800 });
		M_Monstro_SetColl_R->SetPosition({ 500,0 });
		M_Monstro_SetColl_R->On();
		M_Monstro_SetColl_R->SetDebugRenderType(CollisionType::CT_Rect);
	}

}


void Monstro::Update(float _DeltaTime)
{
	PatternTime += _DeltaTime;
	AttackTime += _DeltaTime;
	if (true == MonstroDeathcheck)
	{
		if (true == Countbool)
		{
			Isaac::MainPlayer->MinusMonsterCount(1);
			Countbool = false;
		}
		NextLevelDoor* NextDoor = GetLevel()->CreateActor<NextLevelDoor>();
		NextDoor->SetPos(GetPos());
		Death();
	}

	if (PatternTime > 1.0f)
	{
		
		Movecalculation(_DeltaTime);
		if (PatternTime > 2.0f)
		{
			PatternTime = 0.0f;
			if (true == M_Monstro_SetColl_R->Collision({ .TargetGroup = static_cast<int>(IsaacCollisionOrder::C_Player), .TargetColType = CT_Rect, .ThisColType = CT_Rect }))
			{
				M_Monstro->ChangeAnimation("M_Monstro_Idle_R"); 
			}
			else
			{
				M_Monstro->ChangeAnimation("M_Monstro_Idle_L");
			}
		}
	}
	
	if (AttackTime > 7.0f)
	{
		
		PatternTime = 0.0f;
		if (true == M_Monstro_SetColl_R->Collision({ .TargetGroup = static_cast<int>(IsaacCollisionOrder::C_Player), .TargetColType = CT_Rect, .ThisColType = CT_Rect }))
		{
			M_Monstro->ChangeAnimation("M_Monstro_Attack_R");
			Attack1();
			
		}
		else
		{
			M_Monstro->ChangeAnimation("M_Monstro_Attack_L");
			Attack1();
			
		}
		if (AttackTime > 8.0f)
		{
			AttackBool = true;
			AttackTime = 0.0f;
			if (true == M_Monstro_SetColl_R->Collision({ .TargetGroup = static_cast<int>(IsaacCollisionOrder::C_Player), .TargetColType = CT_Rect, .ThisColType = CT_Rect }))
			{
				M_Monstro->ChangeAnimation("M_Monstro_Idle_R");
			}
			else
			{
				M_Monstro->ChangeAnimation("M_Monstro_Idle_L");
			}
		}
	}

	CollisionCheck(_DeltaTime);
}

void Monstro::Movecalculation(float _DeltaTime)
{
	JumpCheckTime += _DeltaTime;
	float4 M_Move = Isaac::MainPlayer->GetPos() - GetPos();
	M_Move.Normalize();
	if (true == MonstroDeathcheck)
	{
		M_Move = float4::Zero;
	}
	if (true == M_Monstro_SetColl_R->Collision({ .TargetGroup = static_cast<int>(IsaacCollisionOrder::C_Player), .TargetColType = CT_Rect, .ThisColType = CT_Rect }))
	{
		M_Monstro->ChangeAnimation("M_Monstro_Move_R");
	}
	else
	{
		M_Monstro->ChangeAnimation("M_Monstro_Move_L");
	}
	//////////////////////////////////////////
	
	SetMove(M_Move * 150.0f * _DeltaTime);
	
}



void Monstro::CollisionCheck(float _DeltaTime)
{
	NowTime += _DeltaTime;

	if (NowTime >= 0.1f)
	{
		NowTime = 0.0f;
		M_Monstro_Coll->On();  //시간이지나면 다시collision을킨다
		RESET = 1;
	}

	std::vector<GameEngineCollision*> FCollisions;
	CollisionCheckParameter Check = { .TargetGroup = static_cast<int>(IsaacCollisionOrder::C_PlayerAtt_L), .TargetColType = CT_Rect, .ThisColType = CT_Rect };
	CollisionCheckParameter Check1 = { .TargetGroup = static_cast<int>(IsaacCollisionOrder::C_PlayerAtt_R), .TargetColType = CT_Rect, .ThisColType = CT_Rect };
	CollisionCheckParameter Check2 = { .TargetGroup = static_cast<int>(IsaacCollisionOrder::C_PlayerAtt_U), .TargetColType = CT_Rect, .ThisColType = CT_Rect };
	CollisionCheckParameter Check3 = { .TargetGroup = static_cast<int>(IsaacCollisionOrder::C_PlayerAtt_D), .TargetColType = CT_Rect, .ThisColType = CT_Rect };

	//함수짤 시간에 그냥 복붙을하겠노라
	if (true == M_Monstro_Coll->Collision(Check, FCollisions)) 
	{
		FCollisions[0]->GetActor()->Death();

		if (1 == RESET)
		{
			MonstroHp = MonstroHp - Isaac::MainPlayer->GetTearDamage();
			RESET = 0;
			M_Monstro_Coll->Off(); 
		}
		if (0 >= MonstroHp)
		{
			MonstroDeathcheck = true;
		}
	}
	if (true == M_Monstro_Coll->Collision(Check1, FCollisions))
	{
		FCollisions[0]->GetActor()->Death();
		if (1 == RESET)
		{
			MonstroHp = MonstroHp - Isaac::MainPlayer->GetTearDamage();
			RESET = 0;
			M_Monstro_Coll->Off();
		}
		if (0 >= MonstroHp)
		{
			MonstroDeathcheck = true;
		}
	}
	if (true == M_Monstro_Coll->Collision(Check2, FCollisions))
	{
		FCollisions[0]->GetActor()->Death();
		if (1 == RESET)
		{
			MonstroHp = MonstroHp - Isaac::MainPlayer->GetTearDamage();
			RESET = 0;
			M_Monstro_Coll->Off();
		}
		if (0 >= MonstroHp)
		{
			MonstroDeathcheck = true;
		}
	}
	if (true == M_Monstro_Coll->Collision(Check3, FCollisions))
	{
		FCollisions[0]->GetActor()->Death();
		if (1 == RESET)
		{
			MonstroHp = MonstroHp - Isaac::MainPlayer->GetTearDamage();
			RESET = 0;
			M_Monstro_Coll->Off();
		}
		if (0 >= MonstroHp)
		{
			MonstroDeathcheck = true;
		}
	}
	CollisionCheckParameter B_Check = { .TargetGroup = static_cast<int>(IsaacCollisionOrder::C_Isaac_Bomb), .TargetColType = CT_Rect, .ThisColType = CT_Rect };
	if (true == M_Monstro_Coll->Collision(B_Check, FCollisions))
	{
		MonstroHp = MonstroHp - 10; //이것은 폭탄의 데미지여
		if (0 >= MonstroHp)
		{
			MonstroDeathcheck = true;
		}
	}
}



void Monstro::Attack1()
{
	
	if (true == AttackBool)
	{
		float4 PlayerPos = Isaac::MainPlayer->GetPos() - GetPos();


		BloodTear* Tear1 = GetLevel()->CreateActor<BloodTear>();
		Tear1->SetBloodMoveDir(PlayerPos+float4::Up*45+float4::Left*50);
		Tear1->SetPos(GetPos());
		BloodTear* Tear2 = GetLevel()->CreateActor<BloodTear>();
		Tear2->SetBloodMoveDir(PlayerPos + float4::Up * 70 + float4::Right * 40);
		Tear2->SetPos(GetPos());
		BloodTear* Tear3 = GetLevel()->CreateActor<BloodTear>();
		Tear3->SetBloodMoveDir(PlayerPos + float4::Down * 60 + float4::Left * 30);
		Tear3->SetPos(GetPos());
		BloodTear* Tear4 = GetLevel()->CreateActor<BloodTear>();
		Tear4->SetBloodMoveDir(PlayerPos + float4::Down * 30 + float4::Right * 80);
		Tear4->SetPos(GetPos());
		BloodTear* Tear5 = GetLevel()->CreateActor<BloodTear>();
		Tear5->SetBloodMoveDir(PlayerPos + float4::Up * 20 + float4::Left * 90);
		Tear5->SetPos(GetPos());
		BloodTear* Tear6 = GetLevel()->CreateActor<BloodTear>();
		Tear6->SetBloodMoveDir(PlayerPos + float4::Up * 110 + float4::Right * 65);
		Tear6->SetPos(GetPos());
		BloodTear* Tear7 = GetLevel()->CreateActor<BloodTear>();
		Tear7->SetBloodMoveDir(PlayerPos + float4::Down * 105 + float4::Left * 30);
		Tear7->SetPos(GetPos());
		BloodTear* Tear8 = GetLevel()->CreateActor<BloodTear>();
		Tear8->SetBloodMoveDir(PlayerPos + float4::Up * 80 );
		Tear8->SetPos(GetPos());
		BloodTear* Tear9 = GetLevel()->CreateActor<BloodTear>();
		Tear9->SetBloodMoveDir(PlayerPos + float4::Down * 45 );
		Tear9->SetPos(GetPos());
		BloodTear* Tear10 = GetLevel()->CreateActor<BloodTear>();
		Tear10->SetBloodMoveDir(PlayerPos + float4::Up * 95 + float4::Right * 100);
		Tear10->SetPos(GetPos());



		AttackBool = false;
	}
}




void Monstro::Render(float _DeltaTime)
{
	//M_Monstro_Coll->DebugRender();
	//M_Monstro_SetColl_R->DebugRender();
}
