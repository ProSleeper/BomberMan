#pragma once
class FrameCheckManager : public SingleTon<FrameCheckManager>
{
public:
	void Init();
	void Update();
	void FpsCheck();
	bool LimitFps();

	FrameCheckManager();
	virtual ~FrameCheckManager();
private:
	Time mFpsTime;
	Time mLimitTime;

	int miFPSCount = 0;
	PROPERTY_FUNC(int, FPS, miFPS)


};

