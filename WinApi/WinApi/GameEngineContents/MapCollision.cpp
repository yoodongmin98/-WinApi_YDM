#include "MapCollision.h"
#include "IsaacEnum.h"
#include "Isaac.h"

#include <GameEngineCore/GameEngineCore.h>
#include <GameEngineCore/GameEngineCollision.h>
#include <GameEngineCore/GameEngineLevel.h>

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

//Item
#include "ItemBomb.h"

MapCollision::MapCollision()
{

}
MapCollision::~MapCollision()
{

}

//////시작될때 콜리전을 깔아놓고 시작

void MapCollision::Start()
{
	Room1Collision = CreateCollision(IsaacCollisionOrder::Room1);
	Room1Collision->SetDebugRenderType(CollisionType::CT_Rect);
	Room1Collision->SetScale({ 200, 20 });
	Room1Collision->SetPosition({ 640,720 + 120 });
	

	Room2Collision = CreateCollision(IsaacCollisionOrder::Room2);
	Room2Collision->SetDebugRenderType(CollisionType::CT_Rect);
	Room2Collision->SetScale({ 20, 200 });
	Room2Collision->SetPosition({ 1280 + 150,720 + 380 });


	Room3Collision = CreateCollision(IsaacCollisionOrder::Room3);
	Room3Collision->SetDebugRenderType(CollisionType::CT_Rect);
	Room3Collision->SetScale({ 200, 20 });
	Room3Collision->SetPosition({ 2560+640,720 + 120 });


	Room4Collision = CreateCollision(IsaacCollisionOrder::Room4);
	Room4Collision->SetDebugRenderType(CollisionType::CT_Rect);
	Room4Collision->SetScale({ 200, 20});
	Room4Collision->SetPosition({ 2560 + 640, 600 });


	Room5Collision = CreateCollision(IsaacCollisionOrder::Room5);
	Room5Collision->SetDebugRenderType(CollisionType::CT_Rect);
	Room5Collision->SetScale({ 200, 20 });
	Room5Collision->SetPosition({ 2560 + 640,1440 + 130 });
	

	Room6Collision = CreateCollision(IsaacCollisionOrder::Room6);
	Room6Collision->SetDebugRenderType(CollisionType::CT_Rect);
	Room6Collision->SetScale({ 20, 200 });
	Room6Collision->SetPosition({ 3840 + 150,1440 + 380 });
	

	Room7Collision = CreateCollision(IsaacCollisionOrder::Room7);
	Room7Collision->SetDebugRenderType(CollisionType::CT_Rect);
	Room7Collision->SetScale({ 20, 200 });
	Room7Collision->SetPosition({ 5120+150,1440 + 380 });
	

	Room8Collision = CreateCollision(IsaacCollisionOrder::Room8);//보스
	Room8Collision->SetScale({ 20, 200 });
	Room8Collision->SetPosition({ 5120+1280+150,720 + 380 });
	Room8Collision->SetDebugRenderType(CollisionType::CT_Rect);


	Room8Collision2 = CreateCollision(IsaacCollisionOrder::Room8_2);
	Room8Collision2->SetScale({ 200, 20 });
	Room8Collision2->SetPosition({ 5120 + 640 ,720 + 130 });
	Room8Collision2->SetDebugRenderType(CollisionType::CT_Rect);


	Room9Collision = CreateCollision(IsaacCollisionOrder::Room9);//Shop //배경음악 바꾸기용
	Room9Collision->SetScale({ 200, 20 });
	Room9Collision->SetPosition({ 5120 + 640, 580 });
	Room9Collision->SetDebugRenderType(CollisionType::CT_Rect);
}


void MapCollision::Update(float _DeltaTime)
{
	//몬스터를 만들때 한번만로드되도록 bool값을넣음
	if (true== Room1&&
		true == Isaac::MainPlayer->GetIsaacCollision()->Collision({ .TargetGroup = static_cast<int>(IsaacCollisionOrder::Room1), .TargetColType = CT_Rect, .ThisColType = CT_Rect }))
	{
		Room1 = false;
		Room1Collision->Death(); //한번만 작용하게끔

		//Isaac::MainPlayer->SetMonsterCount(4); //이부분주석걸면 안죽여도 맵이동가능(밑에도있음)

		Monster_Fly* Room1Fly = GetLevel()->CreateActor<Monster_Fly>();
		Room1Fly->SetPos({300,720+400});
		Monster_Fly* Room1Fly2 = GetLevel()->CreateActor<Monster_Fly>();
		Room1Fly2->SetPos({ 600,720 + 400 });
		
		Pooter* Room1Pooter1 = GetLevel()->CreateActor<Pooter>();
		Room1Pooter1->SetPos({ 200,720 + 200 });
		Pooter* Room1Pooter2 = GetLevel()->CreateActor<Pooter>();
		Room1Pooter2->SetPos({ 800,720 + 200 });
	}
	if (true == Room2&&
		true == Isaac::MainPlayer->GetIsaacCollision()->Collision({ .TargetGroup = static_cast<int>(IsaacCollisionOrder::Room2), .TargetColType = CT_Rect, .ThisColType = CT_Rect }))
	{
		Room2 = false;
		Room2Collision->Death();

		//Isaac::MainPlayer->SetMonsterCount(4); //이부분주석걸면 안죽여도 맵이동가능(밑에도있음)

		Charger* Room2Charger1 = GetLevel()->CreateActor<Charger>();
		Room2Charger1->SetPos({ 1280+600,720 + 200 });
		Charger* Room2Charger2 = GetLevel()->CreateActor<Charger>();
		Room2Charger2->SetPos({ 1280+600,720 + 500 });
		Monster_Blob* Room2Blob1 = GetLevel()->CreateActor<Monster_Blob>();
		Room2Blob1->SetPos({ 1280 + 400,720 + 200 });
		Monster_Blob* Room2Blob2 = GetLevel()->CreateActor<Monster_Blob>();
		Room2Blob2->SetPos({ 1280 + 400,720 + 500 });
	}
	if (true==Room5&&
		true == Isaac::MainPlayer->GetIsaacCollision()->Collision({ .TargetGroup = static_cast<int>(IsaacCollisionOrder::Room5), .TargetColType = CT_Rect, .ThisColType = CT_Rect }))
	{
		Room5 = false;
		Room5Collision->Death();

		//Isaac::MainPlayer->SetMonsterCount(4); //이부분주석걸면 안죽여도 맵이동가능(밑에도있음)

		Host* Room5Host1 = GetLevel()->CreateActor<Host>();
		Room5Host1->SetPos({ 2560 + 560,1440 + 290 });
		Host* Room5Host2 = GetLevel()->CreateActor<Host>();
		Room5Host2->SetPos({ 2560 + 700,1440 + 290 });
		Host* Room5Host3 = GetLevel()->CreateActor<Host>();
		Room5Host3->SetPos({ 2560 + 560,1440 + 390 });
		Host* Room5Host4 = GetLevel()->CreateActor<Host>();
		Room5Host4->SetPos({ 2560 + 700,1440 + 390 });
	}

	if (true==Room6&&
		true == Isaac::MainPlayer->GetIsaacCollision()->Collision({ .TargetGroup = static_cast<int>(IsaacCollisionOrder::Room6), .TargetColType = CT_Rect, .ThisColType = CT_Rect }))
	{
		Room6 = false;
		Room6Collision->Death();

		//Isaac::MainPlayer->SetMonsterCount(4); //이부분주석걸면 안죽여도 맵이동가능(밑에도있음)

		Gaper* Room6Gaper = GetLevel()->CreateActor<Gaper>();
		Room6Gaper->SetPos({ 3840 + 500,1440 + 250 });
		Gaper* Room6Gaper2 = GetLevel()->CreateActor<Gaper>();
		Room6Gaper2->SetPos({ 3840 + 500,1440 + 500 });


		MuliBoom* Room6Muli1 = GetLevel()->CreateActor<MuliBoom>();
		Room6Muli1->SetPos({ 3840 + 900,1440 + 250 });
		MuliBoom* Room6Muli2 = GetLevel()->CreateActor<MuliBoom>();
		Room6Muli2->SetPos({ 3840 + 900,1440 + 500 });

	}
	if (true==Room7&&
		true == Isaac::MainPlayer->GetIsaacCollision()->Collision({ .TargetGroup = static_cast<int>(IsaacCollisionOrder::Room7), .TargetColType = CT_Rect, .ThisColType = CT_Rect }))
	{
		Room7 = false;
		Room7Collision->Death();

		//Isaac::MainPlayer->SetMonsterCount(4); //이부분주석걸면 안죽여도 맵이동가능(여기가끝임)

		Boil* Room7Boil1 = GetLevel()->CreateActor<Boil>();
		Room7Boil1->SetPos({ 5120 + 170,1440 + 130 });
		Boil* Room7Boil2 = GetLevel()->CreateActor<Boil>();
		Room7Boil2->SetPos({ 5120 + 1110,1440 + 130 });
		Clot* Room7Clot = GetLevel()->CreateActor<Clot>();
		Room7Clot->SetPos({ 5120 + 900,1440 + 250 });
		Clotty* Room7Clotty = GetLevel()->CreateActor<Clotty>();
		Room7Clotty->SetPos({ 5120 + 900,1440 + 500 });

		ItemBomb* Room7ItemBomb1 = GetLevel()->CreateActor<ItemBomb>();
		Room7ItemBomb1->SetPos({ 5120 + 170,1440 + 550 });
		ItemBomb* Room7ItemBomb2 = GetLevel()->CreateActor<ItemBomb>();
		Room7ItemBomb2->SetPos({ 5120 + 1110,1440 + 550 });
	}
	
}
void MapCollision::Render(float _DeltaTime)
{
	Room1Collision->DebugRender();
	Room2Collision->DebugRender();
	Room3Collision->DebugRender();
	Room4Collision->DebugRender();
	Room5Collision->DebugRender();
	Room6Collision->DebugRender();
	Room7Collision->DebugRender();
	Room8Collision->DebugRender();
	Room8Collision2->DebugRender();
	Room9Collision->DebugRender();

}