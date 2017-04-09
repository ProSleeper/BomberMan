#pragma once
class Explosion : public BaseImageObject
{
public:
	void Init(int x, int y, int w, int h, int tw, int th, float tTime);
	void Init(int x, int y);
	bool Update() override;
	void Render(HDC backDC);
	void Release();

	PROPERTY_FUNC(int, Width, miWidth)
		PROPERTY_FUNC(int, Height, miHeight)

	Explosion();
	virtual ~Explosion();
private:
	HDC mHmemDC;
	Image* mpImage;
	Time mTime;

	float EXPLODETIME = 0.5f;
};

