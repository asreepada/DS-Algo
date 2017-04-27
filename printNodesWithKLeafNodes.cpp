/*Print nodes having k leaves in its subtree */
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

int printNodesWithKLeafs(Node *root,int k) {
	if(root== NULL)
		return 0;
	if(root->left==NULL && root->right==NULL)
		return 1;
		
	int leftCount = printNodesWithKLeafs(root->left,k);
	int rightCount = printNodesWithKLeafs(root->right,k);
	
	if((leftCount+rightCount) == k) {
		cout<<root->data<<"  ";
		return leftCount+rightCount;
	}		
}
int main() {
	Node *root = NULL;
	int min = -100;
	int max = 100;
	int k =3;
	
	insertIntoBST(&root,5);
	insertIntoBST(&root,3);
	insertIntoBST(&root,1);
	insertIntoBST(&root,10);
	insertIntoBST(&root,4);
	insertIntoBST(&root,11);
	
	cout<<endl;	
	cout<<"Nodes with '"<<k<<"' leafs : ";
	printNodesWithKLeafs(root,k);
	
	return 0;
	
}
