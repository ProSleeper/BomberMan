#include "GameCommon.h"


void Player::Init(int x, int y, int w, int h, int useSizeX, int useSizeY, float tTime)
{
	mPos.x = x;
	mPos.y = y;
	miWidth = w;
	miHeight = h;

	mbUp = true;
	mbDown = true;
	mbLeft = true;
	mbRight = true;

	startX = 72;
	startY = 46;
	this->useSizeX = useSizeX;
	this->useSizeY = useSizeY;
	bomb = new Bomb(IMAGETYPE::IT_OBJECT);
}

bool Player::Update()
{
	if((GetAsyncKeyState(VK_UP) & 0x8000) == 0x8000 && mbUp)
	{
		mPos.y -= PlayerSpeed;
		if(OBJECTMGR->IsCollision(mPos.x, mPos.y, PLAYERDIRECTION::PM_UP))
		{
			mPos.y += PlayerSpeed;
		}
		else
		{
			mPos.x = ((mPos.x + 30)/ 60) * 60;
		}
	}
	else if((GetAsyncKeyState(VK_DOWN) & 0x8000) == 0x8000 && mbDown)
	{
		mPos.y += PlayerSpeed;
		if(OBJECTMGR->IsCollision(mPos.x, mPos.y, PLAYERDIRECTION::PM_DOWN))
		{
			mPos.y -= PlayerSpeed;
		}
		else
		{
			mPos.x = ((mPos.x + 30) / 60) * 60;
		}
	}
	else if((GetAsyncKeyState(VK_LEFT) & 0x8000) == 0x8000 && mbLeft)
	{
		mPos.x -= PlayerSpeed;
		if(OBJECTMGR->IsCollision(mPos.x, mPos.y, PLAYERDIRECTION::PM_LEFT))
		{
			mPos.x += PlayerSpeed;
		}
		else
		{
			mPos.y = ((mPos.y + 30) / 60) * 60;
		}
	}
	else if((GetAsyncKeyState(VK_RIGHT) & 0x8000) == 0x8000 && mbRight)
	{
		mPos.x += PlayerSpeed;
		if(OBJECTMGR->IsCollision(mPos.x, mPos.y, PLAYERDIRECTION::PM_RIGHT))
		{
			mPos.x -= PlayerSpeed;
		}
		else
		{
			mPos.y = ((mPos.y + 30) / 60) * 60;
		}
	}
	GETKEYDOWN(VK_SPACE, mIsBomb, Release)

	bomb->Update();


	return true;
}

void Player::Render(HDC backDC)
{
	mpImage->RenderImage(backDC,mPos.x, mPos.y, miWidth, miHeight, startX, startY, useSizeX, useSizeY);
	int temp = SetROP2(backDC, R2_MASKPEN);
	Rectangle(backDC, mPos.x, mPos.y, mPos.x + 60, mPos.y + 60);
	
	SetROP2(backDC, temp);

	
	/*Rectangle(backDC, up.left, up.top, up.right, up.bottom);
	Rectangle(backDC, down.left, down.top, down.right, down.bottom);
	Rectangle(backDC, left.left, left.top, left.right, left.bottom);
	Rectangle(backDC, right.left, right.top, right.right, right.bottom);*/

	//MAPMGR->

	if (IsBomb)
	{
		bomb->Render(backDC);
	}
}

void Player::Release()
{       
	int CenterX = 0;
	int CenterY = 0;
	if (mPos.x % 60 >= 35)
	{
		CenterX = ((mPos.x / 60) * 60) + 60;
	}
	else
	{
		CenterX = (mPos.x / 60) * 60;
	}

	if((mPos.y) % 60 >= 35)
	{
		CenterY = (((mPos.y) / 60) * 60) + 60;
	}
	else
	{
		CenterY = ((mPos.y) / 60) * 60;
	}

	bomb->Init(CenterX, CenterY, 60, 60,/**/ 67, 16, 1);
	IsBomb = true;
}

Player::Player(IMAGETYPE type)
{
	mpImage = IMAGEMGR->GetImage(type);
	mPos.x = 0;
	mPos.y = 0;
	miWidth = 0;
	miHeight = 0;
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
void Player::MoveCheck(int pos, PLAYERDIRECTION pm)
{
}

void Player::RectColl(RECT& rect, int x, int y, int w, int h)
{
	rect.left = mPos.x + x;
	rect.top = mPos.y + y;
	rect.right = mPos.x + w;
	rect.bottom = mPos.y + h;
}
