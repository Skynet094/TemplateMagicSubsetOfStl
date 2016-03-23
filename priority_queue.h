#ifndef PRIORITY_QUEUE_INCLUDED
#define PRIORITY_QUEUE_INCLUDED

/** This header includes the priorty queue template, which has heap as it's internal data structure.

The available built in function are (taking 'T' as the template data type)-
    i)void push(T data)
    ii)T top() //this function returns the highest priority element
    iii)void pop() //this function removes the highest priority element
    iv)bool empty() //this function returns a bool value which denotes whether the container is empty
    v)int size() //this function returns the size

**/

/**
    CONSTRAINS TO BE NOTED:

    i) The template types *must* have a blank parametrized constructor //for array creation
    ii) The template types should have ">" operator function overloaded //this is used for comparison purposes

**/

namespace project
{



template<class T> class priority_Queue {

private:
    int current_size;
    T* heap_array;
    int number_of_elements;
public:
    priority_Queue();
    void push( T data );
    T top();
    void pop();
    int size();
    bool empty();
};

template<class T> priority_Queue<T>::priority_Queue()
{
    number_of_elements=0;
    current_size=1000  ;
    heap_array=new T[current_size+1];
}

template<class T> void priority_Queue<T>::push( T data )
{
    if( number_of_elements == current_size )
    {
            T* temp;
            temp=new T[current_size+1];

            for(int i=0;i<=current_size;i++)
                    temp[i]=heap_array[i];

            heap_array= new T[2*current_size+1]; //+1 for the current element

            for(int i=0;i<=current_size;i++)
                heap_array[i]=temp[i];

            current_size+=current_size;

    }

    ++number_of_elements;

    heap_array[number_of_elements] = data; //added to the bottom right most position
    int p = number_of_elements; //position of the leave//current element in the tree

    while( p > 1 )  //so that at the last iteration p==1
    {
        int parent = p / 2;

        if( heap_array[parent] > heap_array[p] )  //leave to root necessary swaps
        {
            std::swap( heap_array[parent], heap_array[p] );
            p = parent;
        }

        else
            break;   //if heap property found, the task is complete
    }
}


template<class T>T priority_Queue<T>::top() //returning the root
{
    return heap_array[1];
}


template<class T>void priority_Queue<T>::pop() {
    if( number_of_elements == 0 )
    {
        exit(1);
    }

    T min_value = heap_array[1];
    heap_array[1] = heap_array[number_of_elements]; //replacing root with the value of the bottom- right most level
    number_of_elements--;

    int parent = 1;

    while( 2 * parent <= number_of_elements )  //root to bottom compare and necessary swaps
    {
        int child = 2 * parent;

        if( 2 * parent + 1 <= number_of_elements ) // this check is necessary, otherwise overflow will be introduced when parent== number_of_elements
        {
            if( heap_array[child] > heap_array[child+1] ) //determining which child is smaller
                    child++;
            }
            if( heap_array[parent] > heap_array[child] )  //whether parent is greater than the child if so, swap
            {
                std::swap( heap_array[parent], heap_array[child] );
                parent = child;  //the current parent is the index of the child which has a smaller value than the previous root
            }

            else
                break;
        }
}

template<class T>int priority_Queue<T>::size()
{
    return number_of_elements;
}

template<class T>bool priority_Queue<T>::empty()
{
    if(!number_of_elements)
        return true;
    return false;
}
}
#endif // PRIORITY_QUEUE_INCLUDED
