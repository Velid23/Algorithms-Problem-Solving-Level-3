#include <iostream>
#include<string>
#include<random>
#include <ctime>  
#include<CCTYPE>
#include <cstdlib>
#include<string>
#include<iomanip>
using namespace std;

string returnUperedCaseWord(string &text) {

	bool isFirstLetter = true;

	for (int i = 0; i < text.length(); i++) {
		if (text[i] != ' ' && isFirstLetter) {
			text[i]=toupper(text[i]);
		}
		isFirstLetter = (text[i] == ' ' ? true : false);
	}

	return text;
}

int main() {
	string userText;

	cout << "please enter a string:";
	getline(cin, userText);

	cout << "the text befor do uper case to each words first letter: "<<endl;
	cout << userText<<endl;
	cout << "the text after do uper case to each words first letter :"<<endl;
	cout<<returnUperedCaseWord(userText);

}

