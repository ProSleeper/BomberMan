#pragma once
class Time
{
public:
	void SetUpTime(float delTimeSecond);
	bool TimeCheck();

	Time();
	virtual ~Time();

private:
	DWORD mDwCurrTime;
	DWORD mDwOldTime;
	int miDelayTime;
};

