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
		}
		
		PLAYBGMPLAYER = GameEngineResources::GetInst().SoundPlayToControl("BasementBGM.ogg"); //기본배경음악
		PLAYBGMPLAYER.Volume(0.05f); 

		PLAYBGMBOSS = GameEngineResources::GetInst().SoundPlayToControl("basicbossfight.ogg"); //보스랑 싸울때
		PLAYBGMBOSS.Volume(0.1f);
		PLAYBGMBOSS.PauseOn();

		PLAYBGMSHOP = GameEngineResources::GetInst().SoundPlayToControl("Shop.ogg"); //Shop room에들어가면 ㅇㅇ
		PLAYBGMSHOP.Volume(0.1f);
		PLAYBGMSHOP.PauseOn();

		PLAYBGMITEMROOM = GameEngineResources::GetInst().SoundPlayToControl("Itemroom.ogg"); //Shop room에들어가면 ㅇㅇ
		PLAYBGMITEMROOM.Volume(0.1f);
		PLAYBGMITEMROOM.PauseOn();

		PlayBool = false;
	}
}