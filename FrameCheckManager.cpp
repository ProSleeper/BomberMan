#include "GameCommon.h"


void FrameCheckManager::Init()
{
	mFpsTime.SetUpTime(1.0f);
	mLimitTime.SetUpTime(0.014f);
}

void FrameCheckManager::Update()
{
	FpsCheck();
}

void FrameCheckManager::FpsCheck()
{
	if(mFpsTime.TimeCheck())
	{
		miFPS = miFPSCount;
		miFPSCount = 0;
		return;
	}
	miFPSCount++;
}

bool FrameCheckManager::LimitFps()
{
	if (mLimitTime.TimeCheck())
	{
		return true;
	}
	return false;
}

FrameCheckManager::FrameCheckManager() : miFPSCount(0), miFPS(0)
{
	Init();
}

FrameCheckManager::~FrameCheckManager()
{
}
