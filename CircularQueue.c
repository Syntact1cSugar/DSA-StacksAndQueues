#include<stdio.h>
#include<stdlib.h>

typedef struct 
{
	int* a;
	int front;
	int rear;
	int count;
	int size;
}
QUEUE;	
QUEUE* CreateQueue(int size)
{
	QUEUE* Q = (QUEUE*)malloc(sizeof(QUEUE));
	(*Q).a = (int*)malloc(sizeof(int)*size);
	(*Q).size = size;
	(*Q).front = (*Q).rear = -1;
	(*Q).count = 0;
	return Q;
}
QUEUE* DestroyQueue(QUEUE* Q)
{
	if(!Q)
	{
		free(Q->a);
		free(Q);
		Q = NULL;
	}
	return Q;
}
int isEmpty(QUEUE* Q)
{
	return ((*Q).front == -1 && (*Q).rear == -1)? 1 : 0;
}
int isFull(QUEUE* Q)
{
	return (((Q->rear+1)%(Q->size)) == (Q->front))? 1 : 0;
}
int enQueue(QUEUE* Q,int dataIn)
{
	if(isFull(Q))return 0;	
	if(isEmpty(Q))
		Q->front = (Q->front+1)%(Q->size);
	Q->rear = (Q->rear+1)%Q->size;
	*(Q->a+(Q->rear)) = dataIn;
	(Q->count)++;
	return 1;
}
int deQueue(QUEUE* Q)
{
	if(isEmpty(Q))return 0;
	*(Q->a+(Q->front)) = 0;
	if(Q->front == Q->rear)
		Q->front = Q->rear = -1;
	else Q->front = (Q->front+1)%(Q->size);
	(Q->count)--;
	return 1;
}
int Front(QUEUE* Q)
{
	return *(Q->a+(Q->front));
}
int Display(QUEUE* Q)
{
	if(isEmpty(Q))return 0;
	for(int i=Q->front;i!=Q->rear;i=(i+1)%(Q->size))
		printf("%d\t",*(Q->a+(i)));
	printf("%d\n",*(Q->a+(Q->rear)));	
	return 1;
}
int main()
{
	return 0;
}
