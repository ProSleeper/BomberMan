#pragma once
class Animation : public BaseImageObject
{
public:

	virtual void Init(int x, int y, int MoveX, int MoveY, int w, int h, int totalWidth, int useWidth, float frameTime, bool bMotion = true);
	virtual bool Update(int x, int y);
	void Render(HDC backDC) override;
	void Release();
	PROPERTY_FUNC(bool, Motion, mbMotion)

	Animation(IMAGETYPE pType, OBJECTTAG pTag);
	virtual ~Animation();
protected:
	int mAnimX;
	int mAnimY;
	int mTotalWidth;
	int mUseWidth;
	int mCurSpriteCount;
	int mMaxSpriteCount;

	float mAnimOldTime;
	float mAnimCurTime;
	int FrameMove;
	float FrameTime;
	bool mbMotion;
};

