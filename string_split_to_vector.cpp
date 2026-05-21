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

string readString() {
	string word;
	cout << "please enter a string:";
	getline(cin, word);
	return word;
}

void printVector(vector <string> words) {
	for (int i = 0; i < words.size(); i++) {
		cout << words[i]<<endl;
	}
}

vector<string> fillVectorWithWords(string text,string split) {
	vector <string> words;
	short pos = 0;
	string word;

	while ((pos= text.find(split))!=std::string::npos) {
		word = text.substr(0, pos);
		if (word != "")
			words.push_back(word);
		text.erase(0, pos + split.length());
	}
	if (text != "") {
		words.push_back(text);
	}
	return words;
}



int main() {

	vector <string> wordvector;
	wordvector = fillVectorWithWords(readString()," ");
	cout << "tokens are:"<<wordvector.size()<<endl;
	printVector(wordvector);
}