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

bool isPalindrome(int matrix[3][3], short rows, short column) {
	for (short i = 0; i < rows; i++) {
		for (short j = 0; j < column; j++) {
			if (!(matrix[i][j]==matrix[i][column-j-1])) {
				return false;
			}
		}
	}

	return true;
}


int main() {
	srand((unsigned)time(NULL));
	int matrix[3][3] = {
		{1,6,1},
		{4,5,4},
		{3,9,3}
	};
	cout << "matrix  is :\n\n";
	printArray(matrix, 3, 3);
	cout << " \n\n";

	if (isPalindrome(matrix, 3, 3)) {
		cout << "the matrix is palindrome";
	}
	else {
		cout << "the matrix is not palindrome";
	}

}

//هنا ملاحظة مهمة : لا يوجد داعي لان تتجول كامل الاراي يكفي النصف الاول فيجب ان تضع بدال >columns,>columns/2 
//فلا داعي لان يتجول الطرف الاخر لان بالاصل كان قد قارنه في النثف الاول ة ذلك لزيادة سرعة البرنامج