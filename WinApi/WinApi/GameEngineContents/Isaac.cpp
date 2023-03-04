#include <GameEngineBase/GameEnginePath.h>

#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineResources.h>
#include <GameEngineCore/GameEngineRender.h>
#include <GameEngineCore/GameEngineCore.h>

#include "IsaacIntro.h"
#include "IsaacEnum.h"
#include "Tears.h"
#include "UpTears.h"
#include "DownTears.h"
#include "RightTears.h"
#include "Isaac.h"
#include "Bomb.h"

//Debug
#include "Heart.h"
#include "Key.h"
#include "ItemBomb.h"
#include "Coin.h"

Isaac* Isaac::MainPlayer;

Isaac::Isaac()
{
}

Isaac::~Isaac()
{
}

bool DebugBool = true;

void Isaac::Start()
{
	MainPlayer = this;  //이 클래스 자체가 메인플레이어다

	
	SetMove(GameEngineWindow::GetScreenSize().half());  //시작하면위치는 가운데로
	SetPos(GameEngineWindow::GetScreenSize().half());
	
	

	if (false == GameEngineInput::IsKey("LeftMove"))
	{
		GameEngineInput::CreateKey("LeftMove", 'A');
		GameEngineInput::CreateKey("RightMove", 'D');
		GameEngineInput::CreateKey("DownMove", 'S');
		GameEngineInput::CreateKey("UpMove", 'W');
		GameEngineInput::CreateKey("Bomb", 'E');
		GameEngineInput::CreateKey("LeftTears", VK_LEFT);
		GameEngineInput::CreateKey("RightTears", VK_RIGHT);
		GameEngineInput::CreateKey("UpTears", VK_UP);
		GameEngineInput::CreateKey("DownTears", VK_DOWN);


		GameEngineInput::CreateKey("DebugItem", '1');
		GameEngineInput::CreateKey("DebugCollOff", '2');
		GameEngineInput::CreateKey("DebugCollOn", '3');
	}

	{
		Head = CreateRender(IsaacOrder::R_Player);
		Head->SetScale({ 135,120 });
		Head->CreateAnimation({ .AnimationName = "Right_Idle",  .ImageName = "Isaac_Face.bmp", .Start = 0, .End = 0, .InterTime = 0.3f });
		Head->CreateAnimation({ .AnimationName = "Right_Move",  .ImageName = "Isaac_Face.bmp", .Start = 10, .End = 19, .InterTime = 0.06f });
		Head->CreateAnimation({ .AnimationName = "Left_Idle",  .ImageName = "Isaac_Face.bmp", .Start = 0, .End = 0, .InterTime = 0.3f });
		Head->CreateAnimation({ .AnimationName = "Left_Move",  .ImageName = "Isaac_Face.bmp", .Start = 20, .End = 29 , .InterTime = 0.06f });
		Head->CreateAnimation({ .AnimationName = "Up_Idle",  .ImageName = "Isaac_Face.bmp", .Start = 0, .End = 0, .InterTime = 0.3f });
		Head->CreateAnimation({ .AnimationName = "Up_Move",  .ImageName = "Isaac_Face.bmp", .Start = 30, .End = 39 , .InterTime = 0.06f });
		Head->CreateAnimation({ .AnimationName = "Down_Idle",  .ImageName = "Isaac_Face.bmp", .Start = 0, .End = 0, .InterTime = 0.3f });
		Head->CreateAnimation({ .AnimationName = "Down_Move",  .ImageName = "Isaac_Face.bmp", .Start = 0, .End = 9 , .InterTime = 0.06f });

		Head->CreateAnimation({ .AnimationName = "Dead",  .ImageName = "Isaac_Face.bmp", .Start = 40, .End = 43 , .InterTime = 0.3f , .Loop = false });

	}
	
	{
		IsaacCollision = CreateCollision(IsaacCollisionOrder::C_Player);
		IsaacCollision->SetScale({ 40, 40 });
		IsaacCollision->SetPosition({ 0,-20 });
		IsaacCollision->On();
		IsaacCollision->SetDebugRenderType(CollisionType::CT_Rect);
	}

	DeadMenu = CreateRender("DeadMenu.BMP", IsaacOrder::R_Menu);
	DeadMenu->SetScaleToImage();
	DeadMenu->Off();
	
}

void Isaac::Update(float _DeltaTime)
{
	if (false == GameEngineInput::IsPress("LeftMove") &&
		false == GameEngineInput::IsPress("RightMove") &&
		false == GameEngineInput::IsPress("DownMove") &&
		false == GameEngineInput::IsPress("UpMove"))
	{
		MoveDir = float4::Zero;
	}
	
	DeadMenu->Off(); //업데이트에서 꼭 해야하나??
	DeathCheck(_DeltaTime);
	if (0 != GetPlayerHP())
	{
		Render(_DeltaTime);
		DebugSet();
		BombCheck(_DeltaTime);
		UpdateState(_DeltaTime);
		TearsAttack(_DeltaTime);
		Movecalculation(_DeltaTime);
		CollisionCheck(_DeltaTime);
		SetMove(MoveDir * _DeltaTime);
	}
}

//아이작 공격(Tears)관리
void Isaac::TearsAttack(float _DeltaTime)
{
	
	ResetTime_T += _DeltaTime;
	
	//방향키를 눌렀을때만 작동함
	if (false == GameEngineInput::IsDown("LeftTears") &&
		false == GameEngineInput::IsDown("RightTears") &&
		false == GameEngineInput::IsDown("UpTears") &&
		false == GameEngineInput::IsDown("DownTears"))
	{
		return;
	}

	if (ResetTime_T > TearUseTime)
	{
		ResetTime_T = 0.0f;
	} 
	//다음공격까지의 딜레이는 0.3초

	else { return; } //그사이에 누르는값은 리턴
	///////////////////왼쪽공격//////////////////
	if (true == GameEngineInput::IsDown("LeftTears"))
	{
		TEARSOUNDS();
		Tears* NewTears = GetLevel()->CreateActor<Tears>(IsaacOrder::R_Player);
		float4 FireDir3 = float4::Left;

		if (true == GameEngineInput::IsPress("UpMove") && true == GameEngineInput::IsPress("DownMove"))
		{
			//둘다누르는경우는 아무것도 안들어오게만든다.
		}
		else if (true == GameEngineInput::IsPress("UpMove"))
		{
			FireDir3.y -= 0.2f;
		}
		else if (true == GameEngineInput::IsPress("DownMove"))
		{
			FireDir3.y += 0.2f;
		}
		NewTears->SetLeftMoveDir(FireDir3); //방향설정
		NewTears->SetPos(GetPos()); //플레이어위치에 Set하고 Tears내부 코드가실행
	}
	/////////////////윗공격////////////////////
	if (true == GameEngineInput::IsDown("UpTears"))
	{
		TEARSOUNDS();
		UpTears* NewUpTears = GetLevel()->CreateActor<UpTears>(IsaacOrder::R_Player);

		float4 FireDir = float4::Up;

		if (true == GameEngineInput::IsPress("RightMove") && true == GameEngineInput::IsPress("LeftMove"))
		{
			//둘다누르는경우는 아무것도 안들어오게만든다.
		}
		else if (true == GameEngineInput::IsPress("RightMove"))
		{
			FireDir.x += 0.2f;
		}
		else if (true == GameEngineInput::IsPress("LeftMove"))
		{
			FireDir.x -= 0.2f;
		}
		NewUpTears->SetUpMoveDir(FireDir); //방향설정
		NewUpTears->SetPos(GetPos()); //나오는 위치설정
	}
	////////////////////아래공격/////////////////////////
	if (true == GameEngineInput::IsDown("DownTears"))
	{
		TEARSOUNDS();
		DownTears* NewDownTears = GetLevel()->CreateActor<DownTears>(IsaacOrder::R_Player);
		float4 FireDir2 = float4::Down;

		if (true == GameEngineInput::IsPress("RightMove") && true == GameEngineInput::IsPress("LeftMove"))
		{
			//둘다누르는경우는 아무것도 안들어오게만든다.
		}
		else if (true == GameEngineInput::IsPress("RightMove"))
		{
			FireDir2.x += 0.4f;
		}
		else if (true == GameEngineInput::IsPress("LeftMove"))
		{
			FireDir2.x -= 0.4f;
		}
		NewDownTears->SetDownMoveDir(FireDir2); //방향설정
		
		NewDownTears->SetPos(GetPos());
	}
	/////////////////오른쪽공격/////////////////
	if (true == GameEngineInput::IsDown("RightTears"))
	{
		TEARSOUNDS();
		RightTears* NewRightTears = GetLevel()->CreateActor<RightTears>(IsaacOrder::R_Player);
		float4 FireDir4 = float4::Right;

		if (true == GameEngineInput::IsPress("UpMove") && true == GameEngineInput::IsPress("DownMove"))
		{
			//둘다누르는경우는 아무것도 안들어오게만든다.
		}
		else if (true == GameEngineInput::IsPress("UpMove"))
		{
			FireDir4.y -= 0.4f;
		}
		else if (true == GameEngineInput::IsPress("DownMove"))
		{
			FireDir4.y += 0.4f;
		}
		NewRightTears->SetRightMoveDir(FireDir4); //방향설정
		NewRightTears->SetPos(GetPos());
	}
}

//맵 충돌 관리
void Isaac::Movecalculation(float _DeltaTime)
{
	GameEngineImage* ColImage = GameEngineResources::GetInst().ImageFind("BackGround_CS.BMP");
	if (nullptr == ColImage)
	{
		MsgAssert("충돌용 맵 이미지가 없습니다.");
	}
	bool Check = true;
	float4 NextPos = GetPos()-GetLevel()->GetCameraPos() + MoveDir * _DeltaTime;

	if (RGB(0, 0, 0) == ColImage->GetPixelColor(NextPos, RGB(0, 0, 0)))
	{
		Check = false;
	}
	if (false == Check)
	{
		MoveDir = float4::Zero;
	}
	
}

//collision 체크
void Isaac::CollisionCheck(float _DeltaTime)
{
	CollTime += _DeltaTime;
	if (CollTime >= 3.0f) 
	{
		CollTime = 0.0f;
		if (true == DebugBool) //Debug모드용 Bool값
		{
			IsaacCollision->On(); //시간이지나면 다시collision을킨다
		}
		DamagedIsaac = false;
		DeadIsaac = false;
	}
	if (nullptr != IsaacCollision) //아이작의 콜리전이 null이아니어야 상호작용가능
	{
		//Monster
		if (true == IsaacCollision->Collision({ .TargetGroup = static_cast<int>(IsaacCollisionOrder::C_Monster), .TargetColType = CT_Rect, .ThisColType = CT_Rect }))
		{
			ISAACHURT = GameEngineResources::GetInst().SoundPlayToControl("hurtgrunt2.wav");
			ISAACHURT.Volume(0.2f);
			ISAACHURT.LoopCount(1);
			CollTime += _DeltaTime;
			HP -= 1;
			IsaacCollision->Off();
			DamagedIsaac = true;
		}
		if (true == IsaacCollision->Collision({ .TargetGroup = static_cast<int>(IsaacCollisionOrder::C_Isaac_Bomb), .TargetColType = CT_Rect, .ThisColType = CT_Rect }))
		{
			ISAACHURT = GameEngineResources::GetInst().SoundPlayToControl("hurtgrunt0.wav");
			ISAACHURT.Volume(0.2f);
			ISAACHURT.LoopCount(1);
			CollTime += _DeltaTime;
			HP -= 2;
			IsaacCollision->Off();
			DamagedIsaac = true;
		}
		if (true == IsaacCollision->Collision({ .TargetGroup = static_cast<int>(IsaacCollisionOrder::C_Fire), .TargetColType = CT_Rect, .ThisColType = CT_Rect }))
		{
			ISAACHURT = GameEngineResources::GetInst().SoundPlayToControl("hurtgrunt1.wav");
			ISAACHURT.Volume(0.2f);
			ISAACHURT.LoopCount(1);
			CollTime += _DeltaTime;
			HP -= 1;
			IsaacCollision->Off();
			DamagedIsaac = true;
		}
		

		//MapActor
		std::vector<GameEngineCollision*> ICollisions;
		CollisionCheckParameter CheckHeart = { .TargetGroup = static_cast<int>(IsaacCollisionOrder::C_Heart), .TargetColType = CT_Rect, .ThisColType = CT_Rect };
		CollisionCheckParameter CheckKey = { .TargetGroup = static_cast<int>(IsaacCollisionOrder::C_Key), .TargetColType = CT_Rect, .ThisColType = CT_Rect };
		CollisionCheckParameter CheckBomb = { .TargetGroup = static_cast<int>(IsaacCollisionOrder::C_ItemBomb), .TargetColType = CT_Rect, .ThisColType = CT_Rect };
		CollisionCheckParameter CheckCoin = { .TargetGroup = static_cast<int>(IsaacCollisionOrder::C_Coin), .TargetColType = CT_Rect, .ThisColType = CT_Rect };
		CollisionCheckParameter CheckLeo = { .TargetGroup = static_cast<int>(IsaacCollisionOrder::C_Item_Leo), .TargetColType = CT_Rect, .ThisColType = CT_Rect };
		CollisionCheckParameter CheckGlasses = { .TargetGroup = static_cast<int>(IsaacCollisionOrder::C_Item_Glasses), .TargetColType = CT_Rect, .ThisColType = CT_Rect };
		CollisionCheckParameter CheckItemHeart = { .TargetGroup = static_cast<int>(IsaacCollisionOrder::C_Item_Heart), .TargetColType = CT_Rect, .ThisColType = CT_Rect };
		CollisionCheckParameter CheckBlackLotus = { .TargetGroup = static_cast<int>(IsaacCollisionOrder::C_Item_Blacklotus), .TargetColType = CT_Rect, .ThisColType = CT_Rect };
		//Heart
		if (true == IsaacCollision->Collision(CheckHeart, ICollisions) && 6 != HP)
		{
			ICollisions[0]->GetActor()->Death();
			HP += 2;
			if (HP > MaxHP)
			{
				HP = MaxHP;
			}
		}
		//Key
		if (true == IsaacCollision->Collision(CheckKey, ICollisions))
		{
			KEYDROPSOUND = GameEngineResources::GetInst().SoundPlayToControl("Keydrop.wav");
			KEYDROPSOUND.Volume(0.2f);
			KEYDROPSOUND.LoopCount(1);
			ICollisions[0]->GetActor()->Death();
			KeyCount += 1;
		}
		//Bomb
		if (true == IsaacCollision->Collision(CheckBomb, ICollisions))
		{
			ICollisions[0]->GetActor()->Death();
			BombCount += 1;
		}
		//Coin
		if (true == IsaacCollision->Collision(CheckCoin, ICollisions))
		{
			COINDROP = GameEngineResources::GetInst().SoundPlayToControl("dimepickup.wav");
			COINDROP.Volume(0.2f);
			COINDROP.LoopCount(1);
			ICollisions[0]->GetActor()->Death();
			CoinCount += 1;
		}
		//Item Leo
		if (true == IsaacCollision->Collision(CheckLeo, ICollisions))
		{
			//COINDROP = GameEngineResources::GetInst().SoundPlayToControl("dimepickup.wav");
			//COINDROP.Volume(0.2f);
			//COINDROP.LoopCount(1);
			ICollisions[0]->GetActor()->Death();
			TearDamage += 1;
		}
		if (true == IsaacCollision->Collision(CheckGlasses, ICollisions))
		{
			//COINDROP = GameEngineResources::GetInst().SoundPlayToControl("dimepickup.wav");
			//COINDROP.Volume(0.2f);
			//COINDROP.LoopCount(1);
			ICollisions[0]->GetActor()->Death();
			TearSpeed += 200.0f;
		}
		if (true == IsaacCollision->Collision(CheckItemHeart, ICollisions))
		{
			//COINDROP = GameEngineResources::GetInst().SoundPlayToControl("dimepickup.wav");
			//COINDROP.Volume(0.2f);
			//COINDROP.LoopCount(1);
			ICollisions[0]->GetActor()->Death();
			TearUseTime -=0.2f;
		}
		if (true == IsaacCollision->Collision(CheckBlackLotus, ICollisions))
		{
			//COINDROP = GameEngineResources::GetInst().SoundPlayToControl("dimepickup.wav");
			//COINDROP.Volume(0.2f);
			//COINDROP.LoopCount(1);
			ICollisions[0]->GetActor()->Death();
			TearRange += 0.5f;
		}
	}
}


void Isaac::DirCheck(const std::string_view& _AnimationName)
{
	std::string PrevDirString = DirString;
	Head->ChangeAnimation(DirString + _AnimationName.data());
	
	if (GameEngineInput::IsPress("LeftMove"))
	{
		DirString = "Left_";
	}
	else if (GameEngineInput::IsPress("RightMove"))
	{
		DirString = "Right_";
	}
	else if (GameEngineInput::IsPress("UpMove"))
	{
		DirString = "Up_";
	}
	else if (GameEngineInput::IsPress("DownMove"))
	{
		DirString = "Down_";
	}

	if (PrevDirString != DirString)
	{
		Head->ChangeAnimation(DirString + _AnimationName.data());
	}
}


//죽은거 체크 ㅇㅇ 아직 잘안됨..
void Isaac::DeathCheck(float _DeltaTime)
{
	if (0 == GetPlayerHP())
	{
		if (false == GameEngineInput::IsKey("BackTitle"))
		{
			GameEngineInput::CreateKey("BackTitle", VK_SPACE);
		}

		DeadTime += _DeltaTime;

		DeadIsaac = false;
		IsaacCollision->Off();
		Head->ChangeAnimation("Dead");
		if (DeadTime > 2.0f)
		{
			SetMove(GameEngineWindow::GetScreenSize().half());
			SetPos(GameEngineWindow::GetScreenSize().half());

			DeadMenu->On();
			if (true == GameEngineInput::IsDown("BackTitle"))
			{
				//DeadMenu->Off(); //얘 왜 안됨?
				SetPlayerHP(6);
				DeadTime = 0.0f;
				GameEngineCore::GetInst()->ChangeLevel("TitleLevel");
				
			}
		}	
	}
}

void Isaac::BombCheck(float _DeltaTime)
{
	ResetTime_B += _DeltaTime;
	if (false == GameEngineInput::IsDown("Bomb"))
	{
		return;
	}
	if (ResetTime_B > 1.0f) { ResetTime_B = 0.0f; } //다음폭탄까지의 딜레이는 1.0
	else { return; } //그사이에 누르는값은 리턴

	if (true == GameEngineInput::IsDown("Bomb"))
	{
		if (0 != BombCount)
		{
			Bomb* NewBomb = GetLevel()->CreateActor<Bomb>(IsaacOrder::R_Player);
			BombCount -= 1;
		}
	}
}


void Isaac::DebugSet()
{
	if (true == GameEngineInput::IsDown("DebugItem"))
	{
		Heart* DebugHeart = GetLevel()->CreateActor<Heart>(IsaacOrder::R_Wall);
		DebugHeart->SetPos(GetPos()+float4::Up*80);
		Key* DebugKey = GetLevel()->CreateActor<Key>(IsaacOrder::R_Wall);
		DebugKey->SetPos(GetPos() + float4::Up * 80+float4::Right*60);
		ItemBomb* DebugItemBomb = GetLevel()->CreateActor<ItemBomb>(IsaacOrder::R_Wall);
		DebugItemBomb->SetPos(GetPos() + float4::Up * 80 + float4::Left * 65);
		Coin* DebugCoin = GetLevel()->CreateActor<Coin>(IsaacOrder::R_Wall);
		DebugCoin->SetPos(GetPos() + float4::Up * 80 + float4::Left * 115);
	}
	if (true == GameEngineInput::IsDown("DebugCollOff"))
	{
		IsaacCollision->Off();
		DebugBool = false;
	}
	if (true == GameEngineInput::IsDown("DebugCollOn"))
	{
		IsaacCollision->On();
		DebugBool = true;
	}
}

void Isaac::TEARSOUNDS()
{
	TEARSOUND = GameEngineResources::GetInst().SoundPlayToControl("tearfire.wav");
	TEARSOUND.Volume(0.3f);
	TEARSOUND.LoopCount(1);
}
void Isaac::Render(float _DeltaTime)
{
	IsaacCollision->DebugRender();
}