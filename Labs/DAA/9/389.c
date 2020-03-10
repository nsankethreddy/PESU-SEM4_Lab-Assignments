#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"heapSort.h"

Heap buildMaxHeap(int* const a,int n)
{
    int index = n/2 - 1;
    Heap newHeap;
    newHeap.a = a;
    newHeap.size = n;
    for(int i=index;i>=0;i--)
    {
        maxHeapify(newHeap,i);
    }
    return newHeap;
}

void maxHeapify(Heap h,int idx)
{
    int largest = idx;
    int l = 2*idx + 1;
    int r = 2*idx + 2;
    int temp;

    if(l<h.size && h.a[l] > h.a[largest])
        largest = l;

    if(r<h.size && h.a[r] > h.a[largest])
        largest=r;
    
    if(largest!=idx)
    {
        temp = h.a[idx];
        h.a[idx] = h.a[largest];
        h.a[largest] = temp;

        maxHeapify(h,largest);
    }
}

void heapSort(int* const a,int n)
{
    Heap h = buildMaxHeap(a,n);
    
    int temp;

    for(int i=n-1;i>=0;i--)
    {
        temp = h.a[0];
        h.a[0] = h.a[i];
        h.a[i] = temp;
        h.size--;
        maxHeapify(h,0);
    }
}
