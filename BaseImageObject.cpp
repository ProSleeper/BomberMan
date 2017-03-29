#include "GameCommon.h"


void BaseImageObject::Init(int rendX, int rendY, int rendWidth, int rendHeight, int cutX, int cutY, int cutWidth, int cutHeight, IMAGEBIT type)
{
	mpImage = IMAGEMGR->GetImage(type);

	mRendRect.left = rendX;
	mRendRect.top = rendY;
	mRendRect.right = rendWidth;
	mRendRect.bottom = rendHeight;

	mCutRect.left = cutX;
	mCutRect.top = cutY;
	mCutRect.right = cutWidth;
	mCutRect.bottom = cutHeight;
}

void BaseImageObject::Render(HDC backDC)
{
	//
	mpImage->RenderImage(backDC, mRendRect, mCutRect);
}

BaseImageObject::BaseImageObject()
{
	mpImage = nullptr;
}


BaseImageObject::~BaseImageObject()
{
	Release();
}
