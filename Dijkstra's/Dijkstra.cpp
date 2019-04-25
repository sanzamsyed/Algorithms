#include <bits/stdc++.h>
#define INF 99999

using namespace std;

int ver;
int edg;

typedef pair <int,int> PI;

vector <PI> Graph[100];
int Par[100];
bool Vis[100];
int Dis[100];

void Connect()
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
    for(int i = 0; i < 100; i++)
    {
        Par[i] = -1;
        Dis[i] = INF;
        Vis[i] = false;
    }
}

void Dijkstra()
{

    Connect();
    Init();

    priority_queue <PI,  vector <PI>, greater <PI> > Q;
    PI P;
    Dis[1] = 0;
    Q.push(make_pair(0,1));


    while(!Q.empty())
    {
        P = Q.top();
        Q.pop();

        int u = P.second;

        if(Vis[u]) continue;
        Vis[u] = true;

        for(int i = 0; i < Graph[u].size();i++)
        {
            int w = Graph[u][i].first;
            int v = Graph[u][i].second;

            if(Dis[u] + w < Dis[v])
            {
                Dis[v] = Dis[u] + w;
                Par[v] = u;
                Q.push(make_pair(w, v));
            }
        }

    }
}

void Print()
{
    cout << "DISTANCE" << endl;

    for(int i = 2; i <= ver; i++)
    {
        cout << Dis[i] << "  ";

    }

    cout << endl;
}


int main()
{

    Dijkstra();
    Print();

}
