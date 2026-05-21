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
	string userstring;
	cout << "please enter a string";
	getline(cin, userstring);

	return userstring;
 }

short returnCountWords(string example) {
	string space = " ";
	short pos = 0;
	string word = "";
	short count = 0;
	while ((pos=example.find(space))!=std::string::npos ) {
		word = example.substr(0, pos);
		if (word != "")
			count++;
		example.erase(0, pos + space.length());
	}
	if (example != "") {
		//cout << example << endl;
		count++;
	}
	return count;

	
}



int main() {
	string text = readString();
	cout<<"the number of words in your string is :"<<returnCountWords(text);

}