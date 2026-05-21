#include <iostream>
#include<string>
#include<random>
#include <ctime>  
#include<CCTYPE>
#include <cstdlib>
#include<string>
#include<iomanip>
using namespace std;
//I combined printing and filling in one place and forgot to delete the output line.
// In short, I did it wrong and messed up, so I edited the code directly.


void printArray(int array[],int length) {
	for (int i = 0; i < length;i++) {
		cout << "the sum of row "<<i+1<<" is " << array[i]<<endl;
	}

}
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

int  sumOfRow(int matrix[3][3], short row, short column) {
	int sum = 0;
	for (int i = 0; i < column;i++) {
		sum = sum + matrix[row][i];
	}
	 return sum;
}

void Sum(int sumArray[3], int matrix[3][3], short row, short column) {
	int arrayOfSums[3];
	for (int j = 0; j < row; j++) {
		sumArray[j] = sumOfRow(matrix,j,column);
	}
}

int main() {
	srand((unsigned)time(NULL));

	int myMatrix[3][3];
	int sumArrays[3];
	fillRandomMatrix3By3(myMatrix, 3, 3);

	cout << "My 3*3 matrix is : \n\n";
	printMatrix3by3(myMatrix, 3, 3);
	Sum(sumArrays,myMatrix, 3, 3);
	printArray(sumArrays, 3);

}	
  