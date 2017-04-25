/* Find an element in circular array */
/* The array should be sorted and the elements should be distinct */
#include<iostream>
#include<stdio.h>

using namespace std;

int findIdxOfElemInCircularArray(int *A,int size, int key) {
	int low = 0;
	int high = size;
	
	while(low<=high) {
		
		int mid = (low+high)/2;
		if(A[mid] == key)
			return mid;
		if(A[mid]<=A[high]) {
			if(key>A[mid] && key<=A[high])
				low = mid+1;
			else
				high = mid-1;
		}
		else {
			if(key<A[mid] && key>=A[low])
				high = mid-1;
			else 
				low = mid+1;			
		}
	}
	return -1;
}

int main() {
	int A[] = {8,11,12,14,18,2,5,6};
	int len = sizeof(A)/sizeof(A[0]) -1;
	int key = 6;
	int index = findIdxOfElemInCircularArray(A,len,key);
	
	cout<<" Element is at '"<<index<<"' in the given circular array"<<endl;
	return 0;
}
