#include "GameCommon.h"


void Animation::Init(int x, int y, int MoveX, int MoveY, int w, int h,  int totalWidth, int useWidth, float frameTime, bool bMotion, bool bLoop)
{
	miPosX = x;
	miPosY = y;
	

	mAnimX = MoveX;
	mAnimY = MoveY;
	
	miWidth = w;
	miHeight = h;

	mTotalWidth = totalWidth;
	mUseWidth = useWidth;
	FrameTime = frameTime;
	mCurSpriteCount = 0;
	FrameMove = 1;
	mMaxSpriteCount = mTotalWidth / mUseWidth;
	mbMotion = bMotion;
	mbLoop = bLoop;
	
	mTime.SetUpTime(FrameTime);
}

bool Animation::Update(int x, int y)
{
	miPosX = x;
	miPosY = y;
	if(mTime.TimeCheck() && mbMotion)
	{
		mCurSpriteCount += FrameMove;
		if (mCurSpriteCount >= mMaxSpriteCount)
		{
			mCurSpriteCount = 0;
		}
		mTime.SetUpTime(FrameTime);
	}
	/*miPosX = x;
	miPosY = y;
	if(mTime.TimeCheck() && mbMotion)
	{
		mCurSpriteCount += FrameMove;
		if(mbLoop)
		{
			if(mCurSpriteCount <= 0)
			{
				FrameMove *= -1;
			}
			if(mCurSpriteCount >= mMaxSpriteCount - 1)
			{
				FrameMove *= -1;
			}
		}
		else
		{
			if(mCurSpriteCount >= mMaxSpriteCount)
			{
				mCurSpriteCount = 0;
			}
		}


		mTime.SetUpTime(FrameTime);
	}*/
	return true;
}

void Animation::Render(HDC backDC)
{
	if (mbMotion)
	{
		mpImage->RenderImage(backDC, miPosX, miPosY, TILESIZE, TILESIZE, mUseWidth * mCurSpriteCount + mAnimX, mAnimY, miWidth, miHeight);
		return;
	}
	mpImage->RenderImage(backDC, miPosX, miPosY, TILESIZE, TILESIZE, mUseWidth * 1 + mAnimX, mAnimY, miWidth, miHeight);
}

void Animation::Release()
{

}

Animation::Animation(IMAGETYPE pType, OBJECTTAG pTag)
{
	mpImage = IMAGEMGR->GetImage(pType);
	miPosX = 0;
	miPosY = 0;
	miWidth = 0;
	miHeight = 0;
	mTag = pTag;
}


Animation::~Animation()
{
}
