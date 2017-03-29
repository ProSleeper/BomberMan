#pragma once
class Explosion
{
public:
	

	void Init(int x, int y, int w, int h, int tw, int th, int tTime);
	void Update();
	void Render(HDC backDC);
	void Release();


	PROPERTY_FUNC(POINT, pPos, mPos)
	PROPERTY_FUNC(bool, IsUse, mIsUse)
	PROPERTY_FUNC(int, Width, miWidth)
	PROPERTY_FUNC(int, Height, miHeight)
	PROPERTY_FUNC(RECT, CollRect, mCollRect)

	PROPERTY_FUNC(int, TotalTime, miTotalTime)
	PROPERTY_FUNC(int, FrameX, miFrameX)
	PROPERTY_FUNC(int, FrameY, miFrameY)
	PROPERTY_FUNC(int, CurFrame, miCurFrame)
	PROPERTY_FUNC(int, CurFrameX, miCurFrameX)
	PROPERTY_FUNC(int, CurFrameY, miCurFrameY)
	PROPERTY_FUNC(int, CurTime, miCurTime)

	Explosion();
	virtual ~Explosion();
private:
	HDC mHmemDC;
	POINT mPos;
	int miWidth;
	int miHeight;
	int miTotalWidth;
	int miTotalHeight;
	int miTotalTime;

	int miFrameX;
	int miFrameY;
	int miCurFrameX;
	int miCurFrameY;
	int miCurFrame;
	int miTotalFrame;
	int miNextTime;
	int miCurTime;
	int miOldTime;
	int miCalTime;

	bool mIsUse;
	RECT mCollRect;
	Enemy* mpEnemy;
};

