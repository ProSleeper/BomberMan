#include "GameCommon.h"



BaseTransform::BaseTransform()
{
	miPosX = 0;
	miPosY = 0;
	miWidth = TILESIZE;
	miHeight = TILESIZE;
	mCutRect.left = 0;
	mCutRect.top = 0;
	mCutRect.right = 0;
	mCutRect.bottom = 0;
	mTag = OBJECTTAG::TAG_NONE;
}


BaseTransform::~BaseTransform()
{
}
