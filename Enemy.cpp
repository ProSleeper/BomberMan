#include "GameCommon.h"


bool Enemy::Update()
{
	if(mfPosY > ScreenSizeY)
	{
		return false;
	}

	mfPosY += 4;
	OffsetRect(&mCollRect, 0, 4);
	return true;
}
void Enemy::OnCollisionEnter(BaseTransform * pCollObj)
{
	mbLife = false;
}
Enemy::Enemy()
{
	ZeroMemory(&mCollRect, sizeof(mCollRect));
}

Enemy::~Enemy()
{
	Release();
}
