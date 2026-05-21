#include <iostream>
#include<string>
#include<random>
#include <ctime>  
#include<CCTYPE>
#include <cstdlib>
#include<string>
#include<iomanip>
using namespace std;



void printArray(int matrix[3][3], short rows, short column) {
	for (short i = 0; i < rows; i++) {
		for (short j = 0; j < column; j++) {
			printf("%0*d   ", 1, matrix[i][j]);
		}
		cout << endl;
	}

}

int ReturnMaxElement(int matrix[3][3], short rows, short column) {
	int maxNumber = matrix[0][0];
	for (short i = 0; i < rows; i++) {
		for (short j = 0; j < column; j++) {
			if (matrix[i][j] > maxNumber) {
				maxNumber = matrix[i][j];
			}
		}
	}
	return maxNumber;
}
int ReturnMinElement(int matrix[3][3], short rows, short column) {
	int minNumber = matrix[0][0];
	for (short i = 0; i < rows; i++) {
		for (short j = 0; j < column; j++) {
			if (matrix[i][j] < minNumber) {
				minNumber = matrix[i][j];
			}
		}
	}
	return minNumber;
}

int main() {
	srand((unsigned)time(NULL));
	int matrix[3][3] = {
		{4,6,1},
		{0,5,3},
		{9,0,3}
	};
 

	//fillRandomMatrix(matrix, 3, 3);
	cout << "matrix  is :\n\n";
	printArray(matrix, 3, 3);
	cout << " \n\n";
	cout << "the max element is :" << ReturnMaxElement(matrix, 3, 3);
	cout << " \n\n";
	cout << "the min element is :" << ReturnMinElement(matrix, 3, 3);

 

}