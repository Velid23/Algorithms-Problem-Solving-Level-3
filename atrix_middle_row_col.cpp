#include <iostream>
#include<string>
#include<random>
#include <ctime>  
#include<CCTYPE>
#include <cstdlib>
#include<string>
#include<iomanip>
using namespace std;

//Try to make the program as comprehensive and general as possible.For example, 
//you made a mistake here by manually entering the middle row and column when you should have known that 
//they are a 2 - column division and not entered them as a number.


int returnRandomNumberInRange(int from, int to) {
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
			cout << setw(3) << matrix[i][j] << "  ";
		}
		cout << endl;
	}

}
void PrintMidleRow(int matrix[3][3], short rows, short column) {
	short middlerow = rows / 2;
	for (int i = 0; i < column; i++) {
		cout << matrix[middlerow][i]<<" ";
	}
}
void PrintMidleColumn(int matrix[3][3], short rows, short column) {
	short middlecolumn = column / 2;

	for (int i = 0; i < column; i++) {
		cout << matrix[i][middlecolumn] << " ";
	}
}
int main() {
	srand((unsigned)time(NULL));

	int matrix[3][3];
	fillRandomMatrix(matrix, 3, 3);
	cout << "matrix 1 is :\n\n";
	printArray(matrix, 3, 3);
	cout << "\nthe Middle row is :"<<endl;
	PrintMidleRow(matrix,3,3);
	cout << "\nthe Middle column is :" << endl;
	PrintMidleColumn(matrix, 3, 3);


}
