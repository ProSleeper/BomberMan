#include "GameCommon.h"


void Explosion::Init(int x, int y, int w, int h, int tw, int th, int tTime)
{
	mPos.x = x;
	mPos.y = y;
	miWidth = w;
	miHeight = h;

	miTotalWidth = tw;
	miTotalHeight = th;
	miTotalTime = tTime;

	miFrameX = miTotalWidth / miWidth;
	miFrameY = miTotalHeight / miHeight;
	miTotalFrame = miFrameX * miFrameY;

	miNextTime = ((float)miTotalTime / miTotalFrame) * 1000;
	miOldTime = timeGetTime();
	miCalTime = miNextTime;

	HDC hdc = GetDC(WINMGR->GethWnd());
	HBITMAP bit;

	mHmemDC = CreateCompatibleDC(hdc);
	bit = static_cast<HBITMAP>(LoadImage(nullptr, "explosion.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE));
	SelectObject(mHmemDC, bit);


	ReleaseDC(WINMGR->GethWnd(), hdc);
}

void Explosion::Update()
{
	miCurTime = timeGetTime() - miOldTime;
	if (miCurTime >= miCalTime)
	{
		miCalTime += miNextTime;
		miCurFrame++;

		if (miCurFrame >= miTotalFrame)
		{
			miCurFrame = 0;
			miCurFrameX = 0;
			miCurFrameY = 0;
			miCalTime = miNextTime;
			miOldTime = timeGetTime();
		}

		if(miFrameY > 1)
		{
			miCurFrame = miCurFrame / miFrameX;
		}
		miCurFrameX = miCurFrame % miFrameX;
	}
}

void Explosion::Render(HDC backDC)
{
	int x, y;
	x = miCurFrameX * miWidth;
	y = miCurFrameY * miHeight;
	TransparentBlt(backDC, mPos.x, mPos.y, miWidth, miHeight, mHmemDC, x, y, miWidth, miHeight, RGB(0, 0, 0));
}

void Explosion::Release()
{
}

Explosion::Explosion()
{
	mHmemDC = nullptr;
	mPos.x = 0;
	mPos.y = 0;
	miWidth = 0;
	miHeight = 0;
	miTotalWidth = 0;
	miTotalHeight = 0;
	miTotalTime = 0;

	miFrameX = 0;
	miFrameY = 0;
	miCurFrameX = 0;
	miCurFrameY = 0;
	miCurFrame = 0;
	miTotalFrame = 0;
	miNextTime = 0;
	miCurTime = 0;
	miOldTime = 0;
	miCalTime = 0;
}

Explosion::~Explosion()
{
	Release();
}
