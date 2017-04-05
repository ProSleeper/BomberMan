#pragma once
class Bomb : public BaseImageObject
{
public:
	

	void Init(int x, int y, int w, int h, int tw, int th, float tTime);
	bool Update();
	void Render(HDC backDC);
	void Release();


	PROPERTY_FUNC(POINT, pPos, mPos)
	PROPERTY_FUNC(int, Width, miWidth)
	PROPERTY_FUNC(int, Height, miHeight)


	Bomb(IMAGETYPE type);
	virtual ~Bomb();
private:
	HDC mHmemDC;
	POINT mPos;
	int miWidth;
	int miHeight;
	Image* mpImage;

};

