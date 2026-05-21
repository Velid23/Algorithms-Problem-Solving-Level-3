#include <iostream>
#include<string>
#include<random>
#include <ctime>  
#include<CCTYPE>
#include <cstdlib>
#include<string>
#include<iomanip>
using namespace std;
 
int genrateRandomNumberInRange(int from,int to) {
	int randomNumber;
	randomNumber = rand() % (to - from + 1) + from;
	return randomNumber;
}
void fillRandomMatrix3By3(int matrix[3][3]) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			matrix[i][j] = genrateRandomNumberInRange(1, 100);
		}

	}
}
void printMatrix3by3(int matrix[3][3] ) {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				cout << setw(3) << matrix[i][j] <<setw(3)<<" ";
			}
			cout << endl;
		}
	}


int main() {
	srand((unsigned)time(NULL));

	int myMatrix[3][3];

	fillRandomMatrix3By3(myMatrix);

	cout << "My 3*3 matrix is : \n\n";
	printMatrix3by3(myMatrix);
}

//instructor code
// The difference is that the number of rows and columns was entered by the main function, while I entered them manually into the functions. 

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
//
//int main() {
//	srand((unsigned)time(NULL));
//
//	int myMatrix[3][3];
//
//	fillRandomMatrix3By3(myMatrix);
//
//	cout << "My 3*3 matrix is : \n\n";
//	printMatrix3by3(myMatrix);
//}

