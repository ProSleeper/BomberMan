#include "GameCommon.h"
#include <assert.h>

template<typename T>
void MyQueue<T>::Push(T data)
{
	if(NextIdx(mnRear) == mnFront)
	{
		assert(!"큐가 꽉 찼음");
	}

	mnRear = NextIdx(mnRear);
	mCircleQueue[mnRear] = data;
}

template<typename T>
T MyQueue<T>::Pop()
{

	if(IsEmpty())
	{
		assert(!"큐가 비었음");
	}

	mnFront = NextIdx(mnFront);
	return mCircleQueue[mnFront];
}

template<typename T>
T MyQueue<T>::Peek()
{

	if(IsEmpty())
	{
		assert(!"큐가 비었음");
	}

	return mCircleQueue[NextIdx(mnFront)];
}

template<typename T>
bool MyQueue<T>::IsEmpty()
{
	if(mnRear == mnFront)
	{
		return true;
	}
	return false;
}

template<typename T>
bool MyQueue<T>::IsFull()
{
	if(((mnRear % mArraySize) + 1) == mnFront)
	{
		return true;
	}
	return false;
}

template<typename T>
int MyQueue<T>::NextIdx(int arrIdx)
{
	if(arrIdx == mArraySize - 1)
	{
		return 0;
	}
	return arrIdx + 1;
}

template<typename T>
MyQueue<T>::MyQueue()
{
	mnFront = 0;
	mnRear = 0;
}

template<typename T>
MyQueue<T>::~MyQueue()
{
	delete[] mCircleQueue;
}