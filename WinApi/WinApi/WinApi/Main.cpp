#include <Windows.h>
#include <Isaac/IsaacCore.h>




int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	//GetInst>>싱글톤으로만든 코어를 부르고 Corestart
	//Corestart>>createwindow+WindowLoop실행(global start,update,end)
	IsaacCore::GetInst().CoreStart(hInstance);
	
	return 1;
}