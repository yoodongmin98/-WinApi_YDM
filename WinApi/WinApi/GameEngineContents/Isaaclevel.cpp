#include "Isaaclevel.h"
#include "IsaacEnum.h"

// ������Ʈ ������ ���� ����
#include <GameEngineBase/GameEngineDirectory.h>
#include <GameEnginePlatform/GameEngineInput.h>

#include <GameEnginePlatform/GameEngineWindow.h>

#include <GameEngineCore/GameEngineResources.h>
#include <GameEngineCore/GameEngineCore.h>
#include <GameEngineCore/GameEngineRender.h>

// ���� ���� ����� �����
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
	// ���� ����
	{
		CreateActor<Isaac>();
		CreateActor<MapCollision>();
		
		Room::RoomCreateStart();
		//						 (Start) (obj) (item)
		CreateRoom(0, 0, 1); //Start                        ��  ��  �� 
		CreateRoom(0, 1, 1); //Monster�� door               ������  ����(Boss)
		CreateRoom(1, 1, 1); //Monster2						    ������
		CreateRoom(2, 1, 1); //item����
		CreateRoom(2, 0, 2); //������Ʈ������ ��ȣ���� ����
		CreateRoom(2, 2, 1); //Monster3
		CreateRoom(3, 2, 1); //Monster4
		CreateRoom(4, 2, 1); //�����Ǵ� �μ����ִ¹�ü��(��ں�,�˹����� ��)
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
	
	MapMoveUpdate();
	
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
	}*/ //�̰͵� �ϳ��� Ŭ����(����)�� ���������ߴµ� ��û�ߴ� ������
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