#include "GameCommon.h"



BaseAnimTransform::BaseAnimTransform()
{
	ZeroMemory(&mRendRect, sizeof(mRendRect));
	ZeroMemory(&mCutRect, sizeof(mCutRect));
}


BaseAnimTransform::~BaseAnimTransform()
{
}

