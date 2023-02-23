#include <GameEngineBase/GameEnginePath.h>

#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineResources.h>
#include <GameEngineCore/GameEngineRender.h>

#include "IsaacIntro.h"
#include "IsaacEnum.h"
#include "Tears.h"
#include "UpTears.h"
#include "DownTears.h"
#include "RightTears.h"
#include "Isaac.h"

Isaac* Isaac::MainPlayer;

Isaac::Isaac()
{
}

Isaac::~Isaac()
{
}

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


	}
	ChangeState(IsaacState::IDLE);
	{
		IsaacCollision = CreateCollision(IsaacCollisionOrder::C_Player);
		IsaacCollision->SetScale({ 50, 50 });
		IsaacCollision->On();
		IsaacCollision->SetDebugRenderType(CollisionType::CT_Rect);
	}
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
	UpdateState(_DeltaTime);
	TearsAttack(_DeltaTime);
	CollisionCheck(_DeltaTime);
	Movecalculation(_DeltaTime);
	SetMove(MoveDir * _DeltaTime);
	
}

//아이작 공격(Tears)관리
void Isaac::TearsAttack(float _DeltaTime)
{
	ResetTime += _DeltaTime;
	//방향키를 눌렀을때만 작동함
	if (false == GameEngineInput::IsDown("LeftTears")&&
		false == GameEngineInput::IsDown("RightTears")&&
		false == GameEngineInput::IsDown("UpTears")&&
		false == GameEngineInput::IsDown("DownTears"))
	{ 
		return; 
	}

	if (ResetTime>0.3f){ ResetTime = 0.0f; } //다음공격까지의 딜레이는 0.3
	else { return; } //그사이에 누르는값은 리턴

	if (true == GameEngineInput::IsDown("LeftTears"))
	{
		Tears* NewTears = GetLevel()->CreateActor<Tears>(IsaacOrder::R_Player);
		NewTears->SetPos(GetPos()); //플레이어위치에 Set하고 Tears내부 코드가실행
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








//맵 충돌 관리
void Isaac::Movecalculation(float _DeltaTime)
{
	GameEngineImage* ColImage = GameEngineResources::GetInst().ImageFind("BackGround_CS.BMP");
	if (nullptr == ColImage)
	{
		MsgAssert("충돌용 맵 이미지가 없습니다.");
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
	ResetTime += _DeltaTime;
	if (nullptr != IsaacCollision) //아이작의 콜리전이 null이아니어야 상호작용가능
	{
		if (true == IsaacCollision->Collision({ .TargetGroup = static_cast<int>(IsaacCollisionOrder::C_Monster), .TargetColType = CT_Rect, .ThisColType = CT_Rect }))
		{
			HP -= 1;
			IsaacCollision->Off();
			ResetTime = 0.0f;
			if (ResetTime > 3.0f)
			{
				IsaacCollision->On();
			}
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
