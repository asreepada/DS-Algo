/* This program prints all the leaf nodes and also
   prints number of leaf nodes
*/

#include<iostream>
#include<stdio.h>
#include<queue>
#include<stdlib.h>
using namespace std;

int cnt = 0;

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


void printAllLeafNodes(Node* root) {
	
	if(root==NULL) return;
	if(root->left==NULL && root->right == NULL) {
		cout<<root->data<<"  ";
		cnt++; // to count the number of leaf nodes
		return;
	}
	printAllLeafNodes(root->left);
	printAllLeafNodes(root->right);
	
}

int main() {
	Node *root = NULL;
	
	
	
	insertIntoBST(&root,5);
	insertIntoBST(&root,3);
	insertIntoBST(&root,1);
	insertIntoBST(&root,10);
	insertIntoBST(&root,4);
	insertIntoBST(&root,11);
	
	cout<<endl;	
	inOrderTraversal(root);
	cout<<endl;
	
	
	cout<<"Leaf Nodes are : ";
	printAllLeafNodes(root);
	cout<<endl<<"Number of leaf nodes in the tree are : "<<cnt;
	cout<<endl;
	
	return 0;
	
}
