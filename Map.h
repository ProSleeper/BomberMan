#pragma once
class Map : public BaseImageObject
{
public:
	PROPERTY_FUNC(bool, IsMove, isMove)

	Map();
	virtual ~Map();
private:
	bool isMove;
};

//baseImage
//PROPERTY_FUNC(Image*, Image, mpImage)
//
//virtual void Init(int rendX, int rendY, int x, int y, int w, int h, IMAGEBIT type);
//virtual bool Update() { return false; };
//virtual void Render(HDC backDC);
//virtual void Release() {};
//
//BaseImageObject();
//virtual ~BaseImageObject();
//	Image* mpImage;


//baseTranform
//	PROPERTY_FUNC(POINT, pPos, mPos)
//		PROPERTY_FUNC(int, Width, miWidth)
//		PROPERTY_FUNC(int, Height, miHeight)
//
//		BaseTransform();
//	virtual ~BaseTransform();
//	POINT mRect;
//	POINT mPos;
//	int miWidth;
//	int miHeight;