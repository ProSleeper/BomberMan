#pragma once
class Enemy : public BaseTargetObject
{
public:
	
	bool Update() override;
	void OnCollisionEnter(BaseTransform* pCollObj) override;

	PROPERTY_FUNC(RECT, CollRect, mCollRect)


	Enemy();
	virtual ~Enemy();
private:
	//HDC mHmemDC;
	RECT mCollRect;
};

