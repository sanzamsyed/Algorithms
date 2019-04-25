#include <stdio.h>
#include <vector>
#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;

void InputVector(vector <int> &v)
{
    cout << "How many Elements : " << endl;
    int noOfElements;
    cin >> noOfElements;
    for(int i = 0; i < noOfElements; i++)
    {
        int input;
        input = rand() % 100;
        v.push_back(input);
    }
}

void MaxHeapify(vector <int> &v, long size, long i)
{
    long largest = i;
    long left = 2*i + 1;
    long right = 2*i + 2;
    
    if(left < size && v[left] > v[largest])
    {
        largest = left;
    }
    if(right < size && v[right] > v[largest])
    {
        largest = right;
    }
    
    if(largest != i)
    {
        swap(v[largest],v[i]);
        MaxHeapify(v,size,largest);
    }
}

void  BuildMaxHeap(vector <int> &v, long size)
{
    for(long i = size/2 -1; i >= 0; i--)
    {
        MaxHeapify(v,size,i);
    }
}

 void HeapSort(vector <int> &v, long size)
{
    BuildMaxHeap(v,size);
    for(long i = size -1; i >= 0; i--)
    {
        swap(v[size-1], v[0]);
        size--;
        MaxHeapify(v,size,0);
    }
}

void Print(vector <int> v, long size)
{
    for(long i = 0; i < size; i++)
    {
        cout << v[i] << "    ";
    }
    
    cout << endl;
}


int main()
{
    vector <int> v;
    InputVector(v);
    long  size = v.size();
    
    cout << "Before Sorting : " << endl << endl;
    Print(v,size);
    cout << endl;
    HeapSort(v,size);
    cout << "After Sorting : " << endl << endl;
    Print(v,size);
    cout << endl;
    
    
    
    
}

