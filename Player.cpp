#include "GameCommon.h"


void Player::Init(int x, int y, int w, int h, int useSizeX, int useSizeY, float tTime)
{
	mPos.x = x;
	mPos.y = y;
	miWidth = w;
	miHeight = h;

	startX = 72;
	startY = 46;
	this->useSizeX = useSizeX;
	this->useSizeY = useSizeY;
	bomb = new Bomb(IMAGETYPE::IT_OBJECT);
	
}


bool Player::Update()
{
	if((GetAsyncKeyState(VK_UP) & 0x8000) == 0x8000)
	{
		startX = 72;
		startY = 20;
		mPos.y -= 3;
		int temp = mPos.x % 50;
		if(temp == 0)
		{
		}
		else if(temp < 25)
		{
			mPos.x -= temp;
		}
		else
		{
			mPos.x += (50 - temp);
		}
	}
	else if((GetAsyncKeyState(VK_DOWN) & 0x8000) == 0x8000)
	{
		startX = 71;
		startY = 46;
		mPos.y += 3;

		int temp = mPos.x % 50;
		if(temp == 0)
		{
		}
		else if(temp < 25)
		{
			mPos.x -= temp;
		}
		else
		{
			mPos.x += (50 - temp);
		}
	}
	else if((GetAsyncKeyState(VK_LEFT) & 0x8000) == 0x8000)
	{
		startX = 2;
		startY = 44;
		mPos.x -= 3;
		int temp = mPos.y % 50;

		if (temp == 0)
		{
		}
		else if (temp < 25)
		{
			mPos.y -= temp;
		}
		else
		{
			mPos.y += (50 - temp);
		}

	}
	else if((GetAsyncKeyState(VK_RIGHT) & 0x8000) == 0x8000)
	{
		startX = 106;
		startY = 47;
		mPos.x += 3;
		int temp = mPos.y % 50;

		if(temp == 0)
		{
		}
		else if(temp < 25)
		{
			mPos.y -= temp;
		}
		else
		{
			mPos.y += (50 - temp);
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
	Rectangle(backDC, mPos.x, mPos.y, mPos.x + 50, mPos.y + 50);
	SetROP2(backDC, temp);

	if (IsBomb)
	{
		bomb->Render(backDC);
	}
	
}

void Player::Release()
{       
	int CenterX = 0;
	int CenterY = 0;
	if (mPos.x % 50 >= 25)
	{
		CenterX = ((mPos.x / 50) * 50) + 50;
	}
	else
	{
		CenterX = (mPos.x / 50) * 50;
	}

	if((mPos.y + 25) % 50 >= 25)
	{
		CenterY = (((mPos.y + 25) / 50) * 50) + 50;
	}
	else
	{
		CenterY = ((mPos.y + 25) / 50) * 50;
	}


	
	bomb->Init(CenterX, CenterY, 50, 50,/**/ 67, 16, 1);
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

void BombDown()
{

}
