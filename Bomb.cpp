#include "GameCommon.h"

void Bomb::Init(int x, int y, int w, int h, int tw, int th, float tTime)
{
	mPos.x = x;
	mPos.y = y;
	miWidth = w;
	miHeight = h;
}

bool Bomb::Update()
{
	
	return true;
}


void Bomb::Render(HDC backDC)
{
	mpImage->RenderImage(backDC, mPos.x, mPos.y, miWidth, miHeight, 137, 151, 16, 16);
	int temp = SetROP2(backDC, R2_MASKPEN);
	Rectangle(backDC, mPos.x, mPos.y, mPos.x + 60, mPos.y + 60);
	SetROP2(backDC, temp);
	//mpImage->RenderImage(backDC, mPos.x, mPos.y, miWidth, miHeight, x, y, miWidth, miHeight);
}

void Bomb::Release()
{
}

Bomb::Bomb(IMAGETYPE type)
{
	mpImage = IMAGEMGR->GetImage(type);
	mPos.x = 0;
	mPos.y = 0;
	miWidth = 0;
	miHeight = 0;
}

Bomb::~Bomb()
{
	Release();
}
