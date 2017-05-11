#include "GameCommon.h"


void BaseImageObject::Init(int rendX, int rendY, int cutX, int cutY, int cutWidth, int cutHeight, IMAGETYPE type)
{
	mpImage = IMAGEMGR->GetImage(type);

	miPosX = rendX;
	miPosY = rendY;

	mCutRect.left = cutX;
	mCutRect.top = cutY;
	mCutRect.right = cutWidth;
	mCutRect.bottom = cutHeight;
}

void BaseImageObject::Init(int x, int y, int w, int h, IMAGETYPE type)
{
	mpImage = IMAGEMGR->GetImage(type);

	miPosX = x;
	miPosY = y;
	miWidth = w;
	miHeight = h;
}

void BaseImageObject::Init(int x, int y, IMAGETYPE type)
{
	mpImage = IMAGEMGR->GetImage(type);

	miPosX = x;
	miPosY = y;
	miWidth = mpImage->GetWidth();
	miHeight = mpImage->GetHeight();

}

void BaseImageObject::Render(HDC backDC)
{
	mpImage->RenderImage(backDC, miPosX, miPosY, miWidth, miHeight, mCutRect);
}

void BaseImageObject::Render(HDC backDC, Image* pBack, int w)
{
	pBack->RenderImage(backDC, miPosX, miPosY);
	mpImage->RenderImage(backDC, miPosX, miPosY, w);
}

void BaseImageObject::ImageChange(int x, int y)
{
	mCutRect.left = x;
	mCutRect.top = y;
}

BaseImageObject::BaseImageObject()
{
	mpImage = nullptr;
	mbCollider = false;
	isMove = true;
	mIsLife = true;
	miWidth = TILESIZE;
	miHeight = TILESIZE;
}


BaseImageObject::~BaseImageObject()
{
	Release();
}
