#include "Queue.h"
#include "Stack.h"
#include "Deque.h"
#include "Map.h"
#include<iostream>
#include "Algorithm.h"
#include<string>
#include<cstring>
#include<cstdio>
using namespace project;
using namespace std;

class student_list
{

      Deque<int> student_id;
      map_<int,string> name;
      map_<int, double> score;
public:
      student_list(){}
      void savestudentinfo(int student_id, string name, double score)
      {
           this->student_id.push_back(student_id);
           this->name[student_id] = name;
           this->score[student_id] = score;
      }
      void printstudentinfo()
      {
           Deque<int>::iterator iter;
           iter = student_id.begin();


           while(iter!=student_id.end())
           {
               cout<<endl;
               cout << "Student Id No.:" << (*iter).data << endl;
               cout << "Name:" << name[(*iter).data] << endl;
               cout << "Score:" << score[(*iter).data] << endl;
               cout<<endl;
               iter++;
           }
      }

      void modifystudentinfo(int student_id, string name, double score)
      {
           this->name[student_id] = name;
           this->score[student_id]  = score;
      }
      void sort_list_descending()
      {
           Sort(student_id.begin(), student_id.end());
      }
      void sort_list_ascending()
      {
           Sort(student_id.begin(), student_id.end());
           Reverse(student_id.begin(), student_id.end());
      }
};








int main()
{
    student_list ob;
    int choice;
    string name;
    int student_id;
    double score;
    while(1)
    {
            cout << "-----------------------------" << endl;
            cout << "Press 1 to enter new student information" << endl;
            cout << "Press 2 to view the informations available" << endl;
            cout << "Press 3 to modify a student's information" << endl;
            cout << "Press 4 to sort according to student ID no. in ascending order" << endl;
            cout << "Press 5 to sort according to student ID no. in descending order" << endl;
            cout << "Press 0 to exit" << endl;
            cout << "-----------------------------" << endl;
            cout << "Enter your choice:" << endl;
            cin >> choice;
            fflush(stdin);
            if(choice==1)
            {
                  cout << "-----------------------------" << endl;
                  cout << "Enter Student ID:";
                cin >> student_id;
                fflush(stdin);
                cout << "Enter Name:";
                getline(cin, name);
                fflush(stdin);
                cout << "Enter Score:";
                cin >> score;
                fflush(stdin);
                cout << "-----------------------------" << endl;
                ob.savestudentinfo(student_id,name,score);
            }
            if(choice==2)
            {
                ob.printstudentinfo();
            }
            if(choice==3)
            {
                cout << "-----------------------------" << endl;
                cout << "Enter Student ID of the student whose data is to be modified:" << endl;
                cin >> student_id;
                fflush(stdin);
                cout << "Enter Name:" << endl;
                getline(cin,name);
                fflush(stdin);
                cout << "Enter Score:" << endl;
                cin >> score;
                fflush(stdin);
                cout << "-----------------------------" << endl;
                ob.modifystudentinfo(student_id,name,score);
            }
            if(choice==4)
            {
                ob.sort_list_ascending();
            }
            if(choice==5)
            {
                ob.sort_list_descending();
            }
            if(choice==0)
            {
                exit(0);
            }
    }

    system("pause");

}
