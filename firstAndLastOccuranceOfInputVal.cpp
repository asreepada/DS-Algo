/* finding first and last occurance of an element using binary serach*/
#include<iostream>
#include<stdio.h>

using namespace std;

int findFirstOrLastOccuranceOfValue(int *A, int high, int valToSearch,bool flag) {
	int mid = 0;	
	int result = -1;
	int low = 0;
	while(low<=high) {
		mid = (low+high)/2;
		if(valToSearch == A[mid]) {
			result = mid;
			if(flag)	//if flag = true, find first occurance of valToSearch
				high = mid-1;
			else // find last occurance of value
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
	int len = sizeof(A)/sizeof(int) -1;	
	int val = 5;
	
	
	int fistOccurance = findFirstOrLastOccuranceOfValue(A,len,val,true);
	if(fistOccurance == -1)
		cout<<"value not found in the given list"<<endl;
	else {
		cout<<"First occurance of value : "<<val<<" is at :  "<<fistOccurance<<endl;
		int lastOccurance = findFirstOrLastOccuranceOfValue(A,len,val,false);
		cout<<"Last occurance of value : "<<val<<" is at :  "<<lastOccurance<<endl;
	}
	
	return 0;
}
