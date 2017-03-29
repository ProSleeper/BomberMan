#include "SingleTon.h"

template<typename T>
T* SingleTon<T>::instance = nullptr;

template<typename T>
T* SingleTon<T>::Instance()
{
	if(instance == nullptr)
	{
		instance = new T;
	}
	return instance;
}

template<typename T>
void SingleTon<T>::Destroy()
{
	if(instance != nullptr)
	{
		delete instance;
		instance = nullptr;
	}
}

template<typename T>
SingleTon<T>::SingleTon()
{
}

template<typename T>
SingleTon<T>::~SingleTon()
{
}