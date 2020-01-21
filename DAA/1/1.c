#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "ss.h"

double time_elapsed(struct timespec start, struct timespec end);

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



int main(int argc, char const *argv[]) {
    int a[1000]; 
    for(int i=0;i<1000;i++)
    {
        a[i]=rand();
    }
    struct timespec start, end; //timestamps

    clock_gettime(CLOCK_REALTIME, &start); //Start timestamp
    int offset = searchFirstOccurrence(a, 1000, 23);
    clock_gettime(CLOCK_REALTIME, &end); //Start timestamp
    if(offset == 1) {
        printf("%lf sec spent on test1 of searchFirstOccurrence()\n",
            time_elapsed(start, end));
    } else {
        printf("FAILED test1 of searchFirstOccurrence()\n");
    }

    clock_gettime(CLOCK_REALTIME, &start); //Start timestamp
    offset = searchLastOccurrence(a, 1000, 23);
    clock_gettime(CLOCK_REALTIME, &end); //Start timestamp
    if(offset == 3) {
        printf("%lf sec spent on test1 of searchLastOccurrence()\n",
            time_elapsed(start, end));
    } else {
        printf("FAILED test1 of searchLastOccurrence()\n");
    }

    clock_gettime(CLOCK_REALTIME, &start); //Start timestamp
    int count = numOccurrences(a, 1000, 23);
    clock_gettime(CLOCK_REALTIME, &end); //Start timestamp
    if(count == 2) {
        printf("%lf sec spent on test1 of numOccurrences()\n",
            time_elapsed(start, end));
    } else {
        printf("FAILED test1 of numOccurrences()\n");
    }
    return 0;
}

//Time elapsed from 'start' to 'end' in seconds
double time_elapsed(struct timespec start, struct timespec end) {
	double t;
	t = (end.tv_sec - start.tv_sec); //diff of tv_sec
	t += (end.tv_nsec - start.tv_nsec) * 0.000000001;
	 //add diff of tv_nsec too
	return t;
}


