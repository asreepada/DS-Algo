#include<stdio.h>
#include<iostream>
#include<stack>
using namespace std;
stack<int> s1;
stack<int> s2;

void insert(int val) {
	cout<<"Pushing to S1: "<<val<<endl;
	s1.push(val);
	if(s2.empty() || s2.top() > val ) {
		cout<<"Pushing to S2: "<<val<<endl;
		s2.push(val);
	}
	
}

void pop() {
	if(s1.top() == s2.top()) {
		cout<<"Poping from S1 & S2 : "<<s1.top()<<endl;
		s1.pop();
		s2.pop();
	}
	else {
		cout<<"Poping from S1 : "<<s1.top()<<endl;
		s1.pop();
	}
}

//get smallest element in the stack
void getMinEle() {
	if(!s2.empty()) {
		cout<<" Minimum value in the stack is : "<<s2.top()<<endl;
	}
	else {
		cout<<"No elements in the stack "<<endl;
	}
}


int main() {

	insert(50);
	insert(60);
	insert(40);
	insert(30);
	insert(90);
	insert(20);
	insert(10);
	insert(75);
	insert(52);
	insert(0);
	pop();
	pop();
	getMinEle();
	
}
