#include<iostream>
#include<stdio.h>
#include <cstring>

using namespace std;

void printSubStr( char* str, int low, int high )
{	cout<<"Palindrom in the given string : ";
    for( int i = low; i <= high; ++i )
        printf("%c", str[i]);
    cout<<endl;
}

void longestPalindromStr(char *inputStr,int len) {
	int location = 0;
   	int maxsize = 0;
   	for ( int i = 0; i < len; i++ ) {
    	int left = i;
       int right = i;
       int count = 0;
       while ( left > 0 ) {       		
           if ( inputStr[left--] != inputStr[right++] ) {
               break;
           }
           //print the available palindromes in the given string
           if(right-left>2)
           		printSubStr(inputStr,left+1,right-1);           
           count++;
       }
       if ( count > maxsize ) {
          maxsize = count;
          location = i;
       }
   }
   
   int startIdx = location - maxsize + 1;
   int endIdx = location + maxsize;
   cout<<"Largest palindrom in the given input string is :  ";
   for ( int i = startIdx; i < endIdx; i++ ) {
       cout << inputStr[i];
   }
}

int main() {
	
	char input[] = "jsdfjdsfhracecarksdfjsdkfmalayalamcheckmaddam";   	
   	int len = strlen(input);
   	
	longestPalindromStr(input,len-1);   
   	cout<<endl;
	return 0;
}
