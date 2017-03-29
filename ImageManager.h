#pragma once

class ImageManager : public SingleTon<ImageManager>
{
public:

	void LoadImages(HDC dc);
	Image* GetImage(IMAGEBIT type);

	ImageManager();
	virtual ~ImageManager();

private:
	Image mImage[static_cast<int>(IMAGEBIT::IMGBIT_MAX)];
};

