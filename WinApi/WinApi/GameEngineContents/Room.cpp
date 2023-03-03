#include "Room.h"
#include"IsaacEnum.h"
#include<GameEnginePlatform/GameEngineWindow.h>
#include<GameEnginePlatform/GameEngineInput.h>
#include<GameEngineCore/GameEngineRender.h>
#include "Isaaclevel.h"
#include <GameEngineCore/GameEngineRender.h>
#include <GameEngineCore/GameEngineCollision.h>
#include <string_view>


//monster
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


//        0-1
// -1, 0  0 0  1, 0
//        0 1

const TileIndex Room::DirRoomIndex[4] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

std::map<__int64, Room*> Room::AllRoom;

Room::Room()
{

}
Room::~Room()
{

}

void Room::Start()
{
	{
		GameEngineRender* Render = CreateRender("Play_BlackGround.BMP", IsaacOrder::R_BackGround_Black);
		Render->SetPosition(Render->GetImage()->GetImageScale().half());
		Render->SetScaleToImage();
	}
	{
		GameEngineRender* Renderc = CreateRender("BackGround_CS.BMP", IsaacOrder::R_BackGround_Black);
		Renderc->SetPosition(Renderc->GetImage()->GetImageScale().half());
		Renderc->SetScaleToImage();
	}
}

void Room::RoomCreateStart()
{
	AllRoom.clear();
}

//void Room::Update() 
//{
//	// 食奄辞 号戚 域紗 巴傾戚嬢研 中宜端滴 馬壱 赤嬢醤 廃陥.
//	// 庚拭 願紹蟹? 庚拭 願紹蟹? 庚拭 願紹蟹?
//	
//	if (true)
//	{
//
//	}
//}

void Room::SetTileIndex(int _X, int _Y, int _MapKey)
{
	switch (_MapKey)
	{
		case 1:
		{
			
			GameEngineRender* Render = CreateRender("Room.BMP", IsaacOrder::R_BackGround);
			Render->SetPosition(Render->GetImage()->GetImageScale().half());
			Render->SetScaleToImage();
			break;
		}
		case 2:
		{
			GameEngineRender* Render = CreateRender("Room.BMP", IsaacOrder::R_BackGround);
			Render->SetPosition(Render->GetImage()->GetImageScale().half());
			Render->SetScaleToImage();
			break;
		}
		case 3:
		{
			GameEngineRender* Render = CreateRender("Room_Depth.BMP", IsaacOrder::R_BackGround);
			Render->SetPosition(Render->GetImage()->GetImageScale().half());
			Render->SetScaleToImage();
			break;
		}
		case 4:
		{
			GameEngineRender* Render = CreateRender("Room_Boss.BMP", IsaacOrder::R_BackGround);
			Render->SetPosition(Render->GetImage()->GetImageScale().half());
			Render->SetScaleToImage();
			break;
		}
		default:
			break;
	}
		
	
	

	Index.X = _X;
	Index.Y = _Y;

	float4 RoomPos = GameEngineWindow::GetScreenSize();
	RoomPos.x *= _X;
	RoomPos.y *= _Y;

	SetPos(RoomPos);

	if (AllRoom.end() != AllRoom.find(Index.TileKey))
	{
		MsgAssert("旭精 是帖拭 号聖 暁 幻級醸柔艦陥.");
		return;
	}

	AllRoom.insert(std::make_pair(Index.TileKey, this));

	for (size_t i = 0; i < static_cast<size_t>(ROOMDIR::MAX); i++)
	{
		TileIndex Dir = DirRoomIndex[i];
		Dir.X += Index.X;
		Dir.Y += Index.Y;

		std::map<__int64, Room*>::iterator FindIter = AllRoom.find(Dir.TileKey);

		if (FindIter == AllRoom.end())
		{
			continue;
		}
		Room* ThisRoom = this;
		Room* LinkRoom = FindIter->second;

		///////////////// 衝斗 壕帖採歳
		


		//0,0								    //Start                        け  け  け 
		if (_X == 0 && _Y == 1) 
		{
			float4 RoomPos = ThisRoom->GetPos();
			Monster_Fly* NewFly = ThisRoom->GetLevel()->CreateActor<Monster_Fly>();
			NewFly->SetPos({ RoomPos .x+300,RoomPos.y+600});
			RoomSet1(); 
		} //Monster人 door               けけけ  けけ(Boss)
		if (_X == 1 && _Y == 1) { RoomSet2(); } //Monster2						    けけけ
		if (_X == 2 && _Y == 1) { RoomSet3(); } //item竺誤
		if (_X == 2 && _Y == 0) { RoomSet4(); } //神崎詮闘晦軒税 雌硲姥繕 竺誤
		if (_X == 2 && _Y == 2) { RoomSet5(); } //Monster3
		if (_X == 3 && _Y == 2) { RoomSet6(); } //Monster4
		if (_X == 4 && _Y == 2) { RoomSet7(); } //郊是暁澗 採綬呪赤澗弘端級(乞韓災,極巷希奄 去)
		if (_X == 4 && _Y == 1) { RoomSet8(); } //Empty room
		if (_X == 4 && _Y == 0) { RoomSet9(); } //SecretRoom
		if (_X == 5 && _Y == 1) { RoomSet10(); } //Boss Room 
											
		ROOMDIR EnumDir = static_cast<ROOMDIR>(i);
		//This room
		GameEngineRender* ThisDoorUpRender = ThisRoom->CreateRender("Map_Door_Up.BMP", IsaacOrder::R_Door);
		GameEngineRender* ThisDoorLeftRender = ThisRoom->CreateRender("Map_Door_Left.BMP", IsaacOrder::R_Door);
		GameEngineRender* ThisDoorRightRender = ThisRoom->CreateRender("Map_Door_Right.BMP", IsaacOrder::R_Door);
		GameEngineRender* ThisDoorDownRender = ThisRoom->CreateRender("Map_Door_Down.BMP", IsaacOrder::R_Door);

		GameEngineRender* ThisBossDoorLeftRender = ThisRoom->CreateRender("Map_BossDoor_Left.BMP", IsaacOrder::R_Door);
		GameEngineRender* ThisBossDoorRightRender = ThisRoom->CreateRender("Map_BossDoor_Right.BMP", IsaacOrder::R_Door);
		//LinkRoom
		GameEngineRender* LinkDoorUpRender = LinkRoom->CreateRender("Map_Door_Up.BMP", IsaacOrder::R_Door);
		GameEngineRender* LinkDoorLeftRender = LinkRoom->CreateRender("Map_Door_Left.BMP", IsaacOrder::R_Door);
		GameEngineRender* LinkDoorRightRender = LinkRoom->CreateRender("Map_Door_Right.BMP", IsaacOrder::R_Door);
		GameEngineRender* LinkDoorDownRender = LinkRoom->CreateRender("Map_Door_Down.BMP", IsaacOrder::R_Door);

		GameEngineRender* LinkBossDoorRightRender = LinkRoom->CreateRender("Map_BossDoor_Right.BMP", IsaacOrder::R_Door);
		GameEngineRender* LinkBossDoorLeftRender = LinkRoom->CreateRender("Map_BossDoor_Left.BMP", IsaacOrder::R_Door);
		// ////////////////////////////
		

		switch (EnumDir)
		{
		case ROOMDIR::LEFT:
		{
			if (4 == _MapKey)
			{
				ThisBossDoorLeftRender->SetPosition({ 100,380});
				ThisBossDoorLeftRender->SetScale({ 200,150 });

				LinkBossDoorRightRender->SetPosition({ 1180,380 });
				LinkBossDoorRightRender->SetScale({ 200,150 });
			}
			else
			{
				ThisDoorLeftRender->SetPosition({ 100,440 });
				ThisDoorLeftRender->SetScale({ 350,270 });
				ThisDoorLeftRender->CreateAnimation({ .AnimationName = "Door_L_Idle",  .ImageName = "Map_Door_Left.BMP", .Start = 0, .End = 0, .InterTime = 0.1f });
				ThisDoorLeftRender->CreateAnimation({ .AnimationName = "Door_L_Open",  .ImageName = "Map_Door_Left.BMP", .Start = 0, .End = 3, .InterTime = 0.1f, .Loop = false });
				ThisDoorLeftRender->ChangeAnimation("Door_L_Idle");
			
				LinkDoorRightRender->SetPosition({ 1180,440 });
				LinkDoorRightRender->SetScale({ 350,270 });
				LinkDoorRightRender->CreateAnimation({ .AnimationName = "Door_R_Idle",  .ImageName = "Map_Door_Right.BMP", .Start = 0, .End = 0, .InterTime = 0.1f });
				LinkDoorRightRender->CreateAnimation({ .AnimationName = "Door_R_Open",  .ImageName = "Map_Door_Right.BMP", .Start = 0, .End = 3, .InterTime = 0.1f, .Loop = false });
				LinkDoorRightRender->ChangeAnimation("Door_R_Idle");
			}
			
			break;
		}
		case ROOMDIR::RIGHT:
		{

			break;
		}
		case ROOMDIR::Up:
		{
			ThisDoorUpRender->SetPosition({ 640,120 });
			ThisDoorUpRender->SetScale({ 350,270 });
			ThisDoorUpRender->CreateAnimation({ .AnimationName = "Door_U_Idle",  .ImageName = "Map_Door_Up.BMP", .Start = 0, .End = 0, .InterTime = 0.1f });
			ThisDoorUpRender->CreateAnimation({ .AnimationName = "Door_U_Open",  .ImageName = "Map_Door_Up.BMP", .Start = 0, .End = 3, .InterTime = 0.1f, .Loop = false });
			ThisDoorUpRender->ChangeAnimation("Door_U_Idle");

			LinkDoorDownRender->SetPosition({ 640,600 });
			LinkDoorDownRender->SetScale({ 350,270 });
			LinkDoorDownRender->CreateAnimation({ .AnimationName = "Door_D_Idle",  .ImageName = "Map_Door_Down.BMP", .Start = 0, .End = 0, .InterTime = 0.1f });
			LinkDoorDownRender->CreateAnimation({ .AnimationName = "Door_D_Open",  .ImageName = "Map_Door_Down.BMP", .Start = 0, .End = 3, .InterTime = 0.1f, .Loop = false });
			LinkDoorDownRender->ChangeAnimation("Door_D_Idle");
			break;
		}
		case ROOMDIR::DOWN:
		{
			ThisDoorDownRender->SetPosition({ 640,600 });
			ThisDoorDownRender->SetScale({ 350,270 });
			ThisDoorDownRender->CreateAnimation({ .AnimationName = "Door_D_Idle",  .ImageName = "Map_Door_Down.BMP", .Start = 0, .End = 0, .InterTime = 0.1f });
			ThisDoorDownRender->CreateAnimation({ .AnimationName = "Door_D_Open",  .ImageName = "Map_Door_Down.BMP", .Start = 0, .End = 3, .InterTime = 0.1f, .Loop = false });
			ThisDoorDownRender->ChangeAnimation("Door_D_Idle");

			LinkDoorUpRender->SetPosition({ 640,120 });
			LinkDoorUpRender->SetScale({ 350,270 });
			LinkDoorUpRender->CreateAnimation({ .AnimationName = "Door_U_Idle",  .ImageName = "Map_Door_Up.BMP", .Start = 0, .End = 0, .InterTime = 0.1f });
			LinkDoorUpRender->CreateAnimation({ .AnimationName = "Door_U_Open",  .ImageName = "Map_Door_Up.BMP", .Start = 0, .End = 3, .InterTime = 0.1f, .Loop = false });
			LinkDoorUpRender->ChangeAnimation("Door_U_Idle");
			break;
		}
		case ROOMDIR::MAX:
		{
			MsgAssert("焼焼.. 焼戚拙精 穐柔艦陥");
			break;
		}
		default:
			break;
		}
	}
}

void Room::Render(float _DeltaTime)
{
	
}




void Room::RoomSet1()
{
	
}
void Room::RoomSet2()
{

}
void Room::RoomSet3()
{

}
void Room::RoomSet4()
{

}
void Room::RoomSet5()
{

}
void Room::RoomSet6()
{

}
void Room::RoomSet7()
{

}
void Room::RoomSet8()
{

}
void Room::RoomSet9()
{

}
void Room::RoomSet10()
{

}