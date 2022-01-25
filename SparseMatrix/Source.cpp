#include <iostream>
using namespace std;

class MatrixTerm
{
	friend class SparseMatrix;
private:
	int row, col, value;
};
class SparseMatrix
{
public:
	SparseMatrix(int r, int c, int t) {
		rows = r, cols = c, terms = t;
	}
	SparseMatrix Transpose();
	SparseMatrix FastTranspose();
	SparseMatrix Add();
	SparseMatrix Show();
private:
	int rows, cols, terms, capacity;
	MatrixTerm *smArray = new MatrixTerm[8];

};
SparseMatrix SparseMatrix::Transpose()
{
	cout << "一般稀疏矩陣轉置:" << endl;
	SparseMatrix b(cols, rows, terms);
	if (terms > 0) {
		int currentB = 0;
		for (int i = 0; i < cols; i++) {
			for (int j = 0; j < terms; j++) {
				if (smArray[j].col == i) {
					b.smArray[currentB].row = i;
					b.smArray[currentB].col = smArray[j].row;
					b.smArray[currentB].value = smArray[j].value;
					currentB++;
				}
			}
		}
	}
	cout << endl;
	b.Show();
	return b;
}
SparseMatrix SparseMatrix::FastTranspose()
{
	cout << "快速稀疏矩陣轉置:" << endl;
	SparseMatrix b(cols, rows, terms);
	if (terms > 0)
	{
		int *rowSize = new int[cols];
		int *rowStart = new int[cols];
		fill(rowSize, rowSize + cols, 0);
		for (int i = 0; i < terms; i++) rowSize[smArray[i].col] ++;

		rowStart[0] = 0;
		for (int i = 1; i < cols; i++) rowStart[i] = rowSize[i - 1] + rowStart[i - 1];

		for (int i = 0; i < terms; i++) {
			int j = rowStart[smArray[i].col];
			b.smArray[j].row = smArray[i].col;
			b.smArray[j].col = smArray[i].row;
			b.smArray[j].value = smArray[i].value;
			rowStart[smArray[i].col]++;
		}
	}
	cout << endl;
	b.Show();
	return b;
}
SparseMatrix SparseMatrix::Add()
{
	SparseMatrix a = *this;
	a.smArray[0].row = 0;
	a.smArray[0].col = 0;
	a.smArray[0].value = 15;

	a.smArray[1].row = 0;
	a.smArray[1].col = 3;
	a.smArray[1].value = 22;

	a.smArray[2].row = 0;
	a.smArray[2].col = 5;
	a.smArray[2].value = -15;

	a.smArray[3].row = 1;
	a.smArray[3].col = 1;
	a.smArray[3].value = 11;

	a.smArray[4].row = 1;
	a.smArray[4].col = 2;
	a.smArray[4].value = 3;

	a.smArray[5].row = 2;
	a.smArray[5].col = 3;
	a.smArray[5].value = -6;

	a.smArray[6].row = 4;
	a.smArray[6].col = 0;
	a.smArray[6].value = 91;

	a.smArray[7].row = 5;
	a.smArray[7].col = 2;
	a.smArray[7].value = 28;
	return a;
}
SparseMatrix SparseMatrix::Show()
{
	SparseMatrix a = *this;
	int c = 0;
	for (int i = 0; i < a.rows; i++) {
		for (int j = 0; j < a.cols; j++) {
			if (a.smArray[c].row == i && a.smArray[c].col == j)
				cout << "  " << a.smArray[c++].value;
			else cout << "  0";
			if (j == 5) cout << endl;
		}
	}
	cout << endl;
	return a;
}
int main(void)
{
	SparseMatrix a(6, 6, 8);
	a.Add();
	a.Show();
	a.Transpose();
	a.FastTranspose();
	system("pause"); return 0;
}
