#include "GameCommon.h"

void Bomb::Init(int x, int y, int w, int h, int tw, int th, float tTime)
{
	miPosX = x;
	miPosY = y;
	miWidth = w;
	miHeight = h;

	mUp = true;
	mDown = true;
	mLeft = true;
	mRight = true;

	mBombRect.left = 1;
	mBombRect.top = 1;
	mBombRect.right = 1;
	mBombRect.bottom = 1;

	mTag = OBJECTTAG::TAG_BOMB;
	DistanceExplode();
	mTime.SetUpTime(2);
}

bool Bomb::Update()
{
	if (mTime.TimeCheck())
	{
		Explosion* explosion;
		/*explosion = new Explosion;
		explosion->Init(miPosX, miPosY);
		OBJECTMGR->CreateObject(explosion);*/
		//MAPMGR->SetMove(miPosY / TILESIZE, miPosX / TILESIZE, false);
		//위
		for (int y = 0; y <= mBombRect.top; y++)
		{
			explosion = new Explosion;
			explosion->Init(miPosX , miPosY - y * TILESIZE);
			OBJECTMGR->CreateObject(explosion);
			//MAPMGR->SetMove((miPosY - y * TILESIZE) / TILESIZE, miPosX / TILESIZE, false);
		}
		//아래
		for(int y = 1; y <= mBombRect.bottom; y++)
		{
			explosion = new Explosion;
			explosion->Init(miPosX, miPosY + y * TILESIZE);
			OBJECTMGR->CreateObject(explosion);
			//MAPMGR->SetMove((miPosY + y * TILESIZE) / TILESIZE, miPosX / TILESIZE, false);
		}
		//왼쪽
		for(int x = 1; x <= mBombRect.left; x++)
		{
			explosion = new Explosion;
			explosion->Init(miPosX - x * TILESIZE, miPosY);
			OBJECTMGR->CreateObject(explosion);
			//MAPMGR->SetMove(miPosY / TILESIZE, (miPosX - x * TILESIZE) / TILESIZE, false);
		}
		//오른쪽
		for(int x = 1; x <= mBombRect.right; x++)
		{
			explosion = new Explosion;
			explosion->Init(miPosX + x * TILESIZE, miPosY);
			OBJECTMGR->CreateObject(explosion);
			//MAPMGR->SetMove(miPosY / TILESIZE, (miPosX + x * TILESIZE) / TILESIZE, false);
		}
		MAPMGR->SetMove(miPosY / TILESIZE, miPosX / TILESIZE, true);
		return false;
	}
	return true;
}


void Bomb::Render(HDC backDC)
{
	mpImage->RenderImage(backDC, miPosX, miPosY, miWidth, miHeight, 137, 151, 16, 16);
	int temp = SetROP2(backDC, R2_MASKPEN);
	Rectangle(backDC, miPosX, miPosY, miPosX + 60, miPosY + 60);
	SetROP2(backDC, temp);
	//mpImage->RenderImage(backDC, mPos.x, mPos.y, miWidth, miHeight, x, y, miWidth, miHeight);
}

void Bomb::Release()
{
}

void Bomb::TimeBomb()
{
	mTime.SetUpTime(0.0f);
}

Bomb::Bomb()
{
	mpImage = IMAGEMGR->GetImage(IMAGETYPE::IT_OBJECT);
	miPosX = 0;
	miPosY = 0;
	miWidth = 0;
	miHeight = 0;
}

Bomb::~Bomb()
{
	Release();
}

void Bomb::DistanceExplode()
{
	for(int i = 0; i < 5; i++)
	{
		//여기서는 좌표를 주고
		//위
		if(mUp &&MAPMGR->IsMove(miPosY / TILESIZE - 1 - i, miPosX / TILESIZE))
		{
			mBombRect.top++;
		}
		else
		{
			mUp = false;
		}
		//아래
		if(mDown &&MAPMGR->IsMove(miPosY / TILESIZE + 1 + i, miPosX / TILESIZE))
		{
			mBombRect.bottom++;
		}
		else
		{
			mDown = false;
		}
		//왼쪽
		if(mLeft && MAPMGR->IsMove(miPosY / TILESIZE, miPosX / TILESIZE - 1 - i))
		{
			mBombRect.left++;
		}
		else
		{
			mLeft = false;
		}
		//오른쪽
		if(mRight && MAPMGR->IsMove(miPosY / TILESIZE, miPosX / TILESIZE + 1 + i))
		{
			mBombRect.right++;
		}
		else
		{
			mRight = false;
		}
	}
}
