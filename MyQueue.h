#pragma once
template<typename T>
class MyQueue
{
public:
	void Push(T data);
	T Pop();
	T Peek();

	bool IsEmpty();
	bool IsFull();
	int NextIdx(int arrIdx);

	MyQueue();
	virtual ~MyQueue();

private:
	int mnFront;
	int mnRear;
	static const int mArraySize = 5;
	T mCircleQueue[mArraySize] = {0,};
};



