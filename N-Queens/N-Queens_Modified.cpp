#include <bits/stdc++.h>

using namespace std;

int totQ;
int Arr[100];
int noOfSols = 1;

void Init()
{
    cout << "Number of Queens : " << endl;
    cin >> totQ;
}

bool isSafe(int pos)
{
    for(int i = 1; i < pos; i++)
    {
        if(Arr[i] == Arr[pos] || fabs(Arr[i] - Arr[pos]) == fabs(i-pos))
            return false;
    }

    return true;
}

void Print()
{
    cout << "Solution: " << noOfSols << endl;
    noOfSols++;

    for(int i = 1; i <= totQ; i++)
    {
        for(int j = 1; j <=totQ; j++)
        {
            if(Arr[i] == j)
                cout << "Q\t";
            else cout << "*\t";
        }

        cout << endl;
    }

    cout << endl << endl;
}

void PlaceQueens()
{
    int curQ = 1;
    Arr[curQ] = 0;

    while(curQ != 0)
    {
        do
        {
            Arr[curQ]++;
        }
        while(Arr[curQ] <= totQ && !isSafe(curQ));

        if(Arr[curQ] <= totQ)
        {
            if(curQ == totQ)
            {
                Print();
            }
            else
            {
                curQ++;
                Arr[curQ] = 0;
            }
        }

        else
        {
            curQ--;
        }
    }
}


int main()
{
    Init();
    PlaceQueens();
    return 0;

}
