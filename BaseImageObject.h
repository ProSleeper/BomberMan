#pragma once
class BaseImageObject : public BaseTransform
{
public:
	PROPERTY_FUNC(Image*, Image, mpImage)

	virtual void Init(int rendX, int rendY, int rendWidth, int rendHeight, int cutX, int cutY, int cutWidth, int cutHeight, IMAGEBIT type);
	virtual bool Update() {return false;};
	virtual void Render(HDC backDC);
	virtual void Release() {};

	BaseImageObject();
	virtual ~BaseImageObject();
private:
	Image* mpImage;

};

