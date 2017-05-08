#include "GameCommon.h"
random_device rd;


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


	mDirection[0] = new LoopAnimation(IMAGETYPE::IT_ENEMY, OBJECTTAG::TAG_ENEMY);
	mDirection[1] = new LoopAnimation(IMAGETYPE::IT_ENEMY, OBJECTTAG::TAG_ENEMY);
	mDirection[2] = new LoopAnimation(IMAGETYPE::IT_ENEMY, OBJECTTAG::TAG_ENEMY);
	mDirection[3] = new LoopAnimation(IMAGETYPE::IT_ENEMY, OBJECTTAG::TAG_ENEMY);


	mDirection[0]->Init(miPosX, miPosY, 130, 1, 15, 23, 48, 16, 0.25f);
	mDirection[1]->Init(miPosX, miPosY, 66, 1, 15, 23, 48, 16, 0.25f);
	mDirection[2]->Init(miPosX, miPosY, 0, 1, 15, 23, 48, 16, 0.25f);
	mDirection[3]->Init(miPosX, miPosY, 194, 1, 15, 23, 48, 16, 0.25f);

	mEnemyAnimation = mDirection[1];
	this->useSizeX = useSizeX;
	this->useSizeY = useSizeY;
	mEnemyDirection = ACTORDIRECTION::AD_DOWN;

}

bool Enemy::Update()
{
	switch (mEnemyDirection)
	{
		case ACTORDIRECTION::AD_UP:
		{
			miPosY -= MONSTERSPEED;
			if(MAPMGR->IsCollision(miPosX, miPosY, ACTORDIRECTION::AD_UP))
			{
				miPosY += MONSTERSPEED;
				RandomDirection();
			}
			mEnemyAnimation = mDirection[0];
			break;
		}
		case ACTORDIRECTION::AD_DOWN:
		{
			miPosY += MONSTERSPEED;
			if(MAPMGR->IsCollision(miPosX, miPosY, ACTORDIRECTION::AD_DOWN))
			{
				miPosY -= MONSTERSPEED;
				RandomDirection();
			}
			mEnemyAnimation = mDirection[1];
			break;
		}
		case ACTORDIRECTION::AD_LEFT:
		{
			miPosX -= MONSTERSPEED;
			if(MAPMGR->IsCollision(miPosX, miPosY, ACTORDIRECTION::AD_LEFT))
			{
				miPosX += MONSTERSPEED;
				RandomDirection();
			}
			mEnemyAnimation = mDirection[2];
			break;
		}
		case ACTORDIRECTION::AD_RIGHT:
		{
			miPosX += MONSTERSPEED;
			if(MAPMGR->IsCollision(miPosX, miPosY, ACTORDIRECTION::AD_RIGHT))
			{
				miPosX -= MONSTERSPEED;
				RandomDirection();
			}
			mEnemyAnimation = mDirection[3];
			break;
		}
		default :
		{
			break;
		}
	}

	mEnemyAnimation->Update(miPosX, miPosY);
	return true;
}

void Enemy::Render(HDC backDC)
{
	int temp = SetROP2(backDC, R2_MASKPEN);
	Rectangle(backDC, miPosX, miPosY, miPosX + TILESIZE, miPosY + TILESIZE);

	SetROP2(backDC, temp);
	mEnemyAnimation->Render(backDC);


}

void Enemy::Release()
{
	
}

void Enemy::RandomDirection()
{
	int a = rd() % 4;
	
	mEnemyDirection = static_cast<ACTORDIRECTION>(a);
}

Enemy::Enemy()
{
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
