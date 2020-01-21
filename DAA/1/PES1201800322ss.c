#include<stdio.h>
#include "ss.h"

int searchFirstOccurrence(int arr[], int n, int key)
{
        for(int i=0;i<n;i++)
        {
                if(arr[i]==key)
                        return i;
        }
        return -1;
}

int searchLastOccurrence(int arr[], int n, int key)
{
        for(int i=n-1;i>0;i--)
        {
                if(arr[i]==key)
                        return i;
        }
        return -1;
}

int numOccurrences(int arr[], int n, int key)
{
        int num=0;
        for(int i=0;i<n;i++)
        {
                if(arr[i]==key)
                {
                        num=num+1;
                }
        }
        return num;
}
