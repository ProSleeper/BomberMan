#pragma once
class BaseImageObject : public BaseTransform
{
public:
	PROPERTY_FUNC(Image*, Image, mpImage)

	virtual void Init(int x, int y, int w, int h, IMAGETYPE type);
	virtual void Init(int x, int y, IMAGETYPE type);
	virtual bool Update() { return true; }
	virtual void Render(HDC backDC);
	virtual void Render(HDC backDC, Image* pBack, int w);
	virtual void Release(){}

	BaseImageObject();
	virtual ~BaseImageObject();
protected:
	Image* mpImage;
};

