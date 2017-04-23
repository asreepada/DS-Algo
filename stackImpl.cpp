#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include<iostream>
#define SIZE  10
using namespace std;

int s1[SIZE]; 
int top=-1;

void push(int data) {
	
	if(top==SIZE) {
		cout<<"Stack overflow "<<endl;
		exit(0);
	}
	else {
		s1[++top] = data;
	}
	
}

void pop() {
	if(top==-1) {
		cout<<"Stack is empty"<<endl;
	}
	else {
		cout<<"Element poped is : "<<s1[top--]<<"  ";
	}
	cout<<endl;
}

void display() {
	int t = top;
	while(t!=-1) {		
		cout<<s1[t--]<<"  ";		
	}
	cout<<endl;
}

int main() {
	
	push(1);
	push(2);
	push(3);
	push(4);
	push(5);
	push(6);
	push(7);
	push(8);
	push(9);
	push(10);
	push(11);
	display();
	pop();
	pop();
	cout<<"TOP is at : "<<top+1<<endl;
	display();
	
	return 0;
}
