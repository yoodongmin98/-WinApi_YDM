#include "MapCollision.h"
#include "IsaacEnum.h"

#include <GameEngineCore/GameEngineCollision.h>
#include <GameEngineCore/GameEngineLevel.h>
#include "Isaac.h"


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

MapCollision::MapCollision()
{

}
MapCollision::~MapCollision()
{

}

void MapCollision::Start()
{
	{
		Room1Collision = CreateCollision(RoomCollisionOrder::Room1);
		Room1Collision->SetScale({ 200, 20 });
		Room1Collision->SetPosition({ 640,720 + 200 });
		Room1Collision->SetDebugRenderType(CollisionType::CT_Rect);
		
	}
	{
		Room2Collision = CreateCollision(RoomCollisionOrder::Room2);
		Room2Collision->SetScale({ 20, 200 });
		Room2Collision->SetPosition({ 1280 + 150,720 + 340 });
		Room2Collision->SetDebugRenderType(CollisionType::CT_Rect);
		
	}
	{
		Room3Collision = CreateCollision(RoomCollisionOrder::Room3);
		Room3Collision->SetScale({ 200, 20 });
		Room3Collision->SetPosition({ 2560 + 640,1440 + 150 });
		Room3Collision->SetDebugRenderType(CollisionType::CT_Rect);
		
	}
	{
		Room4Collision = CreateCollision(RoomCollisionOrder::Room4);
		Room4Collision->SetScale({ 20, 200 });
		Room4Collision->SetPosition({ 2560 + 1280 + 180,1440 + 340 });
		Room4Collision->SetDebugRenderType(CollisionType::CT_Rect);
	}

	//Room5Collision = CreateCollision(RoomCollisionOrder::Room5);
	//Room5Collision->SetScale({ 200, 20 });
	//Room5Collision->SetPosition({ 640,720 + 120 });
	//Room5Collision->SetDebugRenderType(CollisionType::CT_Rect);

	//Room6Collision = CreateCollision(RoomCollisionOrder::Room6);//º¸½º
	//Room6Collision->SetScale({ 200, 20 });
	//Room6Collision->SetPosition({ 640,720 + 120 });
	//Room6Collision->SetDebugRenderType(CollisionType::CT_Rect);

	


}
bool Room1 = true;
void MapCollision::Update(float _DeltaTime)
{
	if (true== Room1&&true == Isaac::MainPlayer->GetIsaacCollision()->Collision({ .TargetGroup = static_cast<int>(RoomCollisionOrder::Room1), .TargetColType = CT_Rect, .ThisColType = CT_Rect }))
	{
		Room1 = false;
		Room1Collision->Death();
		Monster_Fly* Room1Fly = GetLevel()->CreateActor<Monster_Fly>();
		Room1Fly->SetPos({300,720+400});
		Monster_Fly* Room2Fly = GetLevel()->CreateActor<Monster_Fly>();
		Room2Fly->SetPos({ 600,720 + 400 });
		Host* NewHost = GetLevel()->CreateActor<Host>();
		NewHost->SetPos({ 600,720 + 400 });
	}











	if (true == Isaac::MainPlayer->GetIsaacCollision()->Collision({ .TargetGroup = static_cast<int>(RoomCollisionOrder::Room2), .TargetColType = CT_Rect, .ThisColType = CT_Rect }))
	{
		Room2Collision->Death();
	}
	if (true == Isaac::MainPlayer->GetIsaacCollision()->Collision({ .TargetGroup = static_cast<int>(RoomCollisionOrder::Room3), .TargetColType = CT_Rect, .ThisColType = CT_Rect }))
	{
		Room3Collision->Death();
	}
	if (true == Isaac::MainPlayer->GetIsaacCollision()->Collision({ .TargetGroup = static_cast<int>(RoomCollisionOrder::Room4), .TargetColType = CT_Rect, .ThisColType = CT_Rect }))
	{
		Room4Collision->Death();
	}
}
void MapCollision::Render(float _DeltaTime)
{
	Room1Collision->DebugRender();
	Room2Collision->DebugRender();
	Room3Collision->DebugRender();
	Room4Collision->DebugRender();
	//Room5Collision->DebugRender();
	//Room6Collision->DebugRender();
	
}