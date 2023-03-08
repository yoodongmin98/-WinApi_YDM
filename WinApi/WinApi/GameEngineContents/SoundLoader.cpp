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
			GameEngineResources::GetInst().SoundLoad(Dir.GetPlusFileName("BasementBGM.ogg"));//브금
			GameEngineResources::GetInst().SoundLoad(Dir.GetPlusFileName("tearfire.wav"));//공격
			GameEngineResources::GetInst().SoundLoad(Dir.GetPlusFileName("plop.wav")); //공격터질때
			GameEngineResources::GetInst().SoundLoad(Dir.GetPlusFileName("explosions.wav"));//폭탄터질때
			GameEngineResources::GetInst().SoundLoad(Dir.GetPlusFileName("KeyDrop.wav"));//열쇠드랍
			GameEngineResources::GetInst().SoundLoad(Dir.GetPlusFileName("hurtgrunt0.wav"));//아이작이아파요1
			GameEngineResources::GetInst().SoundLoad(Dir.GetPlusFileName("hurtgrunt1.wav"));//아이작이아파요2
			GameEngineResources::GetInst().SoundLoad(Dir.GetPlusFileName("hurtgrunt2.wav"));//아이작이아파요3
			GameEngineResources::GetInst().SoundLoad(Dir.GetPlusFileName("dimepickup.wav"));//동전주움
			GameEngineResources::GetInst().SoundLoad(Dir.GetPlusFileName("basicbossfight.ogg"));//보스방 브금 ㅇㅇ
			GameEngineResources::GetInst().SoundLoad(Dir.GetPlusFileName("Shop.ogg"));//Shop브금 ㅇㅇ
			GameEngineResources::GetInst().SoundLoad(Dir.GetPlusFileName("Itemroom.ogg"));//ItemRoom BGM
			GameEngineResources::GetInst().SoundLoad(Dir.GetPlusFileName("doorheavyclose.wav"));//문이닫혀요
			GameEngineResources::GetInst().SoundLoad(Dir.GetPlusFileName("doorheavyopen.wav"));//문이열려요
			GameEngineResources::GetInst().SoundLoad(Dir.GetPlusFileName("deathburstsmall3.wav"));//보스죽음
			GameEngineResources::GetInst().SoundLoad(Dir.GetPlusFileName("momfight.ogg"));//보스죽음
			GameEngineResources::GetInst().SoundLoad(Dir.GetPlusFileName("Callisaac.wav")); 
			GameEngineResources::GetInst().SoundLoad(Dir.GetPlusFileName("evillaugh.wav"));
			GameEngineResources::GetInst().SoundLoad(Dir.GetPlusFileName("deathburstsmall2.wav"));
			GameEngineResources::GetInst().SoundLoad(Dir.GetPlusFileName("deathburstsmall1.wav"));
		}
		
		PLAYBGMPLAYER = GameEngineResources::GetInst().SoundPlayToControl("BasementBGM.ogg"); //기본배경음악
		PLAYBGMPLAYER.Volume(0.05f); 

		PLAYBGMBOSS = GameEngineResources::GetInst().SoundPlayToControl("basicbossfight.ogg"); //보스랑 싸울때
		PLAYBGMBOSS.Volume(0.1f);
		PLAYBGMBOSS.PauseOn();

		PLAYBGMSHOP = GameEngineResources::GetInst().SoundPlayToControl("Shop.ogg"); //Shop room에들어가면 ㅇㅇ
		PLAYBGMSHOP.Volume(0.1f);
		PLAYBGMSHOP.PauseOn();

		PLAYBGMITEMROOM = GameEngineResources::GetInst().SoundPlayToControl("Itemroom.ogg"); //Item room에들어가면 ㅇㅇ
		PLAYBGMITEMROOM.Volume(0.1f);
		PLAYBGMITEMROOM.PauseOn();

		PLAYMOMBOSS = GameEngineResources::GetInst().SoundPlayToControl("momfight.ogg"); //Mom room에들어가면 ㅇㅇ
		PLAYMOMBOSS.Volume(0.1f);
		PLAYMOMBOSS.PauseOn();

		
		PlayBool = false;
	}
}