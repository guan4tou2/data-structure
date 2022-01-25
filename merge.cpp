#include<iostream>
using namespace std;

void Merge(int *A,int left, int mid, int right) {
	int B[10] = {0};
	for (int x=left,i = left, j = mid+1; x <= right;x++) {
		if (i > mid &&j<=right) {
			B[x] = A[j++];
		}
		else if (i <= mid && j > right) {
			B[x] = A[i++];
		}
		else if (A[i] < A[j]) {
			B[x] = A[i++];
			
		}
		else {
			B[x] = A[j++];
			
		}
	}
	//A = B;
	for (int i = left; i <= right; i++) {
		A[i] = B[i];
	}
}

void Merge_Sort(int *A,int left, int right) {
	if (left < right) {
		int mid = (left + right) / 2;
		Merge_Sort(A,left, mid);
		Merge_Sort(A,mid + 1, right);
		Merge(A,left, mid, right);
	}
}

int main() {
	int arr[10] = { 22,5 , 79, 1, 63, 13, 56, 17, 43, 20};
	Merge_Sort(arr, 0, 9);
	for (int i = 0; i < 10; i++) {
		cout << arr[i] << " ";
	}
	

	system("pause"); return 0;
}