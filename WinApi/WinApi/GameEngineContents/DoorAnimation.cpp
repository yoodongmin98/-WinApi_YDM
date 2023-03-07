#include "isaacLevel.h"
#include "IsaacEnum.h"
#include "AllBack.h"
#include "Isaac.h"

#include <GameEngineCore/GameEngineRender.h>


//Room에서 설정은 안되고 시간은 없으니 그냥 노가다로 박아놓자 아 ㅠ
//생각할시간에 노가다로 해놓고 나중에고치기
void IsaacLevel::DoorAnimationSetandUpdate()
{
	AllBack* Door = CreateActor<AllBack>();


	Room0door = Door->CreateRender("Map_Door_Down.BMP", IsaacOrder::R_OpenDoor);
	Room0door->SetPosition({0,240});
	Room0door->SetScale({ 350,270 });
	Room0door->CreateAnimation({ .AnimationName = "Door_D_Idle",  .ImageName = "Map_Door_Down.BMP", .Start = 0, .End = 0, .InterTime = 0.5f });
	Room0door->CreateAnimation({ .AnimationName = "Door_D_Open",  .ImageName = "Map_Door_Down.BMP", .Start = 0, .End = 3, .InterTime = 0.1f ,.Loop = false });
	
	Room1door = Door->CreateRender("Map_Door_Up.BMP", IsaacOrder::R_OpenDoor);
	Room1door->SetPosition({ 0,360+120 });
	Room1door->SetScale({ 350,270 });
	Room1door->CreateAnimation({ .AnimationName = "Door_U_Idle",  .ImageName = "Map_Door_Up.BMP", .Start = 0, .End = 0, .InterTime = 0.5f });
	Room1door->CreateAnimation({ .AnimationName = "Door_U_Open",  .ImageName = "Map_Door_Up.BMP", .Start = 0, .End = 3, .InterTime = 0.1f ,.Loop = false });

	Room2door = Door->CreateRender("Map_Door_Right.BMP", IsaacOrder::R_OpenDoor);
	Room2door->SetPosition({ 540,360 + 440 });
	Room2door->SetScale({ 350,270 });
	Room2door->CreateAnimation({ .AnimationName = "Door_R_Idle",  .ImageName = "Map_Door_Right.BMP", .Start = 0, .End = 0, .InterTime = 0.5f });
	Room2door->CreateAnimation({ .AnimationName = "Door_R_Open",  .ImageName = "Map_Door_Right.BMP", .Start = 0, .End = 3, .InterTime = 0.1f ,.Loop = false });

	Room3door = Door->CreateRender("Map_Door_Left.BMP", IsaacOrder::R_OpenDoor);
	Room3door->SetPosition({ 640+100,360 + 440 });
	Room3door->SetScale({ 350,270 });
	Room3door->CreateAnimation({ .AnimationName = "Door_L_Idle",  .ImageName = "Map_Door_Left.BMP", .Start = 0, .End = 0, .InterTime = 0.5f });
	Room3door->CreateAnimation({ .AnimationName = "Door_L_Open",  .ImageName = "Map_Door_Left.BMP", .Start = 0, .End = 3, .InterTime = 0.1f ,.Loop = false });

	Room4door = Door->CreateRender("Map_Door_Right.BMP", IsaacOrder::R_OpenDoor);
	Room4door->SetPosition({ 1280+540,360 + 440 });
	Room4door->SetScale({ 350,270 });
	Room4door->CreateAnimation({ .AnimationName = "Door_R_Idle",  .ImageName = "Map_Door_Right.BMP", .Start = 0, .End = 0, .InterTime = 0.5f });
	Room4door->CreateAnimation({ .AnimationName = "Door_R_Open",  .ImageName = "Map_Door_Right.BMP", .Start = 0, .End = 3, .InterTime = 0.1f ,.Loop = false });

	Room5door = Door->CreateRender("Map_Door_Left.BMP", IsaacOrder::R_OpenDoor);
	Room5door->SetPosition({ 640+ 1280 +100,360 + 440 });
	Room5door->SetScale({ 350,270 });
	Room5door->CreateAnimation({ .AnimationName = "Door_L_Idle",  .ImageName = "Map_Door_Left.BMP", .Start = 0, .End = 0, .InterTime = 0.5f });
	Room5door->CreateAnimation({ .AnimationName = "Door_L_Open",  .ImageName = "Map_Door_Left.BMP", .Start = 0, .End = 3, .InterTime = 0.1f ,.Loop = false });

	Room6door = Door->CreateRender("Map_Door_Up.BMP", IsaacOrder::R_OpenDoor);
	Room6door->SetPosition({ 2560,360 + 120 });
	Room6door->SetScale({ 350,270 });
	Room6door->CreateAnimation({ .AnimationName = "Door_U_Idle",  .ImageName = "Map_Door_Up.BMP", .Start = 0, .End = 0, .InterTime = 0.5f });
	Room6door->CreateAnimation({ .AnimationName = "Door_U_Open",  .ImageName = "Map_Door_Up.BMP", .Start = 0, .End = 3, .InterTime = 0.1f ,.Loop = false });

	Room7door = Door->CreateRender("Map_Door_Down.BMP", IsaacOrder::R_OpenDoor);
	Room7door->SetPosition({ 2560,240 });
	Room7door->SetScale({ 350,270 });
	Room7door->CreateAnimation({ .AnimationName = "Door_D_Idle",  .ImageName = "Map_Door_Down.BMP", .Start = 0, .End = 0, .InterTime = 0.5f });
	Room7door->CreateAnimation({ .AnimationName = "Door_D_Open",  .ImageName = "Map_Door_Down.BMP", .Start = 0, .End = 3, .InterTime = 0.1f ,.Loop = false });

	Room8door = Door->CreateRender("Map_Door_Down.BMP", IsaacOrder::R_OpenDoor);
	Room8door->SetPosition({ 2560,720+240 });
	Room8door->SetScale({ 350,270 });
	Room8door->CreateAnimation({ .AnimationName = "Door_D_Idle",  .ImageName = "Map_Door_Down.BMP", .Start = 0, .End = 0, .InterTime = 0.5f });
	Room8door->CreateAnimation({ .AnimationName = "Door_D_Open",  .ImageName = "Map_Door_Down.BMP", .Start = 0, .End = 3, .InterTime = 0.1f ,.Loop = false });

	Room9door = Door->CreateRender("Map_Door_Up.BMP", IsaacOrder::R_OpenDoor);
	Room9door->SetPosition({ 2560,360 + 720+120 });
	Room9door->SetScale({ 350,270 });
	Room9door->CreateAnimation({ .AnimationName = "Door_U_Idle",  .ImageName = "Map_Door_Up.BMP", .Start = 0, .End = 0, .InterTime = 0.5f });
	Room9door->CreateAnimation({ .AnimationName = "Door_U_Open",  .ImageName = "Map_Door_Up.BMP", .Start = 0, .End = 3, .InterTime = 0.1f ,.Loop = false });

	Room10door = Door->CreateRender("Map_Door_Right.BMP", IsaacOrder::R_OpenDoor);
	Room10door->SetPosition({ 2560 + 540,360 + 720+440 });
	Room10door->SetScale({ 350,270 });
	Room10door->CreateAnimation({ .AnimationName = "Door_R_Idle",  .ImageName = "Map_Door_Right.BMP", .Start = 0, .End = 0, .InterTime = 0.5f });
	Room10door->CreateAnimation({ .AnimationName = "Door_R_Open",  .ImageName = "Map_Door_Right.BMP", .Start = 0, .End = 3, .InterTime = 0.1f ,.Loop = false });

	Room11door = Door->CreateRender("Map_Door_Left.BMP", IsaacOrder::R_OpenDoor);
	Room11door->SetPosition({ 640 + 2560 + 100,360+720 +440 });
	Room11door->SetScale({ 350,270 });
	Room11door->CreateAnimation({ .AnimationName = "Door_L_Idle",  .ImageName = "Map_Door_Left.BMP", .Start = 0, .End = 0, .InterTime = 0.5f });
	Room11door->CreateAnimation({ .AnimationName = "Door_L_Open",  .ImageName = "Map_Door_Left.BMP", .Start = 0, .End = 3, .InterTime = 0.1f ,.Loop = false });

	Room12door = Door->CreateRender("Map_Door_Right.BMP", IsaacOrder::R_OpenDoor);
	Room12door->SetPosition({ 2560+1280+ 540,360 +720+ 440 });
	Room12door->SetScale({ 350,270 });
	Room12door->CreateAnimation({ .AnimationName = "Door_R_Idle",  .ImageName = "Map_Door_Right.BMP", .Start = 0, .End = 0, .InterTime = 0.5f });
	Room12door->CreateAnimation({ .AnimationName = "Door_R_Open",  .ImageName = "Map_Door_Right.BMP", .Start = 0, .End = 3, .InterTime = 0.1f ,.Loop = false });

	Room13door = Door->CreateRender("Map_Door_Left.BMP", IsaacOrder::R_OpenDoor);
	Room13door->SetPosition({ 640 + 2560+1280+ 100,360 + 720 + 440 });
	Room13door->SetScale({ 350,270 });
	Room13door->CreateAnimation({ .AnimationName = "Door_L_Idle",  .ImageName = "Map_Door_Left.BMP", .Start = 0, .End = 0, .InterTime = 0.5f });
	Room13door->CreateAnimation({ .AnimationName = "Door_L_Open",  .ImageName = "Map_Door_Left.BMP", .Start = 0, .End = 3, .InterTime = 0.1f ,.Loop = false });

	Room14door = Door->CreateRender("Map_Door_Up.BMP", IsaacOrder::R_OpenDoor);
	Room14door->SetPosition({ 5120,360 + 720 + 120 });
	Room14door->SetScale({ 350,270 });
	Room14door->CreateAnimation({ .AnimationName = "Door_U_Idle",  .ImageName = "Map_Door_Up.BMP", .Start = 0, .End = 0, .InterTime = 0.5f });
	Room14door->CreateAnimation({ .AnimationName = "Door_U_Open",  .ImageName = "Map_Door_Up.BMP", .Start = 0, .End = 3, .InterTime = 0.1f ,.Loop = false });

	Room15door = Door->CreateRender("Map_Door_Down.BMP", IsaacOrder::R_OpenDoor);
	Room15door->SetPosition({ 5120,720+240 });
	Room15door->SetScale({ 350,270 });
	Room15door->CreateAnimation({ .AnimationName = "Door_D_Idle",  .ImageName = "Map_Door_Down.BMP", .Start = 0, .End = 0, .InterTime = 0.5f });
	Room15door->CreateAnimation({ .AnimationName = "Door_D_Open",  .ImageName = "Map_Door_Down.BMP", .Start = 0, .End = 3, .InterTime = 0.1f ,.Loop = false });


	Room16door = Door->CreateRender("Map_Door_Up.BMP", IsaacOrder::R_OpenDoor);
	Room16door->SetPosition({ 5120,360 + 120 });
	Room16door->SetScale({ 350,270 });
	Room16door->CreateAnimation({ .AnimationName = "Door_U_Idle",  .ImageName = "Map_Door_Up.BMP", .Start = 0, .End = 0, .InterTime = 0.5f });
	Room16door->CreateAnimation({ .AnimationName = "Door_U_Open",  .ImageName = "Map_Door_Up.BMP", .Start = 0, .End = 3, .InterTime = 0.1f ,.Loop = false });

	Room17door = Door->CreateRender("Map_Door_Down.BMP", IsaacOrder::R_OpenDoor);
	Room17door->SetPosition({ 5120,240 });
	Room17door->SetScale({ 350,270 });
	Room17door->CreateAnimation({ .AnimationName = "Door_D_Idle",  .ImageName = "Map_Door_Down.BMP", .Start = 0, .End = 0, .InterTime = 0.5f });
	Room17door->CreateAnimation({ .AnimationName = "Door_D_Open",  .ImageName = "Map_Door_Down.BMP", .Start = 0, .End = 3, .InterTime = 0.1f ,.Loop = false });

}


//애니메이션관련
void IsaacLevel::DoorRenderUpdate()
{
	
	if (0 != Isaac::MainPlayer->GetMonsterCount())
	{
		Room0door->ChangeAnimation("Door_D_Idle");
		Room1door->ChangeAnimation("Door_U_Idle");
		Room2door->ChangeAnimation("Door_R_Idle");
		Room3door->ChangeAnimation("Door_L_Idle");
		Room4door->ChangeAnimation("Door_R_Idle");
		Room5door->ChangeAnimation("Door_L_Idle");
		Room6door->ChangeAnimation("Door_U_Idle");
		Room7door->ChangeAnimation("Door_D_Idle");
		Room8door->ChangeAnimation("Door_D_Idle");
		Room9door->ChangeAnimation("Door_U_Idle");
		Room10door->ChangeAnimation("Door_R_Idle");
		Room11door->ChangeAnimation("Door_L_Idle");
		Room12door->ChangeAnimation("Door_R_Idle");
		Room13door->ChangeAnimation("Door_L_Idle");
		Room14door->ChangeAnimation("Door_U_Idle");
		Room15door->ChangeAnimation("Door_D_Idle");
		Room16door->ChangeAnimation("Door_U_Idle");
		Room17door->ChangeAnimation("Door_D_Idle");
	}
	if (0 == Isaac::MainPlayer->GetMonsterCount())
	{
		Room0door->ChangeAnimation("Door_D_Open");
		Room1door->ChangeAnimation("Door_U_Open");
		Room2door->ChangeAnimation("Door_R_Open");
		Room3door->ChangeAnimation("Door_L_Open");
		Room4door->ChangeAnimation("Door_R_Open");
		Room5door->ChangeAnimation("Door_L_Open");
		Room6door->ChangeAnimation("Door_U_Open");
		Room7door->ChangeAnimation("Door_D_Open");
		Room8door->ChangeAnimation("Door_D_Open");
		Room9door->ChangeAnimation("Door_U_Open");
		Room10door->ChangeAnimation("Door_R_Open");
		Room11door->ChangeAnimation("Door_L_Open");
		Room12door->ChangeAnimation("Door_R_Open");
		Room13door->ChangeAnimation("Door_L_Open");
		Room14door->ChangeAnimation("Door_U_Open");
		Room15door->ChangeAnimation("Door_D_Open");
		Room16door->ChangeAnimation("Door_U_Open");
		Room17door->ChangeAnimation("Door_D_Open");
	}
}