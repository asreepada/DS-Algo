/* finding min and max in Binary Search Tree */

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

void findMinInBST(Node *root) {
	if(root->left == NULL) {
		cout<<"Min value is : "<<root->data<<endl;
		return;
	}
	else 
		findMinInBST(root->left);
}

void findMaxInBST(Node *root) {
	if(root->right == NULL) {
		cout<<"Max value is : "<<root->data<<endl;
		return;
	}
	else 
		findMaxInBST(root->right);
}

void inOrderTraversal(Node* root) {
	if(root == NULL) 
		return;
	inOrderTraversal(root->left);
	cout<<root->data<<" ";
	inOrderTraversal(root->right);
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
	cout<<"Inorder traversal : ";
	inOrderTraversal(root);
	cout<<endl;
	
	findMinInBST(root);
	
	findMaxInBST(root);
	return 0;
	
}
