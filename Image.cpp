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
		//�Ű������� �ǹ�! ������ �߿���!!
		/*

		backHdc		�̰� mHmemDc�� �ִ� �׸��� backHdc�׸��ڴٴ� ����. �Ѹ���� �׸� ��ȭ��


		x			ù��° xywh ��ǥ�� ��� �׸��� �� ũ��� ���ڴٴ� ����.
		y			�Ѹ���� 0, 0, 10, 10  �̶�� ��� �׸��� 0, 0�� ��ǥ����
		miWidth		���������� 10��ŭ
		miHeight	�Ʒ��� 10��ŭ �׷��ְڴٴ� ��!


		mHmemDc		�� mHmemDc�� �ִ� �׸��� ���� backHdc �� ������. �̸� �׷����ִ� ��ȭ��


		0			�ι�° xywh ��ǥ�� ��� �׸��� ũ�� �߿��� �̸�ŭ�� �߶� ���ڴٴ� ����
		0			��ǥ�� 0, 0, 20, 20 �̰� ���� mHmemDc�� �ִ� �׸��� ũ�Ⱑ 200x100�̶��
		width		�������� 0, 0 �������� ���������� 20, �Ʒ������� 20��ŭ �߶� ���ڴٴ� ���̴�.
		height		�Ѹ���� 200x100 ũ���� �׸� �� ���� �� 20x20 �� ���ڴٴ� ���̴�.


		mDwColor	�̰� �����ϰ� ��泯���� �������ָ�ȴ�. ���� ����� ���伥���� ���α׷����� �����̵�� ������ rgb���� ���ؿͼ� �Ȱ��� �־��ָ� �� �����ش�!

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
