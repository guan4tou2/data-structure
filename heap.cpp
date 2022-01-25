#include<iostream>
using namespace std;

template <class T>
void Adjust(T* a, const int root, const int n)
{
    int largest = root;
    int l = 2 * root + 1;
    int r = 2 * root + 2;

    if (l<n && a[l]<a[largest])
        largest = l;
    if (r<n && a[r]<a[largest])
        largest = r;
    if (largest != root) {
        swap(a[root], a[largest]);
        Adjust(a, largest, n);
    }
}

template <class T>
void HeapSort(T* a, const int n)
{
    for (int i = n / 2-1; i >= 0; i--)
        Adjust(a, i, n);
    for (int i = n - 1; i >= 0; i--)	 
    {
        swap(a[0], a[i]);
        Adjust(a, 0, i);  
    }
}

int main() {
    int arr[10] = { 179,208,306,93,859,984,55,9,271,33 };
    HeapSort(arr, 9);
    for (int i = 0; i < 10; i++)
        cout << arr[i] << " ";

	system("pause"); return 0;
}