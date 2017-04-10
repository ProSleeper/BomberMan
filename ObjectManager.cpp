#include "GameCommon.h"


void ObjectManager::Init()
{
	for(int y = 4; y < 12; y += 2)
	{
		for(int x = 7; x < 21; x += 2)
		{
			box = new Box;
			box->Init(x * TILESIZE, y * TILESIZE, 60, 60, 60, 60, 1);
			CreateObject(box);
			MAPMGR->SetMove(y, x, false);
		}
	}
}
////애니메이션 효과 분명 메모리 버그 나게 되어있음
//적까지 구현한 후 메모리 버그날만한 것들 다 잡기

void ObjectManager::Update()
{
	//for_each(mObjectList.begin(), mObjectList.end(), [&](BaseImageObject* btf){btf->Update(); });
	
	for (auto iter = mObjectList.begin(); iter != mObjectList.end();)
	{

		if ((*iter)->GetTag() == OBJECTTAG::TAG_BOMB)
		{
			if (!(GAMEMGR->IsCrashObject((*iter), mObjectList.back())))
			{
				MAPMGR->SetMove((*iter)->GetPosY() / TILESIZE, (*iter)->GetPosX() / TILESIZE, false);
			}
		}
		else if((*iter)->GetTag() == OBJECTTAG::TAG_EXPLOSION)
		{
			if(GAMEMGR->IsCrashObject((*iter), mObjectList.back()))
			{
				mObjectList.back()->SetPosX(360);
				mObjectList.back()->SetPosY(120);
			}
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
 	for_each(mObjectList.begin(), mObjectList.end(), [&](BaseImageObject* btf){btf->Render(backDC); });
}

void ObjectManager::Release()
{
}

bool ObjectManager::DistanceExplode(int x, int y)
{
	return false;
}

void ObjectManager::CreateObject(BaseImageObject* pObj)
{

	if (pObj->GetTag() == OBJECTTAG::TAG_EXPLOSION)
	{
		for(auto iter = mObjectList.begin(); iter != mObjectList.end();)
		{
			if((pObj->GetPosX() / TILESIZE) == ((*iter)->GetPosX() / TILESIZE)
			   && (pObj->GetPosY() / TILESIZE) == ((*iter)->GetPosY() / TILESIZE) && (*iter)->GetTag() == OBJECTTAG::TAG_BOMB)
			{
				Bomb* temp = dynamic_cast<Bomb*>(*iter);

				temp->TimeBomb();
				iter++;
			}
			else if((pObj->GetPosX() / TILESIZE) == ((*iter)->GetPosX() / TILESIZE)
					&& (pObj->GetPosY() / TILESIZE) == ((*iter)->GetPosY() / TILESIZE) && (*iter)->GetTag() == OBJECTTAG::TAG_BOX)
			{
				Box* temp = dynamic_cast<Box*>(*iter);

				temp->DestroyBox();
				iter++;
			}
			else
			{
				iter++;
			}

		}
	}
	
	mObjectList.push_front(pObj);

	//COLLMGR->CreateCollider(pObj);
}

void ObjectManager::DeleteObject()
{
	
}

bool ObjectManager::GetTag(int x, int y)
{
	return false;
}

ObjectManager::ObjectManager()
{
}

ObjectManager::~ObjectManager()
{
}
