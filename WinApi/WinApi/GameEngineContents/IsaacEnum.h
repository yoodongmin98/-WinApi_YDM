#pragma once

enum class IsaacOrder
{
	R_BackGround_Black, //1
	R_BackGround, //2

	R_Door, 
	R_MonsterDead,
	R_Wall,
	R_Player,
	R_Monster,
	R_Menu
	
};

enum class IsaacCollisionOrder
{
	C_Door,
	C_Wall,
	C_Item,
	C_Heart,
	C_Fire,
	C_Key,
	C_ItemBomb,
	C_Coin,
	

	C_Player,
	C_PlayerAtt_L,
	C_PlayerAtt_R,
	C_PlayerAtt_U,
	C_PlayerAtt_D,

	C_Moster_Set,
	C_Monster,
	

	C_Isaac_Bomb,

	

};