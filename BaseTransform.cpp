#include "GameCommon.h"



BaseTransform::BaseTransform()
{
	ZeroMemory(&mRendRect, sizeof(mRendRect));
	ZeroMemory(&mCutRect, sizeof(mCutRect));
}


BaseTransform::~BaseTransform()
{
}
