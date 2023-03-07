#include "Room.h"
#include"IsaacEnum.h"
#include <string_view>
#include "Isaaclevel.h"
#include "Isaac.h"

#include<GameEnginePlatform/GameEngineWindow.h>
#include<GameEnginePlatform/GameEngineInput.h>

#include<GameEngineCore/GameEngineRender.h>
#include <GameEngineCore/GameEngineRender.h>
#include <GameEngineCore/GameEngineCollision.h>


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

	
}

void Room::RoomCreateStart()
{
	AllRoom.clear();
}

void IsaacLevel::CreateRoom(int _X, int _Y, int _MapKey)
{
	Room* NewRoom = CreateActor<Room>();
	NewRoom->SetTileIndex(_X, _Y, _MapKey);

}

///////////////////////////////////////////////////

void Room::Update(float _DeltaTime)
{
	
}


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
			GameEngineRender* Render = CreateRender("Room_Library.BMP", IsaacOrder::R_BackGround);
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
		case 5:
		{
			//이미지세팅
			GameEngineRender* Render = CreateRender("Room_MomBoss.BMP", IsaacOrder::R_BackGround);
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

		///////////////// 액터 배치부분
		
	
		ROOMDIR EnumDir = static_cast<ROOMDIR>(i);
		//This room
		 ThisDoorUpRender			 = ThisRoom->CreateRender("Map_Door_Up.BMP", IsaacOrder::R_Door);
		 ThisDoorLeftRender		 = ThisRoom->CreateRender("Map_Door_Left.BMP", IsaacOrder::R_Door);
		 ThisDoorRightRender		 = ThisRoom->CreateRender("Map_Door_Right.BMP", IsaacOrder::R_Door);
		 ThisDoorDownRender		= ThisRoom->CreateRender("Map_Door_Down.BMP", IsaacOrder::R_Door);

		 ThisBossDoorLeftRender	 = ThisRoom->CreateRender("Map_BossDoor_Left.BMP", IsaacOrder::R_Door);
		 ThisBossDoorRightRender	 = ThisRoom->CreateRender("Map_BossDoor_Right.BMP", IsaacOrder::R_Door);
		
		 LinkDoorUpRender			= LinkRoom->CreateRender("Map_Door_Up.BMP", IsaacOrder::R_Door);
		 LinkDoorLeftRender		 = LinkRoom->CreateRender("Map_Door_Left.BMP", IsaacOrder::R_Door);
		 LinkDoorRightRender		= LinkRoom->CreateRender("Map_Door_Right.BMP", IsaacOrder::R_Door);
		 LinkDoorDownRender		= LinkRoom->CreateRender("Map_Door_Down.BMP", IsaacOrder::R_Door);

		 LinkBossDoorRightRender	 = LinkRoom->CreateRender("Map_BossDoor_Right.BMP", IsaacOrder::R_Door);
		 LinkBossDoorLeftRender	= LinkRoom->CreateRender("Map_BossDoor_Left.BMP", IsaacOrder::R_Door);
		// /////Collision
		LinkDoorCollision = LinkRoom->CreateCollision(IsaacCollisionOrder::C_Door);
		ThisDoorCollision = ThisRoom->CreateCollision(IsaacCollisionOrder::C_Door);
		LinkDoorCollision->SetDebugRenderType(CollisionType::CT_Rect);
		ThisDoorCollision->SetDebugRenderType(CollisionType::CT_Rect);
	

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

				ThisDoorCollision->SetPosition({ 130,380 });
				ThisDoorCollision->SetScale({ 15,15 });

				LinkDoorCollision->SetPosition({ 1150,380 });
				LinkDoorCollision->SetScale({ 15,15 });
			}
			else
			{
				{
					{
						ThisDoorCollision->SetPosition({ 130,380 });
						ThisDoorCollision->SetScale({ 15,15});

						LinkDoorCollision->SetPosition({ 1150,380 });
						LinkDoorCollision->SetScale({ 15,15});
					}
				}
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
			ThisDoorUpRender->ChangeAnimation("Door_U_Idle");
			

			LinkDoorDownRender->SetPosition({ 640,600 });
			LinkDoorDownRender->SetScale({ 350,270 });
			LinkDoorDownRender->CreateAnimation({ .AnimationName = "Door_D_Idle",  .ImageName = "Map_Door_Down.BMP", .Start = 0, .End = 0, .InterTime = 0.1f });
			LinkDoorDownRender->ChangeAnimation("Door_D_Idle");

			{
				ThisDoorCollision->SetPosition({ 640,120 });
				ThisDoorCollision->SetScale({ 15,15 });

				LinkDoorCollision->SetPosition({ 640,600 });
				LinkDoorCollision->SetScale({ 15,15});
			}
			break;
		}
		case ROOMDIR::DOWN:
		{
			
			ThisDoorDownRender->SetPosition({ 640,600 });
			ThisDoorDownRender->SetScale({ 350,270 });
			ThisDoorDownRender->CreateAnimation({ .AnimationName = "Door_D_Idle",  .ImageName = "Map_Door_Down.BMP", .Start = 0, .End = 0, .InterTime = 0.1f });
			ThisDoorDownRender->ChangeAnimation("Door_D_Idle");

			LinkDoorUpRender->SetPosition({ 640,120 });
			LinkDoorUpRender->SetScale({ 350,270 });
			LinkDoorUpRender->CreateAnimation({ .AnimationName = "Door_U_Idle",  .ImageName = "Map_Door_Up.BMP", .Start = 0, .End = 0, .InterTime = 0.1f });
			LinkDoorUpRender->ChangeAnimation("Door_U_Idle");
			{
				{
					LinkDoorCollision->SetPosition({ 640,120 });
					LinkDoorCollision->SetScale({ 15,15 });

					ThisDoorCollision->SetPosition({ 640,600 });
					ThisDoorCollision->SetScale({ 15,15 });
				}
			}
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
	//LinkDoorCollision->DebugRender();
	//ThisDoorCollision->DebugRender();
	
}


