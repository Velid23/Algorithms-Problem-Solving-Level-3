#include <iostream>
#include<string>
#include<random>
#include <ctime>  
#include<CCTYPE>
#include <cstdlib>
#include<string>
#include<iomanip>
using namespace std;
 
//Here I defined two variables for zeros and non-zero numbers, but 
// I should have used a function to count the given number to find the number of zeros, 
// compare it to the element, and return it as a logical value without using a condition.

void printArray(int matrix[3][3], short rows, short column) {
	for (short i = 0; i < rows; i++) {
		for (short j = 0; j < column; j++) {
			printf("%0*d   ", 1, matrix[i][j]);
		}
		cout << endl;
	}

}
int returnCounterInNumber(int matrix[3][3],int number, short rows, short column) {
	int count=0;
	for (short i = 0; i < rows; i++) {
		for (short j = 0; j < column; j++) {
			if (matrix[i][j] == number) {
				count++;
			}
		}
	}
	return count;

}
bool isSparce(int matrix[3][3], short rows, short column) {
	short matrixSize = rows * column;
 
	return(returnCounterInNumber(matrix, 0, 3, 3) > matrixSize / 2);
			
	
}
int main() {
	srand((unsigned)time(NULL));
	int matrix[3][3] = {
		{5,0,0},
		{5,0,5},
		{0,0,5}
	};

	//fillRandomMatrix(matrix, 3, 3);
	cout << "matrix 1 is :\n\n";
	printArray(matrix, 3, 3);
	cout << " \n\n";

	if (isSparce(matrix,3,3)) {
		cout << "the matrix is sparce";
	}
	else {
		cout << "the matrix is not sparce";
	}

}




