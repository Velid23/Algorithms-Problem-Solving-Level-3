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
			printf("%0*d   ",2,matrix[i][j]);
		}
		cout << endl;
	}

}
int  SumOfMatrix(int matrix[3][3], short rows, short column) {
	int sum = 0;
	for (short i = 0; i < rows; i++) {
		for (short j = 0; j < column; j++) {
			sum += matrix[i][j];
		}
	}
	return sum;
}
int main() {
	srand((unsigned)time(NULL));

	int matrix[3][3];
	fillRandomMatrix(matrix, 3, 3);
	cout << "matrix 1 is :\n\n";
	printArray(matrix, 3, 3);
	cout<<"\nThe sum of matrix is : "<<SumOfMatrix(matrix,3,3)<<endl;


}

 