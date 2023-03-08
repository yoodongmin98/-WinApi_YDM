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
			GameEngineResources::GetInst().SoundLoad(Dir.GetPlusFileName("BasementBGM.ogg"));//���
			GameEngineResources::GetInst().SoundLoad(Dir.GetPlusFileName("tearfire.wav"));//����
			GameEngineResources::GetInst().SoundLoad(Dir.GetPlusFileName("plop.wav")); //����������
			GameEngineResources::GetInst().SoundLoad(Dir.GetPlusFileName("explosions.wav"));//��ź������
			GameEngineResources::GetInst().SoundLoad(Dir.GetPlusFileName("KeyDrop.wav"));//������
			GameEngineResources::GetInst().SoundLoad(Dir.GetPlusFileName("hurtgrunt0.wav"));//�������̾��Ŀ�1
			GameEngineResources::GetInst().SoundLoad(Dir.GetPlusFileName("hurtgrunt1.wav"));//�������̾��Ŀ�2
			GameEngineResources::GetInst().SoundLoad(Dir.GetPlusFileName("hurtgrunt2.wav"));//�������̾��Ŀ�3
			GameEngineResources::GetInst().SoundLoad(Dir.GetPlusFileName("dimepickup.wav"));//�����ֿ�
			GameEngineResources::GetInst().SoundLoad(Dir.GetPlusFileName("basicbossfight.ogg"));//������ ��� ����
			GameEngineResources::GetInst().SoundLoad(Dir.GetPlusFileName("Shop.ogg"));//Shop��� ����
			GameEngineResources::GetInst().SoundLoad(Dir.GetPlusFileName("Itemroom.ogg"));//ItemRoom BGM
			GameEngineResources::GetInst().SoundLoad(Dir.GetPlusFileName("doorheavyclose.wav"));//���̴�����
			GameEngineResources::GetInst().SoundLoad(Dir.GetPlusFileName("doorheavyopen.wav"));//���̿�����
			GameEngineResources::GetInst().SoundLoad(Dir.GetPlusFileName("deathburstsmall3.wav"));//��������
			GameEngineResources::GetInst().SoundLoad(Dir.GetPlusFileName("momfight.ogg"));//��������
			GameEngineResources::GetInst().SoundLoad(Dir.GetPlusFileName("Callisaac.wav")); 
			GameEngineResources::GetInst().SoundLoad(Dir.GetPlusFileName("evillaugh.wav"));
			GameEngineResources::GetInst().SoundLoad(Dir.GetPlusFileName("deathburstsmall2.wav"));
			GameEngineResources::GetInst().SoundLoad(Dir.GetPlusFileName("deathburstsmall1.wav"));
		}
		
		PLAYBGMPLAYER = GameEngineResources::GetInst().SoundPlayToControl("BasementBGM.ogg"); //�⺻�������
		PLAYBGMPLAYER.Volume(0.05f); 

		PLAYBGMBOSS = GameEngineResources::GetInst().SoundPlayToControl("basicbossfight.ogg"); //������ �οﶧ
		PLAYBGMBOSS.Volume(0.1f);
		PLAYBGMBOSS.PauseOn();

		PLAYBGMSHOP = GameEngineResources::GetInst().SoundPlayToControl("Shop.ogg"); //Shop room������ ����
		PLAYBGMSHOP.Volume(0.1f);
		PLAYBGMSHOP.PauseOn();

		PLAYBGMITEMROOM = GameEngineResources::GetInst().SoundPlayToControl("Itemroom.ogg"); //Item room������ ����
		PLAYBGMITEMROOM.Volume(0.1f);
		PLAYBGMITEMROOM.PauseOn();

		PLAYMOMBOSS = GameEngineResources::GetInst().SoundPlayToControl("momfight.ogg"); //Mom room������ ����
		PLAYMOMBOSS.Volume(0.1f);
		PLAYMOMBOSS.PauseOn();

		
		PlayBool = false;
	}
}