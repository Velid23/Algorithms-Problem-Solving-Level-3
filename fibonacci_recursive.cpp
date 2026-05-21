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

void  printFibonacciSeries(int number,int prev1,int prev2) {
 
	int now=0;
 
	if (number>0) {
		now = prev1 + prev2;
		prev2 = prev1;
		prev1 = now;

		cout << now << " ";
		printFibonacciSeries(number-1,prev1,prev2);
	}


	
}


int main() {
	int length;

	cout << "please enter the series length:";
	cin >> length;

	printFibonacciSeries(length,0,1);

}

