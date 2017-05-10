#include "GameCommon.h"

void Explosion::Init(int x, int y, int animX, int animY, int tw, int th, float tTime)
{
	miPosX = x;
	miPosY = y;
	mTag = OBJECTTAG::TAG_EXPLOSION;
	mTime.SetUpTime(EXPLODETIME);
	mExplosionAnimation = new LoopAnimation(IMAGETYPE::IT_OBJECT, OBJECTTAG::TAG_EXPLOSION);
	mExplosionAnimation->Init(miPosX, miPosY, animX, animY, 16, 16, tw, th, tTime);

	//에러나서 처리한건데... 이건 아닌듯 나중에 고쳐야함
}

void Explosion::Init(int x, int y)
{
	miPosX = x;
	miPosY = y;
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
	mExplosionAnimation->Update(miPosX, miPosY);
	return true;
}


void Explosion::Render(HDC backDC)
{
	//mpImage->RenderImage(backDC, miPosX, miPosY, TILESIZE, TILESIZE, 69, 100, 16, 16);
	mExplosionAnimation->Render(backDC);
	OBJECTMGR->DrawRect(backDC, miPosX, miPosY);
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
}

Explosion::~Explosion()
{
	Release();
}