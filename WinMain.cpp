#include "GameCommon.h"



//void Init();
//void Update();
//void Render();
//void Release();

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdParam, int nCmdShow)
{
	WINMGR->CreateWindowManager(hInstance, SCREENSIZEX, SCREENSIZEY, "BomBerMan!");

	GAMEMGR->Init();

	return WINMGR->GameLoop();
}

//void Init()
//{
//	HDC hdc = GetDC(gHwnd);
//	HBITMAP bit;
//
//
//	gDCBack = CreateCompatibleDC(hdc);
//	bit = static_cast<HBITMAP>(LoadImage(nullptr, "back.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE));
//	SelectObject(gDCBack, bit);
//
//	gDCMap = CreateCompatibleDC(hdc);
//	bit = static_cast<HBITMAP>(LoadImage(nullptr, "map.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE));
//	SelectObject(gDCMap, bit);
//
//	gDCplayer = CreateCompatibleDC(hdc);
//	bit = static_cast<HBITMAP>(LoadImage(nullptr, "Player.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE));
//	SelectObject(gDCplayer, bit);
//
//	gDwOldFpsTime = timeGetTime();
//
//	//ReleaseDC(gHwnd, hdc);
//}
//
//void Update()
//{
//	//gDwOldFpsTime = timeGetTime();
//
//	DWORD curCtime = timeGetTime();
//	if (gDwOldLimitTime < curCtime)
//	{
//		gDwOldLimitTime = curCtime + (1000 / 100);
//		if (gDwOldFpsTime < curCtime)
//		{
//			gDwOldFpsTime = curCtime + 1000;
//			giFps = giFpsCount;
//			giFpsCount = 0;
//		}
//		else
//		{
//			giFpsCount++;
//		}
//	}
//	else
//	{
//		return;
//	}
//	
//	const int speed = 6;
//
//	if ((GetKeyState(VK_RIGHT) & 0x8000) == 0x8000)
//	{
//		//VK_RIGHT가 눌렸고 눌리고 있느냐 판독
//		gnPlayerX += speed;
//		if (gnPlayerX > 605)
//		{
//			gnPlayerX -= speed;
//		}
//
//	}
//	else if((GetKeyState(VK_LEFT) & 0x8000) == 0x8000)
//	{
//		//VK_RIGHT가 눌렸고 눌리고 있느냐 판독
//		gnPlayerX -= speed;
//		if(gnPlayerX < 0)
//		{
//			gnPlayerX += speed;
//		}
//
//	}
//	else if((GetKeyState(VK_UP) & 0x8000) == 0x8000)
//	{
//		//VK_RIGHT가 눌렸고 눌리고 있느냐 판독
//		gnPlayerY -= speed;
//		if(gnPlayerY < 0)
//		{
//			gnPlayerY += speed;
//		}
//
//	}
//	else if((GetKeyState(VK_DOWN) & 0x8000) == 0x8000)
//	{
//		//VK_RIGHT가 눌렸고 눌리고 있느냐 판독
//		gnPlayerY += speed;
//		if(gnPlayerY > 700)
//		{
//			gnPlayerY -= speed;
//		}
//	}
//	
//}
//
//void Render()
//{
//	HDC hdc = GetDC(gHwnd);
//
//	BitBlt(gDCBack, 0, 0, 670, 800, gDCMap, 0, 0, SRCCOPY);
//
//	TransparentBlt(gDCBack, gnPlayerX, gnPlayerY, 50, 60, gDCplayer, 0, 0, 35, 39, RGB(0, 0, 255));
//
//
//	char buff[32] = {0};
//	sprintf_s(buff, "Time: %d", gDwOldFpsTime);
//	TextOut(gDCBack, 1, 1, buff, strlen(buff));
//
//	sprintf_s(buff, "FPS: %d", giFps);
//	TextOut(gDCBack, 1, 100, buff, strlen(buff));
//
//	BitBlt(hdc, 0, 0, 670, 800, gDCBack, 0, 0, SRCCOPY);
//	//TransparentBlt(hdc, gnPlayerX, gnPlayerY, 35, 39, gDCplayer, 0, 0, 35, 39, RGB(0, 0, 255));
//
//	
//	ReleaseDC(gHwnd, hdc);
//}
//
//void Release()
//{
//	DeleteObject(gDCplayer);
//}