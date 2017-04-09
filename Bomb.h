#pragma once
class Bomb : public BaseImageObject
{
public:
	

	void Init(int x, int y, int w, int h, int tw, int th, float tTime);
	bool Update() override;
	void Render(HDC backDC);
	void Release();
	void DistanceExplode();
	void TimeBomb();

	PROPERTY_FUNC(int, Width, miWidth)
	PROPERTY_FUNC(int, Height, miHeight)


	Bomb();
	virtual ~Bomb();
private:
	HDC mHmemDC;
	Image* mpImage;
	RECT mBombRect;
	bool mUp;
	bool mDown;
	bool mLeft;
	bool mRight;
};

