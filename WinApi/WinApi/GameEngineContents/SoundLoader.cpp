#include "Isaaclevel.h"
#include <GameEngineBase/GameEngineDirectory.h>



bool PlayBool = true;
void IsaacLevel::SoundLoad()
{
	

	if (true == PlayBool)
	{
		GameEngineDirectory Dir;
		Dir.MoveParentToDirectory("ContentsResources");
		Dir.Move("ContentsResources");
		Dir.Move("Sound");
		{
			GameEngineResources::GetInst().SoundLoad(Dir.GetPlusFileName("BasementBGM.ogg"));//崎榎
			GameEngineResources::GetInst().SoundLoad(Dir.GetPlusFileName("tearfire.wav"));//因維
			GameEngineResources::GetInst().SoundLoad(Dir.GetPlusFileName("plop.wav")); //因維斗霜凶
			GameEngineResources::GetInst().SoundLoad(Dir.GetPlusFileName("explosions.wav"));//賑添斗霜凶
			GameEngineResources::GetInst().SoundLoad(Dir.GetPlusFileName("KeyDrop.wav"));//伸取球遇
			GameEngineResources::GetInst().SoundLoad(Dir.GetPlusFileName("hurtgrunt0.wav"));//焼戚拙戚焼督推1
			GameEngineResources::GetInst().SoundLoad(Dir.GetPlusFileName("hurtgrunt1.wav"));//焼戚拙戚焼督推2
			GameEngineResources::GetInst().SoundLoad(Dir.GetPlusFileName("hurtgrunt2.wav"));//焼戚拙戚焼督推3
			GameEngineResources::GetInst().SoundLoad(Dir.GetPlusFileName("dimepickup.wav"));//疑穿爽崇
			GameEngineResources::GetInst().SoundLoad(Dir.GetPlusFileName("basicbossfight.ogg"));//左什号 崎榎 しし
			GameEngineResources::GetInst().SoundLoad(Dir.GetPlusFileName("Shop.ogg"));//Shop崎榎 しし
			GameEngineResources::GetInst().SoundLoad(Dir.GetPlusFileName("Itemroom.ogg"));//ItemRoom BGM
			GameEngineResources::GetInst().SoundLoad(Dir.GetPlusFileName("doorheavyclose.wav"));//庚戚丸粕推
			GameEngineResources::GetInst().SoundLoad(Dir.GetPlusFileName("doorheavyopen.wav"));//庚戚伸形推
			GameEngineResources::GetInst().SoundLoad(Dir.GetPlusFileName("deathburstsmall3.wav"));//左什宋製
			GameEngineResources::GetInst().SoundLoad(Dir.GetPlusFileName("momfight.ogg"));//左什宋製
			GameEngineResources::GetInst().SoundLoad(Dir.GetPlusFileName("Callisaac.wav")); 
			GameEngineResources::GetInst().SoundLoad(Dir.GetPlusFileName("evillaugh.wav"));
			GameEngineResources::GetInst().SoundLoad(Dir.GetPlusFileName("deathburstsmall2.wav"));
			GameEngineResources::GetInst().SoundLoad(Dir.GetPlusFileName("deathburstsmall1.wav"));
		}
		
		PLAYBGMPLAYER = GameEngineResources::GetInst().SoundPlayToControl("BasementBGM.ogg"); //奄沙壕井製焦
		PLAYBGMPLAYER.Volume(0.05f); 

		PLAYBGMBOSS = GameEngineResources::GetInst().SoundPlayToControl("basicbossfight.ogg"); //左什櫛 塾随凶
		PLAYBGMBOSS.Volume(0.1f);
		PLAYBGMBOSS.PauseOn();

		PLAYBGMSHOP = GameEngineResources::GetInst().SoundPlayToControl("Shop.ogg"); //Shop room拭級嬢亜檎 しし
		PLAYBGMSHOP.Volume(0.1f);
		PLAYBGMSHOP.PauseOn();

		PLAYBGMITEMROOM = GameEngineResources::GetInst().SoundPlayToControl("Itemroom.ogg"); //Item room拭級嬢亜檎 しし
		PLAYBGMITEMROOM.Volume(0.1f);
		PLAYBGMITEMROOM.PauseOn();

		PLAYMOMBOSS = GameEngineResources::GetInst().SoundPlayToControl("momfight.ogg"); //Mom room拭級嬢亜檎 しし
		PLAYMOMBOSS.Volume(0.1f);
		PLAYMOMBOSS.PauseOn();

		
		PlayBool = false;
	}
}