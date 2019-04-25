#include <stdio.h>
#include <iostream>
#include <stack>


using namespace std;

struct Node
{
    bool visited;
    string item;
    
};

Node Graph[100];
int adjMat[100][100];
stack <int> s;
int ver;
int edg;




void ConnectNodes()
{
    cin >> ver >> edg;
    for(int i = 0; i < edg; i++)
    {
        int n1;
        int n2;
        
        cin >> n1 >> n2;
        
        adjMat[n1][n2] = 1;
    }
}

void DFS(int n)
{
    Graph[n].visited = true;
    for(int i = 0; i < ver; i++)
    {
        if(adjMat[n][i] == 1 && Graph[i].visited == false)
        {
            DFS(i);
        }
    }
    
    s.push(n);
    
    
    
}

void DFS_Util()
{
    for(int i = 0; i < ver; i++)
    {
        if(Graph[i].visited == false)
        {
            DFS(i);
        }
    }
}



int main()
{
    ConnectNodes();
    
    string items[] = {"English", "C","Data Structure","Algorithm","Contest"};
    for(int i = 0; i < ver ; i++)
    {
        Graph[i].item = items[i];
    }
    
    DFS_Util();
    
    while(!s.empty())
    {
        cout << Graph[s.top()].item << endl;
        s.pop();
        
    }
    
}
