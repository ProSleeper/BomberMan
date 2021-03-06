#include "GameCommon.h"


void LoopAnimation::Init(int x, int y, int MoveX, int MoveY, int w, int h, int totalWidth, int useWidth, float frameTime, bool bMotion)
{
	Animation::Init(x, y, MoveX, MoveY, w, h, totalWidth, useWidth, frameTime);
	mbMotion = bMotion;
}

bool LoopAnimation::Update(int x, int y)
{
	miPosX = x;
	miPosY = y;
	if(mTime.TimeCheck() && mbMotion)
	{
		mCurSpriteCount += FrameMove;
		if(mCurSpriteCount <= 0)
		{
			FrameMove *= -1;
		}
		if(mCurSpriteCount >= mMaxSpriteCount - 1)
		{
			FrameMove *= -1;
		}
		mTime.SetUpTime(FrameTime);
	}
	return true;
}

void LoopAnimation::Render(HDC backDC)
{
	if(mbMotion)
	{
		mpImage->RenderImage(backDC, miPosX, miPosY, TILESIZE, TILESIZE, mUseWidth * mCurSpriteCount + mAnimX, mAnimY, miWidth, miHeight);
		return;
	}
	mpImage->RenderImage(backDC, miPosX, miPosY, TILESIZE, TILESIZE, mUseWidth * 1 + mAnimX, mAnimY, miWidth, miHeight);
}

void LoopAnimation::Release()
{
}

LoopAnimation::LoopAnimation(IMAGETYPE pType, OBJECTTAG pTag) : Animation(pType, pTag)
{
}


LoopAnimation::~LoopAnimation()
{
}
