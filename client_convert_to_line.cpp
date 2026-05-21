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
client fillClientInfo() {
	client example;
	cout << "please enter account number:";
	cin >> example.accountNumber;

	cout << "please enter pincode:";
	cin >> example.pinCode;

	cout << "please enter your name:";
	cin >> example.name;

	cout << "please enter phone:";
	cin >> example.phone;

	cout << "please enter account balance:";
	cin >> example.accountBalance;

	return example;
}

string joinclientinfo(client info,string delim) {
	string line;
	line = info.accountNumber + delim + info.pinCode + delim + info.name + delim +
		 info.phone + delim + to_string(info.accountBalance);
	return line;
}

int main() {
	client userinfo= fillClientInfo();
	cout << "client record for saving is:" << endl;
	cout<<joinclientinfo(userinfo,"#//#");
}