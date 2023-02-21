#include "Isaaclevel.h"
#include "IsaacEnum.h"

// 프로젝트 순서에 따라서 정렬
#include <GameEngineBase/GameEngineDirectory.h>
#include <GameEnginePlatform/GameEngineInput.h>

#include <GameEnginePlatform/GameEngineWindow.h>

#include <GameEngineCore/GameEngineResources.h>
#include <GameEngineCore/GameEngineCore.h>
#include <GameEngineCore/GameEngineRender.h>

// 나랑 같은 등급의 헤더들
#include "Isaac.h"
#include "Room.h"
#include "Monster.h"
#include "Door.h"
#include "AllBack.h"



IsaacLevel::IsaacLevel()
{
	
}

IsaacLevel::~IsaacLevel()
{
}

void IsaacLevel::SoundLoad()
{
	//GameEngineDirectory Dir;
	//Dir.MoveParentToDirectory("ContentsResources");
	//Dir.Move("ContentsResources");
	//Dir.Move("Sound");
	//{
	//	GameEngineResources::GetInst().SoundLoad(Dir.GetPlusFileName("BasementBGM.ogg"));
	//}
	//PLAYBGMPLAYER = GameEngineResources::GetInst().SoundPlayToControl("BasementBGM.ogg");
	//PLAYBGMPLAYER.Volume(0.1f);

}


void IsaacLevel::Loading()
{
	// 상대경로 탐색
	GameEngineDirectory Dir;
	Dir.MoveParentToDirectory("ContentsResources");
	Dir.Move("ContentsResources");
	Dir.Move("Image");
	Dir.Move("Play");

	// Level Image Load
	{
		GameEngineImage* head = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Isaac_Face.BMP"));
		head->Cut(10, 4);
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Room.BMP"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Room_Depth.BMP"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Room_Boss.BMP"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("BackGround_CS.BMP"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Play_BlackGround.BMP"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Play_Settingmenu.BMP"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("BackDrop.BMP"));

		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Map_BossDoor_Left.BMP"));
		GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Map_BossDoor_Right.BMP"));

		AllBack* Image = CreateActor<AllBack>();
		BackDrop = Image->CreateRender("BackDrop.BMP", IsaacOrder::R_Door);
		BackDrop->SetScale({ 600,150 });
		

		GameEngineImage* Door_Down = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Map_Door_Down.BMP"));
		Door_Down->Cut(4, 1);
		GameEngineImage* Door_Up = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Map_Door_Up.BMP"));
		Door_Up->Cut(4, 1);
		GameEngineImage* Door_Right = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Map_Door_Right.BMP"));
		Door_Right->Cut(4, 1);
		GameEngineImage* Door_Left = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Map_Door_Left.BMP"));
		Door_Left->Cut(4, 1);

		GameEngineImage* Tear = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Tear.bmp"));
		Tear->Cut(8, 4);
		GameEngineImage* Tears = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Tear_Pop.bmp"));
		Tears->Cut(4, 4);
	}
	// 액터 생성
	{
		CreateActor<Isaac>();


		// 이걸 해줘야 기존에 혹시 방을 만든게 있다면
		// 그걸 다 정리하고 새롭게 시작할수 있다.
		Room::RoomCreateStart();

		//만약 시연회를 한다면?                            (Start) (obj) (item)
		CreateRoom(0, 0, 1); //Start                        ㅁ  ㅁ  ㅁ 
		CreateRoom(0, 1, 1); //Monster와 door               ㅁㅁㅁ  ㅁㅁ(Boss)
		CreateRoom(1, 1, 1); //Monster2						    ㅁㅁㅁ
		CreateRoom(2, 1, 1); //item설명
		CreateRoom(2, 0, 2); //오브젝트끼리의 상호구조 설명
		CreateRoom(2, 2, 1); //Monster3
		CreateRoom(3, 2, 1); //Monster4
		CreateRoom(4, 2, 1); //바위또는 부술수있는물체들(모닥불,똥무더기 등)
		CreateRoom(4, 1, 1); //Empty room
		CreateRoom(4, 0, 3); //SecretRoom
		CreateRoom(5, 1, 4); //Boss Room 

		// 1>BaseMent
		// 2>Library
		// 3>Depth
		// 4>BossRoom
		CreateActor<Monster>();
		// CreateActor<Door>();
		 



		//내가만들어야할것들(?)
		//상호작용될 actor들을 고려해 누가 관리해야할지??
		 
		//총알>>MainPlayer(Isaac) >> 몬스터나 벽(또는 바위 등)에 collision이 만나면 상호작용, 몬스터의 총알도 동일
		//몬스터는 총알에닿으면 깜빡임+애니메이션상태를 변경해야함
		// 
		// Collision으로 상호작용을 만든다면
		// 몬스터<->플레이어의접촉 >>플레이어 (플레이어가 깜빡이면서 애니메이션이바뀌니까)
		// 몬스터<->총알  >>몬스터 (동일)
		// 벽<->총알  >> 총알( 벽에닿으면 사라져야하니까)
		// 열쇠<->플레이어  >>열쇠(닿으면 사라져야하니까)
		// 폭탄(드랍)도 동일
		// 폭탄과상호작용되는 액터들(바위) 모닥불 똥무더기 등등 >>각자관리

		//맵의 이동은level에서 관리

		//몬스터의수가0이되면 문이열린다>>결국 문쪽에서 관리해야함(열리는모션이있음)
		//create monster가되면 몬스터의Count가 늘어나고 특정조건이되면 열림>> ??

		//위 조건을 충족하면서 플레이어<->문 의 collision이 만나면 맵이이동해야한다
		//맵의 이동은level에서관리하니까 문은level을 상속받아체크하면되나? 무ㅠㅓㄴ소리야



		
	}	
	//>>Collision MAX value=1090,600 >>나중에바꿔야함
	if (false == GameEngineInput::IsKey("LoadMenu"))
	{
		GameEngineInput::CreateKey("LoadMenu", VK_ESCAPE);
	}
	
}


void IsaacLevel::Update(float _DeltaTime)
{
	MapMoveUpdate();
	
	if (true == Map_Move)
	{
		P_Time += _DeltaTime * MapMoveSpeed;
	}
	
	if (true == GameEngineInput::IsDown("LoadMenu"))
	{
		if (2 == SettingValue)
		{
			SettingMenu->On();
			SettingValue = SettingValue - 1;
		}
		else
		{
			SettingMenu->Off();
			SettingValue = SettingValue + 1;
		}
	}
	/*if (1 == SettingValue && true == GameEngineInput::IsDown("LoadMenuTitle"))
	{
		GameEngineCore::GetInst()->ChangeLevel("TitleLevel");
	}*/ //버그가 너무많아서 이건 나중에하자
}
void IsaacLevel::LevelChangeStart(GameEngineLevel* _PrevLevel)
{
	SettingMenuUpdate();
	SettingMenu->Off();
	SoundLoad();
}


void IsaacLevel::CreateRoom(int _X, int _Y, int _MapKey)
{
	Room* NewRoom = CreateActor<Room>();
	NewRoom->SetTileIndex(_X, _Y, _MapKey);
}

void IsaacLevel::CreateDoor()
{

}