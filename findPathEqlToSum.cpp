/* find the lowest common ancestor of two given nodes */

#include<iostream>
#include<stdio.h>
#include<stack>
#include<stdlib.h>
using namespace std;

int checkSum = 0;
stack<int> s;

typedef struct node {
	int data;
	struct node *left;
	struct node *right;
}Node;

Node * createNewNode(int data) {
	Node *n = (Node*)malloc(sizeof(Node));
	n->data = data;
	n->left = NULL;
	n->right = NULL;
	
	return n;
}

void insertIntoBST(Node **root,int data) {
	
	if(*root == NULL) {	
		*root = createNewNode(data);		
		return;
	}
	if(data<=(*root)->data){
		insertIntoBST(&(*root)->left,data);
	}
	else {
		insertIntoBST(&(*root)->right,data);
	}
}

void printPathEqlToGivenSum(Node *root,int sum) {
		
	if(root==NULL)
		return;
	if(checkSum!=0 && s.empty()) { 
		// means we also removed the root node from stack,
		// so adding it again to stack for the next path
		//when we back tracked checkSum contains value of the root
		//as we removed root also from stack adding it again
		s.push(checkSum);
	}
	s.push(root->data);
	
	checkSum += root->data;		
	
	if(checkSum == sum) {		
		while(!s.empty()) {	
			cout<<s.top()<<" ";		
			s.pop();
		}
		cout<<endl;
	}
	
	printPathEqlToGivenSum(root->left,sum);
	printPathEqlToGivenSum(root->right,sum);
	
	checkSum -= root->data;
	if(!s.empty())
		s.pop();
	
	
}

int main() {
	Node *root = NULL;
		
	insertIntoBST(&root,5);
	insertIntoBST(&root,3);
	insertIntoBST(&root,1);
	insertIntoBST(&root,7);
	insertIntoBST(&root,4);
	insertIntoBST(&root,11);
	
	cout<<endl;	
		
	cout<<"Path to the given sum is : "<<endl;
	printPathEqlToGivenSum(root,12);
	cout<<endl;
	
	
	return 0;
	
}
