#include "GameCommon.h"



BaseTransform::BaseTransform()
{
	mfPosX = 0;
	mfPosY = 0;
	miWidth = 0;
	miHeight = 0;
	mTag = OBJECTTAG::TAG_NONE;
}


BaseTransform::~BaseTransform()
{
}
