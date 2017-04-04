#pragma once
class BaseAnimImageObject : public BaseAnimTransform
{
public:
	
	PROPERTY_FUNC(Image*, Image, mpImage)

		virtual void Init(int rendX, int rendY, int rendWidth, int rendHeight, int cutX, int cutY, int cutWidth, int cutHeight, IMAGETYPE type);
	virtual bool Update() { return true; };
	virtual void Render(HDC backDC);
	virtual void Release() {};

	BaseAnimImageObject();
	virtual ~BaseAnimImageObject();
private:
	Image* mpImage;
};

