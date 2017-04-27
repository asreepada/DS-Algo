/* find the lowest common ancestor of two given nodes */

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

Node* findLowestCommonAncestor(Node *root,int p, int q) {
	if(root == NULL)
		return NULL;
	if(root->data==p||root->data==q)
		return root;
		
	Node* left = findLowestCommonAncestor(root->left,p,q);
	Node* right = findLowestCommonAncestor(root->right,p,q);
	
	if(left!=NULL && right != NULL)
		return root; // lowest common ancestor
	else 
		return left?left:right;	
}

int main() {
	Node *root = NULL;
	int p = 4;
	int q = 1;
	
	
	insertIntoBST(&root,5);
	insertIntoBST(&root,3);
	insertIntoBST(&root,1);
	insertIntoBST(&root,10);
	insertIntoBST(&root,4);
	insertIntoBST(&root,11);
	
	cout<<endl;	
	
	Node *lca = findLowestCommonAncestor(root,p,q);
	cout<<"Lowest common ancestror for '"<<p<<" & "<<q<<"' is : "<<lca->data<<endl;
	
	
	return 0;
	
}
