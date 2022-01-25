#include<iostream>
using namespace std;
class MatrixTerm {
	friend class SparseMatrix;
private:
	int row, col, value;
};
class SparseMatrix {
private:
	int rows, cols, terms;
	MatrixTerm* smArray = new MatrixTerm[terms];
	int x = 0;
public:
	SparseMatrix(int r, int c, int t) {
		rows = r; cols = c; terms = t;
	};
	~SparseMatrix() {
		delete[] smArray;
	};
	void Transpose();
	void FastTranspose();
	void add(int r, int c, int t);
	void show();

};
void SparseMatrix::Transpose() {
	SparseMatrix b(cols, rows, terms);
	if (terms > 0) {
		int currentB = 0;
		for(int c=0;c<cols;c++)
			for(int i=0;i<terms;i++)
				if (this->smArray[i].col == c) {
					b.smArray[currentB].row = c;
					b.smArray[currentB].col = this->smArray[i].row;
					b.smArray[currentB++].value = this->smArray[i].value;
				}
	}
	b.show();
	//return b;
}
void SparseMatrix::FastTranspose() {
	SparseMatrix b(cols, rows, terms);
	if (terms > 0) {
		int* rowSize = new int[cols];
		int* rowStrat = new int[cols];
		fill(rowSize, rowSize + cols, 0);
		for (int i = 0; i < terms; i++)rowSize[this->smArray[i].col]++;
		rowStrat[0] = 0;
		for (int i = 1; i < cols; i++)rowStrat[i - 1] += rowSize[i - 1];
		for (int i = 0; i < terms; i++) {
			int j = rowStrat[this->smArray[i].col];
			b.smArray[i].row = this->smArray[i].col;
			b.smArray[i].col = this->smArray[i].row;
			b.smArray[i].value = this->smArray[i].value;
			rowStrat[this->smArray[i].col]++;
		}
		delete[] rowSize; delete[] rowStrat;
	}
	b.show();
	//return b;
}

void SparseMatrix::add(int r, int c, int t) {
	this->smArray[x].row = r;
	this->smArray[x].col = c;
	this->smArray[x].value = t;
	x++;
}

void SparseMatrix::show() {
	for (int i = 0; i < terms; i++) {
		cout <<  this->smArray[i].row << " " << this->smArray[i].col << " " << this->smArray[i].value << endl;
	}

}


int main() {
	SparseMatrix a(6, 6, 6);
	a.add(0, 1, 5);
	a.add(1, 0, 10);
	a.add(1, 5, 20);
	a.add(3, 0, 2);
	a.add(4, 3, 11);
	a.add(5, 4, 9);
	a.show();
	cout << "Transpose--------------------------" << endl;
	a.Transpose();



	SparseMatrix b(6, 6, 6);
	b.add(0, 1, 5);
	b.add(1, 0, 10);
	b.add(2, 5, 20);
	b.add(3, 0, 2);
	b.add(4, 3, 11);
	b.add(5, 4, 9);
	cout << "--------------------------" << endl;
	b.show();
	cout << "FastTranspose--------------------------" << endl;
	b.FastTranspose();




	system("pause");
	return 0;
}
