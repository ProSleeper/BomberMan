#include "GameCommon.h"
random_device rd;

void GameManager::Init()
{
	mHdc = GetDC(WINMGR->GethWnd());
	IMAGEMGR->LoadImages(mHdc);
	mGround = IMAGEMGR->GetImage(IMAGETYPE::IT_BACK);
	mAnimation = new PlayerAnimation(IMAGETYPE::IT_SPRITE);
	mAnimation->Init(0, 0, 64, 64, 128, 64, 0.5);
	
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
	mAnimation->Update();
	

	//플레이어 좌표 얻기
	/*pPointX = mPlayer->GetPosX();
	pPointY = mPlayer->GetPosY();*/

}

void GameManager::Render()
{
	MapManager::Instance()->Render(mGround->GetMemdc());
	mAnimation->Render(mGround->GetMemdc());
	DebugView();

	BitBlt(mHdc, 0, 0, ScreenSizeX, ScreenSizeY, mGround->GetMemdc(), 0, 0, SRCCOPY);
	
}

void GameManager::Release()
{
	DeleteObject(mGround->GetMemdc());
	ReleaseDC(WINMGR->GethWnd(), mHdc);
}

void GameManager::DebugView()
{
	int x = 10;
	int y = 10;
	char cTextBuffer[128] = {0,};

	sprintf_s(cTextBuffer, "FPS: %d", FPSMGR->GetFPS());
	TextOut(mGround->GetMemdc(), 1, 1, cTextBuffer, (int)strlen(cTextBuffer));

	/*sprintf_s(buff, "플레이어 좌표: %d, %d", mAnimation->GetpPos().x, mAnimation->GetpPos().y);
	TextOut(mBackImg->GetMemdc(), 1, y += 20, buff, strlen(buff));*/

	/*sprintf_s(cTextBuffer, "<총알정보>");
	TextOut(mpBack->GetMemdc(), x, y += 20, cTextBuffer, strlen(cTextBuffer));*/

	//LISTBULLETS* listBullet = mPlayer.GetBullets();
	/*int iCount = 0;
	for(BULLETITOR iter = listBullet->begin(); iter != listBullet->end(); iter++)
	{
		iCount++;
		sprintf_s(cTextBuffer, "%d 번째: (%d , %d)", iCount, (*iter)->GetpPos().x, (*iter)->GetpPos().y);
		TextOut(mpBack->GetMemdc(), x, y += 20, cTextBuffer, strlen(cTextBuffer));
	}*/

	/*sprintf_s(cTextBuffer, "Explosion Info");
	TextOut(mpBack->GetMemdc(), x, y += 20, cTextBuffer, strlen(cTextBuffer));

	sprintf_s(cTextBuffer, " TotalTime(%d), FrameX(%d), FrameY(%d)", mExplosion.GetTotalTime(), mExplosion.GetFrameX(), mExplosion.GetFrameY());
	TextOut(mpBack->GetMemdc(), x, y += 20, cTextBuffer, strlen(cTextBuffer));

	sprintf_s(cTextBuffer, " CurTime(%d), CurFrame(%d), CurX(%d), CurY(%d)", mExplosion.GetCurTime(), mExplosion.GetCurFrame(), mExplosion.GetCurFrameX(), mExplosion.GetCurFrameY());
	TextOut(mpBack->GetMemdc(), x, y += 20, cTextBuffer, strlen(cTextBuffer));*/

}

void GameManager::CreateObject(BaseTransform * pObj, bool bColl)
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
				COLLMGR->DeleteCollider((*iter));
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

GameManager::GameManager()
{
}

GameManager::~GameManager()
{
	Release();
}