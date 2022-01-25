#include<iostream>
#include<algorithm>
using namespace std;
template <class T>
void ChangeSizeID(T*& a, const int oldSize, const int newSize) {
	if (newSize < 0)throw"new lwngth must be>=0";
	T* temp = new T[newSize];
	int number = min(oldSize, newSize);
	copy(a, a + number, temp);
	delete[]a;
	a = temp;
}
template<class T>
class Stack {
public:
	Stack(int stackCapacity = 10);
	bool IsEmpty()const;
	T& Top()const;
	void Push(const T& item);
	void Pop();
	T& Print();
private:
	T* stack;
	int top;
	int capacity;
};
template<class T>
Stack<T>::Stack(int stackCapacity) :capacity(stackCapacity) {
	if (capacity < 1)throw"Stack capacity must be>0";
	stack = new T[capacity];
	top = -1;
}
template<class T>
inline bool Stack<T>::IsEmpty() const { return top == -1; }

template<class T>
inline T& Stack<T>::Top()const {
	if (IsEmpty()) throw "stack is empty";
	return stack[top];
}
template<class T>
void Stack<T>::Push(const T& x) {
	if (top == capacity - 1) {
		ChangeSizeID(stack, capacity, 2 * capacity);
		capacity *= 2;
	}
	stack[++top] = x;
}
template<class T>
void Stack<T>::Pop() {
	if (IsEmpty())throw "stack is empty.cannot delete";
	stack[top--].~T();
}
template<class T>
T& Stack<T>::Print() {
	return stack[top];
}
int isp(char c) {
	switch (c)
	{
	case '+':
	case '-':
		return 1;
	case '*':
	case '/':
		return 2;
	case '(':
		return 3;
	case ')':
		return 4;
	default:
		return 0;
	}
}
int main() 
{
	char s[100];
	Stack<char> a;
	cout << "輸入算式:";
	cin >> s;
	int len = strlen(s);
	for (int i = 0; i < len; i++) 
	{
		if (isp(s[i])>0)
		{
			if (isp(s[i])<= isp(a.Print()))
			{
				cout << a.Print();
				a.Pop();
				a.Push(s[i]);
			}
			else if(isp(s[i]) > isp(a.Print()))
				a.Push(s[i]);
		}else cout << s[i];
		while(i == len - 1&&!a.IsEmpty()) {
			cout << a.Print();
			a.Pop();	
		}
	}
	system("pause");
	return 0;
}
