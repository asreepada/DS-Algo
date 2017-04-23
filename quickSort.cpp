#include<stdio.h>
#include<iostream>
using namespace std;

void printList(int *arr,int size) {	
	for(int i=0;i<size;i++)
		cout<<arr[i]<<"  ";
	cout<<endl;
}

int partition(int *A,int start,int end) {
	int pivot = A[end];	
	int pIndex = start;
	
	for(int i=start;i<end;i++) {	
		if(A[i]<=pivot) {
			swap(A[i],A[pIndex]);
			pIndex++;
		}		
	}	
	swap(A[pIndex],A[end]);
	return pIndex;
}

void quickSort(int *A,int start,int end) {
	if(start<end) {
	
		int partisionInx = partition(A,start,end);		
		quickSort(A,start,partisionInx-1);
		quickSort(A,partisionInx+1,end);
	}
}

int main() {
	//int arr[] = {7,2,1,6,8,5,3,4};
	int arr[] = {5,2,7,1,8,9};
	int len = sizeof(arr)/sizeof(int);
	
	printList(arr,len);
	
	cout<<endl;
	quickSort(arr,0,len-1);
	printList(arr,len);
	return 0;
}
