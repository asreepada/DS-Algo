#include<stdio.h>
#include<iostream>
using namespace std;

void printList(int *arr,int size) {	
	for(int i=0;i<size;i++)
		cout<<arr[i]<<"  ";
	cout<<endl;
}

void inserAtPosition(int *A,int pos,int len,int data) {
	for(int i=len-1;i>=pos-1;i--) {
		A[i] = A[i-1];
	}
	A[pos-1] = data;
	
}

void insertionSort(int *A,int len) {
	for(int i=1;i<len;i++) {
		int val = A[i];
		int hole = i;
		while(hole>0 && A[hole-1] > val) {
			A[hole] = A[hole-1];
			hole = hole-1;
		}
		A[hole] = val;
	}
}

int main() {
	int arr[] = {2,3,4,5,6,7};
	//int arr[] = {7,2,1,6,8,5,3,4};
	int len = sizeof(arr)/sizeof(int);
	cout<<"Elements in the given array : ";
	printList(arr,len);
	
	cout<<endl<<"Inserting at given position : ";
	//insert at the given position
	inserAtPosition(arr,3,len,20);
	printList(arr,len);
	
	cout<<endl<<"Sorting using insertion sort : ";
	insertionSort(arr,len);	
	printList(arr,len);
	
	
	return 0;
}
