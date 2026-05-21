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

int isExists(int matrix[3][3], int number, short rows, short column) {
	int count = 0;
	for (short i = 0; i < rows; i++) {
		for (short j = 0; j < column; j++) {
			if (matrix[i][j] == number) {
				return true;
			}
		}
	}
	return false;
 }

int main() {
	srand((unsigned)time(NULL));
	int matrix[3][3] = {
		{5,0,0},
		{0,5,0},
		{0,0,5}
	};

	//fillRandomMatrix(matrix, 3, 3);
	cout << "matrix 1 is :\n\n";
	printArray(matrix, 3, 3);
	cout << " \n\n";
	int searchedNumber;
	cout << "enter the number to search:";
	cin >> searchedNumber;
	if(isExists(matrix, searchedNumber, 3, 3))
	cout << "number " << searchedNumber << " exists in matrix ";
	else {
		cout << "number " << searchedNumber << " does not exists in matrix ";

	}


}