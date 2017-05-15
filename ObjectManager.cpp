#include "GameCommon.h"
#include "ObjectData.h"

void ObjectManager::Init()
{
	Enemy* mEnemy;

	for (int i = 0; i < 13 ; i++)
	{
		for (int j = 0; j < 17 ; j++)
		{
			if(ObjectData[i][j] == 1)
			{
				box = new Box;
				box->Init(j * TILESIZE + 300, i * TILESIZE + 60, 1);
				CreateObject(box);
				MAPMGR->SetMove(i + 1 , j + 5, false);
			}

			if(arr[i][j] == 10)
			{
				Player *mPlayer = new Player;
				mPlayer->Init(360, 120, 16, 24, 1);
				CreateObject(mPlayer);
			}
			else if(arr[i][j] == 9)
			{
				mEnemy = new Enemy;
				mEnemy->Init(j * TILESIZE + 360, i * TILESIZE + 120, 16, 24, 1);
				arrEnemy[enemyCount++] = mEnemy;
				CreateObject(mEnemy);
			}
		}
	}
	
}
////애니메이션 효과 분명 메모리 버그 나게 되어있음
//적까지 구현한 후 메모리 버그날만한 것들 다 잡기

void ObjectManager::Update()
{
	for (auto iter = mObjectList.begin(); iter != mObjectList.end();)
	{

		if((*iter) == nullptr)
		{
			continue;
		}
		if ((*iter)->GetTag() == OBJECTTAG::TAG_BOMB)
		{
			if (!(IsCrashObject((*iter), mObjectList.back())))
			{
				MAPMGR->SetMove((*iter)->GetPosY() / TILESIZE, (*iter)->GetPosX() / TILESIZE, false);
			}
		}
		else if((*iter)->GetTag() == OBJECTTAG::TAG_EXPLOSION)
		{
			/*if (!(MAPMGR->IsMove((*iter)->GetPosY(), (*iter)->GetPosX())))
			{
			}*/

			if(IsCrashObject((*iter), mObjectList.back()))
			{
 				mObjectList.back()->SetPosX(360);
				mObjectList.back()->SetPosY(120);
			}
			for(int i = 0; i < 3; i++)
			{
				if(arrEnemy[i] == nullptr)
				{
					continue;
				}
				if((arrEnemy[i]->GetPosX() / TILESIZE) == ((*iter)->GetPosX() / TILESIZE)
				   && (arrEnemy[i]->GetPosY() / TILESIZE) == ((*iter)->GetPosY() / TILESIZE))
				{
					mObjectList.remove(arrEnemy[i]);
				}
			}
		}
		if ((*iter) == nullptr)
		{
			continue;;
		}
		if ((*iter)->Update() == false)
		{
			delete (*iter);
			iter = mObjectList.erase(iter);
		}
		else
		{
			iter++;
		}
	}
}

void ObjectManager::Render(HDC backDC)
{
 	//for_each(mObjectList.begin(), mObjectList.end(), [&](BaseImageObject* btf){btf->Render(backDC); });

	for(auto iter = mObjectList.begin(); iter != mObjectList.end(); iter++)
	{
		if (((*iter)->GetTag() != OBJECTTAG::TAG_EXPLOSION) || (MAPMGR->IsMove((*iter)->GetPosY() / TILESIZE, (*iter)->GetPosX() / TILESIZE)))
		{
			(*iter)->Render(backDC);
		}
	}
}

void ObjectManager::Release()
{
}

bool ObjectManager::DistanceExplode(int x, int y)
{
	return false;
}


void ObjectManager::DrawRect(HDC backDC, int x, int y)
{
	/*int temp = SetROP2(backDC, R2_MASKPEN);
	Rectangle(backDC, x , y, x + TILESIZE, y + TILESIZE);
	SetROP2(backDC, temp);*/
}

void ObjectManager::CreateObject(BaseImageObject* pObj)
{


	/*for(auto iter = mBombList.begin(); iter != mBombList.end(); iter++)
	{
		for(auto jter = mHudleList.begin(); jter != mHudleList.end(); jter++)
		{

		}
	}*/

	for(auto iter = mObjectList.begin(); iter != mObjectList.end(); ++iter)
	{
		if(pObj->GetTag() == OBJECTTAG::TAG_EXPLOSION)
		{
			if((pObj->GetPosX() / TILESIZE) == ((*iter)->GetPosX() / TILESIZE)
			   && (pObj->GetPosY() / TILESIZE) == ((*iter)->GetPosY() / TILESIZE) && (*iter)->GetTag() == OBJECTTAG::TAG_BOMB)
			{
				Bomb* temp = dynamic_cast<Bomb*>(*iter);
				temp->TimeBomb();
			}
			else if((pObj->GetPosX() / TILESIZE) == ((*iter)->GetPosX() / TILESIZE)
					&& (pObj->GetPosY() / TILESIZE) == ((*iter)->GetPosY() / TILESIZE) && (*iter)->GetTag() == OBJECTTAG::TAG_BOX)
			{
				Box* temp = dynamic_cast<Box*>(*iter);

				temp->DestroyBox();

			}
		}
		else if((*iter)->GetTag() == OBJECTTAG::TAG_BOMB && pObj->GetTag() == OBJECTTAG::TAG_BOMB && ((pObj->GetPosX() / TILESIZE) == ((*iter)->GetPosX() / TILESIZE)
																									  && (pObj->GetPosY() / TILESIZE) == ((*iter)->GetPosY() / TILESIZE)))
		{
			delete pObj;
			return;
		}
	}

	mObjectList.push_front(pObj);
}

void ObjectManager::CreateBomb(BaseImageObject * pObj)
{
	mBombList.push_front(pObj);
}

void ObjectManager::DeleteObject()
{
	
}

bool ObjectManager::GetTag(int x, int y)
{
	return false;
}

bool ObjectManager::IsCrashObject(BaseTransform* lhs, BaseTransform* rhs)
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

ObjectManager::ObjectManager()
{
}

ObjectManager::~ObjectManager()
{
}
