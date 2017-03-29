#include "GameCommon.h"


void Actor::Init()
{
	HDC hdc = GetDC(WINMGR->GethWnd());
	HBITMAP bit;

	mHmemDC = CreateCompatibleDC(hdc);
	bit = static_cast<HBITMAP>(LoadImage(nullptr, "PlayerDown.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE));
	SelectObject(mHmemDC, bit);

	ReleaseDC(WINMGR->GethWnd(), hdc);
}

void Actor::Update()
{
	if ((GetAsyncKeyState(VK_RIGHT) & 0x8000) == 0x8000)
	{
		mPos.x += 5;
	}

}

void Actor::Render(HDC backDC)
{
	//BitBlt(backDC, 0, 0, 50, 50, mHmemDC, 0, 0, SRCCOPY);
	TransparentBlt(backDC, mPos.x, mPos.y, 50, 50, mHmemDC, 0, 0, 64, 67, RGB(255, 255, 255));
	//TransparentBlt(backDC, mPos.x, mPos.y, miWidth, miHeight, mHmemDC, 0, 0, 64, 56, RGB(255, 0, 255));
}

void Actor::Release()
{

}

Actor::Actor()
{
	mPos.x = 0;
	mPos.y = 0;
}

Actor::~Actor()
{

}
