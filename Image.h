#pragma once
class Image
{
public:

	PROPERTY_FUNC(HDC, Memdc, mHmemDc)

	void LoadBitImage(HDC dc, char* name, DWORD dwColor = -1);
	void RenderImage(HDC backHdc, RECT rendRect, RECT cutRect);
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


	DWORD mDwColor;

};

