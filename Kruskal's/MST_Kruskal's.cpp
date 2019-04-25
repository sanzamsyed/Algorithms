#include <iostream>
#include <stdio.h>
#include <vector>


using namespace std;

int Parent[100];
vector <pair <int, pair <int, int> > > Graph;
int ver;
int edg;


int Find_Parent(int x)
{
    if(Parent[x] == x)
    {
        return x;
    }
    
    else return Find_Parent(Parent[x]);
    
}

void Unite(int x, int y)
{
    int xParent = Find_Parent(x);
    int yParent = Find_Parent(y);
    
    Parent[xParent] = yParent;
    
}

void InitialiseParentArray()
{
    for(int i = 0; i < 100; i++)
    {
        Parent[i] = i;
    }
}

void Connect()
{
    int u;
    int v;
    int w;
    cin >> ver >> edg;
    for(int i = 0; i < edg; i++)
    {
        cin >> u >> v >> w;
        Graph.push_back(make_pair(w, make_pair(u,v)));
    }
}

void Kruskals()
{
    InitialiseParentArray();
    Connect();
   sort(Graph.begin(),Graph.end());
    
    int mstEdg = 0;
    int mstIndex = 0;
    int mstWeight = 0;
    
    while(mstEdg < ver - 1 || mstIndex < edg)
    {
        int u = Graph[mstIndex].second.first;
        int v = Graph[mstIndex].second.second;
        int w = Graph[mstIndex].first;
        
        if(Find_Parent(u) != Find_Parent(v))
        {
            Unite(u,v);
            mstEdg++;
            mstWeight = mstWeight + w;
            
            cout << u << "    " << v << "    " << w << endl;
        }
        
        mstIndex++;
    }
    
    cout << endl <<  "Total Cost is : " << mstWeight << endl;
}



int main()
{
    Kruskals();
    
}


/*
 
 7 9
1 2 4
7 2 2
6 2 3
6 5 1
5 3 20
4 3 6
1 4 7
2 5 2
2 3 1
 
*/
