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
	// ����� Ž��
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

		// 1>BaseMent
		// 2>Library
		// 3>Depth
		// 4>BossRoom
		CreateActor<Monster>();
		// CreateActor<Door>();
		 



		//�����������Ұ͵�(?)
		//��ȣ�ۿ�� actor���� ����� ���� �����ؾ�����??
		 
		//�Ѿ�>>MainPlayer(Isaac) >> ���ͳ� ��(�Ǵ� ���� ��)�� collision�� ������ ��ȣ�ۿ�, ������ �Ѿ˵� ����
		//���ʹ� �Ѿ˿������� ������+�ִϸ��̼ǻ��¸� �����ؾ���
		// 
		// Collision���� ��ȣ�ۿ��� ����ٸ�
		// ����<->�÷��̾������� >>�÷��̾� (�÷��̾ �����̸鼭 �ִϸ��̼��̹ٲ�ϱ�)
		// ����<->�Ѿ�  >>���� (����)
		// ��<->�Ѿ�  >> �Ѿ�( ���������� ��������ϴϱ�)
		// ����<->�÷��̾�  >>����(������ ��������ϴϱ�)
		// ��ź(���)�� ����
		// ��ź����ȣ�ۿ�Ǵ� ���͵�(����) ��ں� �˹����� ��� >>���ڰ���

		//���� �̵���level���� ����

		//�����Ǽ���0�̵Ǹ� ���̿�����>>�ᱹ ���ʿ��� �����ؾ���(�����¸��������)
		//create monster���Ǹ� ������Count�� �þ�� Ư�������̵Ǹ� ����>> ??

		//�� ������ �����ϸ鼭 �÷��̾�<->�� �� collision�� ������ �����̵��ؾ��Ѵ�
		//���� �̵���level���������ϴϱ� ����level�� ��ӹ޾�üũ�ϸ�ǳ�? ���Фä��Ҹ���



		
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