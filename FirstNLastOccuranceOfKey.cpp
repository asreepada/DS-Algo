#include <iostream>
using namespace std;

int main() {
	//code
	int A[] = {1, 3, 5, 5, 5, 5 ,67, 123, 125};
	int first = -1;
	int last = -1;
	int len = sizeof(A)/sizeof(int);
	cout<< len<<endl;
	int key = 5;
	for(int i=0;i<len;i++) {
	    if(key==A[i]) {
	    	if(first == -1)
	    		first = i;
	    	else 
	    		last = i;
		}		
	}
	
	
	cout<<" First index = " <<first<< "   Last index = " <<last<<endl;
	return 0;
}
