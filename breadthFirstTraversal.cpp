/* Level order/ Breadth first traversal of a binary Tree */

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


void breadthFirstTraversal(Node *root) {
	queue<Node*> q;
	if(root==NULL) return;
	q.push(root);
	while(!q.empty()) {
		Node *cur = q.front();
		cout<<cur->data<<" ";
		if(cur->left!=NULL) q.push(cur->left);
		if(cur->right!=NULL) q.push(cur->right);
		q.pop();
	}
	
}

int main() {
	Node *root = NULL;
	
	insertIntoBST(&root,40);
	insertIntoBST(&root,20);
	insertIntoBST(&root,50);
	insertIntoBST(&root,55);
	insertIntoBST(&root,60);
	insertIntoBST(&root,35);
	insertIntoBST(&root,5);
	insertIntoBST(&root,70);
	
	cout<<endl;	
	breadthFirstTraversal(root);
	return 0;
	
}
