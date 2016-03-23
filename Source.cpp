#include<iostream>
#include<string>
#include<cstring>
#include "Algorithm.h"
#include "Deque.h"
#include "Map.h"
//#include <map>

using namespace project;
using namespace std;

map_<int, string> NAME;
map_ <int, float> SCORE;
int compareSetter=0;

class student
{
      int student_id;
public:
      student(){}
      student(int student_id, string name, float score)
      {
           this->student_id = student_id;
           NAME[student_id] = name;
           SCORE[student_id] = score;
           compareSetter = 0;
      }
      void setStudentInfo(int student_id, string name, float score)
      {
           this->student_id = student_id;
           NAME[student_id] = name;
           SCORE[student_id] = score;
      }
      bool operator>(const class student& ob)
      {
           if(compareSetter == 0)
           {
                return student_id>ob.student_id;
           }
           else if(compareSetter == 1)
           {
                string s1 = NAME[student_id];
                string s2 = NAME[ob.student_id];
                return s1>s2;
           }
           else
           {
               float f1 = SCORE[student_id];
               float f2 = SCORE[ob.student_id];
               return f1>f2;
           }
      }
      bool operator<(const class student& ob)
      {
           if(compareSetter == 0)
           {
                return student_id<ob.student_id;
           }
           else if(compareSetter == 1)
           {
                string s1 = NAME[student_id];
                string s2 = NAME[ob.student_id];
                return s1<s2;
           }
           else
           {
               float f1 = SCORE[student_id];
               float f2 = SCORE[ob.student_id];
               return f1<f2;
           }
      }
      int getStudentId()
      {
           return student_id;
      }
      string getStudentName()
      {
           return NAME[student_id];
      }
      float getStudentScore()
      {
           return SCORE[student_id];
      }
};

int main()
{
    Deque<class student> student_list;
    student_list.push_back(*(new class student(1105104, string("Siamul Normal"), 100)));
    student_list.push_back(*(new class student(1105094, string("Salman Atel"), 150)));
    student_list.push_back(*(new class student(1105097, string("Rafi"), 149)));
    Deque<class student>::iterator iter;
    iter = student_list.begin();
    while(iter!=student_list.end())
    { 
         cout << "Student ID: " << (*iter).data.getStudentId() << endl;
         cout << "Student Name: " << (*iter).data.getStudentName() << endl;
         cout << "Score: " << (*iter).data.getStudentScore() << endl;
         iter++;
    }
    cout << "________________________________________________" << endl;
    cout << "Sorting by Student ID: " << endl;
    Sort(student_list.begin(),student_list.end());
    iter = student_list.begin();
    while(iter!=student_list.end())
    {
         cout << "Student ID: " << (*iter).data.getStudentId() << endl;
         cout << "Student Name: " << (*iter).data.getStudentName() << endl;
         cout << "Score: " << (*iter).data.getStudentScore() << endl;
         iter++;
    }
    cout << "________________________________________________" << endl;
    cout << "Sorting by Student Name: " << endl;
    compareSetter = 1;
    Sort(student_list.begin(),student_list.end());
    iter = student_list.begin();
    while(iter!=student_list.end())
    {
         cout << "Student ID: " << (*iter).data.getStudentId() << endl;
         cout << "Student Name: " << (*iter).data.getStudentName() << endl;
         cout << "Score: " << (*iter).data.getStudentScore() << endl;
         iter++;
    }
    cout << "________________________________________________" << endl;
    cout << "Sorting by Student Score: " << endl;
    compareSetter = 2;
    Sort(student_list.begin(),student_list.end());
    iter = student_list.begin();
    while(iter!=student_list.end())
    {
         cout << "Student ID: " << (*iter).data.getStudentId() << endl;
         cout << "Student Name: " << (*iter).data.getStudentName() << endl;
         cout << "Score: " << (*iter).data.getStudentScore() << endl;
         iter++;
    }

	system("pause");
    return 0;
}
    


           
