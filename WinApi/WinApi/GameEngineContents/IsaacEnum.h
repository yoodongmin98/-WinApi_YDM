#pragma once

enum class IsaacOrder
{
	R_BackGround_Black, 
	R_BackGround,

	R_Door, //지나다닐수있는거면 Door
	R_Wall, //못지나가는거면 Wall
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
	

	C_Player,
	C_PlayerAtt,
	C_Monster,
	C_MonsterAtt,

	C_Isaac_Bomb,

	

};