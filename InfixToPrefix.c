#include<stdio.h>
#include<stdlib.h>
/**Stack Implementation using singly linked list(cuz why not?)*/
struct Node
{
	char Operator;
	struct Node* next;
}
*top = NULL;//top is a global pointer to struct Node type of data
int isEmpty()
{
	return (!top)? 1 : 0;
}
int isFull()
{
	struct Node* testNode = (struct Node*)malloc(sizeof(struct Node));
	if(!testNode)
		return 1;
	else
		free(testNode);
	return 0;
}
int Push(char operator)
{
	if(isFull())return 0;
	struct Node* newP = (struct Node*)malloc(sizeof(struct Node));
	newP->Operator = operator;
	newP->next = top;
	top = newP;
	return 1;
}
int Pop()
{
	if(isEmpty())return 0;
	struct Node* auxPtr = top;
	top = (*top).next;
	free(auxPtr);
	return 1;
}
char Top()
{
	return top->Operator;
}
/**End of Stack Implemenation*/
int Precedence(char c)
{
	switch(c)
	{
		case '^':
			return 3;
		case '*':
		case '/':
			return 2;
		case '+':
		case '-':
			return 1;
	}
	return -1;//Any other operator
}
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
//InfixToPrefix Converter(return address of dynamically allocated space for holding prefix)
char* InfixToPrefix(char* Infix)
{
	int infixCount=0,prefixCount=0;
	for(;*(Infix+infixCount) != '\0';infixCount++)
		if(*(Infix+infixCount) != ')' && *(Infix+infixCount) != '(')
			prefixCount++;
	char* Prefix = (char*)malloc(sizeof(char)*prefixCount);
	for(;infixCount>=0;)
	{
		char c = *(Infix+ (--infixCount));
		if(c == ')')//close paranthesis
			Push(c);
		else if(c == '(')//open paranthesis
		{
			while(Top() != ')')
			{
				*(Prefix+ (--prefixCount)) = Top();
				Pop();
			}
			Pop();//To pop the '(' 
		}
		else if(isOperand(c))
			*(Prefix+ (--prefixCount)) = c;
		else if(isOperator(c))
		{
			while(!isEmpty && Precedence(Top()) >= Precedence(c))
			{
				*(Prefix+ (--prefixCount)) = Top();
				Pop();
			}
			Push(c);
		}
	}
	//Pop the remaining operators from the stack
	while(!isEmpty())
	{
		*(Prefix+ (--prefixCount)) = Top();
		Pop();
	}
	return Prefix;
}
int main()
{
	char* Infix = (char*)malloc(sizeof(char)*30);
	printf("Infix Expression : ");
	scanf("%s",Infix);
	char* Prefix = InfixToPrefix(Infix);
	printf("\nPrefix Expression : %s\n",Prefix);
	return 0;
}
