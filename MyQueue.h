#pragma once


template<typedef T>
class MyQueue
{
public:

	void Push();
	T* Pop();


	MyQueue();
	virtual ~MyQueue();

private:
	int mnFront;
	int mnRear;
	static const int arraySize = 100;
	T CircleQueue[arraySize];
};

