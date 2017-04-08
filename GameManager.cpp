#include "GameCommon.h"
random_device rd;

void GameManager::Init()
{
	mHdc = GetDC(WINMGR->GethWnd());
	IMAGEMGR->LoadImages(mHdc);
	mBackGround = IMAGEMGR->GetImage(IMAGETYPE::IT_BACK);
	MapManager::Instance();

	mPlayer = new Player(IMAGETYPE::IT_PLAYER);
	mPlayer->Init(360, 120, 60, 60, 16, 24, 1);
	//OBJECTMGR->CreateObject(mPlayer);
	//COLLMGR->CreateCollider(mPlayer);

	ObjectSetting();
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
	mPlayer->Update();
	//COLLMGR->Update();
	
	//플레이어 좌표 얻기
	/*pPointX = mPlayer->GetPosX();
	pPointY = mPlayer->GetPosY();*/
}

void GameManager::Render()
{
	MapManager::Instance()->Render(mBackGround->GetMemdc());

	OBJECTMGR->Render(mBackGround->GetMemdc());
	DebugView();
	
	mPlayer->Render(mBackGround->GetMemdc());
	//COLLMGR->Render(mBackGround->GetMemdc());

	BitBlt(mHdc, 0, 0, ScreenSizeX, ScreenSizeY, mBackGround->GetMemdc(), 0, 0, SRCCOPY);
	
}

void GameManager::Release()
{
	DeleteObject(mBackGround->GetMemdc());
	ReleaseDC(WINMGR->GethWnd(), mHdc);
}

void GameManager::DebugView()
{
	
	int x = 10;
	int y = 10;
	char cTextBuffer[128] = {0,};
	int numberX = 0;
	int numberY = 0;

	sprintf_s(cTextBuffer, "FPS: %d", FPSMGR->GetFPS());
	TextOut(mBackGround->GetMemdc(), 1, 1, cTextBuffer, (int)strlen(cTextBuffer));

	for(int x = 0; x < 18; x++)
	{
		for(int y = 0; y < 32; y++)
		{
			sprintf_s(cTextBuffer, "%d, %d", numberX + x, numberY + y);
			TextOut(mBackGround->GetMemdc(), y * 60 + 15, x * 60 + 20, cTextBuffer, strlen(cTextBuffer));
		}
		numberY = 0;
	}

	sprintf_s(cTextBuffer, "플레이어 좌표: %d, %d", mPlayer->GetpPos().x, mPlayer->GetpPos().y);
	TextOut(mBackGround->GetMemdc(), x, y += 20, cTextBuffer, strlen(cTextBuffer));
	

	/*sprintf_s(cTextBuffer, "<총알정보>");
	TextOut(mpBack->GetMemdc(), x, y += 20, cTextBuffer, strlen(cTextBuffer));*/

	//LISTBULLETS* listBullet = mPlayer.GetBullets();
	/*int iCount = 0;
	for(BULLETITOR iter = listBullet->begin(); iter != listBullet->end(); iter++)
	{
		iCount++;
		sprintf_s(cTextBuffer, "%d 번째: (%d , %d)", iCount, (*iter)->GetpPos().x, (*iter)->GetpPos().y);x
		TextOut(mpBack->GetMemdc(), x, y += 20, cTextBuffer, strlen(cTextBuffer));
	}*/

	/*sprintf_s(cTextBuffer, "Explosion Info");
	TextOut(mpBack->GetMemdc(), x, y += 20, cTextBuffer, strlen(cTextBuffer));

	sprintf_s(cTextBuffer, " TotalTime(%d), FrameX(%d), FrameY(%d)", mExplosion.GetTotalTime(), mExplosion.GetFrameX(), mExplosion.GetFrameY());
	TextOut(mpBack->GetMemdc(), x, y += 20, cTextBuffer, strlen(cTextBuffer));

	sprintf_s(cTextBuffer, " CurTime(%d), CurFrame(%d), CurX(%d), CurY(%d)", mExplosion.GetCurTime(), mExplosion.GetCurFrame(), mExplosion.GetCurFrameX(), mExplosion.GetCurFrameY());
	TextOut(mpBack->GetMemdc(), x, y += 20, cTextBuffer, strlen(cTextBuffer));*/

}

void GameManager::ObjectSetting()
{
	for(int y = 1; y < 14; y++)
	{
		OBJECTMGR->ChangeObject(y, 5, 35, 49, false);
		OBJECTMGR->ChangeObject(y, 21, 35, 49, false);
	}

	for(int x = 6; x < 21; x++)
	{
		OBJECTMGR->ChangeObject(1, x, 35, 49, false);
		OBJECTMGR->ChangeObject(13, x, 35, 49, false);
	}

	for(int y = 3; y < 13; y+=2)
	{
		for(int x = 7; x < 21; x+=2)
		{
			OBJECTMGR->ChangeObject(y, x, 35, 32, false);
			OBJECTMGR->ChangeObject(y + 1, x, 52, 32);
		}
	}
}

//void GameManager::ObjectSetting()
//{
//	int x = MAPMGR->GetIdx(1, 0).GetPosX();
//	int y = MAPMGR->GetIdx(1, 0).GetPosY();
//
//	for(int x = 0; x < 17; x++)
//	{
//		mWall = new Wall;
//		mWall->Init(x * 60 + 300, 60, 60, 60, 35, 49, 16, 16, IMAGETYPE::IT_OBJECT);
//
//		OBJECTMGR->CreateObject(mWall);
//		COLLMGR->CreateCollider(mPlayer);
//
//		mWall = new Wall;
//		mWall->Init(x * 60 + 300, 780, 60, 60, 35, 49, 16, 16, IMAGETYPE::IT_OBJECT);
//		OBJECTMGR->CreateObject(mWall);
//		COLLMGR->CreateCollider(mPlayer);
//	}
//
//	for(int y = 0; y < 11; y++)
//	{
//		mWall = new Wall;
//		mWall->Init(300, y * 60 + 120, 60, 60, 35, 49, 16, 16, IMAGETYPE::IT_OBJECT);
//		OBJECTMGR->CreateObject(mWall);
//		COLLMGR->CreateCollider(mPlayer);
//		mWall = new Wall;
//		mWall->Init(1260, y * 60 + 120, 60, 60, 35, 49, 16, 16, IMAGETYPE::IT_OBJECT);
//		OBJECTMGR->CreateObject(mWall);
//		COLLMGR->CreateCollider(mPlayer);
//	}
//
//	/*for(int i = 0; i < 10; i+=2)
//	{
//		for(int j = 0; j < 14; j+=2)
//		{
//			mWall = new Wall;
//			mWall->Init(j * 60 + 420, i * 60 + 180, 60, 60, 35, 32, 16, 16, IMAGETYPE::IT_OBJECT);
//			OBJECTMGR->CreateObject(mWall);
//			COLLMGR->CreateCollider(mPlayer);
//
//			mWall = new Wall;
//			mWall->Init(j * 60 + 420, i * 60 + 240, 60, 60, 52, 32, 16, 16, IMAGETYPE::IT_OBJECT);
//			OBJECTMGR->CreateObject(mWall);
//			COLLMGR->CreateCollider(mPlayer);
//
//		}
//	}*/
//}

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