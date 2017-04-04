#include "GameCommon.h"



void Image::LoadBitImage(HDC dc, char * name, DWORD dwColor)
{
	mHdc = dc;
	mDwColor = dwColor;
	
	mHmemDc = CreateCompatibleDC(mHdc);
	mHbit = static_cast<HBITMAP>(LoadImage(nullptr, name, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE));
	SelectObject(mHmemDc, mHbit);

	BITMAP bitInfo;
	GetObject(mHbit, sizeof(BITMAP), &bitInfo);

	miWidth = bitInfo.bmWidth;
	miHeight = bitInfo.bmHeight;
}

void Image::LoadBitImage(HDC dc, char * name, int fx, int fy, DWORD dwColor)
{
	mHdc = dc;
	mDwColor = dwColor;

	mHmemDc = CreateCompatibleDC(mHdc);
	mHbit = static_cast<HBITMAP>(LoadImage(nullptr, name, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE));
	SelectObject(mHmemDc, mHbit);

	BITMAP bitInfo;
	GetObject(mHbit, sizeof(BITMAP), &bitInfo);

	miWidth = bitInfo.bmWidth / fx;
	miHeight = bitInfo.bmHeight / fy;
}

void Image::RenderImage(HDC backHdc, int x, int y)
{
	if (mDwColor == -1)
	{
		BitBlt(backHdc, x, y, miWidth, miHeight, mHmemDc, 0, 0, SRCCOPY);
	}
	else
	{
		TransparentBlt(backHdc, x, y, miWidth, miHeight, mHmemDc, 0, 0, miWidth, miHeight, mDwColor);
	}
}

void Image::RenderImage(HDC backHdc, int posX, int posY, int Width, int Height, int x, int y, int imgX, int imgY)
{
	if(mDwColor == -1)
	{
		BitBlt(backHdc, x, y, miWidth, miHeight, mHmemDc, imgX, imgY, SRCCOPY);
	}
	else
	{
		TransparentBlt(backHdc, posX, posY, Width, Height, mHmemDc, x, y, imgX, imgY, mDwColor);
	}
}
void Image::RenderImage(HDC backHdc, RECT rendRect, RECT cutRect)
{
	if(mDwColor == -1)
	{
		BitBlt(backHdc, rendRect.left, rendRect.top, rendRect.right, rendRect.bottom, mHmemDc, 0, 0, SRCCOPY);
	}
	else
	{
		//매개변수의 의미! 굉장히 중요함!!
		/*

		backHdc		이건 mHmemDc에 있는 그림을 backHdc그리겠다는 것임. 한마디로 그릴 도화지


		x			첫번째 xywh 좌표는 어떠한 그림을 이 크기로 쓰겠다는 것임.
		y			한마디로 0, 0, 10, 10  이라면 어떠한 그림을 0, 0의 좌표부터
		miWidth		오른쪽으로 10만큼
		miHeight	아래로 10만큼 그려주겠다는 것!


		mHmemDc		이 mHmemDc에 있는 그림을 위의 backHdc 로 복사함. 미리 그려져있는 도화지


		0			두번째 xywh 좌표는 어떠한 그림의 크기 중에서 이만큼만 잘라서 쓰겠다는 것임
		0			좌표가 0, 0, 20, 20 이고 현재 mHmemDc에 있는 그림의 크기가 200x100이라면
		width		왼쪽위의 0, 0 에서부터 오른쪽으로 20, 아래쪽으로 20만큼 잘라서 쓰겠다는 것이다.
		height		한마디로 200x100 크기의 그림 중 왼쪽 위 20x20 만 쓰겠다는 것이다.


		mDwColor	이건 간단하게 배경날릴색 지정해주면된다. 좋은 방법은 포토샵같은 프로그램에서 스포이드로 배경색의 rgb값을 구해와서 똑같이 넣어주면 잘 지워준다!

		*/
		//TransparentBlt(backHdc, x, y, rendX, rendY, mHmemDc, 0, 0, width, height, mDwColor);
		TransparentBlt(backHdc, rendRect.left, rendRect.top, rendRect.right, rendRect.bottom, mHmemDc, cutRect.left, cutRect.top, cutRect.right, cutRect.bottom, mDwColor);
	}
}

void Image::RenderImage(HDC backHdc, int x, int y, int imgX, int imgY)
{
	if(mDwColor == -1)
	{
		BitBlt(backHdc, x, y, miWidth, miHeight, mHmemDc, imgX, imgY, SRCCOPY);
	}
	else
	{
		TransparentBlt(backHdc, x, y, miWidth, miHeight, mHmemDc, imgX, imgY, miWidth, miHeight, mDwColor);
	}
}

void Image::RenderImage(HDC backHdc, int x, int y, int w)
{
	if (mDwColor == -1)
	{
		BitBlt(backHdc, x, y, w, miHeight, mHmemDc, 0, 0, SRCCOPY);
	}
	else
	{
		TransparentBlt(backHdc, x, y, miWidth, miHeight, mHmemDc, 0, 0, w, miHeight, mDwColor);
	}
}

void Image::ReleaseImage()
{
	DeleteObject(mHmemDc);
}

Image::Image()
{
	mHdc = nullptr;
	mHmemDc = nullptr;
	mHbit = nullptr;

	mPos.x = 0;
	mPos.y = 0;
	miWidth = 0;
	miHeight = 0;
	mfSpeed = 1.0f;

	mDwColor = 0;
}

Image::~Image()
{
	ReleaseImage();
}
