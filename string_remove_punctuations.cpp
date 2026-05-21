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

string returnStringRemovedSpecialChar(string str) {
	string newstring="";
	for (int i = 0; i < str.length(); i++) {
		if (!(ispunct(str[i])))
			newstring+=str[i];
	}
	return newstring;
}


int main() {
	string user = "my name is, velid, havethis..";
	cout << returnStringRemovedSpecialChar(user);
}