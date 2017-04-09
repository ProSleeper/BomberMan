#pragma once
class BaseImageObject : public BaseTransform
{
public:
	PROPERTY_FUNC(Image*, Image, mpImage)
	PROPERTY_FUNC(bool, IsMove, isMove)
	PROPERTY_FUNC(bool, IsLife, mIsLife)

	virtual void Init(int rendX, int rendY, int rendWidth, int rendHeight, int cutX, int cutY, int cutWidth, int cutHeight, IMAGETYPE type);
	virtual void Init(int x, int y, int w, int h, IMAGETYPE type);
	virtual void Init(int x, int y, IMAGETYPE type);
	virtual bool Update() { return true; }
	virtual void Render(HDC backDC);
	virtual void Render(HDC backDC, Image* pBack, int w);
	virtual void Release(){}
	virtual void OnCollisionEnter(BaseTransform* pCollObj) {}
	virtual void ImageChange(int x, int y);

	BaseImageObject();
	virtual ~BaseImageObject();
protected:
	Image* mpImage;
	bool isMove;
	bool mIsLife;
	Time mTime;
	
};

