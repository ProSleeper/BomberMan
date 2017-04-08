#include "GameCommon.h"


void BaseImageObject::Init(int rendX, int rendY, int rendWidth, int rendHeight, int cutX, int cutY, int cutWidth, int cutHeight, IMAGETYPE type)
{
	mpImage = IMAGEMGR->GetImage(type);

	mfPosX = rendX;
	mfPosY = rendY;
	miWidth = rendWidth;
	miHeight = rendHeight;

	mCutRect.left = cutX;
	mCutRect.top = cutY;
	mCutRect.right = cutWidth;
	mCutRect.bottom = cutHeight;
}

void BaseImageObject::Init(int x, int y, int w, int h, IMAGETYPE type)
{
	mpImage = IMAGEMGR->GetImage(type);

	mfPosX = x;
	mfPosY = y;
	miWidth = w;
	miHeight = h;
}

void BaseImageObject::Init(int x, int y, IMAGETYPE type)
{
	mpImage = IMAGEMGR->GetImage(type);

	mfPosX = x;
	mfPosY = y;
	miWidth = mpImage->GetWidth();
	miHeight = mpImage->GetHeight();

}

void BaseImageObject::Render(HDC backDC)
{
	mpImage->RenderImage(backDC, mfPosX, mfPosY, miWidth, miHeight, mCutRect);
}

void BaseImageObject::Render(HDC backDC, Image* pBack, int w)
{
	pBack->RenderImage(backDC, mfPosX, mfPosY);
	mpImage->RenderImage(backDC, mfPosX, mfPosY, w);
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
}


BaseImageObject::~BaseImageObject()
{
	Release();
}
