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

//////시작될때 콜리전을 깔아놓고 시작

void MapCollision::Start()
{
	//Room1Collision = CreateCollision(RoomCollisionOrder::Room1);
	//Room1Collision->SetDebugRenderType(CollisionType::CT_Rect);
	//Room1Collision->SetScale({ 200, 20 });
	//Room1Collision->SetPosition({ 640,720 + 120 });
	//
	//Room2Collision = CreateCollision(RoomCollisionOrder::Room2);
	//Room2Collision->SetDebugRenderType(CollisionType::CT_Rect);
	//Room2Collision->SetScale({ 20, 200 });
	//Room2Collision->SetPosition({ 1280 + 150,720 + 340 });
	
	Room5Collision = CreateCollision(RoomCollisionOrder::Room5);
	Room5Collision->SetDebugRenderType(CollisionType::CT_Rect);
	Room5Collision->SetScale({ 200, 20 });
	Room5Collision->SetPosition({ 640, 120 });

	//Room5Collision->SetPosition({ 2560 + 640,1440 + 130 });
	
	//Room6Collision = CreateCollision(RoomCollisionOrder::Room6);
	//Room6Collision->SetDebugRenderType(CollisionType::CT_Rect);
	//Room6Collision->SetScale({ 20, 200 });
	//Room6Collision->SetPosition({ 3840 + 180,1440 + 340 });
	//
	//Room7Collision = CreateCollision(RoomCollisionOrder::Room7);
	//Room7Collision->SetDebugRenderType(CollisionType::CT_Rect);
	//Room7Collision->SetScale({ 200, 20 });
	//Room7Collision->SetPosition({ 5120+180,1440 + 340 });
	
	//Room8Collision = CreateCollision(RoomCollisionOrder::Room8);//보스
	//Room8Collision->SetScale({ 200, 20 });
	//Room8Collision->SetPosition({ 640,720 + 120 });
	//Room8Collision->SetDebugRenderType(CollisionType::CT_Rect);
}


void MapCollision::Update(float _DeltaTime)
{
	//몬스터를 만들때 한번만로드되도록 bool값을넣음
	//if (true== Room1&&
	//	true == Isaac::MainPlayer->GetIsaacCollision()->Collision({ .TargetGroup = static_cast<int>(RoomCollisionOrder::Room1), .TargetColType = CT_Rect, .ThisColType = CT_Rect }))
	//{
	//	Room1 = false;
	//	Room1Collision->Death(); //한번만 작용하게끔
	//	Monster_Fly* Room1Fly = GetLevel()->CreateActor<Monster_Fly>();
	//	Room1Fly->SetPos({300,720+400});
	//	Monster_Fly* Room1Fly2 = GetLevel()->CreateActor<Monster_Fly>();
	//	Room1Fly2->SetPos({ 600,720 + 400 });
	//	
	//	Pooter* Room1Pooter1 = GetLevel()->CreateActor<Pooter>();
	//	Room1Pooter1->SetPos({ 200,720 + 200 });
	//	Pooter* Room1Pooter2 = GetLevel()->CreateActor<Pooter>();
	//	Room1Pooter2->SetPos({ 800,720 + 200 });
	//}
	//if (true == Room2&&
	//	true == Isaac::MainPlayer->GetIsaacCollision()->Collision({ .TargetGroup = static_cast<int>(RoomCollisionOrder::Room2), .TargetColType = CT_Rect, .ThisColType = CT_Rect }))
	//{
	//	Room2 = false;
	//	Room2Collision->Death();
	//	Charger* Room2Charger1 = GetLevel()->CreateActor<Charger>();
	//	Room2Charger1->SetPos({ 1280+600,720 + 200 });
	//	Charger* Room2Charger2 = GetLevel()->CreateActor<Charger>();
	//	Room2Charger2->SetPos({ 1280+600,720 + 500 });
	//	Monster_Blob* Room2Blob1 = GetLevel()->CreateActor<Monster_Blob>();
	//	Room2Blob1->SetPos({ 1280 + 400,720 + 200 });
	//	Monster_Blob* Room2Blob2 = GetLevel()->CreateActor<Monster_Blob>();
	//	Room2Blob2->SetPos({ 1280 + 400,720 + 500 });
	//}
	//if (true==Room5&&
	//	true == Isaac::MainPlayer->GetIsaacCollision()->Collision({ .TargetGroup = static_cast<int>(RoomCollisionOrder::Room5), .TargetColType = CT_Rect, .ThisColType = CT_Rect }))
	//{
	//	Room5 = false;
	//	Room5Collision->Off();
	//	Host* Room5Host1 = GetLevel()->CreateActor<Host>();
	//	Room5Host1->SetPos({ 2560 + 400,1440 + 400 });
	//	//Host* Room5Host2 = GetLevel()->CreateActor<Host>();
	//	//Host* Room5Host3 = GetLevel()->CreateActor<Host>();
	//	//Host* Room5Host4 = GetLevel()->CreateActor<Host>();
	//}
	//if (true == Isaac::MainPlayer->GetIsaacCollision()->Collision({ .TargetGroup = static_cast<int>(RoomCollisionOrder::Room6), .TargetColType = CT_Rect, .ThisColType = CT_Rect }))
	//{
	//	Room6Collision->Death();
	//}
	//if (true == Isaac::MainPlayer->GetIsaacCollision()->Collision({ .TargetGroup = static_cast<int>(RoomCollisionOrder::Room7), .TargetColType = CT_Rect, .ThisColType = CT_Rect }))
	//{
	//	Room7Collision->Death();
	//}
}
void MapCollision::Render(float _DeltaTime)
{
	//Room1Collision->DebugRender();
	//Room2Collision->DebugRender();
	Room5Collision->DebugRender();
	//Room6Collision->DebugRender();
	//Room7Collision->DebugRender();
	//Room6Collision->DebugRender();
	
}