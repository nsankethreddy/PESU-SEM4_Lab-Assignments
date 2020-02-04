#include "session5_sort.h"
#include <time.h>
#include <stdio.h>

double time_elapsed(struct timespec start, struct timespec end) {
	double t;
	t = (end.tv_sec - start.tv_sec); 
	t += (end.tv_nsec - start.tv_nsec) * 0.000000001; //add diff of tv_nsec too
	return t;
}

long int InsertionSort(Record* A, int n)
{
    long int comp=0;
    int i,j,k;
    for(i=1;i<n;i++)
    {
        Record temp=A[i];
        for(j=i-1;j>=0;j--)
        {
            comp++;
            if(temp.serialnumber>A[j].serialnumber)
                break;
        }
        for(k=i;k>j;k--)
        {
            A[k]=A[k-1];
        }
        A[j+1]=temp;
    }
    return comp;
}

long int BubbleSort(Record* A, int n)
{
   int i,j;long int comp=0;int swaps;
   for(i=0;i<n-1;i++)
   {
        swaps=0;
        for(j=0;j<n-i-1;j++)
        {
            comp++;
            if(A[j].serialnumber > A[j+1].serialnumber)
            {
                Record temp=A[j];
                A[j]=A[j+1];
                A[j+1]=temp;
                swaps=1;
            }
        }
        if(swaps==0)
            break;
   }
   return comp;
}

long int SelectionSort(Record* A, int n)
{
    int i,j;long int comp=0;int min=0;
    for(i=0;i<n-1;i++)
    {
        Record temp=A[i];min=i;
        for(j=i+1;j<n;j++)
        {
            comp++;
            if(A[j].serialnumber < A[i].serialnumber)
            {
                temp=A[j];min=j;
            }
        }
        if(min!=i)
        {
            Record t=A[min];
            A[min]=A[i];
            A[i]=t;
        }
    }
    return comp;

}

long int binsearch(Record *A,Record key,int low ,int high){
	if(high<=low){
		if(key.serialnumber<A[low].serialnumber)
			return low;
		else
			return low+1;
	}
	int mid=(high+low)/2;
	if(key.serialnumber<A[mid].serialnumber)
		return binsearch(A,key,low,mid-1);
	else
		return binsearch(A,key,low+1,mid);
}
long int InsertionBinSort(Record* A, int n){
	long int comp=0;
	for(int i=1;i<n;i++){
		Record temp = A[i];
		int j=i-1;
		int bc=binsearch(A,temp,0,j-1);
		while(j>=0&& A[j].serialnumber>temp.serialnumber){
			A[j+1]=A[j];
			j--;
			comp++;
		}
		comp++;
		A[j+1]=temp;
	}
	return comp;
}


int main()
{
        char line[50];
        long int comp;
        int size;
        struct timespec start, end; 
        FILE *fp = fopen("session5_sort_ip_rand064k.txt","r+");
        fscanf(fp,"%d",&size);
        Record stud[size];
        Record stud_temp[size];
        printf("%d\n",size);
        
        for(int i=0;i<size;i++)
        {
                
                fscanf(fp,"%li",&stud[i].serialnumber);
                fscanf(fp,"%d",&stud[i].score);
               // printf("%li -> %d\n",stud[i].serialnumber,stud[i].score);
        }
        
        //Insertion Sort
        for(int i=0;i<size;i++)
        {
                stud_temp[i].serialnumber = stud[i].serialnumber;
                stud_temp[i].score = stud[i].score;
        }
        clock_gettime(CLOCK_REALTIME, &start); //Start timestamp
        comp = InsertionSort(stud,size);
        clock_gettime(CLOCK_REALTIME, &end); //Start timestamp
        printf("%lf sec spent on test1 of InsertionSort()\n",time_elapsed(start, end));
        printf("No of comparisons: %li\n",comp);

        for(int i=0;i<size;i++)
        {
                stud[i].serialnumber = stud_temp[i].serialnumber;
                stud[i].score = stud_temp[i].score;
        }
        
        
        
        //Bubble Sort
        for(int i=0;i<size;i++)
        {
                stud_temp[i].serialnumber = stud[i].serialnumber;
                stud_temp[i].score = stud[i].score;
        }
        clock_gettime(CLOCK_REALTIME, &start); //Start timestamp
        comp = BubbleSort(stud,size);
        clock_gettime(CLOCK_REALTIME, &end); //Start timestamp
        printf("%lf sec spent on test1 of BubbleSort()\n",time_elapsed(start, end));
        printf("No of comparisons: %li\n",comp);
        for(int i=0;i<size;i++)
        {
                stud[i].serialnumber = stud_temp[i].serialnumber;
                stud[i].score = stud_temp[i].score;
        }
        
        //Selection Sort
        for(int i=0;i<size;i++)
        {
                stud_temp[i].serialnumber = stud[i].serialnumber;
                stud_temp[i].score = stud[i].score;
        }
        clock_gettime(CLOCK_REALTIME, &start); //Start timestamp
        comp = SelectionSort(stud,size);
        clock_gettime(CLOCK_REALTIME, &end); //Start timestamp
        printf("%lf sec spent on test1 of SelectionSort()\n",time_elapsed(start, end));
        printf("No of comparisons: %li\n",comp);
        for(int i=0;i<size;i++)
        {
                stud[i].serialnumber = stud_temp[i].serialnumber;
                stud[i].score = stud_temp[i].score;
        }
        
        //bininsertionsort
        for(int i=0;i<size;i++)
        {
                stud_temp[i].serialnumber = stud[i].serialnumber;
                stud_temp[i].score = stud[i].score;
        }
        clock_gettime(CLOCK_REALTIME, &start); //Start timestamp
        comp =  InsertionBinSort(stud,size);
        clock_gettime(CLOCK_REALTIME, &end); //Start timestamp
        printf("%lf sec spent on test1 of BInInsertionSort()\n",time_elapsed(start, end));
        printf("No of comparisons: %li\n",comp);

        for(int i=0;i<size;i++)
        {
                stud[i].serialnumber = stud_temp[i].serialnumber;
                stud[i].score = stud_temp[i].score;
        }
        
               
        
}

