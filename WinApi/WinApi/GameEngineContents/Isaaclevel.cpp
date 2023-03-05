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
	// 衝斗 持失
	{
		CreateActor<Isaac>();
		CreateActor<MapCollision>(); //<<戚橿汐脊艦雁
		
		Room::RoomCreateStart();
		//						 (Start) (obj) (item)
		CreateRoom(0, 0, 1); //Start                        け  け  け 
		CreateRoom(0, 1, 1); //Monster人 door               けけけ  けけ(Boss)
		CreateRoom(1, 1, 1); //Monster2						    けけけ
		CreateRoom(2, 1, 1); //item竺誤
		CreateRoom(2, 0, 2); //神崎詮闘晦軒税 雌硲姥繕 竺誤
		CreateRoom(2, 2, 1); //Monster3
		CreateRoom(3, 2, 1); //Monster4
		CreateRoom(4, 2, 1); //郊是暁澗 採綬呪赤澗弘端級(乞韓災,極巷希奄 去)
		CreateRoom(4, 1, 1); //Empty room
		CreateRoom(4, 0, 3); //SecretRoom
		CreateRoom(5, 1, 4); //Boss Room 

		CreateActor<HP>();
		CreateActor<BombNumber>();
		CreateActor<CoinNumber>();
		CreateActor<KeyNumber>();

		Room1Set();
		Room2Set();
		Room3Set();
		Room4Set();
		Room5Set();
		Room6Set();
		Room7Set();
	}
}


void IsaacLevel::Update(float _DeltaTime)
{
	LevelUpdateTime += _DeltaTime;
	MapMoveUpdate();
	if (true == BossLoadBool &&
		true == Isaac::MainPlayer->GetIsaacCollision()->Collision({ .TargetGroup = static_cast<int>(IsaacCollisionOrder::Room8), .TargetColType = CT_Rect, .ThisColType = CT_Rect }))
	{
		BossLoadBool = false;
		LevelUpdateTime = 0.0f;
		GameEngineCore::GetInst()->ChangeLevel("BossLoad");
		PLAYBGMPLAYER.Stop();	
	}
	if (LevelUpdateTime > 0.2f&& false==BossLoadBool&& true==BossSoundBool)
	{
		BossSoundBool = false;
		PLAYBGMBOSS = GameEngineResources::GetInst().SoundPlayToControl("basicbossfight.ogg");
		PLAYBGMBOSS.Volume(0.1f);
	}
	if (true == Map_Move)
	{
		P_Time += _DeltaTime * MapMoveSpeed;
	}
	
	/*if (true == GameEngineInput::IsDown("LoadMenu"))
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
	}*/ //戚依亀 馬蟹税 適掘什(衝斗)稽 幻級醸嬢醤梅澗汽 雇短梅陥 蟹空叶
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