#include "GameCommon.h"



void ObjectManager::Init()
{

}

void ObjectManager::Update()
{
	//for_each(mListObject.begin(), mListObject.end(), [](BaseImageObject* btf){btf->Update(); });
}

void ObjectManager::Render(HDC backDC)
{
	//for_each(mListObject.begin(), mListObject.end(), [&](BaseImageObject* btf){btf->Render(backDC); });
	for(int x = 1; x < arrSizeX - 1; x++)
	{
		for(int y = 5; y < arrSizeY - 5; y++)
		{
			mListObject[x][y]->Render(backDC);
		}
	}
}

void ObjectManager::Release()
{
}

bool ObjectManager::IsCollision(int x, int y, PLAYERDIRECTION pDir)
{
	int MoveLTgap = 15;
	int MoveRBgap = 45;


	switch (pDir)
	{
		case PLAYERDIRECTION::PM_UP:
		{
			rect.left = (x + MoveLTgap) / MapSize;
			rect.top = y / MapSize;

			rect.right = (x + MoveRBgap) / MapSize;
			rect.bottom = y / MapSize;
			return !(mListObject[rect.top][rect.left]->GetIsMove() && mListObject[rect.bottom][rect.right]->GetIsMove());
		}
		case PLAYERDIRECTION::PM_DOWN:
		{
			rect.left = (x + MoveLTgap) / MapSize;
			rect.top = (y + MapSize - PlayerSpeed) / MapSize;

			rect.right = (x + MoveRBgap) / MapSize;
			rect.bottom = (y + MapSize - PlayerSpeed) / MapSize;
			return !(mListObject[rect.top][rect.left]->GetIsMove() && mListObject[rect.bottom][rect.right]->GetIsMove());
		}
		case PLAYERDIRECTION::PM_LEFT:
		{
			rect.left = x / MapSize;
			rect.top = (y + MoveLTgap) / MapSize;

			rect.right = x / MapSize;
			rect.bottom = (y + MoveRBgap) / MapSize;
			return !(mListObject[rect.top][rect.left]->GetIsMove() && mListObject[rect.bottom][rect.right]->GetIsMove());
		}
		case PLAYERDIRECTION::PM_RIGHT:
		{
			rect.left = (x + MapSize - PlayerSpeed) / MapSize;
			rect.top = (y + MoveLTgap) / MapSize;

			rect.right = (x + MapSize - PlayerSpeed) / MapSize;
			rect.bottom = (y + MoveRBgap) / MapSize;
			return !(mListObject[rect.top][rect.left]->GetIsMove() && mListObject[rect.bottom][rect.right]->GetIsMove());
		}
		default:
		{
			break;
		}
	}
	return true;
}

void ObjectManager::CreateObject(BaseImageObject* pObj)
{
	//mListObject.push_back(pObj);
}

void ObjectManager::ChangeObject(int x, int y, int w, int h, bool bMove)
{
	mListObject[x][y]->ImageChange(w, h);
	mListObject[x][y]->SetIsMove(bMove);
}

bool ObjectManager::IsMove(int x, int y)
{
	return mListObject[x][y]->GetIsMove();
}

RECT ObjectManager::GetRECT(int x, int y)
{
	Object* temp = dynamic_cast<Object*>(mListObject[x][y]);

	RECT rect;
	rect.left = temp->GetPosX();
	rect.top = temp->GetPosY();
	rect.right = temp->GetPosX() + temp->GetWidth();
	rect.bottom = temp->GetPosY() + temp->GetHeight();

	return rect;
}

void ObjectManager::DeleteObject()
{
	//for(auto iter = mListObject.begin(); iter != mListObject.end();)
	//{
	//	if((*iter)->Update())
	//	{
	//		delete (*iter);
	//		iter = mListObject.erase(iter);
	//	}
	//	else
	//	{
	//		iter++;
	//	}
	//}
}

ObjectManager::ObjectManager()
{
	mListObject.assign(arrSizeX, vector<BaseImageObject*>(arrSizeY));
	for(int x = 1; x < arrSizeX - 1; x++)
	{
		for(int y = 5; y < arrSizeY - 5; y++)
		{
			mListObject[x][y] = new Object;
			mListObject[x][y]->Init(MapSize * y, MapSize * x, MapSize, MapSize,/**/ 52, 49, 16, 16, IMAGETYPE::IT_OBJECT);
		}
	}
}

ObjectManager::~ObjectManager()
{
}
