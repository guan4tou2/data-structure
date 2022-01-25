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
class Bag {
public:
	Bag(int bagCapacity = 10);
	~Bag();
	int Size() const;
	bool IsEmpty() const;
	T& Element() const;

	void Push(const T&);
	void Pop();
	void Print();

private:
	T* array;
	int capacity;
	int top;
};
template<class T>
Bag<T>::Bag(int bagCapacity) :capacity(bagCapacity) {
	if (capacity < 1)throw"Capacity must be>0";
	array = new int[capacity];
	top = -1;
}
template<class T>
Bag<T>::~Bag() { delete[]array; }

template<class T>
inline int Bag<T>::Size() const { return top + 1; }
template<class T>
inline bool Bag<T>::IsEmpty() const { return Size == 0; }
template<class T>
inline T& Bag<T>::Element()const {
	if (IsEmpty())throw "Bag is empty";
	return array[0];
}

template<class T>
void Bag<T>::Push(const T&x) {
	if (capacity == top + 1)ChangeSizeID(array, capacity, 2 * capacity);
	capacity *= 2;
	array[++top] = x;
}
template<class T>
void Bag<T>::Pop() {
	if (IsEmpty())throw"Bag is empty,cannot delete";
	int deletePos = top / 2;
	copy(array + deletePos + 1, array + top + 1, array + deletePos);
	top--;
}
template<class T>
void Bag<T>::Print() {
	for (int i = 0; i <= top; i++) {
		cout << array[i] << endl;
	}
}
int main() {
	Bag<int> a;
	a.Push(1);
	a.Push(2);
	a.Push(4);
	a.Push(3);
	a.Push(9);
	a.Push(5);
	a.Push(10);
	a.Push(11);
	a.Push(7);
	a.Push(20);
	a.Print();
	system("pause");
	return 0;
}
