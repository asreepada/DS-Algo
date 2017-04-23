#include<stdio.h>
#include<malloc.h>
#include<iostream>
using namespace std;

typedef struct node {
	
	char data;
	struct node *next;
}Node;

Node* getNewNode(char data) {
	
	Node *n = (Node*)malloc(sizeof(Node));
	n->data = data;
	n->next = NULL;
	
	return n;
}

void addAtFront(Node **head,char data) {
	
	if(*head == NULL)
		*head = getNewNode(data);
	else {
		Node *temp = getNewNode(data);
		temp->next = *head;
		*head = temp;
	}
}

//insert node at the given position
void insertAtNthPosition(Node **head,int position,int data) {
	Node *cur = NULL, *nextLoc = NULL;
	int cnt = 1;
	cur = *head;	
	
	if(position == 1) { // if the position is at the start of the list
			Node *n = getNewNode(data);
			n->next = cur;
			*head = n;	
			return;		
	}			
	nextLoc = cur->next;
	while(cnt<position-1) {
		cnt++;					
		cur=cur->next;		
		nextLoc=nextLoc->next;
	}	
	Node *n = getNewNode(data);
	cur->next = n;	
	if(nextLoc!=NULL) //if it is not end node
		n->next = nextLoc;		
}

//delete all elements in Linked list
Node* pop(Node *head) {
	Node *cur = NULL;
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

//delete node at given position
void popEleAtPos(Node **head,int position) {
	
	Node *cur=*head, *next = NULL;
	next = cur->next;
	int cnt = 1;
	while(next!=NULL) {
		++cnt;		
		if(cnt == position) {
			Node *temp =next;
			next = next->next;
			cur->next = next;
			temp->next=NULL;
			free(temp);
			break;
		}
		if(position == 1) {
			Node *temp =cur;
			cur = cur->next;
			next = next->next;
			*head = cur;
			temp=NULL;
			free(temp);
			break;	
		}		
		cur = cur->next;
		next = next->next;	
		
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

int main() {
	Node *head=NULL;
		
	addAtFront(&head,'a');
	addAtFront(&head,'b');
	addAtFront(&head,'c');
	addAtFront(&head,'b');
	addAtFront(&head,'a');
	
	display(head);
		
	insertAtNthPosition(&head,6,'z');
	insertAtNthPosition(&head,1,'x');
	insertAtNthPosition(&head,3,'y');
	
	display(head);	
	
	popEleAtPos(&head,6);
	popEleAtPos(&head,1);
	popEleAtPos(&head,3);
	
	display(head);
	
}

