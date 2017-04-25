/* finding first and last occurence of an element using binary serach*/
#include<iostream>
#include<stdio.h>

using namespace std;

int findFirstOrLastOccurenceOfValue(int *A, int high, int valToSearch,bool flag) {
	int mid = 0;	
	int result = -1;
	int low = 0;
	while(low<=high) {
		mid = (low+high)/2;
		if(valToSearch == A[mid]) {
			result = mid;
			if(flag)	//if flag = true, find first occurence of valToSearch
				high = mid-1;
			else // find last occurence of value
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
	int val = 1;
	int lastOccurence = 0;
	
	int fistOccurence = findFirstOrLastOccurenceOfValue(A,len,val,true);
	if(fistOccurence == -1) {
		cout<<"Number of occurences of ' "<<val<<"' in the list is : 0"<<endl;
	}
	else {
		cout<<"First occurence of value : "<<val<<" is at :  "<<fistOccurence<<endl;
		lastOccurence = findFirstOrLastOccurenceOfValue(A,len,val,false);
		cout<<"Last occurence of value : "<<val<<" is at :  "<<lastOccurence<<endl;
		cout<<"Number of occurences of ' "<<val<<"' in the list is : "<<lastOccurence-fistOccurence+1<<endl;
	}
	
	
	
	return 0;
}
