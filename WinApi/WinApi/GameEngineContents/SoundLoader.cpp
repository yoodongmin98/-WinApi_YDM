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
			GameEngineResources::GetInst().SoundLoad(Dir.GetPlusFileName("hurtgrunt2.wav"));//�������̾��Ŀ�
			GameEngineResources::GetInst().SoundLoad(Dir.GetPlusFileName("dimepickup.wav"));//�����ֿ�
		}
		
		PlayBool = false;
	}
	PLAYBGMPLAYER = GameEngineResources::GetInst().SoundPlayToControl("BasementBGM.ogg");
	PLAYBGMPLAYER.Volume(0.05f); //�װ� ���θ޴��� ���ư��°Ŷ����� �������̰��� �ؾߵǴµ�.. static�̶� ����Ÿ
}