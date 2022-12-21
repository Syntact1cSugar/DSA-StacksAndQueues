#include<stdio.h>
#include<stdlib.h>
/*Stack Implementation(as singly linked list)*/
struct StackNode
{
	double data;
	struct StackNode* next;
}*top = NULL;
int isEmpty()
{
	return (top == NULL)? 1 : 0;
}
int isFull()
{
	struct StackNode* testP = (struct StackNode*)malloc(sizeof(struct StackNode));
	if(!testP)return 1;
	free(testP);
	return 0;
}
int Push(double dataIn)
{
	if(isFull())return 0;
	struct StackNode* newP = (struct StackNode*)malloc(sizeof(struct StackNode));
	newP->data = dataIn;
	newP->next = top;
	top = newP;
	return 1;
}
int Pop()
{
	if(isEmpty())return 0;
	struct StackNode* deleteP = top;
	top = (*top).next;
	free(deleteP);
	return 1;
}
double Top()
{
	if(isEmpty())return 0;
	return (*top).data;
}
/*End of stack Implementation*/
int isOperator(char c)
{
	if(c == '/' || c == '*' || c == '+' || c == '-')
		return 1;
	return 0;
}
int isNumericDigit(char c)
{
	return (c >= '0' && c <= '9')? 1 : 0;
}
double performOperation(int operand1,int operand2,char operator)
{
	switch(operator)
	{
		case '*':
			return operand1 * operand2;
		case '/':
			return operand1 / operand2;
		case '+':
			return operand1 + operand2;
		case '-':
			return operand1 - operand2;
	}
	return 0;
}
double evaluate(char* postfix)
{
	for(int i=0;*(postfix+i)!='\0';i++)
	{
		if(*(postfix+i) == ' ')continue;
		else if(isOperator(*(postfix+i)))
		{
			double operand2 = Top();
			Pop();
			double operand1 = Top();
			Pop();
			Push((double)performOperation(operand1,operand2,*(postfix+i)));
		}
		else if(isNumericDigit(*(postfix+i)))
		{
			int operand = 0;
			while(isNumericDigit(*(postfix+i)) && (*postfix+i)!='\0')
			{
				operand = operand*10 + *(postfix+i) - '0';
				i++;
			}
			i--;
			Push((double)operand);
		}
	}
	double result = Top();
	Pop();
	return result;
}
int main()
{
	char* postfix = (char*)malloc(sizeof(char)*20);
	printf("Postfix Expression : ");
	scanf("%[^\n]",postfix);
	double result = evaluate(postfix);
	printf("Result : %5.2f\n",result);
	return 0;
}
