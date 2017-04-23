#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<iostream>
using namespace std;

typedef struct node
{
	int data;
	struct node *next;
}Node;

//creating new node
Node *getNewNode(int data)
{
	Node *newNode;
	newNode = (Node*)malloc(sizeof(Node)); 
	newNode->data = data;   
	newNode->next = NULL;
	return newNode;  
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

Node* createListWithLoop(Node *head,int stNodeOfLoop) {
	Node *toStOfLoop = head;
	Node *startNode = head;
	Node *traverseToEnd = head;
	
	while(traverseToEnd->next!=NULL) 
		traverseToEnd = traverseToEnd->next;
	
	while(stNodeOfLoop>0) {
		toStOfLoop = toStOfLoop->next;
		stNodeOfLoop--;
	}	
	traverseToEnd->next = toStOfLoop;	

	return startNode;
}

Node* findIntersectingPointInCaseOfLoop(Node *head) {
	Node *p1 = NULL;
	Node *p2 = NULL;	
	
	p1 = head;
	p2 = head;
	while(1)
	{
		if(p1 == NULL || p2 == NULL)
		{
			printf("\n No loop found in the list");
			return NULL;
			
		}		
		p1 = p1->next;
		p2 = p2->next->next;
		if(p1 == p2)
		{
			
			printf("\n Loop found in the linked list,");
			cout<<"  Intersecting point is : "<<p1->data<<endl;
			return p1;
		}		
	}
	
}

void findLenOfLoop(Node *intersectingPointInLoop,Node *head) {	
	int lenOfLoop = 1;
	Node *temp = intersectingPointInLoop->next;
	
	while(temp!=intersectingPointInLoop)
	{		
		lenOfLoop = lenOfLoop+1;
		temp = temp->next;		
	}
	
	printf("\n Length of the loop is : %d\n",lenOfLoop);
}

void findStartPointOfLoop(Node *head,Node *intersectingPointInLoop) {
		
	Node *p = intersectingPointInLoop;
	Node *q = head;
	while(p!=q)
	{
		p = p->next;
		q = q->next;
	}	
	printf("\n The starting point of the loop is  %d\n", q->data);
}

void removeLoopInLL(Node *head,Node *intersectingPointInLoop) {
	Node *p = intersectingPointInLoop;
	Node *q = head;
	while(p->next!=q->next)
	{
		p = p->next;
		q = q->next;
	}	
	cout<<endl<<" Last node in the list is :  ";
	cout<<p->data<<endl;
	p->next = NULL;
}

//display list
void display(Node *head) {
	cout<<" Nodes in the Linked List are : ";
	Node *temp = head;
	while(temp!=NULL) {
		
		cout<<temp->data<<"  ";
		temp=temp->next;
	}
	cout<<endl;
}

int main()
{
	Node *head = NULL;
	addAtFront(&head,9);
	addAtFront(&head,8);
	addAtFront(&head,7);
	addAtFront(&head,6);
	addAtFront(&head,5);
	addAtFront(&head,4);
	addAtFront(&head,3);
	addAtFront(&head,2);
	addAtFront(&head,1);
	
	//create loop in the linked list
	Node *listWithLoop = createListWithLoop(head,4);
	
	//find the intersecting point of the 2 pointers in the loop
	Node *intersectingPointInLoop = findIntersectingPointInCaseOfLoop(listWithLoop);
	
	//find the length of the loop
	if(intersectingPointInLoop != NULL)
		findLenOfLoop(intersectingPointInLoop,head);
	
	// find the starting point of the loop in ll
	findStartPointOfLoop(head,intersectingPointInLoop);
		
	//remove loop in ll
	removeLoopInLL(head,intersectingPointInLoop);
	
	cout<<endl;
  	//display list after removing loop
  	display(head);
return 0;	
}
