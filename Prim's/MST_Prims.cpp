#include <bits/stdc++.h>

using namespace std;

int ver;
int edg;

typedef pair <int,int> PI;

vector <PI> Graph[100];
bool Vis[100];

int mstWeight = 0;

void CreateGraph()
{
    cin >> ver >> edg;
    for(int i = 0; i < edg; i++)
    {
        int u;
        int v;
        int w;

        cin >> u >> v >> w;

        Graph[u].push_back(make_pair(w,v));
        Graph[v].push_back(make_pair(w,u));
    }
}

void Init()
{
    for(int i = 0; i < ver; i++)
    {
        Vis[i] = false;
    }
}

void Prims(int v)
{

    CreateGraph();
    Init();


    priority_queue <PI, vector <PI>, greater <PI> > Q;
    PI p;
    int y;
    Q.push(make_pair(0,v)); /// SOURCE NODE ER WEIGHT 0

    while(!Q.empty())
    {
        p = Q.top(); /// P er moddhe x ashlo
        Q.pop(); /// Q theke popp holo
        v = p.second;

        if(Vis[v] == true)
            continue;

        mstWeight = mstWeight + p.first;


        Vis[v] = true;

        for(int i = 0; i < Graph[v].size(); i++)
        {
            y = Graph[v][i].second;
            if(Vis[y] == false)
                Q.push(Graph[v][i]);
        }

    }

    cout << "Minimum Cost is : " << mstWeight << endl;

}


int main()
{

    Prims(1 );

    cout << "Hello world " << endl;

}
