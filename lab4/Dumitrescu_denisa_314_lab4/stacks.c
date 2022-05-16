#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

struct Node
{
    int data;
    int size;
    struct Node *next;
};

struct Node *top = NULL;
struct Node *rear = NULL;
struct Node *front = NULL;
int N = 10;

int isFull(){
    if(top->size == N || front->size == N )
    {
        return 1;
    }
    return 0;
}

int isEmpty()
{
    if (top == NULL)
        return 1;
    return 0;
}

void push(int value)
{
    struct Node *newNode;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = value; // assign value to the node
    newNode->size = 1;

    if(isFull)
    {
        return NULL; printf("Stack Overflow");
    }

    if (isEmpty)
    {
        newNode->next = NULL;
    }
    else
    {
        newNode->next = top; 
        newNode->size = newNode->size +1;
    }
    top = newNode; 
    printf("Node is Inserted\n\n");
}

int pop()
{
    if (isEmpty)
    {
        return NULL; printf("Stack Underflow");
    }
    
    struct Node *temp = top;

    int data = top->data;
    top = top->next;
    top->size = top->size - 1;
    free(temp);
    return data;   
}

void enQueue(int data)
{
    struct node *ptr = (struct node *) malloc (sizeof(struct node)); 
    ptr -> data = data; 

    if(isFull)
    {
        return NULL; printf("Overflow");
    }
 
    rear->next = ptr;
    rear = ptr;
    rear->next = NULL;
}
 
void deQueue()
{
    if (isEmpty)
    {
        return NULL; printf("Underflow");
    }
    
    int data = rear->data;
    front = front->next;
 
    if (front == NULL)
        rear = NULL;
    free(front);
    return data;
}