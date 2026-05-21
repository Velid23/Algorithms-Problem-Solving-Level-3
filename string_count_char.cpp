#include <iostream>
#include<string>
#include<random>
#include <ctime>  
#include<CCTYPE>
#include <cstdlib>
#include<string>
#include<iomanip>
using namespace std;

string readString() {
	string text;
	cout << "please enter a string :";
	getline(cin, text);

	return text;
}
char readChar() {
	char text;
	cout << "please enter a char to search :";
	cin>>text;

	return text;
}

short returnLetterCount(string text,char countedletter) {
	short count = 0;
	for (int i = 0; i < text.length(); i++) {
		if(text[i] == countedletter)
		  count++;
	}
	return count;
}




int main() {

	string userString = readString();
	char searchedChar = readChar();

	cout << "letter '" << searchedChar <<"' count = "<< returnLetterCount(userString, searchedChar);
 

}