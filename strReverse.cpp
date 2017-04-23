#include<iostream>
#include<stdio.h>
#include <cstring>
#include<vector>

using namespace std;

// Reverse whole string
//Input: Anuradha
//output : ahdarunA
void strRev(char *str) {

	int i=0;
	int j = strlen(str)-1;
	cout<<j<<endl;
	while(j>i) {
		swap(str[i],str[j]);
		i++;
		j--;
	}
	
}

//reverse words
//EG 
// INPUT  :  This is word
// OUTPUT :  siht si drow 
void wordRev(char *str) {
	int k =0;
	int wordLen = 0;
	int i =0;
	int j = strlen(str) -1;
	cout<<j<<endl;
	while(i<=j) {	
		while(str[k+1]!=' '&&str[k+1]!='\0') {
			k++;
		}
		wordLen = k+1;
		cout<<wordLen<<"    "<<k<<endl;
		while(i<=k) {
			swap(str[i],str[k]);
			i++;
			k--;
		}
		i=wordLen+1;
		k=i;
	}
}

// Reverse only words
//  INPUT  : This is word
//  OUTOUT : word is This
vector<char*> revWords(char *str) {
	
	vector<char*> v;
	char* chars_array = strtok(str, " ");
    while(chars_array)
    {
    	cout<<chars_array<<endl;
        v.push_back(chars_array);
         
        chars_array = strtok(NULL, " ");
    }
    
	return v;
}

int main() {
	char str[] = "This is Anuradha";
	vector<char*> vec;
	
	//strRev(str);
	//wordRev(str);
	
	vec = revWords(str);
	cout<<vec.size()<<"   size of vetor "<< endl;
	for(int i=vec.size()-1;i>=0;i--) {
		cout<<vec[i]<<"  ";
	}
	cout<<endl;

	return 0;
}
