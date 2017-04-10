#include "GameCommon.h"


void Enemy::Init(int x, int y, int w, int h, int useSizeX, int useSizeY, float tTime)
{
	miPosX = x;
	miPosY = y;
	miWidth = w;
	miHeight = h;

	mbUp = true;
	mbDown = true;
	mbLeft = true;
	mbRight = true;

	startX = 2;
	startY = 2;

	this->useSizeX = useSizeX;
	this->useSizeY = useSizeY;

}

bool Enemy::Update()
{
	/*if((GetAsyncKeyState(73) & 0x8000) == 0x8000 && mbUp)
	{
		miPosY -= MONSTERSPEED;

		if(MAPMGR->IsCollision(miPosX, miPosY, ACTORDIRECTION::AD_UP))
		{
			miPosY += MONSTERSPEED;
		}
		else
		{
			miPosX = ((miPosX + HALFTILESIZE) / TILESIZE) * TILESIZE;
			startX = 74;
			startY = 2;
		}
	}
	else if((GetAsyncKeyState(75) & 0x8000) == 0x8000 && mbDown)
	{
		miPosY += MONSTERSPEED;


		if(MAPMGR->IsCollision(miPosX, miPosY, ACTORDIRECTION::AD_DOWN))
		{
			miPosY -= MONSTERSPEED;
		}
		else
		{
			miPosX = ((miPosX + HALFTILESIZE) / TILESIZE) * TILESIZE;
			startX = 2;
			startY = 2;
		}
	}
	else if((GetAsyncKeyState(74) & 0x8000) == 0x8000 && mbLeft)
	{
		miPosX -= MONSTERSPEED;


		if(MAPMGR->IsCollision(miPosX, miPosY, ACTORDIRECTION::AD_LEFT))
		{
			miPosX += MONSTERSPEED;
		}
		else
		{
			miPosY = ((miPosY + HALFTILESIZE) / TILESIZE) * TILESIZE;
			startX = 146;
			startY = 2;
		}
	}
	else if((GetAsyncKeyState(76) & 0x8000) == 0x8000 && mbRight)
	{
		miPosX += MONSTERSPEED;

		if(MAPMGR->IsCollision(miPosX, miPosY, ACTORDIRECTION::AD_RIGHT))
		{
			miPosX -= MONSTERSPEED;
		}
		else
		{
			miPosY = ((miPosY + HALFTILESIZE) / TILESIZE) * TILESIZE;
			startX = 218;
			startY = 2;
		}
	}*/




	return true;
}

void Enemy::Render(HDC backDC)
{
	mpImage->RenderImage(backDC, miPosX, miPosY, miWidth, miHeight, startX, startY, useSizeX, useSizeY);
	int temp = SetROP2(backDC, R2_MASKPEN);
	Rectangle(backDC, miPosX, miPosY, miPosX + TILESIZE, miPosY + TILESIZE);

	SetROP2(backDC, temp);


	/*Rectangle(backDC, up.left, up.top, up.right, up.bottom);
	Rectangle(backDC, down.left, down.top, down.right, down.bottom);
	Rectangle(backDC, left.left, left.top, left.right, left.bottom);
	Rectangle(backDC, right.left, right.top, right.right, right.bottom);*/

	//MAPMGR->

	/*if (IsBomb)
	{
	bomb->Render(backDC);
	}*/
}

void Enemy::Release()
{

}


Enemy::Enemy()
{
	mpImage = IMAGEMGR->GetImage(IMAGETYPE::IT_ENEMY);
	miPosX = 0;
	miPosY = 0;
	miWidth = 0;
	miHeight = 0;
	mTag = OBJECTTAG::TAG_ENEMY;
}
Enemy::~Enemy()
{
	Release();
}
