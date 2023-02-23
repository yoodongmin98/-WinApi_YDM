#pragma once

enum class IsaacOrder
{
	R_BackGround_Black, 
	R_BackGround, 
	R_Door,
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

	C_Player,
	C_PlayerAtt,
	C_Monster,
	C_MonsterAtt,

	C_Bomb,

	

};