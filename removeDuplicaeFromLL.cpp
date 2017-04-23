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

void addAtFront(Node **head,int data) {
	
	if(*head == NULL)
		*head = getNewNode(data);
	else {
		Node *temp = getNewNode(data);
		temp->next = *head;
		*head = temp;
	}
}

void display(Node *head) {
	Node *temp = head;
	while(temp!=NULL) {
		
		cout<<temp->data<<"  ";
		temp=temp->next;
	}
	cout<<endl;
}

//remove using hashing
void removeDuplicateFromList(Node **head) {
	Node *p = *head, *q = NULL;
	int array[5];
	memset(array,0,sizeof(array));
	
	while(p!=NULL) {
		if(array[p->data]==0) {
			array[p->data] = 1;
			q=p;
			p = p->next;
		}
		else {			
			q->next = p->next;
			p = q->next;		
		} 	
	}	
}

//sort and remove duplicates
void sortAndRemoveDup(Node **head) {
	
}

int main() {
	Node *list1=NULL;
	
	//First List
	addAtFront(&list1,1);
	addAtFront(&list1,3);
	addAtFront(&list1,1);
	addAtFront(&list1,3);
	addAtFront(&list1,4);
	addAtFront(&list1,5);
	addAtFront(&list1,4);
	
		
	display(list1);
	removeDuplicateFromList(&list1);
	display(list1);
	return 0;
}
