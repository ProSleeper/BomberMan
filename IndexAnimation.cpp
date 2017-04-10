#include "GameCommon.h"




void IndexAnimation::Init(int x, int y, POINT* arrPoint, int w, int h, int index, float frameTime)
{
	miPosX = x;
	miPosY = y;

	miWidth = w;
	miHeight = h;

	FrameTime = frameTime;
	mCurSpriteCount = 0;
	FrameMove = 1;
	mMaxSpriteCount = mTotalWidth / mUseWidth;

	mTime.SetUpTime(FrameTime);
}

bool IndexAnimation::Update(int x, int y)
{
	return false;
}

void IndexAnimation::Render(HDC backDC)
{
}

void IndexAnimation::Release()
{
}

IndexAnimation::IndexAnimation(IMAGETYPE pType, OBJECTTAG pTag) : Animation(pType, pTag)
{
}


IndexAnimation::~IndexAnimation()
{
}
