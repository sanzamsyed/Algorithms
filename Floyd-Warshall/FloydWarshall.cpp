#include <bits/stdc++.h>

using namespace std;

int Graph[100][100];
int Path[100][100];
int Cost[100][100];

int ver = 4;

void Connect()
{
    for(int i = 0; i < ver; i++)
    {
        for(int j = 0; j < ver; j++)
        {
            cin >> Graph[i][j];
        }
    }

}

void Init()
{
    for(int u = 0; u < ver; u++)
    {
        for(int v = 0; v < ver; v++)
        {
            Cost[u][v] = Graph[u][v];

            if(u == v)
            {
                Path[u][v] = 0;
            }
            else if(Cost[u][v] != 999)
            {
                Path[u][v] = u;
            }
            else Path[u][v] = -1;
        }
    }
}

void FloydW()
{
    for(int k = 0; k < ver; k++)
    {
        for(int u = 0; u < ver; u++)
        {
            for(int v = 0; v < ver; v++)
            {
                if(Cost[u][k] != 999 && Cost[k][v] != 999 && Cost[u][k] + Cost[k][v] < Cost[u][v])
                {
                    Cost[u][v] = Cost[u][k] + Cost[k][v];
                    Path[u][v] = Path[k][v];
                }
            }


        }
    }


}

void PrintRec(int u, int v)
{
    if(Path[u][v] == u)
        return;

    PrintRec(u,Path[u][v]);

    cout << Path[u][v] << "  ";
}

void PrintAns()
{
    for(int u = 0; u < ver; u++)
    {
        for(int v = 0; v < ver; v++)
        {
            if(u != v && Path[u][v] != -1)
            {
                cout << "Shortest Path from vertex " << u <<
					 " to vertex " << v << " is (" << u << " ";
				PrintRec(u, v);
				cout << v << ")" << endl;
            }
        }
    }
}

int main()
{
    freopen("input.txt","r",stdin);
    Connect();
    Init();
    FloydW();
    PrintAns();


}
