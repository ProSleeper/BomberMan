#include "GameCommon.h"


void ObjectManager::Init()
{
	Enemy* mEnemy = new Enemy;

	/*for(int y = 4; y < 12; y += 2)
	{
		for(int x = 7; x < 21; x += 2)
		{
			box = new Box;
			box->Init(x * TILESIZE, y * TILESIZE, 60, 60, 60, 60, 1);
			CreateObject(box);
			MAPMGR->SetMove(y, x, false);
		}
	}*/
	/*Player *mPlayer = new Player;
	mPlayer->Init(360, 120, 60, 60, 16, 24, 1);
	CreateObject(mPlayer);*/
	for (int i = 0; i < 11 ; i++)
	{
		for (int j = 0; j < 15 ; j++)
		{
			if(arr[i][j] == 1)
			{
				box = new Box;
				box->Init(j * TILESIZE + 360, i * TILESIZE + 120, 60, 60, 60, 60, 1);
				CreateObject(box);
				MAPMGR->SetMove(i + 2 , j + 6, false);
			}
			else if(arr[i][j] == 10)
			{
				Player *mPlayer = new Player;
				mPlayer->Init(360, 120, 60, 60, 16, 24, 1);
				CreateObject(mPlayer);
			}
			else if(arr[i][j] == 9)
			{
				mEnemy = new Enemy;
				mEnemy->Init(j * TILESIZE + 360, i * TILESIZE + 120, 60, 60, 16, 24, 1);
				arrEnemy[enemyCount++] = mEnemy;
				CreateObject(mEnemy);
			}
		}
	}
	
	/*Player *mPlayer = new Player;
	mPlayer->Init(1200, 720, 60, 60, 16, 24, 1);

	mEnemy = new Enemy;
	mEnemy->Init(600, 300, 60, 60, 16, 24, 1);
	CreateObject(mEnemy);
	mEnemy = new Enemy;
	mEnemy->Init(480, 480, 60, 60, 16, 24, 1);
	CreateObject(mEnemy);
	mEnemy = new Enemy;
	mEnemy->Init(600, 660, 60, 60, 16, 24, 1);
	CreateObject(mEnemy);*/
	
}
////애니메이션 효과 분명 메모리 버그 나게 되어있음
//적까지 구현한 후 메모리 버그날만한 것들 다 잡기

void ObjectManager::Update()
{
	//for_each(mObjectList.begin(), mObjectList.end(), [&](BaseImageObject* btf){btf->Update(); });
	
	for (auto iter = mObjectList.begin(); iter != mObjectList.end();)
	{

		if((*iter) == nullptr)
		{
			continue;;
		}
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
 	for_each(mObjectList.begin(), mObjectList.end(), [&](BaseImageObject* btf){btf->Render(backDC); });
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
	//int temp = SetROP2(backDC, R2_MASKPEN);
	//Rectangle(backDC, x, y, x + 60, y + 60);
	//SetROP2(backDC, temp);
}

void ObjectManager::CreateObject(BaseImageObject* pObj)
{
	
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
		else if ((*iter)->GetTag() == OBJECTTAG::TAG_BOMB && pObj->GetTag() == OBJECTTAG::TAG_BOMB && ((pObj->GetPosX() / TILESIZE) == ((*iter)->GetPosX() / TILESIZE)
			   && (pObj->GetPosY() / TILESIZE) == ((*iter)->GetPosY() / TILESIZE)))
		{
  			delete pObj;
			return;
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




