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
	cin >> text;

	return text;
}

char inverseCase(char userchar) {
	return isupper(userchar) ? tolower(userchar) : toupper(userchar);
}

//short returnLetterCount(string text, char countedletter) {
//	short count = 0;
//	for (int i = 0; i < text.length(); i++) {
//		if (text[i] == countedletter)
//			count++;
//	}
//	return count;
//}

short returnCount(string text, char countedletter,bool matchcase=true) {
	short count = 0;
	for (int i = 0; i < text.length(); i++) {
		if (matchcase) {
			if (text[i] == countedletter)
				count++;
		}

		else {
			if (tolower(text[i]) == tolower(countedletter))
				count++;
		}
	}
	return count;
}


//short returnLetterCountIgnoringcase(string text, char countedletter) {
//	short count = 0;
//	for (int i = 0; i < text.length(); i++) {
//		if (text[i] == countedletter||text[i]==inverseCase(countedletter))
//			count++;
//	}
//	return count;
//}

int main() {

	string usertext = readString();
	char searchedchar = readChar();
	cout << "letter '" << searchedchar << "' count = " << returnCount(usertext, searchedchar) << endl;
	cout << "letter '" << searchedchar << "' or '"<<inverseCase(searchedchar) <<"' count="<<
		returnCount(usertext,searchedchar,false)<<endl;

}



