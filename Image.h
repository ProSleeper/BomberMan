#pragma once
class Image
{
public:

	PROPERTY_FUNC(HDC, Memdc, mHmemDc)
	PROPERTY_FUNC(int, Width, miWidth)
	PROPERTY_FUNC(int, Height, miHeight)


	void LoadBitImage(HDC dc, char* name, DWORD dwColor = -1);
	void LoadBitImage(HDC dc, char* name, int fx, int fy, DWORD dwColor = -1);
	void RenderImage(HDC backHdc, int x, int y);
	void RenderImage(HDC backHdc, int x, int y, int imgX, int imgY);
	void RenderImage(HDC backHdc, int x, int y, int w);
	void RenderImage(HDC backHdc, RECT rendRect, RECT cutRect);
	void RenderImage(HDC backHdc, int posX, int posY, int Width, int Height, int x, int y, int imgX, int imgY);
	void ReleaseImage();

	Image();
	virtual ~Image();
private:

	HDC mHdc;
	HDC mHmemDc;
	HBITMAP mHbit;

	POINT mPos;
	int miWidth;
	int miHeight;

	float mfSpeed;

	DWORD mDwColor;

};

