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
//vector<string>fillVectorWithWords(string str,string delim) {
//	vector<string>words;
//	short pos = 0;
//	string word = "";
//	while ((pos = str.find(delim)) != std::string::npos) {
//		word = str.substr(0, pos);
//		if (word != "")
//			words.push_back(word);
//		str.erase(0, pos + delim.length());
//	}
//	if (str != "")
//		words.push_back(str);
//	return words;
//
//}
//string  replaceTowWordsInString(vector<string>words,string replacedWord,string newWord) {
//	string newString;
//	for (string &word:words) {
//		if (word == replacedWord) {
//		word=newWord;
// 		}
//		newString = newString + word+" ";
//	}
//	return newString;
// }

//abouhadhoud solution .. you will use the code that u did above in next problem

string returnReplacedText(string str,string replacedString,string replacedTo) {
	short pos = str.find(replacedString);
	while (pos!=std::string::npos) {
		str = str.replace(pos, replacedString.length(), replacedTo);
		pos = str.find(replacedString);
	}
	return str;
}
int main() {
	string text = "my velid name is velid";
	string replace = "velid";
	string replacedto = "ammar";
	cout << "original string:" << endl;
	cout << text<<endl;
	cout << "string after replace:" << endl;
	//cout<< replaceTowWordsInString(fillVectorWithWords(text," "), "velid","ammar");
	cout<<returnReplacedText(text, replace, replacedto);
}