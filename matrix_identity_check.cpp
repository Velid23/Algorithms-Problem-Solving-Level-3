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
bool checkIdentity(int matrix[3][3],short rows, short column) {
	for (short i = 0; i < rows; i++) {
		for (short j = 0; j < column; j++) {
			if (i == j) {
				if (matrix[i][j] != 1) {
					return false;
				}
			}
			else {
				if (matrix[i][j] != 0) {
					return false;
				}
			}
 
		}
	}

}

int main() {
	srand((unsigned)time(NULL));

	int matrix[3][3] = {
		{1,0,0},
		{0,1,0},
		{0,0,1}
	};
	//fillRandomMatrix(matrix, 3, 3);
	cout << "matrix 1 is :\n\n";
	printArray(matrix, 3, 3);
	cout << " \n\n";
 
	if (checkIdentity(matrix, 3, 3)) {
		cout << "yes,the matrix is identity";
	}
	else {
		cout << "no,the matrix is not identity";

	}
}

//Notes:

//Try to avoid running nested if as much as possible.
// instead doing this ,you could have done else if This is the correct function.

//bool checkIdentity(int matrix[3][3], short rows, short column) {
//	for (short i = 0; i < rows; i++) {
//		for (short j = 0; j < column; j++) {
//			if ((i == j) && (matrix[i][j] != 1)) {
//				return false;
//
//			}
//			else if ((i != j) && (matrix[i][j] != 0))
//			{
//				return false;
//			}
//		}
//
//	}
//	return true;
//}
