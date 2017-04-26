/* Find height of a binary tree */

#include<iostream>
#include<stdio.h>
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

int findHeightOfBST(Node *root) {
	int leftHeight = 0;
	int rightHeight = 0;
	
	if(root == NULL)
		return -1;
	leftHeight  = findHeightOfBST(root->left);
	rightHeight = findHeightOfBST(root->right);
	
	return max(leftHeight,rightHeight)+1;
}

int main() {
	Node *root = NULL;
	int key = 90;
	insertIntoBST(&root,40);
	insertIntoBST(&root,20);
	insertIntoBST(&root,50);
	insertIntoBST(&root,55);
	insertIntoBST(&root,60);
	insertIntoBST(&root,35);
	insertIntoBST(&root,5);
	insertIntoBST(&root,70);
	
	cout<<endl;
	
	cout<<"Height of tree is :  "<<findHeightOfBST(root)<<endl;
	
	
	return 0;
	
}

