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
for (string &word:words) {
	 newstring=newstring+word+split;
	
}
return newstring.substr(0,newstring.length() - split.length());
}




int main() {
	vector<string>text = { "velid","ammar","yasir" };

	string str = joinFunction(text, ",");
	cout << str;
}