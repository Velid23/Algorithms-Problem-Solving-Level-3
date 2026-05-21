#include <iostream>
#include<string>
#include<random>
#include <ctime>  
#include<CCTYPE>
#include <cstdlib>
#include<string>
#include<iomanip>
using namespace std;

int returnRandomNumberInRange(int from,int to) {
	int randomNumber;
	randomNumber = rand() % (to - from + 1) + from;
	return randomNumber;
}
void fillRandomMatrix(int matrix[3][3], short rows, short column) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < column; j++) {
			matrix[i][j] = returnRandomNumberInRange(1, 10);
		}
	}
}

void printArray(int matrix[3][3], short rows, short column) {
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < column; j++) {
				cout<<setw(3)<<matrix[i][j]<<"  ";
			}
			cout << endl;
		}
	
}

void multiply2arrays(int matrix[3][3], int matrix2[3][3], int multymatrix[3][3], short rows, short column) {

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < column; j++) {
			multymatrix[i][j] = matrix[i][j] * matrix2[i][j];
		}
	}


}

int main() {
	srand((unsigned) time (NULL));

	int matrix[3][3],matrix2[3][3],multipledMatrix[3][3];
	fillRandomMatrix(matrix, 3, 3);
	cout << "matrix 1 is :\n\n";
	printArray(matrix, 3, 3);
	fillRandomMatrix(matrix2, 3, 3);
	cout << "\nmatrix 2 is :\n\n";
	printArray(matrix2, 3, 3);
	multiply2arrays(matrix, matrix2, multipledMatrix, 3, 3);
	cout << "\nmultiplied matrix :\n\n";
	printArray(multipledMatrix, 3, 3);



}