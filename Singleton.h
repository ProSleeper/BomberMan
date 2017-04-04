#pragma once

template<typename T>
class SingleTon
{
public:

	static T* Instance();
	void Destroy();

	SingleTon();
	virtual ~SingleTon();
private:

	static T* instance;
};