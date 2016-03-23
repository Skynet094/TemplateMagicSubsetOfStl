/*Skynet094*/
#include<bits/stdc++.h>
#include<fstream>
#define MAX 1000
#define dll long long int
#define REP(i,a,b) for(int i=a;i<b;i++)
using namespace std;


void print_file(std::ifstream& myfile)
{
    string line;
    int len=0;

    cout<<"-------------------------------------------------------"<<endl<<endl;
    if (myfile.is_open())

        while ( getline (myfile,line) )
        {
           cout << line << '\n';
         //  i++;
           //if
        }

    myfile.close();
    cout<<"-------------------------------------------------------"<<endl<<endl;
    cout<<endl<<endl;
}


int main(void)
{
    int choice;


    cout<<"Enter choice to simulate\n";
    cout<<"     1 ->Double-ended queue(deque)"<<endl;
    cout<<"     2 ->Map"<<endl;
    cout<<"     3 ->Stack"<<endl;
    cout<<"     4 ->Queue"<<endl;
    cout<<"     5 ->Auto pointer"<<endl;
    cout<<"     6 ->Priority Queue(array version)"<<endl;
    cout<<"     7 ->Priority Queue(linked list version"<<endl;
    cout<<"     8 ->Algorithm" <<endl;
    cout<<"     0 ->Exit"<<endl;
    cout<<endl;


    do{
    cout<<"Enter choice: ";
    cin>>choice;
    cout<<endl;

    std::ifstream file;

    switch(choice)
    {
        case 1:
            file.open("Deque.h");

            cout<<"Printing: "<<"Deque.h"<<endl<<endl;
            cout<<endl<<endl;
            break;
        case 2:
            cout<<"Printing: "<<"Map.h"<<endl<<endl;
            cout<<endl<<endl;

            file.open("Map.h");
            break;
        case 3:
            cout<<"Printing: "<<"Stack.h"<<endl<<endl;
            cout<<endl<<endl;

            file.open("Stack.h");
            break;
        case 4:
            cout<<"Printing: "<<"Queue.h"<<endl<<endl;
            cout<<endl<<endl;

            file.open("Queue.h");
            break;
        case 5:
            cout<<"Printing: "<<"Auto_Ptr.h"<<endl<<endl;
            cout<<endl<<endl;

            file.open("Auto_Ptr.h");
            break;
        case 6:
            cout<<"Printing: "<<"PriorityQueue.h"<<endl<<endl;
            cout<<endl<<endl;

            file.open("PriorityQueue.h");
            break;
        case 7:
            cout<<"Printing: "<<"priority_Queue.h"<<endl<<endl;
            cout<<endl<<endl;

            file.open("priority_queue.h");
            break;
        case 8:
            cout<<"Printing: "<<"Algorithm.h"<<endl<<endl;
            cout<<endl<<endl;

            file.open("Algorithm.h");
            break;
     }

    if(choice>0 && choice<=8)
        print_file(file);
    else if(choice!=0)
        cout<<"Invalid choice..."<<endl;

    }while(choice);

return 0;
}
