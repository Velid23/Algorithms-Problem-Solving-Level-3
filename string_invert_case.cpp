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
//char returnCharUpper(char& userchar) {
//	userchar = toupper(userchar);
//	return userchar;
//}
//
//char returnCharLower(char& userchar) {
//	userchar = tolower(userchar);
//	return userchar;
//}

char inverseCase(char userchar) {
	return isupper(userchar) ? tolower(userchar) : toupper(userchar);
}
string returnInversedString(string userstring) {
	for (int i = 0; i < userstring.length(); i++) {
		userstring[i] = inverseCase(userstring[i]);
	}

	return userstring;
}

int main() {
	string userinput = readString();
	cout << "Char after inverting case:" << endl;
	userinput = returnInversedString(userinput);
	cout << userinput;


}
 