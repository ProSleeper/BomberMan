#include "GameCommon.h"



bool Player::Update()
{
	if ((GetAsyncKeyState(VK_LEFT) & 0x8000) == 0x8000)
	{
		mRendRect.left -= 5;
	}
	if((GetAsyncKeyState(VK_RIGHT) & 0x8000) == 0x8000)
	{
		mRendRect.left += 5;
	}
	if((GetAsyncKeyState(VK_UP) & 0x8000) == 0x8000)
	{
		mRendRect.top -= 5;
	}
	if((GetAsyncKeyState(VK_DOWN) & 0x8000) == 0x8000)
	{
		mRendRect.top += 5;
	}

	return false;
}

void Player::Release()
{
}

Player::Player()
{
}


Player::~Player()
{
}
