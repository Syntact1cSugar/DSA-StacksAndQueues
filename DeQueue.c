#include<stdio.h>
#include<stdlib.h>

int front = -1,rear = -1;
int n;
int* DeQueue = NULL;
int isEmpty()
{
	return (front == -1 && rear == -1)? 1 : 0;
}
int isFull()
{
	return (((rear+1)%n == front) || ((n+front-1)%n == rear))? 1 : 0;
}
void displayQueue()
{
	if(isEmpty())return;
	int i;
	for(i=front;i!=rear;i=(i+1)%n)
		printf("%d\t",*(DeQueue+i));
	printf("%d\n",*(DeQueue+rear));
	return;
}
//Insert Operation
void InsertRear(int data)
{
	if(isFull())return;
	rear = (rear+1)%n;
	*(DeQueue+rear) = data;
	if(front == -1)
		front = 0;
}
void InsertFront(int data)
{
	if(isFull())return;
	if(front == -1)
		front = n-1;
	else 
		front = (n+front-1)%n;
	*(DeQueue+front) = data;
	if(rear == -1)
		rear = n-1;
	return;
}

//Delete Operation
void DeleteRear()
{
	if(isEmpty())return;
	if(front == rear)
	{
		front = rear = -1;
		return;
	}
	rear = (n+rear-1)%n;
	return;
}
void DeleteFront()
{
	if(isEmpty())return;
	if(front == rear) 
	{
		front = rear = -1;
		return;
	}
	front = (front+1)%n;
	return;
}
int main()
{
	return 0;
}
