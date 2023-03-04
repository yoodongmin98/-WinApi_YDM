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
#include "MapCollision.h"


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
#include "ItemHeart.h"
#include "Glasses.h"
#include "BlackLotus.h"



IsaacLevel::IsaacLevel()
{
	
}

IsaacLevel::~IsaacLevel()
{
}
void IsaacLevel::Loading()
{
	ImageLoad();
	if (false == GameEngineInput::IsKey("LoadMenu"))
	{
		GameEngineInput::CreateKey("LoadMenu", VK_ESCAPE);
	}
	AllBack* Image = CreateActor<AllBack>();
	BackDrop = Image->CreateRender("BackDrop.BMP", IsaacOrder::R_Door);
	BackDrop->SetScale({ 600,150 });
	// 액터 생성
	{
		CreateActor<Isaac>();
		CreateActor<MapCollision>();

		Room::RoomCreateStart();
		                        //						 (Start) (obj) (item)
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

		CreateActor<HP>();
		CreateActor<BombNumber>();
		CreateActor<CoinNumber>();
		CreateActor<KeyNumber>();

		///////////////////테스트용 Actor///////////////////

		/////////아이템
		/*Altar* NewAltar=CreateActor<Altar>();
		NewAltar->SetPos({ 300,240 });
		Leo* NewLeo=CreateActor<Leo>();
		NewLeo->SetPos({ 300,210 });
		ItemHeart* NewItemHeart= CreateActor<ItemHeart>();
		NewItemHeart->SetPos({ 300,300});
		Glasses* NewGlasses= CreateActor<Glasses>();
		NewGlasses->SetPos({ 300,400 });
		BlackLotus* NewBlackLotus = CreateActor<BlackLotus>();
		NewBlackLotus->SetPos({ 300,500 });*/




		//몬스터
		//Monster_Fly* TestMonster=CreateActor<Monster_Fly>();
		//TestMonster->SetPos({ 200,200 });
		//Monster_Blob* TestMonster1 = CreateActor<Monster_Blob>();
		//TestMonster1->SetPos({ 200,300 });
		//Gaper* NewGaper= CreateActor<Gaper>();
		//NewGaper->SetPos({ 200,400 });
		//Boil* TestBoil = CreateActor<Boil>();
		//TestBoil->SetPos({ 300,400 });
		//Charger* NewCharger = CreateActor<Charger>();
		//NewCharger->SetPos({ 300,500 });
		//Pooter* NewPooter = CreateActor<Pooter>();
		//NewPooter->SetPos({ 300,400 });
		//MuliBoom* NewMuliBoom = CreateActor<MuliBoom>();
		//NewMuliBoom->SetPos({ 300,400 });
		//Host* TestHost = CreateActor<Host>();
		//TestHost->SetPos({ 300,100 });
		//Clot* TestClot = CreateActor<Clot>();
		//TestClot->SetPos({ 500,500 });
		//Clotty* TestClotty = CreateActor<Clotty>();
		//TestClotty->SetPos({ 500,300 });



		//액터
		/*CreateActor<Poop>();
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
		NewSpike->SetPos({ 420,550 });*/
		////////////////////////////////////////////////////
	}	

	//if (true == Room1Value &&
	//	true == Isaac::MainPlayer->GetIsaacCollision()->Collision
	//	({ .TargetGroup = static_cast<int>(RoomCollisionOrder::Room1), .TargetColType = CT_Rect, .ThisColType = CT_Rect }))
	//{
	//	Room1Value = false;
	//	//Isaac::MainPlayer->SetIsaacMapMovefalse();
	//	Isaac::MainPlayer->SetMonsterCount(1);
	//	Monster_Fly* Room1Host = GetLevel()->CreateActor<Monster_Fly>();
	//	Room1Host->SetPos({ 300,720 + 300 });

	
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