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
    int getSize();

};
template<class T>
TQueue<T>::TQueue(int maxSize){
    pMem = new T[maxSize];
    memSize = maxSize;
    lptr = rptr = size = 0;
}
template<class T>
TQueue<T>::~TQueue(){
    delete[] pMem;
}
template<class T>
void TQueue<T>::Push(T elem){
    pMem[rptr]=elem;
    rptr=(rptr+1)%memSize;
    size+=1;
}
template<class T>
T TQueue<T>::Pop(){
    T res = pMem[lptr];
    lptr=(lptr+1)%memSize;
    size--;
    return res;
}

template<class T>
bool TQueue<T>::IsEmpty(){
    return size<=0;
}
template<class T>
bool TQueue<T>::IsFull(){
    return size>=memSize;
}
template<class T>
int TQueue<T>::getSize(){
    return size;
}

#endif