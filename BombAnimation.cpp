#include "GameCommon.h"

void BombAnimation::Init(int x, int y, int w, int h, int tw, int th, float tTime)
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
	miTotalFrame = 5;

	miNextTime = ((float)miTotalTime / miTotalFrame) * 1000;
	miOldTime = timeGetTime();
	miCalTime = miNextTime;
}

int x, y;
int num = 0;
bool BombAnimation::Update()
{
	miCurTime = timeGetTime();
	if(miCurTime >= miOldTime + miCalTime)
	{
		x = 17 * num++;
		if(num > 3)
		{
			num = 0;
		}
		y = (miCurFrameY + 3) * miHeight;
		miOldTime = timeGetTime();





		//miCalTime += miNextTime;
		//miCurFrame++;

		//if(miCurFrame >= miTotalFrame)
		//{
		//	miCurFrame = 0;
		//	miCurFrameX = 0;
		//	miCurFrameY = 0;
		//	miCalTime = miNextTime;
		//	miOldTime = timeGetTime();
		//	
		//}

		///*if(miFrameY > 1)
		//{
		//miCurFrame = miCurFrame / miFrameX;
		//}*/
		//miCurFrameX = miCurFrame % miFrameX;
	}

	
	
	return true;
}


void BombAnimation::Render(HDC backDC)
{
	mpImage->RenderImage(backDC, mPos.x, mPos.y, miWidth, miHeight, x, 48, 16, 16);
	//mpImage->RenderImage(backDC, mPos.x, mPos.y, miWidth, miHeight, x, y, miWidth, miHeight);
}

void BombAnimation::Release()
{
}

BombAnimation::BombAnimation(IMAGETYPE type)
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

BombAnimation::~BombAnimation()
{
	Release();
}
