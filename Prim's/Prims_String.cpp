#include <bits/stdc++.h>

using namespace std;

int ver;
int edg;
typedef pair <int,int> PI;

vector <PI> Graph[100];
int Parent[100];
bool Visited[100];
string Arr[100];

int FindIndex(string s)
{
    for(int i = 0; i < 100; i++)
    {
        if(Arr[i] == s) return i;
        if(Arr[i] == "-1")
        {
            Arr[i] = s;
            return i;
        }
    }
}




void Connect()
{
    cin >> ver >> edg;
    for(int i = 0; i < edg; i++)
    {
        string s1;
        string s2;
        int u;
        int v;
        int w;

        cin >> s1 >> s2 >> w;

        u = FindIndex(s1);
        v = FindIndex(s2);

        Graph[u].push_back(make_pair(w,v));
        Graph[v].push_back(make_pair(w,u));
    }
}



void Initialse()
{
    for(int i = 0; i < 100; i++)
    {
        Visited[i] = false;
        Parent[i] = -1;
        Arr[i] = "-1";
    }
}

void Prims(int v)
{
    priority_queue <PI, vector <PI>, greater <PI> > Q;
    PI P;
    int u;
    int mstWeight = 0;

    Q.push(make_pair(0,v));

    while(!Q.empty())
    {
        P = Q.top();
        Q.pop();

        v = P.second;

        if(Visited[v] == true)
            continue;

        if(Parent[v] != -1)
        cout << Arr[v] << "\t" << Arr[Parent[v]] << "\t" << P.first << endl;
        mstWeight = mstWeight + P.first;
        Visited[v] = true;


        for(int i = 0; i < Graph[v].size(); i++)
        {
            u = Graph[v][i].second;
            if(Visited[u] == false)
                Q.push(Graph[v][i]);
                Parent[u] = v;

        }

    }

    cout << endl << endl;
    cout << "Total minimum cost is : " << mstWeight << endl;

}





int main()
{
    freopen("inputString.txt","r",stdin);

    Initialse();
    Connect();

    Prims(0);


}
