#include "GameCommon.h"

void ImageManager::LoadImages(HDC dc)
{
	mImage[static_cast<int>(IMAGETYPE::IT_BACK)].LoadBitImage(dc, "bmp/BackGround.bmp", RGB(255, 111, 222));
	mImage[static_cast<int>(IMAGETYPE::IT_BACKGROUND)].LoadBitImage(dc, "bmp/bg.bmp");
	mImage[static_cast<int>(IMAGETYPE::IT_OBJECT)].LoadBitImage(dc, "bmp/Peacetown.bmp", RGB(24, 158, 93));
	mImage[static_cast<int>(IMAGETYPE::IT_PLAYER)].LoadBitImage(dc, "bmp/Character.bmp", RGB(64, 144, 56));
	mImage[static_cast<int>(IMAGETYPE::IT_ENEMY)].LoadBitImage(dc, "bmp/Enemy2Plus.bmp", RGB(48, 136, 160));
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
