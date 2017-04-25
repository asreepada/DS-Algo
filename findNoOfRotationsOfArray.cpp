/*find number of times the array is rotated*/
/* The array needs to be circularly sorted and the elements need to be distinct */
#include<iostream>
#include<stdio.h>

using namespace std;

int findNumberOfRotations(int *A, int size) {
	
	int low =0;
	int high = size;
	int N=size;
	if(A[low] <= A[high])
		return low;
	while(low<=high) {
		int mid = (low+high)/2;
		int next = (mid+1)%N;
		int prev = (mid+N-1)%N;
		if(A[mid] <=A[next] && A[mid] <= A[prev])
			return mid;
		if(A[mid] <=A[high])
			high = mid-1;
		else if(A[mid] >=A[low])
			low = mid+1;
	}
	return -1;
	
}

int main() {
	int A[] = {8,11,12,14,18,2,5,6};
	int len = sizeof(A)/sizeof(A[0]) -1;
	int count = findNumberOfRotations(A,len);
	
	cout<<" Array is rotated '"<<count<<"' times"<<endl;
	return 0;
}
