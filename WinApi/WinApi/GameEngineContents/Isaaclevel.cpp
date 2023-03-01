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
	// ���� ����
	{
		CreateActor<Isaac>();


		// �̰� ����� ������ Ȥ�� ���� ����� �ִٸ�
		// �װ� �� �����ϰ� ���Ӱ� �����Ҽ� �ִ�.
		Room::RoomCreateStart();

		//���� �ÿ�ȸ�� �Ѵٸ�?                            (Start) (obj) (item)
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

		//key
		// 1>BaseMent
		// 2>Library
		// 3>Depth
		// 4>BossRoom
		CreateActor<HP>();
		CreateActor<BombNumber>();
		CreateActor<CoinNumber>();
		CreateActor<KeyNumber>();

		///////////////////�׽�Ʈ�� Actor///////////////////
		CreateActor<Altar>();
		CreateActor<Leo>();

		//����
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



		//����
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
		
		
		//���� �̵���level���� ����(�̰Ŵ� ��)  >>Actor�� �����ؼ� ������Ʈ�ϴϱ� �۵������� �������� ��������?

		//���� ������� ���������� �ᱹ �ϳ��� �������� ����Ǳ⋚���� Actor���� �˾ƾ��Ұ��� ����.

		//�����Ǽ���0�̵Ǹ� ���̿�����>>�ᱹ �� �Ǵ� Room�ʿ��� �����ؾ���(�����¸��������)
		//create monster���Ǹ� ������Count�� �þ�� Ư�������̵Ǹ� ���� >> Room���� Actor��(��,���� ���)�� ����� �׿����� ������ ��������

		//�� ������ �����ϸ鼭 �÷��̾�<->�� �� collision�� ������ �����̵��ؾ��Ѵ�
		



		
	}	
	//>>Collision MAX value=1090,600 >>���߿��ٲ����
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
	}*/ //���װ� �ʹ����Ƽ� �̰� ���߿�����

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