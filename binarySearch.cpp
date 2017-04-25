/* Binary search works only on sorted list of elements*/
#include<iostream>
#include<stdio.h>

using namespace std;

int binarySearch(int *A, int low, int high, int valToSearch) {
	int mid = 0;	
	while(low<=high) {
		mid = (low+high)/2;
		if(valToSearch == A[mid]) 
			return mid;
		else if(A[mid] > valToSearch) {
			high = mid-1;		
		}
		else {
			low = mid+1;
		}
	}
	return -1;
}

//binary search using recursion
int binarySearchRecursivly(int *A,int low,int high,int val) {
	int mid = 0;
	if(low > high) //to break recursion
		return -1;	
	mid = (low+high)/2;
	
	if(val == A[mid]) 
		return mid;
	else if(A[mid] > val) {
		binarySearchRecursivly(A,low,mid-1,val);
	}
	else {
		binarySearchRecursivly(A,mid+1,high,val);	
	}
}

int main() {
	int A[] = {1,1,3,3,5,5,5,5,5,9,9,11};
	int B[] = {3,5,6,7,8,9,10,14,15,17,23};
	int len = sizeof(A)/sizeof(int) -1;
	int lenB = sizeof(B)/sizeof(int) -1;
	int val = 9;
	int valB = 17;
	
	cout<<"The value "<<val<<"  is at position "<<binarySearch(A,0,len,val)<<"  int the given array A"<<endl;
	
	//binary search recursive way
	cout<< "value : "<<valB<<"  is at position : "<<binarySearchRecursivly(B,0,lenB,valB);
	
	
	return 0;
}
