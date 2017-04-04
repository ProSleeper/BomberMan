#pragma once
class BaseTargetObject : public BaseImageObject
{
public:
	virtual void OnCollisionEnter(BaseTransform* pCollObj) {}

	PROPERTY_FUNC(bool, Life, mbLife)
	PROPERTY_FUNC(float, Speed, mfSpeed)
	PROPERTY_FUNC(int, Hp, miHp)
	PROPERTY_FUNC(int, MaxHp, miMaxHp)
		
	BaseTargetObject();
	virtual ~BaseTargetObject();

protected:
	bool mbLife;
	float mfSpeed;
	int miHp;
	int miMaxHp;
	

	
};

