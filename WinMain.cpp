#include "GameCommon.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdParam, int nCmdShow)
{
	WINMGR->CreateWindowManager(hInstance,ScreenSizeX, ScreenSizeY, "BomBerMan!");

	GAMEMGR->Init();

	return WINMGR->GameLoop();
}