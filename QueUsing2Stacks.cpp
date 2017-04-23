#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include<iostream>
using namespace std;

typedef struct stack {
	
	int data;
	struct stack *next;
}Node;

typedef struct queue {
	Node *stack1;
	Node *stack2;
}Queue;

Node* getNewNode(int data) {
	
	Node *n = (Node*)malloc(sizeof(Node));
	if(n==NULL) {
		cout<<"Stack is full "<<endl;
		return NULL;
	}
		
	n->data = data;
	n->next = NULL;
	
	return n;
}

void push(Node **top,int data) {
	
	if(*top == NULL)
		*top = getNewNode(data);
	else {
		Node *temp = getNewNode(data);
		temp->next = *top;
		*top = temp;
	}
}

int pop(Node **top) {
	Node *stack = NULL;
	int data = 0;
	if(*top!=NULL) {
		stack = *top;
		data = stack->data;
		*top = (*top)->next;
		free(stack);
	}
	else {
		cout<<"Stack is empty"<<endl;
		exit(0);
	}
	return data;
}

void pusToStack2(Node **stack1, Node **stack2) {
	Node *temp = NULL;
	while(*stack1 != NULL) {
		int data = pop(stack1);
		push(stack2,data);
	}
}

//Incase if we want to add elements to front of queue
//when stack2 is not empty
void pusToStack1(Node **stack1, Node **stack2) {
	Node *temp = NULL;
	while(*stack2 != NULL) {
		int data = pop(stack2);
		push(stack1,data);
	}
}

void Enqueque(Queue *q,int data) {
	if(q->stack2!=NULL) {
		pusToStack1(&q->stack1,&q->stack2);
	}
	push(&q->stack1,data);
}


void display(Node *head) {
	Node *p1 = head;	
	while(p1!=NULL) {		
		cout<<p1->data<<"  ";
		p1=p1->next;
	}	
	cout<<endl;
}

void Dequeue(Queue *q) {
	cout<<endl;
	if(q->stack1 == NULL && q->stack2 == NULL)
    {
        printf("Q is empty");
        getchar();
        exit(0);
    }
	if(q->stack2==NULL) 
		pusToStack2(&q->stack1,&q->stack2);		
	pop(&q->stack2);
	cout<<endl;
}

int main() {
	Queue *q=(Queue*)malloc(sizeof(Queue));
	q->stack1=NULL;
	q->stack2=NULL;
	
	//First List
	Enqueque(q,1);
	Enqueque(q,3);
	Enqueque(q,1);
	Enqueque(q,3);
	Enqueque(q,4);
	Enqueque(q,5);
	Enqueque(q,4);	
		
	display(q->stack1);

	Dequeue(q);	
	Dequeue(q);	
	Enqueque(q,8);
	display(q->stack1);
	Dequeue(q);
	display(q->stack2);
	Enqueque(q,7);
	display(q->stack1);
	Enqueque(q,9);
	display(q->stack1);
	Dequeue(q);
	display(q->stack2);
	
	return 0;
}
