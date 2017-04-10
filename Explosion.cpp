#include "GameCommon.h"

void Explosion::Init(int x, int y, int w, int h, int tw, int th, float tTime)
{
	miPosX = x;
	miPosY = y;
	miWidth = w;
	miHeight = h;
	mTag = OBJECTTAG::TAG_EXPLOSION;
	mTime.SetUpTime(EXPLODETIME);
}

void Explosion::Init(int x, int y)
{
	miPosX = x;
	miPosY = y;
	miWidth = TILESIZE;
	miHeight = TILESIZE;
	mTag = OBJECTTAG::TAG_EXPLOSION;
	mTime.SetUpTime(EXPLODETIME);
}

bool Explosion::Update()
{
	if(mTime.TimeCheck())
	{
		//MAPMGR->SetMove(miPosY / TILESIZE, miPosX / TILESIZE, true);
		return false;
	}
	return true;
}


void Explosion::Render(HDC backDC)
{
	mpImage->RenderImage(backDC, miPosX, miPosY, TILESIZE, TILESIZE, 69, 100, 16, 16);
	/*int temp = SetROP2(backDC, R2_MASKPEN);
	Rectangle(backDC, miPosX, miPosY, miPosX + 60, miPosY + 60);
	SetROP2(backDC, temp);*/
	//mpImage->RenderImage(backDC, mPos.x, mPos.y, miWidth, miHeight, x, y, miWidth, miHeight);
}

void Explosion::Release()
{
}

Explosion::Explosion()
{
	mpImage = IMAGEMGR->GetImage(IMAGETYPE::IT_OBJECT);
	miPosX = 0;
	miPosY = 0;
	miWidth = 0;
	miHeight = 0;
}

Explosion::~Explosion()
{
	Release();
}