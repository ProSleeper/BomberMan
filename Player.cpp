#include "GameCommon.h"


void Player::Init(int x, int y, int w, int h, int useSizeX, int useSizeY, float tTime)
{
	miPosX = x;
	miPosY = y;
	miWidth = w;
	miHeight = h;

	startX = 71;
	startY = 46;

	mDirection[0] = new LoopAnimation(IMAGETYPE::IT_PLAYER, OBJECTTAG::TAG_PLAYER);
	mDirection[1] = new LoopAnimation(IMAGETYPE::IT_PLAYER, OBJECTTAG::TAG_PLAYER);
	mDirection[2] = new LoopAnimation(IMAGETYPE::IT_PLAYER, OBJECTTAG::TAG_PLAYER);
	mDirection[3] = new LoopAnimation(IMAGETYPE::IT_PLAYER, OBJECTTAG::TAG_PLAYER);


	mDirection[0]->Init(miPosX, miPosY, 98, 1, 15, 24, 48, 16, 0.25f, false, true);
	mDirection[1]->Init(miPosX, miPosY, 50, 1, 15, 24, 48, 16, 0.25f, false, true);
	mDirection[2]->Init(miPosX, miPosY, 0, 1, 16, 24, 51, 17, 0.25f, false, true);
	mDirection[3]->Init(miPosX, miPosY, 145, 1, 16, 24, 51, 17, 0.25f, false, true);

	mPlayerAnimation = mDirection[1];

	//mAnimation = new Animation(IMAGETYPE::IT_PLAYER, OBJECTTAG::TAG_PLAYER);
	//mAnimation->Init(360, 240, 0, 1, 16, 24, 51, 17, 1);
	
	

	this->useSizeX = useSizeX;
	this->useSizeY = useSizeY;
	
}

bool Player::Update()
{
	if((GetAsyncKeyState(VK_UP) & 0x8000) == 0x8000)
	{
		miPosY -= PLAYERSPEED;
		mPlayerAnimation = mDirection[0];
		mPlayerAnimation->SetMotion(true);
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
	else if((GetAsyncKeyState(VK_DOWN) & 0x8000) == 0x8000)
	{
		miPosY += PLAYERSPEED;
		
		mPlayerAnimation = mDirection[1];
		mPlayerAnimation->SetMotion(true);
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
	else if((GetAsyncKeyState(VK_LEFT) & 0x8000) == 0x8000)
	{
		miPosX -= PLAYERSPEED;
		
		mPlayerAnimation = mDirection[2];
		mPlayerAnimation->SetMotion(true);
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
	else if((GetAsyncKeyState(VK_RIGHT) & 0x8000) == 0x8000)
	{
		miPosX += PLAYERSPEED;
		mPlayerAnimation = mDirection[3];
		mPlayerAnimation->SetMotion(true);
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
	else
	{
		mPlayerAnimation->SetMotion(false);
	}
	GETKEYDOWN(VK_SPACE, mIsBomb, DropBomb)
	mPlayerAnimation->Update(miPosX, miPosY);
	return true;
}

void Player::Render(HDC backDC)
{
	mPlayerAnimation->Render(backDC);
	//mpImage->RenderImage(backDC, miPosX, miPosY, miWidth, miHeight, startX, startY, useSizeX, useSizeY);
	/*int temp = SetROP2(backDC, R2_MASKPEN);
	Rectangle(backDC, miPosX, miPosY, miPosX + TILESIZE, miPosY + TILESIZE);

	SetROP2(backDC, temp);*/
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
	mIsBomb = true;
}

Player::Player()
{
	//mpImage = IMAGEMGR->GetImage(IMAGETYPE::IT_PLAYER);
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