#include<stdio.h>
#include<malloc.h>
#include<iostream>
using namespace std;

typedef struct node {
    int data;
    struct node *link;
}Node;

Node* newNode(int data) {
	Node *newNode;
	newNode = (struct node *) malloc(sizeof(Node));
	newNode->data = data;
	newNode->link = NULL;
	
	return newNode;
}

void addNodeAtFront(Node **head,int data) {
	
	if(head==NULL) {
		*head=newNode(data);		
	}
	else {
		Node *n = newNode(data);
		n->link = *head;		
		*head = n;
		
	}
}

void display(Node *source) {	
    Node *temp = source;
    cout<<"list data =  ";
    while(temp != NULL) {
        printf(" %d  ",temp->data);
        temp = temp->link;
    }
    cout<<endl;   
}

void getNthNodeFromLast(Node *head,int n) {
	
	Node *p1=head;
	Node *p2=head;
	int pos = n;
	
	if(head==NULL)
		return;	
	while(n>0) {
		if(p1==NULL) {
			cout<<pos<<"  is larger than the list"<<endl;
			return;
		}
		p1=p1->link;
		n--;
	}
	while(p1!=NULL) {
		p1=p1->link;
		p2=p2->link;
	}
	cout<<"The node at ["<< pos<<"] position from last is :  "<<p2->data<<endl;
}

int main()
{
	
	Node *head=NULL;
	
	addNodeAtFront(&head,1);
    addNodeAtFront(&head,2);
    addNodeAtFront(&head,3);
    addNodeAtFront(&head,4);
    addNodeAtFront(&head,5);
    addNodeAtFront(&head,6);
    
    display(head);
    //getNthNodeFromLast(head,10);
    
    getNthNodeFromLast(head,3);
    
}


