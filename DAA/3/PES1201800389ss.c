#include "sort.h"
int isSorted(int *a, int n)
{
        int i;
        for(i=0;i<n-1;i++)
        {
                if(a[i]>a[i+1])
                return 0;
        }
        return 1;
}

void bubblePass(int *a, int n)
{
        int temp;
        for(int j=0;j<n-1;j++)
        {
                if(a[j]>=a[j+1])
                {
                        temp=a[j];
                        a[j]=a[j+1];
                        a[j+1]=temp;
                }
        }
}

void bubbleSort(int *a, int n)
{
       int i;
        for(i=0;i<n;i++)
        {
                bubblePass(a,n-i);
        }
}

int numBubblePasses(int *a, int n)
{
        if(isSorted(a,n))
                return 0;
        else
        {
                int c=0,f=0,temp;
        for(int i=0;i<n-1;i++)
        {
                f=0;
        for(int j=0;j<n-i-1;j++)
        {
                 if(a[j]>a[j+1])
                {
                        temp=a[j];
                        a[j] = a[j+1];
                        a[j+1] = temp;
                        f=1;
                }
        }
        if(f)
        c++;
        }
        return c;
        }
}



int maxIndex(int *a, int n)
{
        int max=0;
        for(int i=1;i<n;i++)
        {
                if(a[i]>=a[max])
                {
                max=i;
                }
        }
        return max;
}



void swapWithMax(int *a, int n)
{
        int m=maxIndex(a,n),temp;
        if(m<n)
        {
                temp=a[m];
                a[m]=a[n-1];
                a[n-1]=temp;
        }
}

void selectionSort(int *a, int n)
{
        for(int i=0;i<n;i++)
        {
        swapWithMax(a,n-i);
        }
}

int numSwaps(int *a,int n)
{
        int c=0;
        for(int i=0;i<n-1;i++)
        {
        if(isSorted(a,n))
        return c;
        if(maxIndex(a,n-i)!=n-i-1)
        {
        c++;
        swapWithMax(a,n-i);
        }
}  
        return c;
}

