#pragma once

enum class IsaacOrder
{
	R_BackGround_Black, 
	R_BackGround,

	R_Door, //�����ٴҼ��ִ°Ÿ� Door
	R_Wall, //���������°Ÿ� Wall
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


	C_Monster,
	C_MonsterAtt,

	C_Isaac_Bomb,

	

};