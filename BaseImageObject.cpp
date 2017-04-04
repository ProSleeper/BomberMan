#include "GameCommon.h"


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
	mpImage->RenderImage(backDC, mfPosX, mfPosY);
}

void BaseImageObject::Render(HDC backDC, Image* pBack, int w)
{
	pBack->RenderImage(backDC, mfPosX, mfPosY);
	mpImage->RenderImage(backDC, mfPosX, mfPosY, w);
}

BaseImageObject::BaseImageObject()
{
	mpImage = nullptr;
	mbCollider = false;
}


BaseImageObject::~BaseImageObject()
{
	Release();
}
