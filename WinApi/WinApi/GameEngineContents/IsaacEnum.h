#pragma once

enum class IsaacOrder
{
	R_BackGround_Black, //1
	R_BackGround, //2

	R_Door, 
	R_OpenDoor,
	R_BoomDead,
	R_MonsterDead,
	R_Wall,
	R_Item,
	R_Player,
	R_PlayerItem,
	R_Monster,
	R_Menu
	 
};

enum class IsaacCollisionOrder
{
	C_Door,
	C_Wall,
	
	C_Item_Leo,
	C_Item_Heart,
	C_Item_Blacklotus,
	C_Item_Glasses,

	C_Fire,
	C_Heart,
	C_Key,
	C_ItemBomb,
	C_Coin,

	C_CoinBomb,
	C_CoinHeart,
	C_CoinKey,
	

	C_Player,
	C_PlayerAtt_L,
	C_PlayerAtt_R,
	C_PlayerAtt_U,
	C_PlayerAtt_D,

	C_Moster_Set,
	C_Monster,
	

	C_Isaac_Bomb,

	Room1,
	Room2,
	Room3,
	Room4,
	Room5,
	Room6,
	Room7,
	Room8,
	Room8_2,
	Room9,
	Room10,




	NextLevel,
};

