#include <iostream>
#include<string>
#include<random>
#include <ctime>  
#include<CCTYPE>
#include <cstdlib>
#include<string>
#include<iomanip>
using namespace std;

void PrintFirstLetter(string text) {
	cout << text[0]<<endl;

	for (int i = 0; i < text.length(); i++) {
		char letter = text[i];
		if (letter == ' ') {
			cout << text[i+1]<<endl;
		}
	}
}

int main() {
	string userText;

	cout << "please enter a string:";
	getline(cin, userText);

	PrintFirstLetter(userText);

}

//اولا من الخطا تعريف متغير داخل الفور لوب ثانيا بركي المستخدم دخل نص في اكثر من فرغ بين كل كلمة و كلمة


//void PrintFirstLetter(string text) {
// 
//	bool isFirstLetter = true;
//
//	for (int i = 0; i < text.length(); i++) {
// 		if (text[i]!=' '&&isFirstLetter) {
//			cout << text[i]<<endl;
//		}
//		isFirstLetter = (text[i] == ' ' ? true : false);
//
//	}
//}