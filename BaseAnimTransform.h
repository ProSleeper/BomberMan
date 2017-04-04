#pragma once
class BaseAnimTransform
{
public:

	PROPERTY_FUNC(RECT, pRendRect, mRendRect)
		PROPERTY_FUNC(RECT, pCutRect, mCutRect)
		//PROPERTY_FUNC(int, Speed, mSpeed)

		BaseAnimTransform();
	virtual ~BaseAnimTransform();
protected:
	RECT mRendRect;
	RECT mCutRect;
};

