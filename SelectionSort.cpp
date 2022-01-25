#include<iostream>
using namespace std;

template<class T>
void SelectionSort(T*a, const int n) {
	for (int i = 0; i < n;i++)
	{
		int j = i;
		for(int k = i + 1; k < n; k++)
			if (a[k] < a[j])j = k;
		swap(a[i], a[j]);
	}
}
int main() {
	int ia[10] = {5,9,4,20,6,50,11,2,35,10};
	float fa[10] = {1.5,6.2,1.1,8.2,9.6,4.5,2.2,7.8,9.4,10.2};

	SelectionSort(ia, 10);
	for (int i = 0; i < 10; i++)
		cout << ia[i]<<" ";
	cout << endl;
	SelectionSort(fa, 10);
	for (int i = 0; i < 10; i++)
		cout << fa[i] << " ";

	system("pause");
	return 0;
}
