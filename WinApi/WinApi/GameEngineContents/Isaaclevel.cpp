#include "Isaaclevel.h"
#include "IsaacEnum.h"

// 覗稽詮闘 授辞拭 魚虞辞 舛慶
#include <GameEngineBase/GameEngineDirectory.h>
#include <GameEnginePlatform/GameEngineInput.h>

#include <GameEnginePlatform/GameEngineWindow.h>

#include <GameEngineCore/GameEngineResources.h>
#include <GameEngineCore/GameEngineCore.h>
#include <GameEngineCore/GameEngineRender.h>

// 蟹櫛 旭精 去厭税 伯希級
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
#include "Target.h"



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

	
	// 衝斗 持失
	{
		CreateActor<Isaac>();
		CreateActor<MapCollision>(); 

		//TEST
	/*	Monstro* TestMonstro= CreateActor<Monstro>();
		TestMonstro->SetPos({ 300,300 });*/
		

		Room::RoomCreateStart();
							 //							 (Start) (obj) (item)
		CreateRoom(0, 0, 1); //Start                        け  け  け 
		CreateRoom(0, 1, 1); //Monster人 door               けけけ  けけけ(Boss)
		CreateRoom(1, 1, 1); //Monster2						    けけけ
		CreateRoom(2, 1, 1); //item竺誤
		CreateRoom(2, 0, 2); //神崎詮闘晦軒税 雌硲姥繕 竺誤
		CreateRoom(2, 2, 1); //Monster3
		CreateRoom(3, 2, 1); //Monster4
		CreateRoom(4, 2, 1); //郊是暁澗 採綬呪赤澗弘端級(乞韓災,極巷希奄 去)
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
	if (BaseMentPos.x > 1000.0) //鉢檎角嬢亜檎 蒸蕉獄鍵陥
	{
		BaseMent->Death();
	}
}
