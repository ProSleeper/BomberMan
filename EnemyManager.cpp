#include "GameCommon.h"

void EnemyManager::Init()
{
}

void EnemyManager::Update()
{
	
	
}

void EnemyManager::DeleteEnemy(BaseTransform * pTarget)
{
	for(auto iter = mListEnemy.begin(); iter != mListEnemy.end();)
	{
		if ((*iter) == pTarget)
		{
			iter = mListEnemy.erase(iter);
		}
		else
		{
			iter++;
		}
	}
}
	
void EnemyManager::CreateEnemy(int x, int y, BaseImageObject* pObj, bool coll)
{
	miTotalEnemyCount++;
	while (true)
	{
		if (COLLMGR->RePosCheck(pObj))
		{
			break;
		}
		else
		{
			int rndX = rand() % ScreenSizeX;
			pObj->SetPosX(static_cast<float>(rndX));
		}
	}

	GAMEMGR->CreateObject(pObj, coll);
	mListEnemy.push_back(pObj);
}

EnemyManager::EnemyManager()
{
	miTotalEnemyCount = 0;
}

EnemyManager::~EnemyManager()
{
}
