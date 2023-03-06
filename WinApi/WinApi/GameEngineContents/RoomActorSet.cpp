#include "Isaaclevel.h"


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
#include "CoinBomb.h"
#include "CoinHeart.h"
#include "CoinKey.h"
#include "ShopKeeper.h"

////Item
#include "Altar.h"
#include "Leo.h"
#include "ItemHeart.h"
#include "Glasses.h"
#include "BlackLotus.h"


void IsaacLevel::Room1Set()
{
	Spike* NewSpike1 = CreateActor<Spike>();
	NewSpike1->SetPos({ 230,720 + 145 });
	Spike* NewSpike2 = CreateActor<Spike>();
	NewSpike2->SetPos({ 170,720 + 200 });
	Spike* NewSpike3 = CreateActor<Spike>();
	NewSpike3->SetPos({ 1050,720 + 145 });
	Spike* NewSpike4 = CreateActor<Spike>();
	NewSpike4->SetPos({ 1110,720 + 200 });
	Spike* NewSpike5 = CreateActor<Spike>();
	NewSpike5->SetPos({ 170,720 + 520 });
	Spike* NewSpike6 = CreateActor<Spike>();
	NewSpike6->SetPos({ 230,720 + 575 });
	Spike* NewSpike7 = CreateActor<Spike>();
	NewSpike7->SetPos({ 1110,720 + 520 });
	Spike* NewSpike8 = CreateActor<Spike>();
	NewSpike8->SetPos({ 1050,720 + 575 });
	Spike* NewSpike9 = CreateActor<Spike>();
	NewSpike9->SetPos({ 640,720 + 360 });
}
void IsaacLevel::Room2Set()
{
	Rock* NewRock1= CreateActor<Rock>();
	NewRock1->SetPos({ 1280+170,720 + 150 });
	Rock* NewRock2 = CreateActor<Rock>();
	NewRock2->SetPos({ 1280 + 170,720 + 575 });
	Rock* NewRock3 = CreateActor<Rock>();
	NewRock3->SetPos({ 1280 + 1110,720 + 150 });
	Rock* NewRock4 = CreateActor<Rock>();
	NewRock4->SetPos({ 1280 + 1110,720 + 575});

}
void IsaacLevel::Room3Set()
{
	Poop* NewPoop = CreateActor<Poop>();
	NewPoop->SetPos({ 2560 + 800,720 + 200 });
	Coin* NewCoin = CreateActor<Coin>();
	NewCoin->SetPos({ 2560 + 800,720 + 300 });
	Heart* NewHeart = CreateActor<Heart>();
	NewHeart->SetPos({ 2560 + 800,720 + 400 });
	Key* NewKey = CreateActor<Key>();
	NewKey->SetPos({ 2560 + 800,720 + 500 });
	ItemBomb* NewItemBomb = CreateActor<ItemBomb>();
	NewItemBomb->SetPos({ 2560 + 800,720 + 550 });

	Spike* NewSpike = CreateActor<Spike>();
	NewSpike->SetPos({ 2560 + 950,720 + 200 });
	Rock_Boom* NewRockBoom = CreateActor<Rock_Boom>();
	NewRockBoom->SetPos({ 2560 + 950,720 + 300 });
	Rock* NewRock = CreateActor<Rock>();
	NewRock->SetPos({ 2560 + 950,720 + 400 });
	Fire* NewFire = CreateActor<Fire>();
	NewFire->SetPos({ 2560 + 950,720 + 500 });
	FireWood* NewWood = CreateActor<FireWood>();
	NewWood->SetPos({ 2560 + 950,720 + 530 });

}
void IsaacLevel::Room4Set()
{
	Altar* NewAltar1 = CreateActor<Altar>();
	NewAltar1->SetPos({ 2560 + 300,300 });
	Leo* NewLeo = CreateActor<Leo>();
	NewLeo->SetPos({ 2560 + 300,280 });
	
	Altar* NewAltar2 = CreateActor<Altar>();
	NewAltar2->SetPos({ 2560 + 500,300 });
	ItemHeart* NewItemHeart = CreateActor<ItemHeart>();
	NewItemHeart->SetPos({ 2560 + 500,280 });

	Altar* NewAltar3 = CreateActor<Altar>();
	NewAltar3->SetPos({ 2560 + 700,300 });
	Glasses* NewGlasses = CreateActor<Glasses>();
	NewGlasses->SetPos({ 2560 + 700,280 });

	Altar* NewAltar4 = CreateActor<Altar>();
	NewAltar4->SetPos({ 2560 + 900,300 });
	BlackLotus* NewBlackLotus = CreateActor<BlackLotus>();
	NewBlackLotus->SetPos({ 2560 + 900,280 });

}
void IsaacLevel::Room5Set()
{
	Rock* Romm5Rock1 = CreateActor<Rock>();
	Romm5Rock1->SetPos({ 2560 + 500,1440 + 360 });
	Rock* Romm5Rock2 = CreateActor<Rock>();
	Romm5Rock2->SetPos({ 2560 + 550,1440 + 360 });
	Rock* Romm5Rock3 = CreateActor<Rock>();
	Romm5Rock3->SetPos({ 2560 + 600,1440+360 });
	Rock* Romm5Rock4 = CreateActor<Rock>();
	Romm5Rock4->SetPos({ 2560 + 650,1440 + 360 });
	Rock* Romm5Rock5 = CreateActor<Rock>();
	Romm5Rock5->SetPos({ 2560 + 700,1440 + 360 });
	Rock* Romm5Rock6 = CreateActor<Rock>();
	Romm5Rock6->SetPos({ 2560 + 750,1440 + 360 });
	Rock* Romm5Rock7 = CreateActor<Rock>();
	Romm5Rock7->SetPos({ 2560 + 450,1440 + 360 });
	Rock* Romm5Rock8 = CreateActor<Rock>();
	Romm5Rock8->SetPos({ 2560 + 800,1440 + 360 });
	Rock* Romm5Rock9 = CreateActor<Rock>();
	Romm5Rock9->SetPos({ 2560 + 630,1440 + 310 });
	Rock* Romm5Rock10 = CreateActor<Rock>();
	Romm5Rock10->SetPos({ 2560 + 630,1440 + 260 });
	Rock* Romm5Rock11 = CreateActor<Rock>();
	Romm5Rock11->SetPos({ 2560 + 630,1440 + 210 });
	Rock* Romm5Rock12 = CreateActor<Rock>();
	Romm5Rock12->SetPos({ 2560 + 630,1440 + 410 });
	Rock* Romm5Rock13 = CreateActor<Rock>();
	Romm5Rock13->SetPos({ 2560 + 630,1440 + 460 });
	Rock* Romm5Rock14 = CreateActor<Rock>();
	Romm5Rock14->SetPos({ 2560 + 630,1440 + 510 });
}
void IsaacLevel::Room6Set()
{
	Fire* Room6Fire = CreateActor<Fire>();
	Room6Fire->SetPos({ 3840 + 400,1440 + 240 });
	FireWood* Room6Wood = CreateActor<FireWood>();
	Room6Wood->SetPos({ 3840 + 400,1440 + 270 });

	Fire* Room6Fire1 = CreateActor<Fire>();
	Room6Fire1->SetPos({ 3840 + 400,1440 + 440 });
	FireWood* Room6Wood1 = CreateActor<FireWood>();
	Room6Wood1->SetPos({ 3840 + 400,1440 + 470 });

	Fire* Room6Fire2 = CreateActor<Fire>();
	Room6Fire2->SetPos({ 3840 + 900,1440 + 240 });
	FireWood* Room6Wood2 = CreateActor<FireWood>();
	Room6Wood2->SetPos({ 3840 + 900,1440 + 270 });

	Fire* Room6Fire3 = CreateActor<Fire>();
	Room6Fire3->SetPos({ 3840 + 900,1440 + 440 });
	FireWood* Room6Wood3 = CreateActor<FireWood>();
	Room6Wood3->SetPos({ 3840 + 900,1440 + 470 });
}
void IsaacLevel::Room7Set()
{
	Rock* Room7Rock1 = CreateActor<Rock>();
	Room7Rock1->SetPos({ 5120 + 230,1440 + 145 });
	Rock* Room7Rock2 = CreateActor<Rock>();
	Room7Rock2->SetPos({ 5120 + 170,1440 + 200 });
	Rock* Room7Rock3 = CreateActor<Rock>();
	Room7Rock3->SetPos({ 5120 + 1050,1440 + 145 });
	Rock* Room7Rock4 = CreateActor<Rock>();
	Room7Rock4->SetPos({ 5120 + 1110,1440 + 200 });
}
void IsaacLevel::Room8Set()
{

}
void IsaacLevel::Room9Set()
{
	CoinBomb* ShopBomb = CreateActor<CoinBomb>();
	ShopBomb->SetPos({ 5120 + 540, 400 });
	CoinHeart* ShopHeart = CreateActor<CoinHeart>();
	ShopHeart->SetPos({ 5120 + 640, 400 });
	CoinKey* ShopKey = CreateActor<CoinKey>();
	ShopKey->SetPos({ 5120 + 740, 400 });

	ShopKeeper* ShopKeepers = CreateActor<ShopKeeper>();
	ShopKeepers->SetPos({ 5120 + 640, 250 });

	Fire* Room9Fire1 = CreateActor<Fire>();
	Room9Fire1->SetPos({ 5120 + 170,130 });
	Fire* Room9Fire2 = CreateActor<Fire>();
	Room9Fire2->SetPos({ 5120 + 170,535 });
	Fire* Room9Fire3 = CreateActor<Fire>();
	Room9Fire3->SetPos({ 5120 + 1110,130 });
	Fire* Room9Fire4 = CreateActor<Fire>();
	Room9Fire4->SetPos({ 5120 + 1110,535 });

	FireWood* Room9FireWood1 = CreateActor<FireWood>();
	Room9FireWood1->SetPos({ 5120 + 170,170 });
	FireWood* Room9FireWood2 = CreateActor<FireWood>();
	Room9FireWood2->SetPos({ 5120 + 170,575 });
	FireWood* Room9FireWood3 = CreateActor<FireWood>();
	Room9FireWood3->SetPos({ 5120 + 1110,170 });
	FireWood* Room9FireWood4 = CreateActor<FireWood>();
	Room9FireWood4->SetPos({ 5120 + 1110,575 });
	
}