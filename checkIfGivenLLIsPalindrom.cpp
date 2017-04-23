#include<stdio.h>
#include<malloc.h>
#include<iostream>
using namespace std;

typedef struct node {
    int data;
    struct node *next;
}Node;

Node* newNode(int data) {
	Node *newNode;
	newNode = (struct node *) malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = NULL;
	
	return newNode;
}
//add node at the begining of the list
void addNodeAtFront(Node **head,int data) {
	
	if(head==NULL) {
		*head=newNode(data);		
	}
	else {
		Node *n = newNode(data);
		n->next = *head;		
		*head = n;
		
	}
}
void display(Node *head) {	
    Node *temp = head;    
    while(temp != NULL) {
        printf(" %d  ",temp->data);
        temp = temp->next;
    }
    cout<<endl;   
}

//Reversing nexted list using recursion
Node* reverse(Node *head) {
	Node *cur, *next;
	if(head == NULL) {
		return head;
	}
	cur = head;
	next=cur->next;
	if(next==NULL)  {
		return cur; // breaking recursion
	}
	next = reverse(next);	
	cur->next->next = cur;	
	cur->next = NULL;	
	return next;
}

int checkIfLLIsPalindrom(Node **head, Node **target) {
    Node *sou = *head,*tar = *target;
    
    while( (sou) && (tar) ) {
        if(sou->data != tar->data) {
            printf("given linked list not a palindrome\n");
            return 0;
        }
        sou = sou->next;
        tar = tar->next;
    }
    
    printf("given linked list is a palindrome\n");    
    return 0;
}

//to remove all nodes of ll
void removeAllEleOfList(Node *target) {
    Node *temp;
    while(target != NULL) {
        temp = target;
        target = target->next;        
        free(temp);
    }   
}


int main()
{
    Node *head = NULL, *revList = NULL;
    
    //add elements to list
    addNodeAtFront(&head,1);
    addNodeAtFront(&head,2);
    addNodeAtFront(&head,1);
    addNodeAtFront(&head,1);
    addNodeAtFront(&head,1);
    addNodeAtFront(&head,2);
    addNodeAtFront(&head,1);
    
    cout<<"List before reversing : ";
    display(head);
    cout<<endl;
    
    revList = reverse(head);
    printf("list after reversing : ");
    display(revList);
    cout<<endl;
    
    checkIfLLIsPalindrom(&head,&revList); 
  	//removing list
	removeAllEleOfList(revList);
    
    return 0;
} 
