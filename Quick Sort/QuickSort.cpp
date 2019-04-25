#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

int Partition(int A[], int start, int end)
{
    int pivot = A[start];
    int i = start + 1;

    for(int j = start + 1; j <= end; j++)
    {
        if(A[j] < pivot)
        {

            swap(A[j],A[i]);
            i++;

        }
    }

    swap(A[i-1],A[start]);

    return i-1;


}

void QuickSort(int A[], int start, int end)
{
    if(start < end)
    {
        int pivot_index = Partition(A,start,end);
        QuickSort(A,start,pivot_index - 1);
        QuickSort(A,pivot_index + 1, end);
    }
}

int main()
{

    int A[10];
    for(int i = 0; i < 10; i++)
    {
        A[i] = rand() % 10;
    }


    cout << "Before Sorting : " << endl << endl;

    for(int i = 0; i < 10; i++)
    {
        cout << A[i] << "  ";
    }

    cout << endl << endl;

    QuickSort(A,0,9);

    cout << "After Sorting : " << endl << endl;

    cout << endl;

    for(int i = 0; i < 10; i++)
    {
        cout << A[i] << "  ";
    }

    cout << endl;

    return 0;

}


