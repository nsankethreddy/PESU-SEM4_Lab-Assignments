#include<stdio.h>
#include<stdlib.h>
#include "mergeSort.h"

void mergeSortedHalfs(int *a, int start, int mid, int end){
	int i,j,k;
	int n1=mid-start+1;
	int n2=end-mid;
	int b[n1],c[n2];
	for(i=0;i<n1;i++)
		b[i]=a[start+i];
	for(j=0;j<n2;j++)
		c[j]=a[1+mid+j];
	i=0;j=0;k=start;
	while(i<n1 && j<n2){
		if(b[i]<=c[j]){
			a[k]=b[i];
			i++;
			}
		else
		{a[k]=c[j];
		j++;
		}
		k++;
	}//end of while
	while(i<n1){
		a[k]=b[i];
		i++;
		k++;
	}
	while(j<n2){
		a[k]=c[j];
		j++;
		k++;
	}
}

void mergeSort(int *a, int start, int end){
	
	if(start<end)
	{
		int mid= start+(end-start)/2;
		mergeSort(a,start,mid);
		mergeSort(a,mid+1,end);
		mergeSortedHalfs(a,start,mid,end);
	}
}

void insertionSort(int *a, int start, int end){
	int i,j;
	int temp;
	for(i=start+1;i<end;i++){
		temp=a[i];
		j=i-1;
		while(j>=start && a[j]>temp){
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=temp;
	}
}

void selectiveMergeSort(int *a, int start, int end, int parameter){
	if(end-start+1<=parameter)
		insertionSort(a,start,end);
	else{
		int mid= start+(end-start)/2;
		mergeSort(a,start,mid);
		mergeSort(a,mid+1,end);
		mergeSortedHalfs(a,start,mid,end);
		}
}

