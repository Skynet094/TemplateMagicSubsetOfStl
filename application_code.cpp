/*Skynet094*/
#include "Stack.h"
#include "Deque.h"
#include "Queue.h"
#include "Algorithm.h"
#include "priority_queue.h"
#include<iostream>
#include<vector>
#define MAX 1000
#define dll long long int
#define REP(i,a,b) for(int i=a;i<b;i++)
using namespace std;
using namespace project;



/*DATA FOR DISJKTRA*/

struct node_graph {
    int u,w;
    node_graph() {

    }

    node_graph(int a,int b) {
        u=a;
        w=b;
    }
    bool operator>(const node_graph& ob) const {
        if(w!=ob.w)
            return w>ob.w;

    }
};


vector<node_graph>adj_list[MAX];
int dist[MAX];
int parent[MAX];


void print_path(int dest)
{


    Stack<int> stk;

//cout<< "Printing the shortest "
    cout<<"Printing the shortest path by dijkstra: "<<endl;

    stk.push(dest);

    while(parent[dest]!=-1) {
        stk.push(parent[dest]);
        dest=parent[dest];
    }
    while(!stk.empty()) {
        cout<<stk.top()<<" ";
        stk.pop();
    }
    cout<<endl;

}

int dijkstra_sssp(int source,int dest)  //single source shortest path
{
    memset(dist,-1,sizeof(dist)); //SETTING A HIGH VALUE HERE
    memset(parent,-1,sizeof(dist)); //initializing parent

    dist[source]=0;  //dist from source is 0

    parent[source]=-1;

    priority_Queue<node_graph>Q;

    Q.push(node_graph(source,dist[source]));

    while(!Q.empty()) {
        node_graph cur_node=Q.top();
        Q.pop();
        int u=cur_node.u;

        if(u==dest) //u will be equal to dest when , dest has already been calculated
            return dist[dest];


        REP(i,0,adj_list[u].size()) {


            int v=(adj_list[u][i]).u;

            if(dist[v]==-1 || (dist[u]+(adj_list[u][i]).w < dist[v])) { // if ( source_to_u + u_to_v is less than source_to_v, then update
                dist[v]=dist[u]+(adj_list[u][i]).w;
                Q.push(node_graph(v,dist[v]));
                parent[v]=u;
            }
        }
    }
    return -1;
}



void create_adj_list_dijkstra()
{
    int n,m;

    cout<<"Enter number of Vertex:\n";
    cin>>n;
    cout<<"Enter number of Edges:\n";
    cin>>m;


    int u,v,w;

    cout<<"Enter ( start(u) vertex , end vertex(v) , weight(w) ):" <<endl;

    REP(i,0,m) {
        cin>>u>>v>>w;
        if(u==v)
            continue;
        else {
            adj_list[u].push_back(node_graph(v,w));
            adj_list[v].push_back(node_graph(u,w));
        }
    }
}



/*DATA FOR DISJKSTRA FINISH*/


/* DATA FOR BFS AND DFS*/


vector<int> adj_list_bfs[MAX];

void create_adj_list() //bfs and dfs
{
    int n,m;

    cout<<"Enter number of Vertex:\n";
    cin>>n;
    cout<<"Enter number of Edge:\n";
    cin>>m;


    int u,v,w;

    cout<<"Enter Edges, ( u , v ) :"<<endl;

    REP(i,0,m) {

        cin>>u>>v;
        if(u==v)
            continue;
        else {
            adj_list_bfs[u].push_back(v);
            adj_list_bfs[v].push_back(u);
        }
    }
}



void bfs_print(int source)
{
    cout<<"Printing BFS Traversal"<<endl;
    bool visit[MAX];
    memset(visit, 0 , sizeof(visit));
    Queue<int> Q;
    visit[source]=true;
    Q.push(source);
    cout<<source<<" ";

    cout<<"flag"<< Q.empty() <<endl;
    while(!(Q.empty())) {
        cout<<"hello"<<endl;

        source= Q.front(); Q.pop();

        // cout<<source<<endl;
        cout<<"Snap at this point"<<endl;



        cout<<"SIZE "<<adj_list_bfs[source].size()<<endl;

        for(int i=0; i < adj_list_bfs[source].size(); i++) {
            int temp= adj_list_bfs[source][i] ;
            cout<<"HELLO"<<endl;

            if(!visit[temp]) {
                // cout<<"Enter the dragon"<<endl;
                cout<<temp<<" ";
                visit[temp]=true;
                Q.push(temp);
            }
        }
    }
    cout<<endl<<endl;
}


void dfs_print(int source)
{
    cout<<"Printing DFS TRAVERSAL:"<<endl;
    bool visit[MAX];
    memset(visit, 0 , sizeof(visit));
    Stack<int> Stk;
    Stk.push(source);
    cout<<source<<" ";

    visit[source]=true;
    int flag=1;

    while(!Stk.empty()) {

        flag=1;

        for(int i=0; i < adj_list_bfs[source].size(); i++) {
            int temp= adj_list_bfs[source][i] ;
            if(!visit[temp]) {
                cout<<temp<<" ";
                visit[temp]=1;
                Stk.push(temp);
                source=temp;
                break;
            }
        }

        source=Stk.top();

        for(int i=0; i< adj_list_bfs[source].size(); i++) {
            if(!visit[adj_list_bfs[source][i]]) {
                flag=0;
                break;
            }
        }
        if(flag)
            Stk.pop();

    }

    cout<<endl<<endl;

}


/*DATA FOR BFS AND DFS*/


/*
DATA FOR DEQUE
*/

Deque<int> D;

void take_input(int number)
{
    for(int i=0; i < number ; i++) {
        int value;
        cin>>value;
        D.push_back(value);
    }
}

void menu()
{
    cout<<"Enter a number to simulate an application of -"<<endl;
    cout<<"     1 Queue(using bfs)"<<endl;
    cout<<"     2 Stack(using dfs)"<<endl;
    cout<<"     3 to Priority Queue(Dijkstra)"<<endl;
    cout<<"Press 0 to quit Program"<<endl;

}




int main(void)
{
    int choice;
    int source,dest;
    menu();

    do {

        cin>>choice;

        switch(choice) {
        case 1:   //BFS
            cout<<"Graph creation step for bfs..."<<endl;
            create_adj_list();
            cout<<"Please Enter Source: ";
            cin>>source;
            bfs_print(source);
            break;
        case 2: //DFS
            cout<<"Graph Creation step dfs..."<<endl;
            create_adj_list();
            cout<<"Please Enter Source: ";
            cin>>source;
            dfs_print(source);
            break;
        case 3: //SHORTEST PATH DIJKSTRA
            cout<<"Graph creation step for dijkstra..."<<endl;
            create_adj_list_dijkstra();
            cout<<"Enter Source and destination"<<endl;
            cin>>source>>dest;
            dijkstra_sssp(source, dest);
            print_path(dest);
            break;
        case 0:
            break;
        default:
            cout<<"Invalid key pressed! Press one of the valid key"<<endl;
            break;
        };

    } while(choice!=0);


    return 0;
}
