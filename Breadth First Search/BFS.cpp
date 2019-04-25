#include <bits/stdc++.h>

using namespace std;

vector <int> Mat[100];
queue <int> q;
bool Vis[100];
int ver;
int edg;

void CreateGraph()
{
    cin >> ver >> edg;
    for(int i = 0; i < edg; i++)
    {
        int a,b;
        cin >> a >> b;

        Mat[a].push_back(b);
        Mat[b].push_back(a);
    }

    cout << endl;
}

void FindNeighbours(int start)
{
    if(!Mat[start].empty())
    {
        for(vector <int> :: iterator i = Mat[start].begin(); i != Mat[start].end(); i++)
        {
            cout << *i << "  ";
        }

        cout << endl;
    }
}


void BFS(int start)
{
    q.push(start);
    Vis[start] = true;

    while(!q.empty())
    {
        int frnt = q.front();
        cout << frnt << "  ";
        q.pop();

        for(vector <int> :: iterator i = Mat[frnt].begin(); i!= Mat[frnt].end(); i++)
        {
            if(Vis[*i] == false)
            {
                Vis[*i] = true;
                q.push(*i);

            }
        }
    }

    cout << endl;
}


int main()
{
    freopen("input3.txt","r",stdin);
    CreateGraph();
    BFS(2);
    FindNeighbours(3);

}
