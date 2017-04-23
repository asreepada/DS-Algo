#include<stdio.h>
#include<iostream>
using namespace std;

void printList(int *arr,int size) {	
	for(int i=0;i<size;i++)
		cout<<arr[i]<<"  ";
	cout<<endl;
}

void merge(int *L, int l1, int *R, int l2, int *A) {
	
	int i = 0, j = 0, k = 0;
	while(i<l1 && j <l2) {
		if(L[i] <= R[j]) {
			A[k++] = L[i++];			
		}
		if(R[j] <= L[i]) {
			A[k++] = R[j++];			
		}	
	}
	while(i<l1) {
		A[k++] = L[i++];
	}	
	while(j<l2) {
		A[k++] = R[j++];		
	}
}

void mergeSort(int *A,int len) {
	
	if(len<2) 
		return;
	int mid = len/2;

	int L[mid];
	int R[len-mid];
	
	for(int i=0;i<mid;i++) {		
		L[i] = A[i];
	}
	
	for(int j=mid;j<len;j++) {	
		R[j-mid] = A[j];
	}

	
	mergeSort(L,mid);
	mergeSort(R,len-mid);	
	merge(L,mid,R,len-mid,A);
	
}

//Find all the pair in array equal to given sum
void findAllPairsEqualToGivenSum(int *A,int st, int end,int sum) {
	while(st<end) {		
		if(A[st]+A[end] > sum) {
			end--;
		}
		else if(A[st]+A[end] < sum) {
			st++;
		}
		else {
			cout<<"Pair is : [ "<<A[st]<<" , "<<A[end]<<" ]"<<endl;
			st++;	
		}
	}
}

int main() {
	int arr[] = {5,2,7,1,8,9};
	int len = sizeof(arr)/sizeof(int);
	
	printList(arr,len);	
	cout<<endl;
	
	mergeSort(arr,len);
	printList(arr,len);
	cout<<endl;
	
	findAllPairsEqualToGivenSum(arr,0,len-1,10);
	return 0;
}
