#include<iostream>
#include<stdio.h>
#include <cstring>

using namespace std;

bool isAlpha(char c) {
	
	if(c>='a' && c<='z' || c>='A' && c<='Z') 
		return true;
}
int main() {
	char str[] = "An##ur$ad!!ha";
	int i = 0;
	int j = strlen(str)-1;
	
	while(j>i) {
	
		if(!isAlpha(str[i])) { 
			i++;
		}
		else if(!isAlpha(str[j])) {
			j--;
		}
		else {
			swap(str[i], str[j]);
            i++;
            j--;
			
		}
	}
	
	cout<<str;
	
	return 0;
}
