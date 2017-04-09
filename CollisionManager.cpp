#include "GameCommon.h"



void CollisionManager::CreateCollider(BaseTransform * pTarget)
{
	int x = pTarget->GetPosY() / TILESIZE;
	int y = pTarget->GetPosX() / TILESIZE;/*
	if(mObjectVector[x][y] != nullptr && mObjectVector[x][y]->GetTag() != OBJECTTAG::TAG_BOMB)
	{
		delete mObjectVector[x][y];
	}*/
	mObjectVector[x][y] = pTarget;
}

void CollisionManager::Update()
{
	//for_each(mListObject.begin(), mListObject.end(), [](BaseImageObject* btf){btf->Update(); });
	for(int x = 0; x < TILECOUNTX; x++)
	{
		for(int y = 0; y < TILECOUNTY; y++)
		{
			if(mObjectVector[x][y] != nullptr)
			{
				//bool update = mObjectVector[x][y]->Update();

				/*if((!update) && mObjectVector[x][y]->GetTag() == OBJECTTAG::TAG_BOMB)
				{
					Explosion * explosion = new Explosion;
					explosion->Init(mObjectVector[x][y]->GetPosX(), mObjectVector[x][y]->GetPosY(), TILESIZE, TILESIZE, 0, 0, 0);
					delete mObjectVector[x][y];
					mObjectVector[x][y] = explosion;
				}
				else if(!update)
				{
					delete mObjectVector[x][y];
					mObjectVector[x][y] = nullptr;
				}*/
			}
			/*bool update = mListObject[x][y]->Update();

			if((!update) && mListObject[x][y]->GetTag() == OBJECTTAG::TAG_BOMB)
			{
			Explosion * explosion = new Explosion;
			explosion->Init(mListObject[x][y]->GetPosX(), mListObject[x][y]->GetPosY(), TileSize, TileSize, 0, 0, 0);
			delete mListObject[x][y];
			mListObject[x][y] = explosion;
			}
			else if((!update))
			{
			delete mListObject[x][y];
			mListObject[x][y] = mBackObject[x][y];
			mBackObject[x][y] = nullptr;
			}*/

		}
	}
}

void CollisionManager::Render(HDC backDC)
{
	/*for(int x = 1; x < TILECOUNTX - 1; x++)
	{
		for(int y = 5; y < TILECOUNTY - 5; y++)
		{
			if(mObjectVector[x][y] != nullptr)
			{
				mObjectVector[x][y]->Render(backDC);
			}
		}
	}*/
}

void CollisionManager::Release()
{
	
}

void CollisionManager::DeleteCollider(BaseTransform * pTarget)
{


}

CollisionManager::CollisionManager()
{
	mObjectVector.assign(TILECOUNTX, vector<BaseTransform*>(TILECOUNTY));
}


CollisionManager::~CollisionManager()
{
	Release();
}
