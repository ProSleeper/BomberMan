#include "GameCommon.h"


void Explosion::Init(int x, int y, int w, int h, int tw, int th, int tTime, IMAGETYPE type)
{
	mfPosX = x;
	mfPosY = y;
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
}

bool Explosion::Update()
{
	miCurTime = timeGetTime() - miOldTime;
	if (miCurTime >= miCalTime)
	{
		miCalTime += miNextTime;
		miCurFrame++;

		if (miCurFrame >= miTotalFrame)
		{
			return false;
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
	mpImage->RenderImage(backDC, mfPosX, mfPosY, x, y);
}

void Explosion::Release()
{
}

Explosion::Explosion()
{
	mpImage = IMAGEMGR->GetImage(IMAGETYPE::IT_EXPLOSION);
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
