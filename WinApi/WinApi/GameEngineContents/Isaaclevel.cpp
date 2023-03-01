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
#include "AllBack.h"

//UI
#include "HP.h"
#include "BombNumber.h"
#include "CoinNumber.h"
#include "KeyNumber.h"


/////Monster
#include "Monster_Fly.h"
#include "Monster_Blob.h"
#include "Monster_Gaper.h"
#include "Monster_Boil.h"
#include "Charger.h"
#include "Pooter.h"
#include "Muliboom.h"
#include "Host.h"
#include "Clot.h"
#include "Clotty.h"



////Map Actor
#include "Poop.h"
#include "Heart.h"
#include "FireWood.h"
#include "Fire.h"
#include "Key.h"
#include "ItemBomb.h"
#include "Coin.h"
#include "Rock.h"
#include "Rock_Boom.h"
#include "Spike.h"

////Item
#include "Altar.h"
#include "Leo.h"


IsaacLevel::IsaacLevel()
{
	
}

IsaacLevel::~IsaacLevel()
{
}
void IsaacLevel::Loading()
{
	ImageLoad();
	AllBack* Image = CreateActor<AllBack>();
	BackDrop = Image->CreateRender("BackDrop.BMP", IsaacOrder::R_Door);
	BackDrop->SetScale({ 600,150 });
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

		//key
		// 1>BaseMent
		// 2>Library
		// 3>Depth
		// 4>BossRoom
		CreateActor<HP>();
		CreateActor<BombNumber>();
		CreateActor<CoinNumber>();
		CreateActor<KeyNumber>();

		///////////////////테스트용 Actor///////////////////
		CreateActor<Altar>();
		CreateActor<Leo>();

		//몬스터
	/*	Monster_Fly* TestMonster=CreateActor<Monster_Fly>();
		TestMonster->SetPos({ 200,200 });
		Monster_Blob* TestMonster1 = CreateActor<Monster_Blob>();
		TestMonster1->SetPos({ 200,300 });
		Gaper* NewGaper= CreateActor<Gaper>();
		NewGaper->SetPos({ 200,400 });
		Boil* TestBoil = CreateActor<Boil>();
		TestBoil->SetPos({ 300,400 });
		Charger* NewCharger = CreateActor<Charger>();
		NewCharger->SetPos({ 300,500 });
		Pooter* NewPooter = CreateActor<Pooter>();
		NewPooter->SetPos({ 300,400 });
		MuliBoom* NewMuliBoom = CreateActor<MuliBoom>();
		NewMuliBoom->SetPos({ 300,400 });
		Host* TestHost = CreateActor<Host>();
		TestHost->SetPos({ 300,100 });
		Clot* TestClot = CreateActor<Clot>();
		TestClot->SetPos({ 500,500 });
		Clotty* TestClotty = CreateActor<Clotty>();
		TestClotty->SetPos({ 500,300 });*/



		//액터
		CreateActor<Poop>();
		Heart* TestHeart=CreateActor<Heart>();
		TestHeart->SetPos({ 180,230 });
		FireWood* NewWood= CreateActor<FireWood>();
		NewWood->SetPos({180,300});
		Fire* NewFire = CreateActor<Fire>();
		NewFire->SetPos({ 180,270 });
		Key* NewKey = CreateActor<Key>();
		NewKey->SetPos({ 180,360 });
		ItemBomb* NewItemBomb = CreateActor<ItemBomb>();
		NewItemBomb->SetPos({ 180,430 });
		Coin* NewCoin = CreateActor<Coin>();
		NewCoin->SetPos({ 180,490 });
		Rock* NewRock = CreateActor<Rock>();
		NewRock->SetPos({ 180,550 });
		Rock_Boom* NewRock_B = CreateActor<Rock_Boom>();
		NewRock_B->SetPos({ 350,550 });
		Spike* NewSpike = CreateActor<Spike>();
		NewSpike->SetPos({ 420,550 });
		////////////////////////////////////////////////////
		
		
		//맵의 이동은level에서 관리(이거는 됨)  >>Actor가 관리해서 업데이트하니까 작동안했음 왜인지는 아직몰루?

		//현재 만들어진 스테이지는 결국 하나의 레벨에서 진행되기떄문에 Actor별로 알아야할것이 많음.

		//몬스터의수가0이되면 문이열린다>>결국 문 또는 Room쪽에서 관리해야함(열리는모션이있음)
		//create monster가되면 몬스터의Count가 늘어나고 특정조건이되면 열림 >> Room에서 Actor들(벽,몬스터 등등)을 만들고 그에따른 조건을 만들어야함

		//위 조건을 충족하면서 플레이어<->문 의 collision이 만나면 맵이이동해야한다
		



		
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