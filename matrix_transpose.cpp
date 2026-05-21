#include <iostream>
#include<string>
#include<random>
#include <ctime>  
#include<CCTYPE>
#include <cstdlib>
#include<string>
#include<iomanip>
using namespace std;

void printArray(int matrix[3][3], short rows, short columns) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			cout << setw(3) << matrix[i][j] << " ";
		}
		cout << endl;
	}
}
void fillMatrixWithOrderdNumbers(int matrix[3][3], short rows, short columns) {
	short count = 1;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			matrix[i][j] = count;
			count++;
		}
	}
}

void fillTransposeMatrix(int matrix[3][3],int transposedMatrix[3][3], short rows, short columns) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			transposedMatrix[i][j] = matrix[j][i];
		}
	}
}

int main() {
	int matrix[3][3],transposematrix[3][3];

	fillMatrixWithOrderdNumbers(matrix, 3, 3);
	cout << "original array is :" << endl;
	printArray(matrix, 3, 3);
	cout << "\ntransposed array is :"<<endl;
	fillTransposeMatrix(matrix, transposematrix,3,3);
	printArray(transposematrix,3,3);
}