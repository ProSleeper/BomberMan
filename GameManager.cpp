#include "GameCommon.h"


void GameManager::Init()
{
	mHdc = GetDC(WINMGR->GethWnd());
	IMAGEMGR->LoadImages(mHdc);
	mScreen = IMAGEMGR->GetImage(IMAGETYPE::IT_BACK);
	mBackGround = IMAGEMGR->GetImage(IMAGETYPE::IT_BACKGROUND);
	mBackGround->RenderImage(mScreen->GetMemdc(), 0, 0);
	mPlayer = new Player;
	mPlayer->Init(1200, 720, 60, 60, 16, 24, 1);
	mEnemy = new Enemy;
	mEnemy->Init(360, 120, 60, 60, 16, 24, 1);

	OBJECTMGR->CreateObject(mPlayer);
	OBJECTMGR->CreateObject(mEnemy);
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
	COLLMGR->Update();

	
}

void GameManager::Render()
{
	MapManager::Instance()->Render(mScreen->GetMemdc());
	DebugView();

	OBJECTMGR->Render(mScreen->GetMemdc());
	COLLMGR->Render(mScreen->GetMemdc());
	

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

	sprintf_s(cTextBuffer, "플레이어 좌표: %d, %d", mPlayer->GetPosX(), mPlayer->GetPosY());
	TextOut(mScreen->GetMemdc(), x, y += 20, cTextBuffer, strlen(cTextBuffer));
	sprintf_s(cTextBuffer, "오브젝트 숫자: %d", OBJECTMGR->mObjectList.size());
	TextOut(mScreen->GetMemdc(), x, y += 20, cTextBuffer, strlen(cTextBuffer));
}

void GameManager::CreateObject(BaseImageObject * pObj, bool bColl)
{
	mListObjects.push_back(pObj);
	if (bColl)
	{
		pObj->SetCollider(true);
		COLLMGR->CreateCollider(pObj);
	}
}

void GameManager::DeleteObjectCheck()
{
	for(auto iter = mListObjects.begin(); iter != mListObjects.end();)
	{
		BaseTargetObject* pObj = (BaseTargetObject*)(*iter);

		if (pObj->GetLife() == false)
		{
			ENEMYMGR->DeleteEnemy((*iter));

			if (pObj->GetCollider() == true)
			{
				//COLLMGR->DeleteCollider((*iter));
			}
			
   			delete pObj;
			iter = mListObjects.erase(iter);
		}
		else
		{
			iter++;
		}
	}
}

bool GameManager::IsCrashObject(BaseTransform* lhs, BaseTransform* rhs)
{
	mRect1.left = lhs->GetPosX();
	mRect1.top = lhs->GetPosY();
	mRect1.right = lhs->GetPosX() + lhs->GetWidth();
	mRect1.bottom = lhs->GetPosY() + lhs->GetHeight();

	mRect2.left = rhs->GetPosX();
	mRect2.top = rhs->GetPosY();
	mRect2.right = rhs->GetPosX() + rhs->GetWidth();
	mRect2.bottom = rhs->GetPosY() + rhs->GetHeight();


	return IntersectRect(&mRect1, &mRect1, &mRect2);
}

GameManager::GameManager()
{
}

GameManager::~GameManager()
{
	Release();
}