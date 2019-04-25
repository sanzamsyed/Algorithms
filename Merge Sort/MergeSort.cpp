#include <stdio.h>
#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

void Merge(int A[], int start, int mid, int end)
{
    int p = start;
    int q = mid + 1;
    int Arr[end - start + 1];
    int k = 0;

    for(int i = start; i<= end; i++)
    {
        if(p > mid)
        {
            Arr[k++] = A[q++];
        }
        else if(q > end)
        {
            Arr[k++] = A[p++];
        }
        else if(A[p] < A[q])
        {
            Arr[k++] = A[p++];
        }
        else
        {
            Arr[k++] = A[q++];
        }
    }

    for(int i = 0; i < k; i++)
    {
        A[start++] = Arr[i];
    }

}

void MergeSort(int A[], int start, int end)
{
    if(start < end)
    {
        int mid = (start + end)/2;
        MergeSort(A,start,mid);
        MergeSort(A,mid + 1, end);
        Merge(A,start,mid,end);
    }
}

void Print(int A[], int start, int end)
{
    cout << "S O R T E D " << endl;
    for(int i = start; i <= end; i++)
    {
        cout << A[i] << "  ";
    }

}


int main()
{
   int A[] = {-5,5,6,-14,7,0,1};
   int start = 0;
   int end = (sizeof(A)/sizeof(int));

   MergeSort(A,start,end);
   Print(A,start,end);

}
