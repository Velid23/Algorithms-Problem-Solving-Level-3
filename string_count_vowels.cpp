#include <iostream>
#include<string>
#include<random>
#include <ctime>  
#include<CCTYPE>
#include <cstdlib>
#include<string>
#include<iomanip>
using namespace std;

 

bool isVowel(char charuser) {
	charuser = tolower(charuser);

	return ((charuser == 'a') || (charuser == 'i') || (charuser == 'e') ||
		(charuser == 'o') || (charuser == 'u'));


}

short returnVowelNumberCount(string text) {
	short count=0;
	for (int i = 0; i < text.length(); i++) {
		if (isVowel(text[i]))
			count++;
	}
	return count;
}


string readString() {
	string text;
	cout << "please enter a string  :";
	getline(cin,text);

	return text;
}



int main() {

	string userstring = readString();
	cout << "number of values is = " << returnVowelNumberCount(userstring);
}

