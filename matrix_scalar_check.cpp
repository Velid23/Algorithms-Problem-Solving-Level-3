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
int  SumOfMatrix(int matrix[3][3], short rows, short column) {
	int sum = 0;
	for (short i = 0; i < rows; i++) {
		for (short j = 0; j < column; j++) {
			sum += matrix[i][j];
		}
	}
	return sum;
}
bool checkScalarity(int matrix[3][3], short rows, short column) {
	for (short i = 0; i < rows; i++) {
		for (short j = 0; j < column; j++) {
			if ((i == j) && (matrix[i][j] != matrix[rows/2][column/2])) {
				return false;

			}
			else if ((i != j) && (matrix[i][j] != 0))
			{
				return false;
			}
		}

	}
	return true;
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

	if (checkScalarity(matrix, 3, 3)) {
		cout << "yes,the matrix is scalar";
	}
	else {
		cout << "no,the matrix is not scalar";

	}
}

//Here, teacher Abu Hudhud stored the first element in a variable and compared it to the rest of the elements. 
// The difference is that I chose the middle element and did not store it in a variable.

//bool IsScalarMarix(int Matrix1[3][3], short Rows, short Cols)
//{
//	int FirstDiagElemement = Matrix1[0][0];
//	for (short i = 0; i < Rows; i++)
//	{
//		for (short j = 0; j < Cols; j++)
//		{
//			//check for diagonals element
//			if (i == j && Matrix1[i][j] != FirstDiagElemement)
//			{
//				return false;
//			}
//			//check for rest elements
//			else if (i != j && Matrix1[i][j] != 0)
//			{
//				return false;
//			}
//		}
//	}
//	return true;
//}
