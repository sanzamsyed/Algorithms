#include <bits/stdc++.h>

using namespace std;

int lcs[100][100];
set <string> result;

void SetMatrix(char *x, char*y, int m, int n)
{
    for(int i = 0; i <= m; i++)
    {
        for(int j = 0; j <= n; j++)
        {
            if(i == 0 || j == 0)
            {
                lcs[i][j] = 0;
            }

            else if(x[i-1] == y[j-1])
            {
                lcs[i][j] = lcs[i-1][j-1] + 1;
            }
            else
            {
                lcs[i][j] = max(lcs[i-1][j],lcs[i][j-1]);
            }
        }
    }

}


void GetAllLCS(char *x, char *y, int m, int n, string s)
{
    if(m == 0 || n == 0)
    {
        result.insert(s);
        return;
    }
    else if(x[m-1] == y[n-1])
    {
        s = x[m-1] + s;
        GetAllLCS(x,y,m-1,n-1,s);
    }

    else if(lcs[m-1][n] == lcs[m][n-1])
    {
        GetAllLCS(x,y,m-1,n,s);
        GetAllLCS(x,y,m,n-1,s);
    }

    else if(lcs[m-1][n] > lcs[m][n-1])
    {
        GetAllLCS(x,y,m-1,n,s);
    }
    else
    {
        GetAllLCS(x,y,m,n-1,s);
    }

}

void Print()
{
    cout << "Number of LCSs : " << result.size() << endl << endl;
    set <string> :: iterator it = result.begin();
    while(it != result.end())
    {
        cout << *it << " ";
        it++;
    }
    cout << endl;
}





int main()
{
    char str1[] = "WJAKSGVBYAUOD";
    char str2[] = "ABSJDURATUDO";

    int m = strlen(str1);
    int n = strlen(str2);

    SetMatrix(str1,str2,m,n);
    GetAllLCS(str1,str2,m,n,"");
    Print();




}

