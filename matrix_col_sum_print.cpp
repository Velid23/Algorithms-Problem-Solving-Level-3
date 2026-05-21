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

int RowSum(int arr[3][3], short RowNumber, short Cols)
{
	int Sum = 0;
	for (short j = 0; j < RowNumber; j++)
	{
		Sum += arr[j][Cols];
	}
	return Sum;
}

void PrintEachRowSum(int arr[3][3], short Rows, short Cols)
{
	cout << "\nThe following are the sum of each column in the matrix:\n";
	for (short i = 0; i < Rows; i++)
	{
		cout << " column " << i + 1 << " Sum = " << RowSum(arr, Rows, i) << endl;
	}
}

int main() {
	srand((unsigned)time(NULL));

	int myMatrix[3][3];

	fillRandomMatrix3By3(myMatrix, 3, 3);

	cout << "My 3*3 matrix is : \n\n";
	printMatrix3by3(myMatrix, 3, 3);
	PrintEachRowSum(myMatrix, 3, 3);
}
