#include <stdio.h>
#include "iostream"
using namespace std;

int addInt(int n, int m) {
	return n+m;
}

typedef int(*myFuncPtr)(int,int);


int main() {
	int a = 10; 
	int b = 20;
	myFuncPtr myPtr = &addInt;
	cout<< myPtr(a,b);
	//cout<< fptr;
}
