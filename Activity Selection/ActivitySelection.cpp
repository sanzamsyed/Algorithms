#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

int main()
{
    freopen("inputAS.txt","r",stdin);

    vector <pair <int,int> > V;
    vector <pair <int,int> > output;

    int noOfTasks;
    cin >> noOfTasks;
    int cnt = 0;
    int current = 0;

    for(int i = 0; i < noOfTasks; i++)
    {
        int start;
        int finish;

        cin >> start >> finish;

        V.push_back(make_pair(finish,start));
    }

    sort(V.begin(),V.end());


    for(int i = 1; i < V.size();i++)
    {
        if(V[i].second >= V[current].first)
        {
            //cout << V[i].second << " " << V[i].first << endl;
            output.push_back(make_pair(V[i].second,V[i].first));
            cnt++;
            current = i;
        }
    }

    cout << cnt << endl;
    cout << V[0].second << " " << V[0].first << endl;
    for(int i = 0; i < output.size();i++)
    {
        cout << output[i].first << " " << output[i].second << endl;
    }







}
