#pragma once
class BaseTransform
{
public:
	PROPERTY_FUNC(float, PosX, mfPosX)
	PROPERTY_FUNC(float, PosY, mfPosY)
	PROPERTY_FUNC(int, Width, miWidth)
	PROPERTY_FUNC(int, Height, miHeight)
	OBJECTTAG mTag;
	PROPERTY_FUNC(OBJECTTAG, Tag, mTag)
	
	PROPERTY_FUNC(bool, Collider, mbCollider)
	


	BaseTransform();
	virtual ~BaseTransform();
protected:
	float mfPosX;
	float mfPosY;
	int miWidth;
	int miHeight;
	bool mbCollider;
};

