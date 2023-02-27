#include "Room.h"
#include"IsaacEnum.h"
#include<GameEnginePlatform/GameEngineWindow.h>
#include<GameEnginePlatform/GameEngineInput.h>
#include<GameEngineCore/GameEngineRender.h>
#include "Isaaclevel.h"
#include <GameEngineCore/GameEngineRender.h>
#include <GameEngineCore/GameEngineCollision.h>
#include <string_view>

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
}

void Room::RoomCreateStart()
{
	AllRoom.clear();
}

//void Room::Update() 
//{
//	// 여기서 방이 계속 플레이어를 충돌체크 하고 있어야 한다.
//	// 문에 닿았나? 문에 닿았나? 문에 닿았나?
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
		ThisDoorCollision = ThisRoom->CreateCollision(IsaacCollisionOrder::C_Door);
		LinkDoorCollision = LinkRoom->CreateCollision(IsaacCollisionOrder::C_Door);
		

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
			
				////////////
				ThisDoorCollision->SetPosition({ 100,440 });
				ThisDoorCollision->SetScale({ 350,270 });
				//////////////////
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
			MsgAssert("아아.. 아이작은 갔습니다");
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