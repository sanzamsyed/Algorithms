#include <bits/stdc++.h>
#define INF 9999
using namespace std;

int ver;
int edg;
int d[100];
int par[100];
bool neg = false;
vector <pair <int, pair <int,int> > > graph;


void init()
{
    for(int i = 0; i < 100; i++)
    {
        d[i] = INF;
        par[i] = -1;
    }
}


void Connect()
{
    cin >> ver >> edg;
    for(int i = 0; i < edg; i++)
    {
        int u;
        int v;
        int w;

        cin >> u >> v >> w;

        graph.push_back(make_pair(w,make_pair(u,v)));
    }
}


bool Relax(int u, int v, int w)
{
    if((d[u] + w) < d[v])
    {
        d[v] = d[u] + w;
        return true;
    }

    return false;
}




void BellmanFord(int s)
{
    d[s] = 0;

    for(int i = 0; i < ver - 1; i++)
    {
        for(int j = 0; j < edg; j++)
        {
            if(Relax(graph[j].second.first,graph[j].second.second,graph[j].first))
            {
                par[graph[j].second.second] = graph[j].second.first;
            }
        }

    }


    for(int i = 0; i < ver; i++)
    {
        if(Relax(graph[i].second.first,graph[i].second.second,graph[i].first))
        {
            cout << "Negative Cycle Present!!" << endl;
            neg = true;
            return;
        }
    }
}


void Print()
{
    for(int i = 0; i < ver; i++)
    {

        cout << "Node : " << i << "  Parent : "  << par[i] << " Distance : " << d[i] << endl;
    }

    cout << endl << endl;


}


int main()
{
    //freopen("inputBF.txt","r",stdin);
    init();
    Connect();
    BellmanFord(0);

    if(!neg)
        Print();


}



/*


4 4
0 1 10
1 3 20
2 1 -60
3 2 30


*/
