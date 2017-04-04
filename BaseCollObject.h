#pragma once
class BaseCollObject : public BaseTransform
{
public:

	PROPERTY_FUNC(BaseTransform*, Target, mpTarget)
	void Init(BaseTransform* pTarget);
	void Update();
	void Render(HDC backDC);

	BaseCollObject();
	virtual ~BaseCollObject();


private:
	BaseTransform* mpTarget;
};

