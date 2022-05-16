#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

const int MAXSIZE = 10;
int stack[10];
int top = -1;
const int n;
int T1 = -1;
int T2 = 9;
int v[10 - 1];
int queue[10 - 1];
unsigned int size = 0;
unsigned int rear ;
unsigned int front = 0;

int isempty()
{

   if (top == -1)
      return 1;
   else
      return 0;
}

int qisempty()
{

   if (rear == -1)
      return 1;
   else
      return 0;
}

int isfull()
{

   if (top == MAXSIZE)
      return 1;
   else
      return 0;
}

int qisfull()
{

   if (rear == MAXSIZE)
      return 1;
   else
      return 0;
}

int peek()
{
   return stack[top];
}

int pop()
{
   int data;

   if (isempty())
   {
      return -1;
   }
   else
   {
      data = stack[top];
      stack[top] = 0;
      top = top - 1;
      return data;
   }
}

int push(int data)
{

   if (isfull())
   {
      return -1;
   }
   else
   {
      top = top + 1;
      stack[top] = data;
   }
}

void push1(int x)
{
   if (T1 == T2 - 1)
      printf("STack 1 is full");
   else
   {
      T1++;
      v[T1] = x;
   }
}

void push2(int x)
{
   if (T2 == T1 + 1)
      printf("stack 2 is full");
   else
   {
      T2--;
      v[T2] = x;
   }
}

void pop1()
{
   if (T1 == -1)
      printf("void stack");
   else
   {
      v[T2] = 0;
      T2++;
   }
}

void pop2()
{
   if (T2 = n)
      printf("void stack");
   else
   {
      T2--;
      v[T2] = 0;
   }
}

void inqueue(int data)
{
   // if (qisfull)
   //    return NULL;
   queue[front] = data;
   front = front + 1;
}

int dequeue()
{
   int data;

   if (qisempty())
   {
      return -1;
   }
   while(queue[rear]!=0){
      rear = rear + 1;
   }
   data = queue[rear];
   rear = rear - 1;
   queue[rear]=0;
   return data;
   
}



int main()
{
   // push(6);
   // push(26);
   // push(16);
   // for (int i = 0; i < 9; i++)
   //    printf("%d ",stack[i]);
   // printf("\n");
   // pop();
   // for (int i = 0; i < 9; i++)
   //    printf("%d ",stack[i]);
   // push1(6);
   // push2(23);
   // push1(16);
   // push2(13);
   // push1(25);
   // push1(36);
   // push2(176);
   // push2(263);
   // pop1();
   // pop2();
   // printf("\n");
   //  for (int i = 0; i < 9; i++)
   //    printf("%d ",v[i]);

   inqueue(9);
   inqueue(19);
   inqueue(29);
   inqueue(39);
   inqueue(49);
   inqueue(59);
   inqueue(69);
   inqueue(79);
   for (int i = 0; i < 9; i++)
      printf("%d ", queue[i]);
      printf("\n");
   dequeue();
   for (int i = 0; i < 9; i++)
      printf("%d ", queue[i]);
}
