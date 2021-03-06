#include <bits/stdc++.h>


using namespace std;

vector <pair <int, pair <int,int> > > Graph;
int ver;
int edg;

string Arr[100];

int ParentArr[100];




int Find(int x)
{
    if(ParentArr[x] == x)
        return x;
    else return Find(ParentArr[x]);
}

void Unite(int x, int y)
{
    int xParent = Find(x);
    int yParent = Find(y);

    ParentArr[xParent] = yParent;
}

void InitialseParentArray()
{
    for(int i = 0; i < 100; i++)
    {
        ParentArr[i] = i;
        Arr[i] = "-1";
    }
}

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
    string u;
    string v;
    int w;

    cin >> ver >> edg;

    for(int i = 0; i < edg; i++)
    {
        cin >> u >> v >> w;

        Graph.push_back(make_pair(w,make_pair(FindIndex(u),FindIndex(v))));
    }
}

void Kruskals()
{
    InitialseParentArray();
    Connect();


    sort(Graph.begin(), Graph.end());

    int mstEdg = 0;
    int mstIndex = 0;
    int mstWeight = 0;

    cout << endl << endl;

    while(mstEdg < ver - 1 || mstIndex < edg)
    {
        int u = Graph[mstIndex].second.first;
        int v = Graph[mstIndex].second.second;
        int w = Graph[mstIndex].first;

        if(Find(u) != Find(v))
        {
            Unite(u,v);
            mstEdg++;
            mstWeight = mstWeight + w;

            cout << Arr[u] << "  " << Arr[v] << "  " << w << endl;
        }

        mstIndex++;
    }

    cout << endl << endl << "Total Cost : " << mstWeight << endl;

}




int main()
{

    Kruskals();

}

/*

8 14
mi ga 7
d as 8
mo as 9
mo sh 12
mi sh 14
d mo 15
d sh 20
mo ga 28
f d 30
f sh 30
mi k 35
d ga 40
f k 50
f mi 55

*/
