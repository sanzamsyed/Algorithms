#include <bits/stdc++.h>

using namespace std;

int Mat[100][100];
int vertex;
int edge;
int cnt = 0;

stack <int> s;

void CreateGraph()
{
    cout << "Vertices and Nodes : " << endl;
    cin >> vertex >> edge;

    cout << "Put the edges : " << endl;
    for(int i = 0; i < edge;i++)
    {

        int n1;
        int n2;
        cin >> n1 >> n2;
        Mat[n1][n2] = 1;
        Mat[n2][n1] = 1;
    }
}



struct Node
{
    int discoveryTime;
    int finishingTime;
    bool visit;
};

Node Graph[100];

void DFS(int v)
{
    Graph[v].visit = true;
    Graph[v].discoveryTime = cnt++;

    for(int i = 0; i < vertex; i++)
    {
        if(Mat[v][i] == 1 && Graph[i].visit == false)
        {
            DFS(i);
        }
    }

    Graph[v].finishingTime = cnt++;

    s.push(v);
}




int main()
{

    CreateGraph();

    DFS(0);

    while (!s.empty())
    {
        cout << s.top() << "  ";
        s.pop();
    }

}

