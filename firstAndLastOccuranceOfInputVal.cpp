/* finding first and last occurance of an element using binary serach*/
#include<iostream>
#include<stdio.h>

using namespace std;

int firstOccuranceOfInputVal(int *A, int low, int high, int valToSearch) {
	int mid = 0;	
	int result;
	
	while(low<=high) {
		mid = (low+high)/2;
		if(valToSearch == A[mid]) {
			result = mid;
			high = mid-1;
		} 			
		else if(A[mid] > valToSearch) {
			high = mid-1;		
		}
		else {
			low = mid+1;
		}
	}
	return result;
}

int lastOccuranceOfInputVal(int *A, int low, int high, int valToSearch) {
	int mid = 0;	
	int result;
	
	while(low<=high) {
		mid = (low+high)/2;
		if(valToSearch == A[mid]) {
			result = mid;
			low = mid+1;
		} 			
		else if(A[mid] > valToSearch) {
			high = mid-1;		
		}
		else {
			low = mid+1;
		}
	}
	return result;
}


int main() {
	int A[] = {1,1,3,3,5,5,5,5,5,9,9,11};
	int B[] = {3,5,6,7,8,9,10,14,15,17,23};
	int len = sizeof(A)/sizeof(int) -1;
	int lenB = sizeof(B)/sizeof(int) -1;
	int val = 5;

	int fistOccurance = firstOccuranceOfInputVal(A,0,len,val);
	int lastOccurance = lastOccuranceOfInputVal(A,0,len,val);
	
	cout<<"First occurance of value : "<<val<<" is at :  "<<fistOccurance<<endl;
	cout<<"Last occurance of value : "<<val<<" is at :  "<<lastOccurance<<endl;
	cout<<endl;
	
	
	
	return 0;
}
