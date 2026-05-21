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

struct client {
	string accountNumber;
	string pinCode;
	string name;
	string phone;
	double accountBalance;
};

vector <string> splitString(string data,string delim) {
 	short pos = 0;
	string element = "";

	vector <string> splitteddata;
	while((pos=data.find(delim)) != std::string::npos) {
		element = data.substr(0, pos);
		if (element != "")
			splitteddata.push_back(element) ;
		data.erase(0, pos + delim.length());
 	}
	 if(data!="")
		 splitteddata.push_back(data);



	return splitteddata;
}

client fillStructWithVector(vector <string> splitteddata) {
	client info;
	info.accountNumber = splitteddata[0];
	info.pinCode = splitteddata[1];
	info.name = splitteddata[2];
	info.phone = splitteddata[3];
	info.accountBalance = stod(splitteddata[4]);
 
	return info;
}

void printStruct(client info) {

	cout << "Account number:" << info.accountNumber << endl;
	cout << "pin code:" << info.pinCode << endl;
	cout << "Name:" << info.name << endl;
	cout << "Phone:" << info.phone << endl;
	cout << "Account balance:" << info.accountBalance << endl;

}

int main() {
	string data = "a546#//#9999#//#velid#//#05541863483#//#8787.000000";
	cout << "the following is the extracted client record";
	printStruct(fillStructWithVector(splitString(data,"#//#")));

}