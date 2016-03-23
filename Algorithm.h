#ifndef ALGORITHM_INCLUDED
#define ALGORITHM_INCLUDED
#include<iostream>
using std::cout;
using std::endl;

/**Available Functions: Iter_swap(iterator 1, iterator 2), Reverse(iterator first, iterator last), Sort(iterator first, iterator last)**/
/**The Reverse Algorithm reverses the elements in the list from the element in the iterator sent as first to the element
before the element in the iterator sent as last**/
/**The Mergesort Algorithm sorts the element from the iterator sent as first to the element sent from the iterator as last.
Giving last iterator pointing before first will also generate a run-time error here.**/


namespace project
{
          template<class node>
          void Node_swap(node& node1, node& node2) //swaps the data in the nodes.
          {
              node* temp;
              temp = new node;
              temp->data = node1.data;
              node1.data = node2.data;
              node2.data = temp->data;
              delete temp;
          }
          template<class iterator>
          void Iter_swap(iterator iter1, iterator iter2) //takes in iterator class objects and sends it's data to Node_swap to swap the data.
          {
              Node_swap((*iter1), (*iter2));
          }
          template<class iterator>
          void Reverse(iterator first, iterator last)  //the data send through the object 'last' is skipped, thus, a user must call with the iterator 1 step forward to last to reverse elements between first and last. Also, putting in last>first will generate a runtime error.
          {
              while((first!=last)&&(first!=--last))
              {
                 Iter_swap(first,last);
                 ++first;
              }
          }

          template<class iterator, class T> void Merge(iterator first, int low, int pivot, int high, T dataIdentifier)  //merges two sorted list together to make a single sorted list. dataIdentifier is passed to the function to identify the data type of the data saved in deque, it has no other function.
          {
             T* dataList;
             int i=0;
             dataList = new T[high+5];
             iterator endfirstlist = first;
             iterator startsecondlist = first;
             iterator endsecondlist = first;
             //cout << high << endl;
             endsecondlist += (high+1);
             endfirstlist += pivot;
             startsecondlist += pivot;
             first += low;
             iterator start_copy = first;
             while((first!=endfirstlist)&&(startsecondlist!=endsecondlist))
             {
                  if((*first).data < (*startsecondlist).data)
                  {
                        dataList[i] = (*startsecondlist).data;
                       // cout << dataList[i] << " ";
                        i++;
                        startsecondlist++;
                  }
                  else
                  {
                        dataList[i] = (*first).data;
                       // cout << dataList[i] << " ";
                        i++;
                        first++;
                  }
             }
             while(first!=endfirstlist)
             {
                  dataList[i] = (*first).data;
                 // cout << dataList[i] << " ";
                  i++;
                  first++;
             }
             while(startsecondlist!=endsecondlist)
             {
                  dataList[i] = (*startsecondlist).data;
                //  cout << dataList[i] << " ";
                  i++;
                  startsecondlist++;
             }
             i=0;
             while(start_copy!=endsecondlist)
             {
                  start_copy()->data = dataList[i];
                  start_copy++;
                  i++;
             }
             delete dataList;
          }
          template<class iterator> void Mergesort(iterator first, int low, int high) //recursive algorithm that breaks the list to parts and then merges it to sort the list.
          {
              int pivot;
              if (low<high)
              {
                  pivot = (low+high)/2;
                  Mergesort(first, low, pivot);
                  Mergesort(first, pivot+1, high);
                  Merge(first, low, pivot+1, high, (*first).data);
                  return;
              }
              return;
          }
          template<class iterator> void Sort(iterator first, iterator last) //calls mergesort in the appropriate manner
          {
               last--;
               if(first!=last)
               {
                   int low = 0;
                   int high = 0;
                   iterator first_copy = first;
                   while(first++!=last)
                   {
                       high++;
                   }
                   first = first_copy;
                   //cout << high << endl;
                   if (low<high) Mergesort(first, low, high);
               }
          }
}
#endif
