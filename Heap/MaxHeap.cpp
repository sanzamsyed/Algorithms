#include <stdio.h>
#include <iostream>

using namespace std;



void MaxHeapify(int Arr[], int heapsize, int i)
{
    int largest = i;
    int leftIndex = 2*i + 1;
    int rightIndex = 2*i + 2;
    
    if(leftIndex < heapsize && Arr[leftIndex] > Arr[largest])
    {
        largest = leftIndex;
    }
    
    if(rightIndex < heapsize && Arr[rightIndex] >= Arr[largest])
    {
        largest = rightIndex;
    }
    
    if(i != largest)
    {
        swap(Arr[largest],Arr[i]);
        MaxHeapify(Arr,heapsize,largest);
    }
}

void BuildMaxHeap(int Arr[], int heapsize)
{
    for(int i = heapsize/2 - 1; i >= 0; i--)
    {
        MaxHeapify(Arr,heapsize,i);
    }
}

void HeapSort(int Arr[], int heapSize)
{
    BuildMaxHeap(Arr, heapSize);
    for(int i = heapSize - 1; i >= 0; i--)
    {
        swap(Arr[0],Arr[heapSize - 1]);
        heapSize--;
        MaxHeapify(Arr,heapSize,0);
        
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
