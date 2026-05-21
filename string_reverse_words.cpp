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

vector<string> splitWords(string text,string delim) {
	vector<string>words;
	string word = "";
 	short pos =0;
 	while ((pos=text.find(delim))!=std::string::npos) {
		word =  text.substr(0,pos);

		if (word != "")
			words.push_back(word);
		text.erase(0, pos + delim.length());

 	}
	if(text!="")
		words.push_back(text);
	return words;
}

string reversedWords(string str) {
	vector<string>wordsreversed;
	string word="";

	wordsreversed = splitWords(str, " ");
	vector<string>::iterator iter = wordsreversed.end();

	while (iter != wordsreversed.begin()) {
		iter--;
		word = word + *iter + " ";

	}

	word =  word.substr(0, word.length() - 1);
		return word;
}

int main() {
	string name = "my name is velid saeedi";
	cout<<reversedWords(name);
}



