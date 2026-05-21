#include <iostream>
#include<string>
#include<random>
#include <ctime>  
#include<CCTYPE>
#include <cstdlib>
#include<string>
#include<iomanip>
using namespace std;

int genrateRandomNumberInRange(int from, int to) {
	int randomNumber;
	randomNumber = rand() % (to - from + 1) + from;
	return randomNumber;
}
void fillRandomMatrix3By3(int matrix[3][3], short rows, short column) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < column; j++) {
			matrix[i][j] = genrateRandomNumberInRange(1, 100);
		}

	}
}
void printMatrix3by3(int matrix[3][3], short rows, short column) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < column; j++) {
			cout << setw(3) << matrix[i][j] << " ";
		}
		cout << endl;
	}
}

void printSumOfRowsOfMatrix(int matrix[3][3],short rows,short column) {

	for (int i = 0; i < rows; i++) {
		int sum = 0;
		for (int j = 0; j < column; j++) {
			sum += matrix[i][j];
		}
		cout << "sum of row " << i+1 << " is " << sum << endl;
	}


}

int main() {
	srand((unsigned)time(NULL));

	int myMatrix[3][3];

	fillRandomMatrix3By3(myMatrix,3,3);

	cout << "My 3*3 matrix is : \n\n";
	printMatrix3by3(myMatrix,3,3);
	printSumOfRowsOfMatrix(myMatrix, 3, 3);
}

//abou hadhoud teacher code

//The difference is that I didn't create two separate functions, 
// one running through the lines and the other returning the result
// of the lines; I created them all in one function.


//int genrateRandomNumberInRange(int from, int to) {
//	int randomNumber;
//	randomNumber = rand() % (to - from + 1) + from;
//	return randomNumber;
//}
//void fillRandomMatrix3By3(int matrix[3][3], short rows, short column) {
//	for (int i = 0; i < rows; i++) {
//		for (int j = 0; j < column; j++) {
//			matrix[i][j] = genrateRandomNumberInRange(1, 100);
//		}
//
//	}
//}
//void printMatrix3by3(int matrix[3][3], short rows, short column) {
//	for (int i = 0; i < rows; i++) {
//		for (int j = 0; j < column; j++) {
//			cout << setw(3) << matrix[i][j] << " ";
//		}
//		cout << endl;
//	}
//}
//
//int RowSum(int arr[3][3], short RowNumber, short Cols)
//{
//	int Sum = 0;
//	for (short j = 0; j <= Cols - 1; j++)
//	{
//		Sum += arr[RowNumber][j];
//	}
//	return Sum;
//}
//
//void PrintEachRowSum(int arr[3][3], short Rows, short Cols)
//{
//	cout << "\nThe following are the sum of each row in the matrix:\n";
//	for (short i = 0; i < Rows; i++)
//	{
//		cout << " Row " << i + 1 << " Sum = " << RowSum(arr, i, Cols) << endl;
//	}
//}
//
//int main() {
//	srand((unsigned)time(NULL));
//
//	int myMatrix[3][3];
//
//	fillRandomMatrix3By3(myMatrix, 3, 3);
//
//	cout << "My 3*3 matrix is : \n\n";
//	printMatrix3by3(myMatrix, 3, 3);
//	PrintEachRowSum(myMatrix, 3, 3);
//}
