#ifndef __TQUEUE_H
#define __TQUEUE_H
template<class T>
class TQueue{
	T* pMem;
	int memSize;
	int lptr,rptr,size;

public:
	TQueue(int maxSize = 10);
	~TQueue();
	void Push(T elem);
	T Pop();
	bool IsEmpty();
	bool IsFull();

};
TQueue::TQueue(int maxSize){
	pMem = new T[maxSize];
	memSize = maxSize;
	lptr = rptr = size = 0;
}
TQueue::~TQueue(){
	delete[] pMem;
}

TQueue::Push(T elem){

}

#endif