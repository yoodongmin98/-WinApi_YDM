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
	// 衝斗 持失
	{
		CreateActor<Isaac>();


		// 戚杏 背操醤 奄糎拭 箸獣 号聖 幻窮惟 赤陥檎
		// 益杏 陥 舛軒馬壱 歯罫惟 獣拙拝呪 赤陥.
		Room::RoomCreateStart();

		//幻鉦 獣尻噺研 廃陥檎?                            (Start) (obj) (item)
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

		//key
		// 1>BaseMent
		// 2>Library
		// 3>Depth
		// 4>BossRoom
		CreateActor<HP>();
		CreateActor<BombNumber>();
		CreateActor<CoinNumber>();
		CreateActor<KeyNumber>();

		///////////////////砺什闘遂 Actor///////////////////


		//佼什斗
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



		//衝斗
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
		
		
		//己税 戚疑精level拭辞 淫軒(戚暗澗 喫)  >>Actor亜 淫軒背辞 穣汽戚闘馬艦猿 拙疑照梅製 訊昔走澗 焼送侯欠?

		//薄仙 幻級嬢遭 什砺戚走澗 衣厩 馬蟹税 傾婚拭辞 遭楳鞠奄��庚拭 Actor紺稽 硝焼醤拝依戚 弦製.

		//佼什斗税呪亜0戚鞠檎 庚戚伸鍵陥>>衣厩 庚 暁澗 Room楕拭辞 淫軒背醤敗(伸軒澗乞芝戚赤製)
		//create monster亜鞠檎 佼什斗税Count亜 潅嬢蟹壱 働舛繕闇戚鞠檎 伸顕 >> Room拭辞 Actor級(混,佼什斗 去去)聖 幻級壱 益拭魚献 繕闇聖 幻級嬢醤敗

		//是 繕闇聖 中膳馬檎辞 巴傾戚嬢<->庚 税 collision戚 幻蟹檎 己戚戚疑背醤廃陥
		



		
	}	
	//>>Collision MAX value=1090,600 >>蟹掻拭郊蚊醤敗
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
	}*/ //獄益亜 格巷弦焼辞 戚闇 蟹掻拭馬切

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