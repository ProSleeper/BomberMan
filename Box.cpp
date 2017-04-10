#include "GameCommon.h"


void Box::Init(int x, int y, int w, int h, int tw, int th, float tTime)
{
	miPosX = x;
	miPosY = y;
	miWidth = w;
	miHeight = h;
	mIsLife = true;
	mTime.SetUpTime(0);
	mBoxAnimation[0] = new Animation(IMAGETYPE::IT_OBJECT, OBJECTTAG::TAG_BOX);
	mBoxAnimation[0]->Init(miPosX, miPosY, 69, 32, 16, 16, 68, 17, 0.1f);

	mBox = mBoxAnimation[0];

	mTag = OBJECTTAG::TAG_BOX;
}

bool Box::Update()
{
	mBox->Update(miPosX, miPosY);
	if(mTime.TimeCheck())
	{
		return mIsLife;
	}
	
	return true;
}

void Box::Render(HDC backDC)
{
	//mpImage->RenderImage(backDC, miPosX, miPosY, miWidth, miHeight, 69, 32, 16, 16);
	mBox->Render(backDC);
	/*int temp = SetROP2(backDC, R2_MASKPEN);
	Rectangle(backDC, miPosX, miPosY, miPosX + 60, miPosY + 60);
	SetROP2(backDC, temp);*/
}

void Box::Release()
{
}

Box::Box()
{
	//mpImage = IMAGEMGR->GetImage(IMAGETYPE::IT_OBJECT);
	miPosX = 0;
	miPosY = 0;
	miWidth = 0;
	miHeight = 0;
}


Box::~Box()
{
	Release();
}

void Box::DestroyBox()
{
	mTime.SetUpTime(0.6f);
	mBoxAnimation[1] = new Animation(IMAGETYPE::IT_OBJECT, OBJECTTAG::TAG_BOX);
	mBoxAnimation[1]->Init(miPosX, miPosY, 1, 151, 16, 16, 102, 17, 0.1f);
	mBox = mBoxAnimation[1];
	delete mBoxAnimation[0];
	mIsLife = false;
	MAPMGR->SetMove(miPosY/ TILESIZE, miPosX / TILESIZE, true);
}
