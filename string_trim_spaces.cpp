#include <iostream>
#include<string>
#include<random>
#include <ctime>  
#include<CCTYPE>
#include <cstdlib>
#include<string>
#include<iomanip>
#include<vector>
using namespace std;


string readString() {
	string temptext;
	cout << "please enter a string:";
	getline(cin, temptext);
	return temptext;
}

string trimLeft(string& text) {
 
	for (int i = 0; i < text.length(); i++) {
		if (text[i] != ' ') {
			text.erase(0, i);
			return text;
		}
	}
}
string trimRight(string &text) {

	for (int i = text.length()-1; i >0; i--) {
		if (text[i] != ' ') {
			text.erase(i+1, text.length());
			return text;
		}
	}
}

string trim(string text) {
	trimLeft(text);
	trimRight(text);
	return text;
}




int main() {
	string str = readString();
	//cout << trimLeft(readString())<<endl;
	cout << trimLeft(str) << "hello";
 }