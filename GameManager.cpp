#include "GameCommon.h"
random_device rd;

void GameManager::Init()
{
	mHdc = GetDC(WINMGR->GethWnd());
	IMAGEMGR->LoadImages(mHdc);
	mBackImg = IMAGEMGR->GetImage(IMAGEBIT::OBJ_BACK);

	//mMap.Init(ScreenSizeX / 2, ScreenSizeY / 2, 50, 50,/**/ 17, 14, 16, 16, IMAGEBIT::OBJ_MAP);
	//mMap2.Init(ScreenSizeX / 2 - 50, ScreenSizeY / 2, 50, 50,/**/ 34, 14, 16, 16, IMAGEBIT::OBJ_MAP);

	//mBomb.Init(ScreenSizeX / 2, ScreenSizeY / 2, 50, 50,/**/ 34, 48, 16, 16, IMAGEBIT::OBJ_MAP);
	
	//mPlayer.Init(ScreenSizeX / 2, ScreenSizeY / 2, 90, 90,/**/ 0, 0, 68, 68, IMAGEBIT::ACTOR_PLAYER);
	
}

void GameManager::Loop()
{
	if (FPSMGR->LimitFps() == false)
	{
		return;
	}

	Update();
	Render();
}	

void GameManager::Update()
{
	//FPSMGR->Update();
	//mPlayer.Update();
}

void GameManager::Render()
{
	/*RECT rect;
	rect.left = 0;
	rect.top = 0;
	rect.right = ScreenSizeX;
	rect.bottom = ScreenSizeY;*/
	//FillRect(mBackImg->GetMemdc(), &rect, GetSysColorBrush(COLOR_WINDOW));

	//mMap.Render(mBackImg->GetMemdc());
	//mMap2.Render(mBackImg->GetMemdc());
	//mBomb.Render(mBackImg->GetMemdc());
	//mPlayer.Render(mBackImg->GetMemdc());

	

	

	//어떠한 정보 표시할때 쓰면 됨
	//DebugView();
	
	BitBlt(mHdc, 0, 0, ScreenSizeX, ScreenSizeY, mBackImg->GetMemdc(), 0, 0, SRCCOPY);
}

void GameManager::Release()
{
	DeleteObject(mHbackDc);
	ReleaseDC(WINMGR->GethWnd(), mHdc);
}

void GameManager::DebugView()
{
	char buff[32] = {0};
	sprintf_s(buff, "FPS: %d", FPSMGR->GetFPS());
	TextOut(mBackImg->GetMemdc(), 1, 1, buff, strlen(buff));
	/*int x = 10;
	int y = 10;
	char cTextBuffer[128] = {0,};

	sprintf_s(cTextBuffer, "<총알정보>");
	TextOut(mHbackDc, x, y += 20, cTextBuffer, strlen(cTextBuffer));

	LISTBULLETS* listBullet = mPlayer.GetBullets();
	int iCount = 0;
	for(BULLETITOR iter = listBullet->begin(); iter != listBullet->end(); iter++)
	{
		iCount++;
		sprintf_s(cTextBuffer, "%d 번째: (%d , %d)", iCount, (*iter)->GetpPos().x, (*iter)->GetpPos().y);
		TextOut(mHbackDc, x, y += 20, cTextBuffer, strlen(cTextBuffer));
	}*/

}

GameManager::GameManager()
{
}

GameManager::~GameManager()
{
	Release();
}