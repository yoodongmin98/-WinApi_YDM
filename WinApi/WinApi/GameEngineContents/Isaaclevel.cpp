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
#include "MonstroHpBar.h"


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
#include "Monstro.h"
#include "MomsHeart.h"



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
#include "CoinBomb.h"
#include "CoinHeart.h"
#include "CoinKey.h"
#include "ShopKeeper.h"

////Item
#include "Altar.h"
#include "Leo.h"
#include "ItemHeart.h"
#include "Glasses.h"
#include "BlackLotus.h"


#include "NextLevelDoor.h"




IsaacLevel::IsaacLevel()
{
	
}

IsaacLevel::~IsaacLevel()
{
}
void IsaacLevel::Loading()
{
	ImageLoad();
	SoundLoad();
	if (false == GameEngineInput::IsKey("LoadMenu"))
	{
		GameEngineInput::CreateKey("LoadMenu", VK_ESCAPE);
	}
	AllBack* Image = CreateActor<AllBack>();
	BackDrop = Image->CreateRender("BackDrop.BMP", IsaacOrder::R_Door);
	BackDrop->SetScale({ 600,150 });

	BaseMent = Image->CreateRender("Basement1.BMP", IsaacOrder::R_Door);
	BaseMent->SetScale({ 600,100 });
	BaseMent->SetPosition({ -800,-250 });

	
	// 액터 생성
	{
		CreateActor<Isaac>();
		CreateActor<MapCollision>(); 

		//TEST
	/*	Monstro* TestMonstro= CreateActor<Monstro>();
		TestMonstro->SetPos({ 300,300 });*/
		

		Room::RoomCreateStart();
							 //							 (Start) (obj) (item)
		CreateRoom(0, 0, 1); //Start                        ㅁ  ㅁ  ㅁ 
		CreateRoom(0, 1, 1); //Monster와 door               ㅁㅁㅁ  ㅁㅁㅁ(Boss)
		CreateRoom(1, 1, 1); //Monster2						    ㅁㅁㅁ
		CreateRoom(2, 1, 1); //item설명
		CreateRoom(2, 0, 2); //오브젝트끼리의 상호구조 설명
		CreateRoom(2, 2, 1); //Monster3
		CreateRoom(3, 2, 1); //Monster4
		CreateRoom(4, 2, 1); //바위또는 부술수있는물체들(모닥불,똥무더기 등)
		CreateRoom(4, 1, 1); //Empty room
		CreateRoom(4, 0, 3); //SecretRoom
		CreateRoom(5, 1, 4); //Boss Room 
		CreateRoom(6, 1, 5); //Boss2 Room 

		CreateActor<HP>();
		CreateActor<BombNumber>();
		CreateActor<CoinNumber>();
		CreateActor<KeyNumber>();

		DoorAnimationSetandUpdate();

		Room1Set();
		Room2Set();
		Room3Set();
		Room4Set();
		Room5Set();
		Room6Set();
		Room7Set();
		Room9Set();
	}
}

void IsaacLevel::Update(float _DeltaTime)
{
	BaseMentUpdate(_DeltaTime);
	MapMoveUpdate();
	DoorRenderUpdate();
	
	ALLCollisionSoundSet(_DeltaTime);
	
	if (true == Map_Move)
	{
		P_Time += _DeltaTime * MapMoveSpeed;
	}
}


void IsaacLevel::LevelChangeStart(GameEngineLevel* _PrevLevel)
{
	SettingMenuUpdate();
	SettingMenu->Off();
	
}


void IsaacLevel::BaseMentUpdate(float _DeltaTime)
{
	float4 BaseMentPos = BaseMent->GetPosition();
	BaseMentPos += float4::Right * 10.0f * LevelUpdateTime;

	if (BaseMentPos.x >= 0.0f)
	{
		BaseMentPos = BaseMent->GetPosition();
	}
	if (LevelUpdateTime > 3.0f)
	{
		BaseMentPos += float4::Right * 3.0f * LevelUpdateTime;
	}
	BaseMent->SetPosition(BaseMentPos);
	if (BaseMentPos.x > 1000.0) //화면넘어가면 없애버린다
	{
		BaseMent->Death();
	}
}
