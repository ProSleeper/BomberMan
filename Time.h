#pragma once
class Time
{
public:
	void SetUpTime(float delTimeSecond);
	bool TimeCheck();



	Time();
	virtual ~Time();

private:
	DWORD mDwCurrTime = 0;
	DWORD mDwOldTime = 0;
	int miDelayTime = 0;
};

