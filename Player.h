#pragma once
class Player : public BaseImageObject
{
public:

	bool Update() override;
	void Release() override;


	Player();
	virtual ~Player();
private:

};