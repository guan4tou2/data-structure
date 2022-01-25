#include<iostream>
using namespace std;

void  StoogeSort(int a[], int left, int right) {
	if (a[right] < a[left])
		swap(a[left], a[right]);
	if ((right - left + 1) >= 3){
		int t = (right - left + 1) / 3;
		StoogeSort(a, left, right - t);
		StoogeSort(a, left + t, right);
		StoogeSort(a, left, right - t);
	}
}

int main() {
	int arr[10] = { 0,55,2,96,41,3,20,78,15,42 };
	StoogeSort(arr, 0, 9);
	for (int i = 0; i < 10; i++) {
		cout << arr[i] << " ";
	}

	system("pause"); return 0;
}