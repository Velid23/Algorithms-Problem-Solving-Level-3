#include <iostream>
#include<string>
#include<random>
#include <ctime>  
#include<CCTYPE>
#include <cstdlib>
#include<string>
#include<iomanip>
using namespace std;

int returnRandomNumberInRange(int from, int to) {
	int randomNumber;
	randomNumber = rand() % (to - from + 1) + from;
	return randomNumber;
}
void fillRandomMatrix(int matrix[3][3], short rows, short column) {
	for (short i = 0; i < rows; i++) {
		for (short j = 0; j < column; j++) {
			matrix[i][j] = returnRandomNumberInRange(1, 10);
		}
	}
}

void printArray(int matrix[3][3], short rows, short column) {
	for (short i = 0; i < rows; i++) {
		for (short j = 0; j < column; j++) {
			printf("%0*d   ", 1, matrix[i][j]);
		}
		cout << endl;
	}

}
 
int returnCountOfNumber(int matrix[3][3],int number, short rows, short column) {
	int count = 0;
	for (short i = 0; i < rows; i++) {
		for (short j = 0; j < column; j++) {
			if (matrix[i][j]==number) {
				count++;
			}
 
		}

	}
	return count;
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
	cout << "enter the number to count in matrix";
	cin >> searchedNumber;
	cout << "number " << searchedNumber << " count in matrix is " << returnCountOfNumber(matrix, searchedNumber, 3, 3);


}