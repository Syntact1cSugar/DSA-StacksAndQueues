#include<iostream>
using namespace std;
class Stack
{
	private:
		int top;
		int size;
		int* a;
	public:
		Stack()
		{
			this->top = -1;
			this->size = 0;
			this->a = NULL;
		}
		Stack(int n)
		{
			this->size = n;
			this->top = -1;
			this->a = new int[this->size];
		}
		~Stack()
		{
			delete[] this->a;
		}
		void Push(int);
		void Display(void);
		void Pop(void);
		int Top(void);
};
void Stack :: Push(int n)
{
	if(this->top == (this->size-1))return;
	*(this->a + (++(this->top))) = n;
	return;
}
void Stack :: Pop()
{
	if(this->top == -1)return;
	*(this->a+((this->top)--)) = 0;

}
int Stack :: Top()
{
	if(this->top == -1)return -1;
	return *(this->a+this->top);
}
void Stack :: Display()
{
	if(this->top == -1)return;
	for(int i=this->top;i>=0;i--)
		cout << *(this->a+i) << "\t";
	cout << endl;
}
int main()
{
	Stack S1(4);
	S1.Push(1);
	S1.Push(2);
	S1.Push(3);
	S1.Push(4);
	S1.Display();
	S1.Pop();
	S1.Display();
	S1.Pop();
	S1.Display();
	cout << S1.Top() << endl;
	return 0;
}
