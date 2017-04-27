/* print next greater element for each element in the array */
#include<stdio.h>
#include<iostream>
#include<stack>
using namespace std;


void findNextGreaterEleForEachEleInArray(int *A,int size) {
	stack<int> s;
	for(int i=0;i<=size;i++) {
	
		if(s.empty() || A[i]< s.top() ) {
			s.push(A[i]);
		}
		else if(A[i] > s.top()) {
			while( !s.empty() && s.top()<A[i] ) {				
				cout<<s.top()<<"->"<<A[i]<<endl;
				s.pop();
			}	
			s.push(A[i]);			
		}
				
	}
	cout<<endl<<"No greater element found for the following elements in array"<<endl<<endl;
	while(!s.empty()) {
		cout<<s.top()<<"->  "<<endl;
		s.pop();
	}
}

int main() {
	int A[] = {5,3,2,10,6,8,1,4,12,7,4};
	int len = sizeof(A)/sizeof(A[0]) -1;
	cout<<"Next greater elements are : "<<endl<<endl;
	findNextGreaterEleForEachEleInArray(A,len);
	return 0;
}
