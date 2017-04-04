#include "GameCommon.h"



void BaseAnimImageObject::Init(int rendX, int rendY, int rendWidth, int rendHeight, int cutX, int cutY, int cutWidth, int cutHeight, IMAGETYPE type)
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

void BaseAnimImageObject::Render(HDC backDC)
{
	mpImage->RenderImage(backDC, mRendRect, mCutRect);
}

BaseAnimImageObject::BaseAnimImageObject()
{
	mpImage = nullptr;
}

BaseAnimImageObject::~BaseAnimImageObject()
{
	Release();
}