#include "GameCommon.h"



void CollisionManager::CreateCollider(BaseTransform * pTarget)
{
	BaseCollObject* pCollObj = new BaseCollObject;
	pCollObj->Init(pTarget);
	mCollObj.push_back(pCollObj);
}

void CollisionManager::Update()
{
	for_each(mCollObj.begin(), mCollObj.end(), [](BaseCollObject* bco){bco->Update(); });

	for(auto iter = mCollObj.begin(); iter != mCollObj.end(); iter++)
	{
		auto nextIter = iter;
		nextIter++;

		for(nextIter; nextIter != mCollObj.end(); nextIter++)
		{

			//이 부분을 나한테 맞게 바꿔야할듯
			if (IsCollision((*iter), (*nextIter)) && GetCollTag((*iter)->GetTarget()->GetTag(), (*nextIter)->GetTarget()->GetTag()))
			{
				//충돌처리
				/*BaseImageObject* pSrc = (BaseImageObject*)(*iter)->GetTarget();
				BaseImageObject* pDest = (BaseImageObject*)(*nextIter)->GetTarget();*/

				BaseImageObject* pSrc = dynamic_cast<BaseImageObject*>((*iter)->GetTarget());
				BaseImageObject* pDest = dynamic_cast<BaseImageObject*>((*nextIter)->GetTarget());
				pSrc->OnCollisionEnter(pDest);
				pDest->OnCollisionEnter(pSrc);
			}
		}

	}

}

void CollisionManager::Render(HDC backDC)
{
	for_each(mCollObj.begin(), mCollObj.end(), [&](BaseCollObject* bco){bco->Render(backDC); });
}

void CollisionManager::Release()
{
	for_each(mCollObj.begin(), mCollObj.end(), [&](BaseCollObject* bco){delete bco; });
	mCollObj.clear();
}

void CollisionManager::DeleteCollider(BaseTransform * pTarget)
{
	for(auto iter = mCollObj.begin(); iter != mCollObj.end();)
	{
		if((*iter)->GetTarget() == pTarget)
		{
			delete (*iter);
			iter = mCollObj.erase(iter);
		}
		else
		{
			iter++;
		}
	}
}

bool CollisionManager::IsCollision(BaseCollObject * pSrc, BaseCollObject * pDest)
{
	if ((pSrc->GetPosX() + pSrc->GetWidth()) < pDest->GetPosX())
	{
		return false;
	}

	if ((pDest->GetPosX() + pDest->GetWidth()) < pSrc->GetPosX())
	{
		return false;
	}

	if((pDest->GetPosY() + pDest->GetHeight()) < pSrc->GetPosY())
	{
		return false;
	}

	if((pSrc->GetPosY() + pSrc->GetHeight()) < pDest->GetPosY())
	{
		return false;
	}

	return true;
}

bool CollisionManager::GetCollTag(OBJECTTAG pSrc, OBJECTTAG pTarget)
{
	return collTag[static_cast<int>(pSrc)][static_cast<int>(pTarget)];
}

void CollisionManager::SetCollTag(OBJECTTAG pSrc, OBJECTTAG pTarget, bool value, bool setBoth)
{
	collTag[static_cast<int>(pSrc)][static_cast<int>(pTarget)] = value;
	if (setBoth)
	{
		collTag[static_cast<int>(pTarget)][static_cast<int>(pSrc)] = value;
	}
}

bool CollisionManager::RePosCheck(BaseTransform* pTarget)
{
	if (pTarget->GetPosX() > ScreenSizeX - pTarget->GetWidth())
	{
		return false;
	}
	
	for(auto iter = mCollObj.begin(); iter != mCollObj.end(); iter++)
	{
		BaseCollObject* pObj = (BaseCollObject*)pTarget;
		if (IsCollision(pObj, (*iter)) == true)
		{
			return false;
		}
	}
	return true;
}

CollisionManager::CollisionManager()
{
	mCollObj.clear();
	for(int i = 0; i < static_cast<int>(OBJECTTAG::TAG_MAX); i++)
	{
		for(int j = 0; j < static_cast<int>(OBJECTTAG::TAG_MAX); j++)
		{
			collTag[i][j] = true;
		}
	}

	SetCollTag(OBJECTTAG::TAG_PLAYER, OBJECTTAG::TAG_PLAYER_BULLET, false);
	SetCollTag(OBJECTTAG::TAG_ENEMY, OBJECTTAG::TAG_ENEMY, false);
	SetCollTag(OBJECTTAG::TAG_PLAYER_BULLET, OBJECTTAG::TAG_PLAYER_BULLET, false);
	SetCollTag(OBJECTTAG::TAG_ENEMY, OBJECTTAG::TAG_ENEMY_BULLET, false);
	SetCollTag(OBJECTTAG::TAG_BOSS, OBJECTTAG::TAG_ENEMY_BULLET, false);
	//SetCollTag(OBJECTTAG::TAG_PLAYER, OBJECTTAG::TAG_ENEMY_BULLET, false, false);
}


CollisionManager::~CollisionManager()
{
	Release();
}
