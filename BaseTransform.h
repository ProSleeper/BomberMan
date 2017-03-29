#pragma once
class BaseTransform
{
public:
	PROPERTY_FUNC(RECT, pRendRect, mRendRect)
	PROPERTY_FUNC(RECT, pCutRect, mCutRect)

	BaseTransform();
	virtual ~BaseTransform();
protected:
	RECT mRendRect;
	RECT mCutRect;
};

