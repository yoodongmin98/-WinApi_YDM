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
			GameEngineResources::GetInst().SoundLoad(Dir.GetPlusFileName("hurtgrunt2.wav"));//아이작이아파요
			GameEngineResources::GetInst().SoundLoad(Dir.GetPlusFileName("dimepickup.wav"));//동전주움
		}
		
		PlayBool = false;
	}
	PLAYBGMPLAYER = GameEngineResources::GetInst().SoundPlayToControl("BasementBGM.ogg");
	PLAYBGMPLAYER.Volume(0.05f); //죽고 메인메뉴로 돌아가는거때문에 아이작이관리 해야되는디.. static이라 귀찬타
}