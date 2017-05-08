#pragma once
class BaseTargetObject : public BaseImageObject
{
public:
	virtual void OnCollisionEnter(BaseTransform* pCollObj) {}

	
		
	BaseTargetObject();
	virtual ~BaseTargetObject();

protected:
	PROPERTY_FUNC(bool, Life, mbLife)
		PROPERTY_FUNC(float, Speed, mfSpeed)
		PROPERTY_FUNC(int, Hp, miHp)
		PROPERTY_FUNC(int, MaxHp, miMaxHp)
};

