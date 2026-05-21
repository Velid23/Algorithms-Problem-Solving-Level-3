#include <iostream>
#include<string>
#include<random>
#include <ctime>  
#include<CCTYPE>
#include <cstdlib>
#include<string>
#include<iomanip>
#include<vector>
#include<fstream>
using namespace std;

const string ClientsFileName = "Clients.txt"; //abouhadhoud code

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

void saveStringToFile(string filename, string data) {
	fstream file;
	file.open(filename, ios::app | ios::out);
	file << data<<endl;
	file.close();
}

string joinclientinfo(client info, string delim) {
	string line;
	line = info.accountNumber + delim + info.pinCode + delim + info.name + delim +
		info.phone + delim + to_string(info.accountBalance);
	return line;
}
void addNewClient() {
	client newone;
	newone = fillClientInfo();
	saveStringToFile(ClientsFileName, joinclientinfo(newone, "#//#"));
}

void addClients() {
	char more = 'Y';
	do {
		addNewClient();
		cout << "do you want to add more:";
		cin >> more;
	} while (toupper(more) == 'Y');
}


//bool askToAddMore() {
//	char choose = 'Y';
//	cout << "do you want to enter more:";
//	cin >> choose;
//
//	if ((choose == 'Y') || (choose == 'y')) {
//		return true;
//	}
//	else {
//		return false;
//	}
//}
    
int main() {
	addClients();
}

//make your program general and able to develop 