#include "GameCommon.h"

void ImageManager::LoadImages(HDC dc)
{
	mImage[static_cast<int>(IMAGETYPE::IT_BACK)].LoadBitImage(dc, "bmp/BackGround.bmp", RGB(255, 111, 222));
	mImage[static_cast<int>(IMAGETYPE::IT_BACKGROUND)].LoadBitImage(dc, "bmp/bg.bmp");
	mImage[static_cast<int>(IMAGETYPE::IT_OBJECT)].LoadBitImage(dc, "bmp/PeacetownNormalize.bmp", RGB(24, 158, 93));
	mImage[static_cast<int>(IMAGETYPE::IT_PLAYER)].LoadBitImage(dc, "bmp/Bomberman.bmp", RGB(255, 0, 255));
	mImage[static_cast<int>(IMAGETYPE::IT_ENEMY)].LoadBitImage(dc, "bmp/W1_Enemies.bmp", RGB(255, 0, 255));
}

Image* ImageManager::GetImage(IMAGETYPE type)
{
	return &mImage[static_cast<int>(type)];
}


ImageManager::ImageManager()
{
}

ImageManager::~ImageManager()
{
}
