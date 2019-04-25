#include <stdio.h>
#include <iostream>
#include <stack>
#include <vector>
#include <queue>
#include <iterator>
#include <fstream>

using namespace std;

struct Node
{
    bool vis;
};

bool Vis[100];

Node Graph[100];
int Mat[100][100];
int revMat[100][100];
stack <int> s;
queue <int> q;

int ver;
int edg;


void Connect()
{
    cin >> ver >> edg;

    for(int i = 0; i < edg; i++)
    {
        int n1,n2;
        cin >> n1 >> n2;
        Mat[n1][n2] = 1;
        revMat[n2][n1] = 1;
    }

}
void DFS(int n)
{
    Graph[n].vis = true;
    for(int i = 0; i < ver; i++)
    {
        if(Mat[n][i] == 1 && Graph[i].vis == false)
        {
            DFS(i);
        }
    }

    s.push(n);
}


void SetGraphToFalse()
{
    for(int i = 0; i < ver; i++)
    {
        Graph[i].vis = false;
    }
}


void FindComponents(int n, int Mat[][100])
{
    Graph[n].vis = true;
    q.push(n);
    for(int i = 0; i < ver; i++)
    {
        if(Mat[n][i] == 1 && Graph[i].vis == false)
        {
            FindComponents(i,revMat);
        }
    }
}


void DFS_Initialise()
{
    for(int i = 0; i < ver; i++)
    {
        if(Graph[i].vis == false)
        {
            DFS(i);
        }
    }
}


int main()
{

    Connect();


    DFS_Initialise();

    SetGraphToFalse();


    cout << endl;
    cout << "Strongly Connected Components are : " << endl << endl;

    while(!s.empty())
    {
        int i = s.top();
        if(Graph[i].vis == false)
        {


            FindComponents(i,revMat);



            while(!q.empty())
            {
                cout << q.front();
                cout << "  ";
                q.pop();
            }
        }

        s.pop();
        cout << endl;


    }

}

/*
 8 8


 0 3
 1 3
 3 5
 1 5
 5 1
 1 2
 2 1
 6 7

 */
