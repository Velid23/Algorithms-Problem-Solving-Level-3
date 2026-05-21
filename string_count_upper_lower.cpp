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
 

int  capitalLetterCount(string userchar) {
	int count = 0;
	for(int i=0;i< userchar.length();i++){
		if(isupper(userchar[i]))
		  count++;
	}
	return count;
}
int  smallLetterCount(string userchar) {
	int count = 0;
	for (int i = 0; i < userchar.length(); i++) {
		if (islower(userchar[i]))
			count++;
	}
	return count;
}

int main() {
	string userinput = readString();
	cout << "your string length is:" << endl;
	cout << userinput.length() << endl;
	cout << "capital letter count is:" << endl;
	cout << capitalLetterCount(userinput) << endl;
	cout << "small letter count is:" << endl;
	cout << smallLetterCount(userinput) << endl;


}

//يمكن عمله عن طريق الانوم 

enum enWhatToCount {capitalleters=0,smalleters = 1};

short returnCount(string s1,enWhatToCount whattocount) {
	short count = 0;
	for (int i = 0; i < s1.length(); i++) {
		if (whattocount == enWhatToCount::capitalleters && isupper(s1[i])) {
			count++;
		}
		if (whattocount == enWhatToCount::smalleters && islower(s1[i])) {
			count++;
		}

	}
	return count;

}