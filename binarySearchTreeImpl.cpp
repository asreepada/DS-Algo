/* Binary Search Tree implementation */

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

void preOrderTraversal(Node *root) {
	if(root==NULL) 
		return;
	cout<<root->data<<"  ";
	preOrderTraversal(root->left);
	preOrderTraversal(root->right);
}

void postOrderTraversal(Node *root) {
	if(root == NULL) 
		return;
	postOrderTraversal(root->left);
	postOrderTraversal(root->right);
	cout<<root->data<<"  ";
}

void inOrderTraversal(Node* root) {
	if(root == NULL) 
		return;
	inOrderTraversal(root->left);
	cout<<root->data<<" ";
	inOrderTraversal(root->right);
}

void searchInBST(Node *root,int key) {
	if(root == NULL) {
		cout<<"'"<<key<<"' not found in the tree"<<endl;
		return;
	}
	if(key == root->data) {
		cout<<"'"<<key<<"' found in the tree "<<endl;
		return;
	}
	else if(key<=root->data)
		searchInBST(root->left,key);
	else if(key>=root->data)
		searchInBST(root->right,key);
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
	
	cout<<endl<<"Pre-order Traversal : ";
	preOrderTraversal(root);
	cout<<endl<<"Post-order traversal : ";
	postOrderTraversal(root);
	cout<<endl<<"In-order traversal : ";
	inOrderTraversal(root);
	cout<<endl<<"Searching  '"<<key<<"' in the tree ..."<<endl;
	searchInBST(root,key);
	//Search(root,key);
	return 0;
}
