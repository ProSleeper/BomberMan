#include "GameCommon.h"


void FrameCheckManager::Init()
{
	mFpsTime.SetUpTime(1.0f);
	mLimitTime.SetUpTime(0.01f);
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

FrameCheckManager::FrameCheckManager()
{
	Init();
}

FrameCheckManager::~FrameCheckManager()
{
}
