#ifndef AUTO_PTR_H_INCLUDED
#define AUTO_PTR_H_INCLUDED
#include <iostream>
#include<cstdlib>

using std::cout;
using std::endl;
namespace project{
    template<typename T>
    struct Auto_Ptr_Ref
    {
           T* _ptr;
           Auto_Ptr_Ref(T* ptr) : _ptr(ptr){}
    };
    template<typename T>
    class Auto_Ptr
    {
           T* _ptr;
    public:
           Auto_Ptr(T* ptr = NULL) : _ptr(ptr){}
           Auto_Ptr(Auto_Ptr& ob) : _ptr(ob.release()) {}
           template<class DerivedType>
           Auto_Ptr(Auto_Ptr<DerivedType>& ob) : _ptr(ob.release()){}
           Auto_Ptr(Auto_Ptr_Ref<T> ref): _ptr(ref._ptr){}
           ~Auto_Ptr()
           {
                if(_ptr!=NULL){
                    delete _ptr;
                    cout << "pointer deleted" << endl;
                }
           }
           T* get()
           {
                return _ptr;
           }
           T* release()
           {
                T* temp = _ptr;
                _ptr = NULL;
                return temp;
           }
           void reset(T* ptr = NULL)
           {
                if(_ptr!=ptr)
                {
                    if(_ptr!=NULL)
                        delete _ptr;
                    _ptr = ptr;
                }
           }
           T operator*() const {
                if(_ptr!=NULL)
                    return *_ptr;
                else
                {
                    cout << "No pointer assigned to Auto Pointer." << endl;
                    exit(0);
                }
           }
           T* operator->() const {
                if(_ptr!=NULL) return _ptr;
                else
                {
                    cout << "No pointer assigned to Auto Pointer." << endl;
                    exit(0);
                }
           }
           Auto_Ptr& operator=(Auto_Ptr& ob)
           {
                reset(ob.release());
                return *this;
           }
           template<class DerivedType>
           Auto_Ptr& operator=(Auto_Ptr<DerivedType>& ob)
           {
                reset(ob.release());
                return *this;
           }
           Auto_Ptr& operator=(Auto_Ptr_Ref<T> ref)
           {
                if(ref._ptr != this->get())
                {
                     if(_ptr!=NULL) delete _ptr;
                     _ptr = ref._ptr;
                }
                return *this;
           }
           template<class DerivedType>
           operator Auto_Ptr_Ref<DerivedType>()
           {
               return Auto_Ptr_Ref<DerivedType>(this->release());
           }
    };
}
#endif
