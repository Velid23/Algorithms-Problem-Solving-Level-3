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



string joinFunction(vector<string>words, string split) {
	string newstring;
	for (string& word : words) {
		newstring = newstring + word + split;

	}
	return newstring.substr(0, newstring.length() - split.length());
}
string joinFunction(string words[],short length, string split) {
	string newstring;
	for (int i = 0; i < length;i++) {
		newstring = newstring + words[i] + split;

	}
	return newstring.substr(0, newstring.length() - split.length());
}



int main() {
	vector<string>text = { "velid","ammar","yasir" };
	string arrword[3] = { "mahmoud","sayit","lokman" };
	string str = joinFunction(text, ",");
	string str2 = joinFunction(arrword,3,",");

	cout << str << endl;
	cout << str2 << endl;
}