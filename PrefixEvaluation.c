#include<stdio.h>
#include<stdlib.h>
/**Stack Implementation*/
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
	top = top->next;
	free(deleteP);
	return 1;
}
double Top()
{
	if(isEmpty())return 0;
	return (*top).data;
}
/**End*/
int isOperator(char c)
{
	if(c == '*' || c == '/' || c == '+' || c == '-')
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
double evaluate(char* prefix)
{
	if(!prefix)return 0;
	int i;
	for(i=0;*(prefix+i)!='\0';i++)
	{}
	for(;i>=0;i--)
	{
		if(*(prefix+i) == ' ')continue;
		else if(isOperator(*(prefix+i)))
		{
			int operand1 = Top();
		        Pop();
			int operand2 = Top();
			Pop();
			Push((double)performOperation(operand1,operand2,*(prefix+i)));
		}
		else if(isNumericDigit(*(prefix+i)))
		{
			int operand = 0;
			int exponent = 1;
			while(i >= 0 && isNumericDigit(*(prefix+i)))
			{
				operand = operand + exponent * (*(prefix+i) - '0');
				exponent *= 10;
				i--;
			}
			i++;
			Push((double)operand);
		}
	}
	return Top();
}
int main()
{
	char *prefix = (char*)malloc(sizeof(char)*30);
	printf("Prefix Expression : ");
	scanf("%[^\n]",prefix);
	double result = evaluate(prefix);
	printf("Result : %6.3f\n",result);
	return 0;
}
