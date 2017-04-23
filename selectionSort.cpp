#include<stdio.h>
#include<iostream>
using namespace std;

void selectionSort(int arr[]) {
	int size = sizeof(arr);
	int i =0;
	int iMin;
	
	while(i<size-1) {
		iMin = i;	
		for(int j=i+1;j<size-1;j++) {			
			if(arr[iMin]>arr[j]) {				
				iMin = j;
			}
		}		
		swap(arr[i],arr[iMin]);
		i++;
	}
}

void printList(int *arr) {
	int size = sizeof(arr);
	for(int i=0;i<size-1;i++)
		cout<<arr[i]<<"  ";
	cout<<endl;
}
int main() {
	int arr[] = {5,2,7,1,8,9,0};
	printList(arr);
	selectionSort(arr);
	printList(arr);
	return 0;
}
