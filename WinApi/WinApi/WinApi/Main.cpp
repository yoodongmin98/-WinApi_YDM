#include <Windows.h>
#include <Isaac/IsaacCore.h>




int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	//GetInst>>�̱������θ��� �ھ �θ��� Corestart
	//Corestart>>createwindow+WindowLoop����(global start,update,end)
	IsaacCore::GetInst().CoreStart(hInstance);
	
	return 1;
}