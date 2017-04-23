#include<iostream>
#include <set>
#include <map>
#include<string>
using namespace std;

 int main() {
 	int arr[] = {2,2,3,4,5,6,7,5};
 
 	
 	int size = sizeof(arr)/sizeof(int);
 	set <int> s;
 	for(int i=0;i<size;i++) {
	 	//set eliminates duplicates
	 	//the elements of set are sorted and unique
 		s.insert(arr[i]);
 	}
 	for (set<int>::iterator it=s.begin(); it!=s.end(); ++it)
		    cout << *it<<"   " ;
		    
	cout<<endl; 	
 	
 	return 0;
 }
