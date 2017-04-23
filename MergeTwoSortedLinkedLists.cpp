#include<stdio.h>
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

Node * mergeLists(Node *p,Node *q,Node *s) {
	
	Node * mergedList = NULL;
	if(p==NULL) return q;
	if(q==NULL) return p;
	if(p && q) {
	
		if(p->data >= q->data) {
			s=q;
			q=q->next;
		}
		if(p->data <= q->data) {
			s = p;
			p = p->next;
		}
	}
	mergedList = s;
	while(p && q) {
		
		if(p->data >= q->data) {
						
			s->next=q;
			s = s->next;
			q=q->next;
		}
		if(p->data <= q->data) {
			
			
			s->next = p;
			s = s->next;
			p = p->next;
		}
	
	}
	if(p==NULL) s->next = q;
	if(q==NULL) s->next = p;
	
	return mergedList;
}

int main() {
	Node *list1=NULL, *list2=NULL, *mList = NULL,*s = NULL;
	
	//First List
	addAtFront(&list1,60);
	addAtFront(&list1,50);
	addAtFront(&list1,40);
	addAtFront(&list1,30);
	addAtFront(&list1,20);
	addAtFront(&list1,10);
	
	display(list1);
	
	//second List
	addAtFront(&list2,95);
	addAtFront(&list2,85);
	addAtFront(&list2,75);
	addAtFront(&list2,65);
	addAtFront(&list2,55);
	addAtFront(&list2,45);
	addAtFront(&list2,35);
	addAtFront(&list2,25);
	addAtFront(&list2,15);
	
	display(list2);
	
	//merge list1 & list2 in sorted order	
	mList = mergeLists(list1,list2,s);
	display(mList);
	return 0;
}
