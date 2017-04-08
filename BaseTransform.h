#pragma once
class BaseTransform
{
public:
	PROPERTY_FUNC(int, PosX, mfPosX)
	PROPERTY_FUNC(int, PosY, mfPosY)
	PROPERTY_FUNC(int, Width, miWidth)
	PROPERTY_FUNC(int, Height, miHeight)
	PROPERTY_FUNC(RECT, Rect, mCutRect)
	OBJECTTAG mTag;
	PROPERTY_FUNC(OBJECTTAG, Tag, mTag)
	
	PROPERTY_FUNC(bool, Collider, mbCollider)
	


	BaseTransform();
	virtual ~BaseTransform();
protected:
	int mfPosX;
	int mfPosY;
	int miWidth;
	int miHeight;
	RECT mCutRect;
	bool mbCollider;
};

