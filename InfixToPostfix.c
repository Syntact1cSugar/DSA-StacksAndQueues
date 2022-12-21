#include<stdio.h>
#include<stdlib.h>
/**Implementation of stack using single linked list*/
struct StackNode
{
	char operator;
	struct StackNode *next;
}
*top = NULL;
int isEmpty()
{
	return (!top)? 1 : 0;
}
int isFull()
{
	struct StackNode* newP = malloc(sizeof(struct StackNode));
	if(!newP)
		return 1;
	else
		free(newP);
	return 0;
}
int Push(char operator)
{
	if(isFull())return 0;
	struct StackNode* newP = malloc(sizeof(struct StackNode));
	(*newP).operator = operator;
	(*newP).next = top;
	top = newP;
	return 1;
}
int Pop()
{
	if(isEmpty())return 0;
	struct StackNode* deletePtr = top;
	top = (*top).next;
	free(deletePtr);
	return 1;
}
char Top()
{
	if(isEmpty())return '\0';
	return (*top).operator;
}
/**End of stack Implementation**/

int isOperand(char c)
{
	return (c >= 'A' && c <= 'Z')? 1 : (c >= 'a' && c <= 'z')? 1 : 0;
}
int isOperator(char c)
{
	if(c == '^' || c == '/' || c == '*' || c == '+' || c == '-')
		return 1;
	return 0;
}
int Precedence(char operator)
{
	if(operator == '^')
		return 3;
	else if(operator == '/' || operator == '*')
		return 2;
	else if(operator == '+' || operator == '-')
		return 1;
	return -1;
}
//Infix To Postfix Converter
char* InfixToPostfix(char* Infix)
{
	int InfixCount,PostfixCount;
	for(InfixCount = 0,PostfixCount = 0;*(Infix+InfixCount) != '\0';InfixCount++)
	{
		if(*(Infix+InfixCount) != ')' && *(Infix+InfixCount) != '(')
			PostfixCount++;
	}
	char* Postfix = (char*)malloc(sizeof(char)*PostfixCount);
	PostfixCount = 0;
	for(int i = 0;i<InfixCount;i++)
	{
		char c = *(Infix+i);
		if(c == '(') Push(c);
		else if(c == ')')
		{
			while(Top() != '(')
			{
				*(Postfix + (PostfixCount++)) = Top();
				Pop();
			}
			Pop();
		}
		else if(isOperator(c))
		{
			while(!isEmpty() && Precedence(Top()) >= Precedence(c))	
			{
				*(Postfix + (PostfixCount++)) = Top();
				Pop();
			}
			Push(c);
		}
		else if(isOperand(c))
			*(Postfix + (PostfixCount++)) = c;
	}
	//Pop the remaining opeartors from stack
	while(!isEmpty())
	{
		*(Postfix + (PostfixCount++)) = Top();
		Pop();
	}
	return Postfix;
}
int main()
{
	char* Infix = (char*)malloc(sizeof(char)*20);
	printf("Infix Expression : ");
	scanf("%s",Infix);
	char* Postfix = InfixToPostfix(Infix);
	printf("\nPostfix Expression : %s\n",Postfix);
	return 0;
}
