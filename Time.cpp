#include "GameCommon.h"



void Time::SetUpTime(float delTimeSecond)
{
	miDelayTime = static_cast<int>(delTimeSecond * 1000);
	mDwOldTime = timeGetTime();
}

bool Time::TimeCheck()
{
	mDwCurrTime = timeGetTime();
	if (mDwCurrTime > mDwOldTime + miDelayTime)
	{
		mDwOldTime = mDwCurrTime;
		return true;
	}
	return false;
}

Time::Time() : mDwCurrTime(0), mDwOldTime(0), miDelayTime(0)
{
}

Time::~Time()
{
}
