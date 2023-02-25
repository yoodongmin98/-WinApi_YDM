#include "Isaaclevel.h"
#include <GameEngineBase/GameEngineDirectory.h>



bool ImageBool = true;
void IsaacLevel::ImageLoad()
{
	if (true == ImageBool)
	{
		GameEngineDirectory Dir;
		Dir.MoveParentToDirectory("ContentsResources");
		Dir.Move("ContentsResources");
		Dir.Move("Image");
		Dir.Move("Play");
		{
			GameEngineImage* head = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Isaac_Face.BMP"));
			head->Cut(10, 5);
			GameEngineImage* Ani = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Isaac_Ani.BMP"));
			Ani->Cut(4, 3);
			GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Room.BMP"));
			GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Room_Depth.BMP"));
			GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Room_Boss.BMP"));
			GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("BackGround_CS.BMP"));
			GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Play_BlackGround.BMP"));
			GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Play_Settingmenu.BMP"));
			GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("BackDrop.BMP"));
			GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("DeadMenu.BMP"));

			GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Map_BossDoor_Left.BMP"));
			GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Map_BossDoor_Right.BMP"));

			GameEngineImage* Door_Down = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Map_Door_Down.BMP"));
			Door_Down->Cut(4, 1);
			GameEngineImage* Door_Up = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Map_Door_Up.BMP"));
			Door_Up->Cut(4, 1);
			GameEngineImage* Door_Right = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Map_Door_Right.BMP"));
			Door_Right->Cut(4, 1);
			GameEngineImage* Door_Left = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Map_Door_Left.BMP"));
			Door_Left->Cut(4, 1);

			GameEngineImage* Tear = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Tear.bmp"));
			Tear->Cut(8, 4);
			GameEngineImage* Tears = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Tear_Pop.bmp"));
			Tears->Cut(4, 4);

			GameEngineImage* HP = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("HP.bmp"));
			HP->Cut(5, 2);
			GameEngineImage* Number_UI = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Number_UI.bmp"));
			Number_UI->Cut(3, 2);
			GameEngineImage* Number_ = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Number.bmp"));
			Number_->Cut(10, 1);
		}
		
		ImageBool = false;
	}
}