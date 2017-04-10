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
	mBombAnimation = new LoopAnimation(IMAGETYPE::IT_OBJECT, OBJECTTAG::TAG_BOMB);
	mBombAnimation->Init(miPosX, miPosY, 103, 151, 16, 16, 51, 17, 0.3f, true);
	//DistanceExplode();
	mTime.SetUpTime(2);
}

bool Bomb::Update()
{
	if (mTime.TimeCheck())
	{
		Explosion* explosion;
		explosion = new Explosion;
		explosion->Init(miPosX, miPosY, 1, 117, 85, 17, 0.05f);
		OBJECTMGR->CreateObject(explosion);
		for (int y = 1; y <= mBombRect.top; y++)
		{
			if (y == mBombRect.top)
			{
				explosion = new Explosion;
				explosion->Init(miPosX, miPosY - y * TILESIZE, 1, 202, 85, 17, 0.05f);
				OBJECTMGR->CreateObject(explosion);
				continue;
			}
			explosion = new Explosion;
			explosion->Init(miPosX , miPosY - y * TILESIZE , 1, 134, 85, 17, 0.05f);
			OBJECTMGR->CreateObject(explosion);
			//MAPMGR->SetMove((miPosY - y * TILESIZE) / TILESIZE, miPosX / TILESIZE, false);
		}
		//아래
		for(int y = 1; y <= mBombRect.bottom; y++)
		{
			if(y == mBombRect.bottom)
			{
				explosion = new Explosion;
				explosion->Init(miPosX, miPosY + y * TILESIZE, 1, 185, 85, 17, 0.05f);
				OBJECTMGR->CreateObject(explosion);
				continue;
			}
			explosion = new Explosion;
			explosion->Init(miPosX, miPosY + y * TILESIZE, 1, 134, 85, 17, 0.05f);
			OBJECTMGR->CreateObject(explosion);
			/*explosion = new Explosion;
			explosion->Init(miPosX, miPosY + y * TILESIZE);
			OBJECTMGR->CreateObject(explosion);*/
			//MAPMGR->SetMove((miPosY + y * TILESIZE) / TILESIZE, miPosX / TILESIZE, false);
		}
		//왼쪽
		for(int x = 1; x <= mBombRect.left; x++)
		{
			if(x == mBombRect.left)
			{
				explosion = new Explosion;
				explosion->Init(miPosX - x * TILESIZE, miPosY, 1, 66, 85, 17, 0.05f);
				OBJECTMGR->CreateObject(explosion);
				continue;
			}
			explosion = new Explosion;
			explosion->Init(miPosX - x * TILESIZE, miPosY, 1, 100, 85, 17, 0.05f);
			OBJECTMGR->CreateObject(explosion);
			/*explosion = new Explosion;
			explosion->Init(miPosX - x * TILESIZE, miPosY);
			OBJECTMGR->CreateObject(explosion);*/
			//MAPMGR->SetMove(miPosY / TILESIZE, (miPosX - x * TILESIZE) / TILESIZE, false);
		}
		//오른쪽
		for(int x = 1; x <= mBombRect.right; x++)
		{
			if(x == mBombRect.right)
			{
				explosion = new Explosion;
				explosion->Init(miPosX + x * TILESIZE, miPosY, 1, 83, 85, 17, 0.05f);
				OBJECTMGR->CreateObject(explosion);
				continue;
			}
			explosion = new Explosion;
			explosion->Init(miPosX + x * TILESIZE, miPosY, 1, 100, 85, 17, 0.05f);
			OBJECTMGR->CreateObject(explosion);
			/*explosion = new Explosion;
			explosion->Init(miPosX + x * TILESIZE, miPosY);
			OBJECTMGR->CreateObject(explosion);*/
			//MAPMGR->SetMove(miPosY / TILESIZE, (miPosX + x * TILESIZE) / TILESIZE, false);
		}
		MAPMGR->SetMove(miPosY / TILESIZE, miPosX / TILESIZE, true);
		delete mBombAnimation;
		return false;
	}

	mBombAnimation->Update(miPosX, miPosY);
	return true;
}


void Bomb::Render(HDC backDC)
{
	//mpImage->RenderImage(backDC, miPosX, miPosY, miWidth, miHeight, 137, 151, 16, 16);
	mBombAnimation->Render(backDC);
	/*int temp = SetROP2(backDC, R2_MASKPEN);
	Rectangle(backDC, miPosX, miPosY, miPosX + 60, miPosY + 60);
	SetROP2(backDC, temp);*/
	//mpImage->RenderImage(backDC, mPos.x, mPos.y, miWidth, miHeight, x, y, miWidth, miHeight);
}

void Bomb::Release()
{
}

void Bomb::TimeBomb()
{
	mTime.SetUpTime(0.1f);
}

Bomb::Bomb()
{
	//mpImage = IMAGEMGR->GetImage(IMAGETYPE::IT_OBJECT);
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
