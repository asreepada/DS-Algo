/* check if a given binary tree is binary search tree or not    */
/* A binary search tree is a tree in which each root node is    */
/* is greater than its left child and less than its right child */
/* the same rule applied to each node in the tree               */

#include<iostream>
#include<stdio.h>
#include<queue>
#include<stdlib.h>
using namespace std;

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

void inOrderTraversal(Node* root) {
	if(root == NULL) 
		return;
	
	inOrderTraversal(root->left);
	cout<<root->data<<" ";
	inOrderTraversal(root->right);
}

bool checkIfTreeIsBST(Node *root,int min,int max) {
	if(root==NULL) {		
		return true;
	}
	if(root->data<=min || root->data>max) {		
		return false;
	}
	
	return checkIfTreeIsBST(root->left,min,root->data) && 
			checkIfTreeIsBST(root->right,root->data,max);
	
}
int main() {
	Node *root = NULL;
	int min = -100;
	int max = 100;
	
	insertIntoBST(&root,5);
	insertIntoBST(&root,3);
	insertIntoBST(&root,1);
	insertIntoBST(&root,10);
	insertIntoBST(&root,4);
	insertIntoBST(&root,11);
	
	
	cout<<endl;	
	inOrderTraversal(root);
	cout<<endl;
	
	if((checkIfTreeIsBST(root,min,max))==true) {
		cout<<"Given tree is a binary search tree "<<endl;
	}
	else {
		cout<<"Given tree is not a binary search tree "<<endl;
	}
	return 0;
	
}
