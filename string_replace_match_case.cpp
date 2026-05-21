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

vector<string>fillVectorWithWords(string str,string delim) {
	vector<string>words;
	short pos = 0;
	string word = "";
	while ((pos = str.find(delim)) != std::string::npos) {
		word = str.substr(0, pos);
		if (word != "")
			words.push_back(word);
		str.erase(0, pos + delim.length());
	}
	if (str != "")
		words.push_back(str);
	return words;

}
string tolwerword(string word) {
	for (int i = 0; i < word.length(); i++) {
		word[i] = tolower(word[i]);
	}
	return word;
}
//string  replaceTowWordsInStringWithMachCase(vector<string>words,string replacedWord,string newWord) {
//	string newString;
//	for (string &word:words) {
//		if (word == replacedWord) {
//		word=newWord;	
// 		}
//		newString = newString + word+" ";
//	}
//	return newString;
// }
//
//string  replaceTowWordsInStringWithNoMachCase(vector<string>words, string replacedWord, string newWord) {
//	string newString;
//	for (string& word : words) {
//		if (tolwerword(word) == tolwerword(replacedWord)) {
//			 word = newWord;
//		}
//		newString = newString + word + " ";
//	}
//	return newString;
//}
string joinFunction(vector<string>words, string delim) {
	string joinedstring;
	for (string item : words) {
		joinedstring = joinedstring + item + delim;
	}
	 return joinedstring.substr(0, joinedstring.length() - delim.length());;
}
string replaceWithMatchCaseOrNot(string str, string replacedWord, string newWord, bool matchcase = true) {
	
	vector<string>words = fillVectorWithWords(str," ");
	for (string& word : words) {
		if (matchcase) {
			if (word == replacedWord)
				word = newWord;
		}
		else {
			if (tolwerword(word) == tolwerword(replacedWord))
				word = newWord;
		}
	}
	return joinFunction(words, " ");

}
int main() {
	string text = "my velid name is velid";
	string replace = "Velid";
	string replacedto = "Ammar";
	cout << "original string:" << endl;
	cout << text << "\n\n";
	cout << "string after replace with match case:" << endl;
	cout<< replaceWithMatchCaseOrNot(text, replace, replacedto)<<"\n\n";
	cout << "string after replace with no match case:" << endl;
	cout << replaceWithMatchCaseOrNot(text, replace, replacedto,false)<<endl;
 }

//try to make your functions general always by bool values
