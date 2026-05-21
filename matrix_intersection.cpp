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

void printIntersectedNumbers(int matrix[3][3], int matrix2[3][3], short rows, short column) {
 	for (short i = 0; i < rows; i++) {
		for (short j = 0; j < column; j++) {
			if (matrix[i][j] == matrix2[i][j]) {
				cout << matrix[i][j]<<"   ";
			}
		}
	}
 }

int main() {
	srand((unsigned)time(NULL));
	int matrix[3][3] = {
		{4,6,1},
		{0,5,3},
		{9,0,3}
	};
	int matrix2[3][3] = {
		{4,6,0},
		{0,4,3},
		{8,0,2}
	};

	//fillRandomMatrix(matrix, 3, 3);
	cout << "matrix 1 is :\n\n";
	printArray(matrix, 3, 3);
	cout << " \n\n";
	cout << "matrix 2 is :\n\n";
	printArray(matrix2, 3, 3);
	cout << " \n\n";
	printIntersectedNumbers(matrix, matrix2, 3, 3);


}
 //الكود يل يكتبته انا بيتطلع عالموقع بالضبط يعني مثل المساواة و لكن المطلوب هو ما ان كان 
//في الماتركس الثانية كلها و ليس ان يكون في نفس الموقع يعني ممكن يكون العنصر موجود بالماتركس الثانية لكن بغير موقع 
//هون مناكل هوا ساعتها 

//منطق ابو هدهد

//bool isElementExistInMartix(int matrix[3][3],int element, short rows, short column) {
//	for (short i = 0; i < rows; i++) {
//		for (short j = 0; j < column; j++) {
//			if (matrix[i][j] == element) {
//				return true;
//			}
//		}
// 	}
//	return false;
//
//}
//
//void printIntersectedNumbers(int matrix[3][3], int matrix2[3][3], short rows, short column) {
//	int number;
//	for (short i = 0; i < rows; i++) {
//		for (short j = 0; j < column; j++) {
//			number = matrix[i][j];
//			if (isElementExistInMartix(matrix2,number,3,3)) {
//				cout <<  setw(3)<<matrix[i][j] << " ";
//			}
//		}
//	}
//
//}