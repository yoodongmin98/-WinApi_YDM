#include "Room.h"
#include"IsaacEnum.h"
#include<GameEnginePlatform/GameEngineWindow.h>
#include<GameEnginePlatform/GameEngineInput.h>
#include<GameEngineCore/GameEngineRender.h>
#include "Isaaclevel.h"
#include <GameEngineCore/GameEngineRender.h>
#include <GameEngineCore/GameEngineCollision.h>

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
		GameEngineRender* Render = CreateRender("Room.BMP", IsaacOrder::R_BackGround);
		Render->SetPosition(Render->GetImage()->GetImageScale().half());
		Render->SetScaleToImage();
	}
}

void Room::RoomCreateStart()
{
	AllRoom.clear();
}

void Room::Update() 
{
	// 여기서 방이 계속 플레이어를 충돌체크 하고 있어야 한다.
	// 문에 닿았나? 문에 닿았나? 문에 닿았나?
	
	if (true)
	{

	}
}

void Room::SetTileIndex(int _X, int _Y)
{
	Index.X = _X;
	Index.Y = _Y;

	float4 RoomPos = GameEngineWindow::GetScreenSize();
	RoomPos.x *= _X;
	RoomPos.y *= _Y;

	SetPos(RoomPos);

	if (AllRoom.end() != AllRoom.find(Index.TileKey))
	{
		MsgAssert("같은 위치에 방을 또 만들었습니다.");
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

		ROOMDIR EnumDir = static_cast<ROOMDIR>(i);

		GameEngineRender* ThisDoorRender = ThisRoom->CreateRender();
		GameEngineRender* LinkDoorRender = LinkRoom->CreateRender();


		GameEngineCollision* ThisDoorCollision = ThisRoom->CreateCollision();
		GameEngineCollision* LinkDoorCollision = LinkRoom->CreateCollision();


		switch (EnumDir)
		{
		case ROOMDIR::LEFT:
		{
			//DoorRender->SetImage();
			//DoorRender->SetPosition();
			//LinkDoorRender->SetImage();
			//LinkDoorRender->SetPosition();
			// DoorRenderer[static_cast<int>(ROOMDIR::RIGHT)] = ThisDoorRender;
			// LinkRoom->DoorRenderer.push_back(ThisDoorRender);
			int a = 0;
			break;
		}
		case ROOMDIR::RIGHT:
		{
			//DoorRender->SetImage();
			//DoorRender->SetPosition();
			//LinkDoorRender->SetImage();
			//LinkDoorRender->SetPosition();
			//DoorCollision.push_back(ThisDoorCollision);
			//LinkRoom->DoorCollision.push_back(LinkDoorCollision);

			int a = 0;
			break;
		}
		case ROOMDIR::Up:
		{
			//DoorRender->SetImage();
			//DoorRender->SetPosition();
			//LinkDoorRender->SetImage();
			//LinkDoorRender->SetPosition();
			int a = 0;
			break;
		}
		case ROOMDIR::DOWN:
		{
			//DoorRender->SetImage();
			//DoorRender->SetPosition();
			//LinkDoorRender->SetImage();
			//LinkDoorRender->SetPosition();
			int a = 0;
			break;
		}
		case ROOMDIR::MAX:
		{
			MsgAssert("망했어요");
			break;
		}
		default:
			break;
		}
	}
}