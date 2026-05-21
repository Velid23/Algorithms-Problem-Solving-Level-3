#include <iostream>
#include<string>
#include<random>
#include <ctime>  
#include<CCTYPE>
#include <cstdlib>
#include<string>
#include<iomanip>
#include<vector>
#include <fstream>
using namespace std;

const string filename = "Clients.txt";

struct client {
	string accountNumber;
	string pinCode;
	string name;
	string phone;
	double accountBalance;
};

vector <string> splitString(string data, string delim) {
	short pos = 0;
	string element = "";

	vector <string> splitteddata;
	while ((pos = data.find(delim)) != std::string::npos) {
		element = data.substr(0, pos);
		if (element != "")
			splitteddata.push_back(element);
		data.erase(0, pos + delim.length());
	}
	if (data != "")
		splitteddata.push_back(data);
	return splitteddata;
}

client fillStructWithVector(string line,string delim) {
	client info;
	vector <string> data;
	data = splitString(line,delim);

	info.accountNumber = data[0];
	info.pinCode = data[1];
	info.name = data[2];
	info.phone = data[3];
	info.accountBalance = stod(data[4]);

	return info;
}

void printStruct(client info) {

	cout << "| " << setw(15) << left << info.accountNumber;
	cout << "| " << setw(10) << left << info.pinCode;
	cout << "| " << setw(40) << left << info.name;
	cout << "| " << setw(12) << left << info.phone;
	cout << "| " << setw(12) << left << info.accountBalance;

}
vector <client> loadFileDataToVector(string fileName) {
	client client1;
	fstream file;
	vector <client>clients;
	file.open(fileName, ios::in);
	if (file.is_open()) {
		string dataLine = "";
		while (getline(file, dataLine)) {
			client1 = fillStructWithVector(dataLine,"#//#");
			clients.push_back(client1);
		}
	}
	return clients;
}

void printAllClientsData(vector <client>clients) {
	cout << "\t\t\t\t Client List (" << clients.size() << ")Client(s)."<<endl;
	cout << "----------------------------------------------";
	cout << "------------------------------------------------------------------- " << endl;
	cout << "| " << left << setw(15) << "Account number";
	cout << "| " << left << setw(10) << "Pin code";
	cout << "| " << left << setw(40) << "name";
	cout << "| " << left << setw(12) << "phone";
	cout << "| " << left << setw(12) << "balance";
	cout << "\n----------------------------------------------";
	cout << "------------------------------------------------------------------- " << endl;

		for (client cln : clients) {
			printStruct(cln);
			cout << endl;
		}
}
int main() {
	vector <client>clients;
	clients = loadFileDataToVector(filename);
	printAllClientsData(clients);

}