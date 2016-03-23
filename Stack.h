#ifndef STACK_INCLUDED_
#define STACK_INCLUDED_
#include "Deque.h"


/**
This header contains the Queue template class, all of it's functionalities are defined in the base class it inherits from.
Queue is basicially a first in - first out philosophy data structure.

Stack is basically a "first in - last out" type data structure

The following operations are available for Queue-

i) void push(T data) //Inserts an element to the stack
ii)void pop() //deletes the last element added to the Stack
iii)T top() //returns the last element added to the Stack
iv)iterator begin() //this function returns an iterator to the first element of the container
v)iterator end() //this function returns an iterator next to the end of the container


*/


namespace project{

template<class T> class Stack : public Deque<T>
{
public:

    Stack() : Deque<T>(){}
    void push(T data){
        Deque<T>::push_front(data);
    }
    void pop(){
        Deque<T>::pop_front();
    }
    T top(){
        Deque<T>::front();
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
