#include <stdio.h>
#include <iostream>

using namespace std;



void MinHeapify(int Arr[], int heapsize, int i)
{
    int smallest = i;
    int leftIndex = 2*i + 1;
    int rightIndex = 2*i + 2;
    
    if(leftIndex < heapsize && Arr[leftIndex] < Arr[smallest])
    {
        smallest = leftIndex;
    }
    
    if(rightIndex < heapsize && Arr[rightIndex] < Arr[smallest])
    {
        smallest = rightIndex;
    }
    
    if(i != smallest)
    {
        swap(Arr[smallest],Arr[i]);
        MinHeapify(Arr,heapsize,smallest);
    }
}

void BuildMinHeap(int Arr[], int heapsize)
{
    for(int i = heapsize/2 - 1; i >= 0; i--)
    {
        MinHeapify(Arr,heapsize,i);
    }
}

void HeapSort(int Arr[], int heapSize)
{
    BuildMinHeap(Arr, heapSize);
    for(int i = heapSize - 1; i >= 0; i--)
    {
        swap(Arr[0],Arr[heapSize - 1]);
        heapSize--;
        MinHeapify(Arr,heapSize,0);
        
    }
    
}

void Print(int Arr[], int heapSize)
{
    cout << "Sorted Array : " << endl;
    for(int i = 0; i < heapSize; i++)
    {
        cout << Arr[i] <<  "  ";
    }
    
    cout << endl;
}

int main()
{
    int heapSize;
    int Arr[] = {12,11,43,3,1,-12};
    int size = sizeof(Arr)/sizeof(int);
    heapSize = size;
    HeapSort(Arr,heapSize);
    Print(Arr,size);
    
    
    
    
    
    
    
}
