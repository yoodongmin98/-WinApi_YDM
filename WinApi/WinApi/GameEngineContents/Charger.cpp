
#include <GameEngineBase/GameEngineDirectory.h>

#include <GameEnginePlatform/GameEngineInput.h>

#include <GameEngineCore/GameEngineRender.h>
#include <GameEngineCore/GameEngineResources.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCollision.h>


#include "Isaac.h"
#include "IsaacEnum.h"
#include "Charger.h"

#include<cstdlib>
#include<ctime>


Charger::Charger()
{

}

Charger::~Charger()
{
}

bool ChargerLoad = true;
void Charger::ImageLoad()
{
	GameEngineDirectory Dir;
	Dir.MoveParentToDirectory("ContentsResources");
	Dir.Move("ContentsResources");
	Dir.Move("Image");
	Dir.Move("Play");
	Dir.Move("Monster");

	GameEngineImage* L_Charger = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("M_Charger_L.BMP"));
	L_Charger->Cut(4, 4);
	GameEngineImage* R_Charger = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("M_Charger_R.BMP"));
	R_Charger->Cut(4, 4);
}


void Charger::Start()
{
	if (true == ChargerLoad)
	{
		ImageLoad();	
		ChargerLoad = false;
	}
	M_Charger = CreateRender(IsaacOrder::R_Monster);
	M_Charger->SetScale({ 70, 70 });


	M_Charger->CreateAnimation({ .AnimationName = "M_Charger_Idle_Left",  .ImageName = "M_Charger_L.bmp", .Start = 0, .End = 3, .InterTime = 0.15f });
	M_Charger->CreateAnimation({ .AnimationName = "M_Charger_Idle_Down",  .ImageName = "M_Charger_L.bmp", .Start = 8, .End = 11, .InterTime = 0.1f });
	M_Charger->CreateAnimation({ .AnimationName = "M_Charger_Idle_Right",  .ImageName = "M_Charger_R.bmp", .Start = 0, .End = 3, .InterTime = 0.15f });
	M_Charger->CreateAnimation({ .AnimationName = "M_Charger_Idle_Up",  .ImageName = "M_Charger_L.bmp", .Start = 4, .End = 7, .InterTime = 0.15f });

	M_Charger->CreateAnimation({ .AnimationName = "M_Charger_UpDash",  .ImageName = "M_Charger_L.bmp", .Start = 14, .End = 14, .InterTime = 0.15f });
	M_Charger->CreateAnimation({ .AnimationName = "M_Charger_DownDash",  .ImageName = "M_Charger_L.bmp", .Start = 12, .End = 12, .InterTime = 0.15f });
	M_Charger->CreateAnimation({ .AnimationName = "M_Charger_LeftDash",  .ImageName = "M_Charger_L.bmp", .Start = 13, .End = 13, .InterTime = 0.15f });
	M_Charger->CreateAnimation({ .AnimationName = "M_Charger_RightDash",  .ImageName = "M_Charger_R.bmp", .Start = 13, .End = 13, .InterTime = 0.15f });

	//M_Blob->CreateAnimation({ .AnimationName = "M_Blob_Idle",  .ImageName = "M_fly_Dead.bmp", .Start = 0, .End = 11, .InterTime = 0.03f, .Loop = false });
	M_Charger->ChangeAnimation("M_Charger_Idle_Up");
	{
		M_Charger_Coll = CreateCollision(IsaacCollisionOrder::C_Monster);
		M_Charger_Coll->SetScale({ 35, 35 });
		M_Charger_Coll->On();
		M_Charger_Coll->SetDebugRenderType(CollisionType::CT_Rect);

		M_Charger_SetColl_U = CreateCollision(IsaacCollisionOrder::C_Moster_Set);
		M_Charger_SetColl_U->SetDebugRenderType(CollisionType::CT_Rect);
		M_Charger_SetColl_U->SetScale({ 20, 500 });
		M_Charger_SetColl_U->SetPosition({ 0,-250 });
		M_Charger_SetColl_U->On();

		M_Charger_SetColl_D = CreateCollision(IsaacCollisionOrder::C_Moster_Set);
		M_Charger_SetColl_D->SetDebugRenderType(CollisionType::CT_Rect);
		M_Charger_SetColl_D->SetScale({ 20, 500 });
		M_Charger_SetColl_D->SetPosition({ 0,250 });
		M_Charger_SetColl_D->On();

		M_Charger_SetColl_L = CreateCollision(IsaacCollisionOrder::C_Moster_Set);
		M_Charger_SetColl_L->SetDebugRenderType(CollisionType::CT_Rect);
		M_Charger_SetColl_L->SetScale({ 500, 20 });
		M_Charger_SetColl_L->SetPosition({ -250,0 });
		M_Charger_SetColl_L->On();

		M_Charger_SetColl_R = CreateCollision(IsaacCollisionOrder::C_Moster_Set);
		M_Charger_SetColl_R->SetDebugRenderType(CollisionType::CT_Rect);
		M_Charger_SetColl_R->SetScale({ 500, 20 });
		M_Charger_SetColl_R->SetPosition({ 250,0 });
		M_Charger_SetColl_R->On();
	}

}

bool ChargerDeathcheck = false;
bool Check = true;
void Charger::Update(float _DeltaTime)
{
	if (true == ChargerDeathcheck)
	{
		Death();
	}
	SetTime += _DeltaTime;
	if (SetTime > 1.0)
	{
		SetTime = 0.0f;
		Check = true;
	}
	Movecalculation(_DeltaTime);
	CollisionCheck(_DeltaTime);
	SetMove(MoveDir * _DeltaTime);
}

void Charger::Movecalculation(float _DeltaTime)
{
	
	RandomTime += _DeltaTime;
	if (RandomTime > 7.0f)
	{
		srand((unsigned int)time(NULL)); //seed값으로 현재시간 부여 
		RandomMove = rand() % 10;
	}
	float4 MoveRange = float4::Zero;
	if (1 == RandomMove || 2 == RandomMove || 3 == RandomMove)
	{
		M_Charger->ChangeAnimation("M_Charger_Idle_Up");
		MoveRange += float4::Up;
	}
	if (4 == RandomMove || 5 == RandomMove)
	{
		M_Charger->ChangeAnimation("M_Charger_Idle_Right");
		MoveRange += float4::Right;
	}
	if (6 == RandomMove || 7 == RandomMove || 8 == RandomMove)
	{
		M_Charger->ChangeAnimation("M_Charger_Idle_Down");
		MoveRange += float4::Down;
	}
	if (9 == RandomMove || 0 == RandomMove)
	{
		M_Charger->ChangeAnimation("M_Charger_Idle_Left");
		MoveRange += float4::Left;
	}
	/////////////////////////백그라운드 이미지로드//////////////////////////
	GameEngineImage* ColImage = GameEngineResources::GetInst().ImageFind("BackGround_CS.BMP");
	if (nullptr == ColImage)
	{
		MsgAssert("충돌용 맵 이미지가 없습니다.");
	}
	
	/////////////////////////////////////////////////////////////////////

	if (true == M_Charger_SetColl_U->Collision({ .TargetGroup = static_cast<int>(IsaacCollisionOrder::C_Player), .TargetColType = CT_Rect, .ThisColType = CT_Rect }))
	{
		M_Charger->ChangeAnimation("M_Charger_UpDash");
		MoveRange = float4::Up * 5.0f;
	}
	else if (true == M_Charger_SetColl_D->Collision({ .TargetGroup = static_cast<int>(IsaacCollisionOrder::C_Player), .TargetColType = CT_Rect, .ThisColType = CT_Rect }))
	{
		M_Charger->ChangeAnimation("M_Charger_DownDash");
		MoveRange = float4::Down * 5.0f;
	}
	else if (true == M_Charger_SetColl_R->Collision({ .TargetGroup = static_cast<int>(IsaacCollisionOrder::C_Player), .TargetColType = CT_Rect, .ThisColType = CT_Rect }))
	{
		M_Charger->ChangeAnimation("M_Charger_RightDash");
		MoveRange = float4::Right * 5.0f;
	}
	else if (true == M_Charger_SetColl_L->Collision({ .TargetGroup = static_cast<int>(IsaacCollisionOrder::C_Player), .TargetColType = CT_Rect, .ThisColType = CT_Rect }))
	{
		M_Charger->ChangeAnimation("M_Charger_LeftDash");
		MoveRange = float4::Left * 5.0f;
	}
	MoveDir = MoveRange * 50.0f; //움직임을 미리 정해놓고

	float4 NextPos = GetPos() + MoveDir * _DeltaTime; //다음포스를 정의한다음

	if (RGB(0, 0, 0) == ColImage->GetPixelColor(NextPos, RGB(0, 0, 0))) //그위치가 0,0,0이면
	{
		Check = false; //못움직인다
	}
	if (false == Check)
	{
		MoveDir = float4::Zero;
	}

}


void Charger::CollisionCheck(float _DeltaTime)
{
	NowTime += _DeltaTime;

	if (NowTime >= 0.3f)
	{
		NowTime = 0.0f;
		M_Charger_Coll->On();  //시간이지나면 다시collision을킨다
		RESET = 1;
		
	}

	std::vector<GameEngineCollision*> FCollisions;
	CollisionCheckParameter Check = { .TargetGroup = static_cast<int>(IsaacCollisionOrder::C_PlayerAtt_L), .TargetColType = CT_Rect, .ThisColType = CT_Rect };
	CollisionCheckParameter Check1 = { .TargetGroup = static_cast<int>(IsaacCollisionOrder::C_PlayerAtt_R), .TargetColType = CT_Rect, .ThisColType = CT_Rect };
	CollisionCheckParameter Check2 = { .TargetGroup = static_cast<int>(IsaacCollisionOrder::C_PlayerAtt_U), .TargetColType = CT_Rect, .ThisColType = CT_Rect };
	CollisionCheckParameter Check3 = { .TargetGroup = static_cast<int>(IsaacCollisionOrder::C_PlayerAtt_D), .TargetColType = CT_Rect, .ThisColType = CT_Rect };

	//함수짤 시간에 그냥 복붙을하겠노라
	if (true == M_Charger_Coll->Collision(Check, FCollisions)) //PlayerAtt에 닿았을때
	{
		FCollisions[0]->GetActor()->Death(); //닿은 ATT는 지워버리고
		if (1 == RESET)
		{
			ChargerHp = ChargerHp - Isaac::MainPlayer->GetTearDamage();
			RESET = 0;
			M_Charger_Coll->Off(); //맞아도 일정시간동안 상호작용이안된다.
		}
		if (0 >= ChargerHp)
		{
			//M_Blob->ChangeAnimation("M_fly_Dead");
			ChargerDeathcheck = true;
		}
	}
	if (true == M_Charger_Coll->Collision(Check1, FCollisions))
	{
		FCollisions[0]->GetActor()->Death();

		if (1 == RESET)
		{
			ChargerHp = ChargerHp - Isaac::MainPlayer->GetTearDamage();
			RESET = 0;
			M_Charger_Coll->Off();
		}
		if (0 >= ChargerHp)
		{
			//M_Blob->ChangeAnimation("M_fly_Dead");
			ChargerDeathcheck = true;
		}
	}
	if (true == M_Charger_Coll->Collision(Check2, FCollisions))
	{
		FCollisions[0]->GetActor()->Death();

		if (1 == RESET)
		{
			ChargerHp = ChargerHp - Isaac::MainPlayer->GetTearDamage();
			RESET = 0;
			M_Charger_Coll->Off();
		}
		if (0 >= ChargerHp)
		{
			//M_Blob->ChangeAnimation("M_fly_Dead");
			ChargerDeathcheck = true;
		}
	}
	if (true == M_Charger_Coll->Collision(Check3, FCollisions))
	{
		FCollisions[0]->GetActor()->Death();

		if (1 == RESET)
		{
			ChargerHp = ChargerHp - Isaac::MainPlayer->GetTearDamage();
			RESET = 0;
			M_Charger_Coll->Off();
		}
		if (0 >= ChargerHp)
		{
			//M_Blob->ChangeAnimation("M_fly_Dead");
			ChargerDeathcheck = true;
		}
	}




	



	CollisionCheckParameter B_Check = { .TargetGroup = static_cast<int>(IsaacCollisionOrder::C_Isaac_Bomb), .TargetColType = CT_Rect, .ThisColType = CT_Rect };
	if (true == M_Charger_Coll->Collision(B_Check, FCollisions))
	{
		ChargerHp = ChargerHp - 5; //이것은 폭탄의 데미지여
		if (0 >= ChargerHp)
		{
			//M_Blob->ChangeAnimation("M_fly_Dead");
			ChargerDeathcheck = true;
		}
	}
}

void Charger::Render(float _DeltaTime)
{
	/*M_Charger_SetColl_U->DebugRender();
	M_Charger_SetColl_D->DebugRender();
	M_Charger_SetColl_L->DebugRender();
	M_Charger_SetColl_R->DebugRender();
	M_Charger_Coll->DebugRender();*/
}