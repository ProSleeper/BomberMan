#pragma once
class Map : public BaseImageObject
{
public:
	
	Map();
	virtual ~Map();
private:
	PROPERTY_FUNC(bool, IsMove, isMove)
};