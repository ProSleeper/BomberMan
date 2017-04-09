#pragma once
class BaseTransform
{
public:
	PROPERTY_FUNC(int, PosX, miPosX)
	PROPERTY_FUNC(int, PosY, miPosY)
	PROPERTY_FUNC(int, Width, miWidth)
	PROPERTY_FUNC(int, Height, miHeight)
	PROPERTY_FUNC(RECT, Rect, mCutRect)
	
	PROPERTY_FUNC(OBJECTTAG, Tag, mTag)
	
	PROPERTY_FUNC(bool, Collider, mbCollider)
	


	BaseTransform();
	virtual ~BaseTransform();
protected:
	int miPosX;
	int miPosY;
	int miWidth;
	int miHeight;
	RECT mCutRect;
	bool mbCollider;
	OBJECTTAG mTag;
};

