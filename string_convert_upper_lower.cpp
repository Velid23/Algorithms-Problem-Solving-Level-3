#include <iostream>
#include<string>
#include<random>
#include <ctime>  
#include<CCTYPE>
#include <cstdlib>
#include<string>
#include<iomanip>
using namespace std;

string readText() {
	string text;
	cout << "please enter a string :";
	getline(cin, text);
	return text;
}
string returnAllStringUpper(string text) {
	for (int i = 0; i < text.length();i++) {
		text[i] = toupper(text[i]);
	}

	return text;
}

string returnAllStringLower(string text) {
	for (int i = 0; i < text.length(); i++) {
		text[i] = tolower(text[i]);
	}

	return text;
}

int main() {
	string userinput = readText();
	cout << "all string done upper:" << endl;
	cout<<returnAllStringUpper(userinput);
	cout << "\n all string done lower:" << endl;
	cout<< returnAllStringLower(userinput);

}