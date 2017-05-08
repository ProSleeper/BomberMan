#include "GameCommon.h"


void GameManager::Init()
{
	mHdc = GetDC(WINMGR->GethWnd());
	IMAGEMGR->LoadImages(mHdc);
	mScreen = IMAGEMGR->GetImage(IMAGETYPE::IT_BACK);
	mBackGround = IMAGEMGR->GetImage(IMAGETYPE::IT_BACKGROUND);
	mBackGround->RenderImage(mScreen->GetMemdc(), 0, 0);
	//mPlayer = new Player;
	//mPlayer->Init(1200, 720, 60, 60, 16, 24, 1);
	

	//OBJECTMGR->CreateObject(mPlayer);
	OBJECTMGR->Init();
	
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
	FPSMGR->Update();
	OBJECTMGR->Update();

	
}

void GameManager::Render()
{
	MapManager::Instance()->Render(mScreen->GetMemdc());
	DebugView();

	OBJECTMGR->Render(mScreen->GetMemdc());
	

	BitBlt(mHdc, 0, 0, SCREENSIZEX, SCREENSIZEY, mScreen->GetMemdc(), 0, 0, SRCCOPY);
}

void GameManager::Release()
{
	DeleteObject(mScreen->GetMemdc());
	ReleaseDC(WINMGR->GethWnd(), mHdc);
}

void GameManager::DebugView()
{

	int x = 10;
	int y = 10;
	char cTextBuffer[128] = {0, 0};
	int numberX = 0;
	int numberY = 0;

	sprintf_s(cTextBuffer, "FPS: %d", FPSMGR->GetFPS());
	TextOut(mScreen->GetMemdc(), 1, 1, cTextBuffer, (int)strlen(cTextBuffer));

	/*for(int x = 0; x < 18; x++)
	{
		for(int y = 0; y < 32; y++)
		{
			sprintf_s(cTextBuffer, "%d, %d", numberX + x, numberY + y);
			TextOut(mScreen->GetMemdc(), y * 60 + 15, x * 60 + 20, cTextBuffer, strlen(cTextBuffer));
		}
		numberY = 0;
	}*/

	//sprintf_s(cTextBuffer, "플레이어 좌표: %d, %d", mPlayer->GetPosX(), mPlayer->GetPosY());
	//TextOut(mScreen->GetMemdc(), x, y += 20, cTextBuffer, strlen(cTextBuffer));
	sprintf_s(cTextBuffer, "오브젝트 숫자: %d", static_cast<int>(OBJECTMGR->GetObjectList().size()));
	TextOut(mScreen->GetMemdc(), x, y += 20, cTextBuffer, static_cast<int>(strlen(cTextBuffer)));
}

GameManager::GameManager()
{
}

GameManager::~GameManager()
{
	Release();
}