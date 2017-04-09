#include "GameCommon.h"


void Player::Init(int x, int y, int w, int h, int useSizeX, int useSizeY, float tTime)
{
	miPosX = x;
	miPosY = y;
	miWidth = w;
	miHeight = h;

	mbUp = true;
	mbDown = true;
	mbLeft = true;
	mbRight = true;

	startX = 71;
	startY = 46;

	this->useSizeX = useSizeX;
	this->useSizeY = useSizeY;
	
}

bool Player::Update()
{
	if((GetAsyncKeyState(VK_UP) & 0x8000) == 0x8000 && mbUp)
	{
		miPosY -= PLAYERSPEED;
		
		if(MAPMGR->IsCollision(miPosX, miPosY, ACTORDIRECTION::AD_UP))
		{
			miPosY += PLAYERSPEED;
		}
		else
		{
			miPosX = ((miPosX + HALFTILESIZE)/ TILESIZE) * TILESIZE;
			startX = 72;
			startY = 20;
		}
	}
	else if((GetAsyncKeyState(VK_DOWN) & 0x8000) == 0x8000 && mbDown)
	{
		miPosY += PLAYERSPEED;
		
		
		if(MAPMGR->IsCollision(miPosX, miPosY, ACTORDIRECTION::AD_DOWN))
		{
			miPosY -= PLAYERSPEED;
		}
		else
		{
			miPosX = ((miPosX + HALFTILESIZE) / TILESIZE) * TILESIZE;
			startX = 71;
			startY = 46;
		}
	}
	else if((GetAsyncKeyState(VK_LEFT) & 0x8000) == 0x8000 && mbLeft)
	{
		miPosX -= PLAYERSPEED;
		
		
		if(MAPMGR->IsCollision(miPosX, miPosY, ACTORDIRECTION::AD_LEFT))
		{
			miPosX += PLAYERSPEED;
		}
		else
		{
			miPosY = ((miPosY + HALFTILESIZE) / TILESIZE) * TILESIZE;
			startX = 2;
			startY = 44;
		}
	}
	else if((GetAsyncKeyState(VK_RIGHT) & 0x8000) == 0x8000 && mbRight)
	{
		miPosX += PLAYERSPEED;
		
		if(MAPMGR->IsCollision(miPosX, miPosY, ACTORDIRECTION::AD_RIGHT))
		{
			miPosX -= PLAYERSPEED;
		}
		else
		{
			miPosY = ((miPosY + HALFTILESIZE) / TILESIZE) * TILESIZE;
			startX = 106;
			startY = 47;
		}
	}
	GETKEYDOWN(VK_SPACE, mIsBomb, DropBomb)

	return true;
}

void Player::Render(HDC backDC)
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

void Player::Release()
{

}

void Player::DropBomb()
{       
	int CenterX = 0;
	int CenterY = 0;
	if (miPosX % TILESIZE >= HALFTILESIZE)
	{
		CenterX = ((miPosX / TILESIZE) * TILESIZE) + TILESIZE;
	}
	else
	{
		CenterX = (miPosX / TILESIZE) * TILESIZE;
	}

	if((miPosY) % TILESIZE >= HALFTILESIZE)
	{
		CenterY = (((miPosY) / TILESIZE) * TILESIZE) + TILESIZE;
	}
	else
	{
		CenterY = ((miPosY) / TILESIZE) * TILESIZE;
	}
	bomb = new Bomb;
	bomb->Init(CenterX, CenterY, TILESIZE, TILESIZE,/**/ 67, 16, 1);
	OBJECTMGR->CreateObject(bomb);
	//COLLMGR->CreateCollider(bomb);
	IsBomb = true;
}

Player::Player()
{
	mpImage = IMAGEMGR->GetImage(IMAGETYPE::IT_PLAYER);
	miPosX = 0;
	miPosY = 0;
	miWidth = 0;
	miHeight = 0;
	mTag = OBJECTTAG::TAG_PLAYER;
}

Player::~Player()
{
	Release();
}

//void Player::MoveLock(LONG& rhs)
//{
//	int temp = rhs % 60;
//
//	if(temp == 0)
//	{
//	}
//	else if(temp < 10)
//	{
//		rhs -= temp;
//	}
//	else 
//	{
//		rhs += (60 - temp);
//	}
//}
void Player::MoveCheck(int pos, ACTORDIRECTION pm)
{
}

void Player::RectColl(RECT& rect, int x, int y, int w, int h)
{
	rect.left = miPosX + x;
	rect.top = miPosY + y;
	rect.right = miPosX + w;
	rect.bottom = miPosY + h;
}
