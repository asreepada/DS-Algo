/* This program checks if the parenthesis is balanced or not */
#include<iostream>
#include<stdio.h>
#include<stack>

using namespace std;

void pop(stack<char> *st, char ch) {
	
	if((ch == ')'&&st->top()=='(' )|| 
		(ch == '}'&&st->top()=='{') || 
		(ch == ']'&&st->top()=='[')) {	
		st->pop();	
	}	
}


bool isBalancedParenthesis(char *A,int size) {
	int cnt = 0;
	stack<char> st;	
	while(cnt<=size) {		
		if(A[cnt]=='(' ||A[cnt]=='{'||A[cnt]=='[' ) {			
			st.push(A[cnt]);			
		}
		else if(A[cnt]==')' ||A[cnt]=='}'||A[cnt]==']') {			
			if(st.empty()==true) {
				return false;
			}
			else {				
				pop(&st,A[cnt]);				
			}
		}
		cnt++;		
	}
	
	return true;
}

int main() {
	//char A[]="{()}()}[]";
	char A[]="{()()}[]";
	int len = sizeof(A)-1;
	bool isBalanced = isBalancedParenthesis(A,len);
	if(isBalanced == true)
		cout<<" The string has balanced Parenthesis"<<endl;
	else 
		cout<<" The string does not have balanced Parenthesis"<<endl;
	return 0;
}
