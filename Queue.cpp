#include<iostream>
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
class Queue {
public:
	Queue(int QueueCapacity = 10);
	bool IsEmpty()const;
	T& Front()const;
	T& Rear()const;
	void Push(const T& item);
	void Pop();
	void print();
private:
	T* queue;
	int front,rear;
	int capacity;

};
template<class T>
Queue<T>::Queue(int QueueCapacity) :capacity(QueueCapacity) {
	if (capacity < 1)throw"Queue capacity must be>0";
	queue = new T[capacity];
	front = rear = 0;
}

template<class T>
inline bool Queue<T>::IsEmpty() const { return front==rear; }

template<class T>
inline T& Queue<T>::Front()const {
	if (IsEmpty()) throw "Queue is empty";
	return queue[(front+1)%capacity];
}
template<class T>
inline T& Queue<T>::Rear()const {
	if (IsEmpty()) throw "Queue is empty";
	return queue[rear];
}
template<class T>
void Queue<T>::Push(const T& x) {
	if ((rear+1)%capacity==front) {
		ChangeSizeID(queue, capacity, 2 * capacity);
		capacity *= 2;
	}
	rear = (rear + 1) % capacity;
	queue[rear] = x;
	if (rear > capacity)rear = front;
}
template<class T>
void Queue<T>::Pop() {
	if (IsEmpty())throw "Queue is empty.cannot delete";
	front = (front + 1) % capacity;
	queue[front].~T();
}
template<class T>
void Queue<T>::print() {
	//cout << front << " " << rear<<"--";
	for (int x = front, y = rear; x != y; x++) {
		cout << queue[x]<<" ";
	}
}
int main() {
	Queue<int> a;
	a.Push(1);
	a.Push(2);
	a.Push(3);
	a.Push(4);
	a.Push(5);
	a.Push(6);
	a.Push(7);
	a.Push(8);
	a.Push(9);

	a.print();
	system("pause"); return 0;
}
