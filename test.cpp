#include "Auto_Ptr.h"
#include <iostream>
using namespace project;
using namespace std;

class base{
      string name;
      string age;
public:
       base(string name, string age)
       {
           this->name = name;
           this->age = age;
       }
       string getName()
       {
           return name;
       }
       string getAge()
       {
           return age;
       }
};

class derived : public base
{
      string id;
public:
      derived(string name, string age, string id): base(name,age),id(id){}
      string getId()
      {
           return id;
      }
};

typedef class derived derivedType;
typedef class base baseType;

Auto_Ptr<int> f(Auto_Ptr<int> _ptr)
{
     Auto_Ptr<int> ptr (_ptr);
     cout << *ptr << endl;
     cout << "returing" << endl;
     return ptr;
}

void f2()
{
   Auto_Ptr<int> ptr(new int(5));
   Auto_Ptr<int> ptr2 = f(ptr);
   cout << "Printing in f2" << endl;
   cout << *ptr2 << endl;
   //cout << x << endl;
}

int main()
{
    f2();
    Auto_Ptr<class base> ob(*(new Auto_Ptr<class derived>(new class derived("Hello","infinite","World"))));
    cout << ob->getName() << endl;
    Auto_Ptr<class derived> ob2(*(new Auto_Ptr<class derived>((class derived*)ob.release())));
    cout << ob2->getId() << endl;
    system("pause");
}

