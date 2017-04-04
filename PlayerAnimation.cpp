#include "GameCommon.h"


void PlayerAnimation::Init(int x, int y, int w, int h, int tw, int th, float tTime)
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
	bomb = new BombAnimation(IMAGETYPE::IT_MAP);
}

bool PlayerAnimation::Update()
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

		/*if(miFrameY > 1)
		{
			miCurFrame = miCurFrame / miFrameX;
		}*/
		miCurFrameX = miCurFrame % miFrameX;
	}
	if((GetAsyncKeyState(VK_UP) & 0x8000) == 0x8000)
	{
		WidthCut = 1;
		mPos.y -= 3;
		HeightCut = 1;
	}
	else if((GetAsyncKeyState(VK_DOWN) & 0x8000) == 0x8000)
	{
		WidthCut = 1;
		mPos.y += 3;
		HeightCut = 0;
	}
	else if((GetAsyncKeyState(VK_LEFT) & 0x8000) == 0x8000)
	{
		WidthCut = 1;
		mPos.x -= 3;
		HeightCut = 2;
	}
	else if((GetAsyncKeyState(VK_RIGHT) & 0x8000) == 0x8000)
	{
		WidthCut = 1;
		mPos.x += 3;
		HeightCut = 5;
	}
	else
	{
		WidthCut = 0;
	}
	GETKEYDOWN(VK_SPACE, mIsBomb, Release)
	if(IsBomb)
	{
		bomb->Update();
	}
	return true;
}

void PlayerAnimation::Render(HDC backDC)
{
	int x, y;
	x = (miCurFrameX + 1) * miWidth * WidthCut;
	y = (miCurFrameY + HeightCut) * miHeight;
	mpImage->RenderImage(backDC,mPos.x, mPos.y, miWidth, miHeight, x, y, miWidth, miHeight);
	
	if (IsBomb)
	{
		bomb->Render(backDC);
	}
	
}

void PlayerAnimation::Release()
{       
	bomb->Init(mPos.x, mPos.y, 50, 50,/**/ 67, 16, 1);
	IsBomb = true;
}

PlayerAnimation::PlayerAnimation(IMAGETYPE type)
{
	mpImage = IMAGEMGR->GetImage(type);
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

PlayerAnimation::~PlayerAnimation()
{
	Release();
}

void BombDown()
{

}
