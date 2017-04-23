#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include<iostream>
using namespace std;

typedef struct node {
	
	int data;
	struct node *next;
}Node;

Node* getNewNode(int data) {
	
	Node *n = (Node*)malloc(sizeof(Node));
	n->data = data;
	n->next = NULL;
	
	return n;
}

void display(Node *head) {
	Node *temp = head;
	if(temp==NULL) {
		cout<<endl<<"No elements in List, it is empty "<<endl;
		return;	
	}
	while(temp!=NULL) {
		
		cout<<temp->data<<"  ";
		temp=temp->next;
	}
	cout<<endl;
}

void push(Node **head,int data) {
	
	if(*head == NULL)
		*head = getNewNode(data);
	else {
		Node *temp = getNewNode(data);
		temp->next = *head;
		*head = temp;
	}
}

Node* pop(Node *head) {
	Node *cur = NULL;
	cout<<endl<<"Poping elements in stack : ";
	while(head!=NULL) {
		cur = head;
		head = head->next;
		cout<<cur->data<<"   ";
		cur->next = NULL;
		free(cur);
	}
	cout<<endl;
	return head;
}

int main() {
	Node *head=NULL;
	
	//First List
	push(&head,1);
	push(&head,3);
	push(&head,1);
	push(&head,3);
	push(&head,4);
	push(&head,5);
	push(&head,4);
	
	cout<<"data before pop : ";	
	display(head);
	
	Node *popedList = pop(head);
	
	display(popedList);
	
	return 0;
}
