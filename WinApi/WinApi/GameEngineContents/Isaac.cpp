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

Isaac* Isaac::MainPlayer;

Isaac::Isaac()
{
}

Isaac::~Isaac()
{
}

void Isaac::Start()
{
	MainPlayer = this;  //�� Ŭ���� ��ü�� �����÷��̾��

	
	SetMove(GameEngineWindow::GetScreenSize().half());  //�����ϸ���ġ�� �����
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

		Head->CreateAnimation({ .AnimationName = "Dead",  .ImageName = "Isaac_Face.bmp", .Start = 40, .End = 43 , .InterTime = 0.3f , .Loop=false});

	}
	ChangeState(IsaacState::IDLE);
	{
		IsaacCollision = CreateCollision(IsaacCollisionOrder::C_Player);
		IsaacCollision->SetScale({ 50, 50 });
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
		MoveDir *= 0.0000000001f;
	}

	DeadMenu->Off(); //������Ʈ���� �� �ؾ��ϳ�??
	DeathCheck(_DeltaTime);
	if (0 != GetPlayerHP())
	{
		BombCheck(_DeltaTime);
		UpdateState(_DeltaTime);
		TearsAttack(_DeltaTime);
		Movecalculation(_DeltaTime);
		CollisionCheck(_DeltaTime);
		SetMove(MoveDir * _DeltaTime);
	}
}

//������ ����(Tears)����
void Isaac::TearsAttack(float _DeltaTime)
{
	ResetTime_T += _DeltaTime;
	//����Ű�� ���������� �۵���
	if (false == GameEngineInput::IsDown("LeftTears")&&
		false == GameEngineInput::IsDown("RightTears")&&
		false == GameEngineInput::IsDown("UpTears")&&
		false == GameEngineInput::IsDown("DownTears"))
	{ 
		return; 
	}

	if (ResetTime_T >0.3f){ ResetTime_T = 0.0f; } //�������ݱ����� �����̴� 0.3
	else { return; } //�׻��̿� �����°��� ����

	if (true == GameEngineInput::IsDown("LeftTears"))
	{
		Tears* NewTears = GetLevel()->CreateActor<Tears>(IsaacOrder::R_Player);
		NewTears->SetPos(GetPos()); //�÷��̾���ġ�� Set�ϰ� Tears���� �ڵ尡����
	}
	if (true == GameEngineInput::IsDown("UpTears"))
	{
		UpTears* NewUpTears = GetLevel()->CreateActor<UpTears>(IsaacOrder::R_Player);
		NewUpTears->SetPos(GetPos());
	}
	if (true == GameEngineInput::IsDown("DownTears"))
	{
		DownTears* NewUpTears = GetLevel()->CreateActor<DownTears>(IsaacOrder::R_Player);
		NewUpTears->SetPos(GetPos());
	}
	if (true == GameEngineInput::IsDown("RightTears"))
	{
		RightTears* NewUpTears = GetLevel()->CreateActor<RightTears>(IsaacOrder::R_Player);
		NewUpTears->SetPos(GetPos());
	}
}

//�� �浹 ����
void Isaac::Movecalculation(float _DeltaTime)
{
	GameEngineImage* ColImage = GameEngineResources::GetInst().ImageFind("BackGround_CS.BMP");
	if (nullptr == ColImage)
	{
		MsgAssert("�浹�� �� �̹����� �����ϴ�.");
	}
	bool Check = true;
	float4 NextPos = GetPos() + MoveDir * _DeltaTime;

	if (RGB(0, 0, 0) == ColImage->GetPixelColor(NextPos, RGB(0, 0, 0)))
	{
		Check = false;

	}
	if (false == Check)
	{
		MoveDir = float4::Zero;
	}
}

void Isaac::CollisionCheck(float _DeltaTime)
{
	CollTime += _DeltaTime;
	if (CollTime >= 3.0f) 
	{
		CollTime = 0.0f;
		IsaacCollision->On(); //�ð��������� �ٽ�collision��Ų��

		DamagedIsaac = false;
	}
	if (nullptr != IsaacCollision) //�������� �ݸ����� null�̾ƴϾ�� ��ȣ�ۿ밡��
	{
		if (true == IsaacCollision->Collision({ .TargetGroup = static_cast<int>(IsaacCollisionOrder::C_Monster), .TargetColType = CT_Rect, .ThisColType = CT_Rect }))
		{
			CollTime += _DeltaTime;
			HP -= 1;
			IsaacCollision->Off();
			DamagedIsaac = true;
		}
		else if (true == IsaacCollision->Collision({ .TargetGroup = static_cast<int>(IsaacCollisionOrder::C_Bomb), .TargetColType = CT_Rect, .ThisColType = CT_Rect }))
		{
			CollTime += _DeltaTime;
			HP -= 1;
			IsaacCollision->Off();
			DamagedIsaac = true;
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


void Isaac::DeathCheck(float _DeltaTime)
{
	if (0 == GetPlayerHP())
	{
		if (false == GameEngineInput::IsKey("BackTitle"))
		{
			GameEngineInput::CreateKey("BackTitle", VK_SPACE);
		}

		DeadTime += _DeltaTime;

		DamagedIsaac = false;
		IsaacCollision->Off();
		Head->ChangeAnimation("Dead");
		if (DeadTime > 2.0f)
		{
			SetMove(GameEngineWindow::GetScreenSize().half());
			SetPos(GameEngineWindow::GetScreenSize().half());

			DeadMenu->On();
			if (true == GameEngineInput::IsDown("BackTitle"))
			{
				//DeadMenu->Off(); //�� �� �ȵ�?
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
	if (ResetTime_B > 1.0f) { ResetTime_B = 0.0f; } //������ź������ �����̴� 1.0
	else { return; } //�׻��̿� �����°��� ����


	if (true == GameEngineInput::IsDown("Bomb"))
	{
		Bomb* NewBomb = GetLevel()->CreateActor<Bomb>(IsaacOrder::R_Player);
	}
}

void Isaac::Render(float _DeltaTime)
{
//	IsaacCollision->DebugRender();
}