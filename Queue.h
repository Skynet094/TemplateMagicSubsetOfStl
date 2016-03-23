#ifndef QUEUE_INCLUDED_
#define QUEUE_INCLUDED_
#include "Deque.h"
namespace project{


/**
This header contains the Queue template class, all of it's functionalities are defined in the base class it inherits from.
Queue is basicially a first in - first out philosophy data structure.

The following operations are available for Queue-

i) void push_back(T data) //Inserts an element at the end of the Queue
ii)void pop_front() //deletes the first element of the Queue
iii)T front() //returns the element which is at the front of the Queue
iv)T back() // returns the element which is at the back of the Queue
v)iterator begin() //this function returns an iterator to the first element of the container
vi)iterator end() //this function returns an iterator next to the end of the container

*/

template<class T>class Queue : public Deque<T>
{
public:
    Queue() : Deque<T>(){}
    void push(T data){
        Deque<T>::push_back(data);
    }

    T front(){
        return Deque<T>::front();
    }
    T back(){
        return Deque<T>::back();
    }
    void pop(){
        Deque<T>::pop_front();
    }

    typename project::Deque<T>::iterator begin()
    {
        return Deque<T>::begin();
    }
   typename project::Deque<T>::iterator end()
    {
        return Deque<T>::end();
    }
};

}
#endif
