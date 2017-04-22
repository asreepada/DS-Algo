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

void display(Node *head) {
	Node *temp = head;
	while(temp!=NULL) {
		
		cout<<temp->data<<"  ";
		temp=temp->next;
	}
	cout<<endl;
}

void displayRecursively(Node *head) {
	
	Node *temp = head;
	if(temp==NULL) {		
		return;
	}
	cout<<temp->data<<"   ";
	displayRecursively(temp->next);
}

bool isEqual(Node *list1, Node *list2) {
	if(!list1 && !list2)
		return false;		
	while(list1 && list2) {		
		if(list1->data == list2->data) {
			list1 = list1->next;
			list2 = list2->next;
		}
		else {
			return false;
		}			
	}
	return true;
}

//Reverse Linked list using temporary list
void reverseList(Node **target) {
	
    Node *head = *target,*next,*cursor = NULL;
    while(head != NULL) {
    	
        next = head->next;
        head->next = cursor;
        cursor = head;
        head = next;
    }
    *target = cursor;   

}

//Reversing linked list using recursion
Node* reverseWithoutTempList(Node *head) {
	Node *cur, *next;
	if(head == NULL) {
		return head;
	}
	cur = head;
	next=cur->next;
	if(next==NULL)  {
		return cur; // breaking recursion
	}
	next = reverseWithoutTempList(next);	
	cur->next->next = cur;	
	cur->next = NULL;	
	return next;
}

void checkIFListIsPalindromOrNot(Node *head) {
	Node *temp = head;
	Node *p = head, *q = head;
	Node *list1 = NULL, *list2 = NULL;
	
	while(1) {
		q = q->next->next;
		if(q==NULL) {
			list2 = p->next;
			break;
		}
		if(q->next == NULL) {
			list2 = p->next->next;
			break;
		}
		p = p->next;
	}
	p->next = NULL;
	Node *revList = reverseWithoutTempList(list2);	
	list1 = head;
	
	if( isEqual(list1,revList)==true )
		cout<<" Yes, The list is palindrom "<<endl;
	else 
		cout<<" No, The list is not palindrom " << endl;
}

void isEvenOrOddList(Node *head) {
	Node *q=head, *p=head;
	while(1) {
		q = q->next->next;
		if(q==NULL) {
			cout<<"There are Even number of elements in the list "<<endl;			
			break;
		}
		if(q->next == NULL) {
			cout<<"There are Odd number of elements in the list "<<endl;
			break;
		}
		p = p->next;
	}
	
}
int main() {
	Node *head=NULL;
	
	//First List
	addAtFront(&head,'a');
	addAtFront(&head,'b');
	addAtFront(&head,'c');
	addAtFront(&head,'b');
	addAtFront(&head,'a');
	
	displayRecursively(head);
	cout<<endl<<endl;	
	isEvenOrOddList(head);
	cout<<endl;
	cout<<"Displaying recursively ";
	displayRecursively(head);
	cout<<endl;
	cout<<endl;
	checkIFListIsPalindromOrNot(head);	
	
	return 0;
}
