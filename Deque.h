 #ifndef DEQUE_INCLUDED_
#define DEQUE_INCLUDED_
#include<typeinfo>
#include<iostream>
#include<cstdlib>
#include<cstring>

#define debug cout<<"Debug"<<endl
using std::cout;
using std::endl;

/* USE PROPER STD::COUT AND STD::ENDL */
/* A KEYWORD WILL GENERATE ERROR IF IT'S SCOPE IS EXPANDED, SO BE CAREFUL OF THAT*/

namespace project{

    struct node;

    template<class T>class Deque{

    protected:
        typedef int size_type;
            size_type _size;

            struct node{
            T data;
            node* prev;
            node* next;

        }*head,*tail;

        node* new_node(void){
            node* temp=NULL;

            try{
                temp=new node;
                temp->next=NULL;
                temp->prev=NULL;
            }
            catch(std::exception& ex){
                if(typeid(ex)==typeid(std::bad_alloc))
                    std::cout<<"Memory allocation error"<<std::endl;
                exit(1);
            }
            return temp;
        }

    public:
        Deque(){
            head=tail=NULL;
            _size=0;
        }

        void pop_back();
        void pop_front();
        void push_front(T data);
        void push_back(T data);
        T front();
        T back();
        bool empty()
        {
            if(!_size) return true;
            else
                return false;
        }

        class iterator{

        public:
            typedef iterator self_type;
            typedef T value_type;
            typedef node& reference;
            typedef node* pointer;
            typedef std::forward_iterator_tag iterator_category;
            int max_count;
            typedef int difference_type;

            iterator() { _ptr=NULL; index=0; max_count=0; addressTable=NULL; s_p=NULL;}

            iterator(pointer ptr) : _ptr(ptr)
            {
                s_p = new self_type;
                if (_ptr->prev == NULL) //it's all about head here
                {
                    index = 0;
                    max_count = 0;
                    while(_ptr!= NULL)      //THIS LOOP IS USED FOR defining max_count, nothing else.
                    {
                         max_count++;
                         _ptr = _ptr->next;
                    }
                    addressTable = new pointer[max_count+1];
                    _ptr = ptr;
                    while(_ptr!=NULL)
                    {
                         addressTable[index] = _ptr;
                         index++;
                         _ptr=_ptr->next;
                    }
                    addressTable[index] = _ptr;
                    _ptr = ptr;   //this head is important because, just after, i=iter.head(); we might wanna do, *i in which case there needs to be a head :)
                    index = 0;
                }

                else if(_ptr->next==NULL)  //it's all about tail here
                {
                    index = 0;
                    max_count = 0;

                    _ptr=_ptr->prev;

                    while(_ptr->prev!=NULL)
                    {
                        _ptr = _ptr->prev;       //taking the head
                        max_count++;
                    }
                    max_count++; //including head
                    addressTable = new pointer[max_count+1]; //we are gonna keep the null too
                    while(_ptr->next!= NULL)
                    {
                         addressTable[index] = _ptr;
                         index++;
                         _ptr = _ptr->next;
                    }
                    addressTable[index] = _ptr; //so we have NULL here, index will be kept as it is because, it's the index of tail->next
                }
            }

            iterator(const iterator& iter){
                *this=iter;
            }
            ~iterator(){
                delete addressTable;
            }
            //preincrement
            self_type& operator++(){
                _ptr=addressTable[++index];
                return *this;
            }
            //postincrement
            self_type& operator++(int notused){
                *s_p=*this;
                _ptr=addressTable[++index];
                return *s_p;
            }
            self_type& operator+=(int offset){
                _ptr = addressTable[index+offset];
                index+=offset;
                return *this;
            }
            //predecrement
            self_type& operator--(){
                _ptr=addressTable[--index];
                return *this;
            }
            //postdecrement
            self_type& operator--(int notused){
                if(_ptr)*s_p=*this;
                _ptr=addressTable[--index];
                return *s_p;
            }
            self_type& operator-=(int offset){
                _ptr = addressTable[index-offset];
                index-=offset;
                return *this;
            }
            reference operator*(){
                return *_ptr;
            }
            pointer operator()(){
                return _ptr;
            }
            difference_type  operator-(const self_type right_side){
                return index - right_side.index;
            }
            difference_type operator+(const self_type right_side) {
                return index+ right_side.index;
            }
            bool operator==(const self_type &right_side) const{
                return _ptr==right_side._ptr;
            }
            bool operator!=(const self_type &right_side) const{
                return _ptr!=right_side._ptr;
            }

            self_type& operator=(const self_type& iter){
                _ptr=iter._ptr;
                addressTable=new pointer[iter.max_count+1];
                for(int i=0;i<iter.max_count;i++)
                    addressTable[i]=iter.addressTable[i];

                index=iter.index;
                 max_count = iter.max_count;
                 s_p = iter.s_p;
                 return *this;
            }
            difference_type _index(){
                return index;
            }
        private:
            pointer _ptr;
            self_type* s_p;
            int index;
            pointer* addressTable;
        };

        iterator begin()
        {
            return iterator(head);
        }

        iterator end()
        {
            return iterator(tail->next);
        }


    };


    template<class T> void Deque<T>::pop_back(){
         _size--;
        node* sentinel=tail->next;
        node* temp=tail->prev;
        delete tail;
        tail=temp;
        if(tail)
            tail->next=sentinel;
        else
            delete sentinel;
     }

    template<class T> void Deque<T>::pop_front(){
        _size--;
        node* temp=head->next;
        if(temp->next==NULL)
        {
            delete temp;
            exit(1);
        }
        delete head;
        head=temp;
        if(head)
            head->prev=NULL;
    }

    template<class T> void Deque<T>::push_back(T data){
        node* temp=new_node();
        _size++;
        if(head==NULL){
            head=temp;
            head->next=NULL;
            head->data=data;
            head->prev=NULL;
            tail=head;
            tail->next=new_node();  //SENTINEL
            temp=tail->next;
            temp->prev=tail;
            temp->next=NULL;
            return;
        }
        temp->prev=tail;  //THIS WILL ADD A NODE TO THE TAIL
        tail->next=temp;
        temp->data=data;
        tail=temp;
        tail->next=new_node();  //THIS WILL ADD A SENTINEL AFTER THE TAIL
        temp=tail->next;
        temp->prev=tail;
        temp->next=NULL;
    }

    template<class T> void Deque<T>::push_front(T data){
        node* temp=new_node();
         _size++;
        if(tail==NULL){
            head=temp;
            head->next=NULL;
            head->data=data;
            head->prev=NULL;
            tail=head;
            tail->next=new_node();
            temp=tail->next;
            temp->prev=tail;
            temp->next=NULL;
            return;
        }
        temp->next=head;  //SENTINEL
        head->prev=temp;
        temp->prev=NULL;
        temp->data=data;
        head=temp;
    }

    template<class T> T Deque<T>::front(){
        return head->data;
    }

    template<class T> T Deque<T>::back(){
        return tail->data;
    }
}

#endif
