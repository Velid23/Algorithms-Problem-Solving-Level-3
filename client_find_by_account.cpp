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

client fillStructWithVector(string line, string delim) {
	client info;
	vector <string> data;
	data = splitString(line, delim);

	info.accountNumber = data[0];
	info.pinCode = data[1];
	info.name = data[2];
	info.phone = data[3];
	info.accountBalance = stod(data[4]);

	return info;
}

void printStruct(client info) {

	cout << "Account number:" << info.accountNumber<<endl;
	cout << "Pin code: "  << info.pinCode<<endl;
	cout << "Name : "  << info.name<<endl;
	cout << "Phone :"   << info.phone<<endl;
	cout << "Account Balance : " << info.accountBalance<<endl;

}
vector <client> loadFileDataToVector(string fileName) {
	client client1;
	fstream file;
	vector <client>clients;
	file.open(fileName, ios::in);
	if (file.is_open()) {
		string dataLine = "";
		while (getline(file, dataLine)) {
			client1 = fillStructWithVector(dataLine, "#//#");
			clients.push_back(client1);
		}
	}
	return clients;
}

//void printSearchedClient(vector <client>clients,string accountNumber) {
// 
//
//	for (client &cln : clients) {
//		if (cln.accountNumber == accountNumber) {
//			printStruct( cln);
//			return;
//		}
//	}
//	cout << "client with account number (" << accountNumber << ") not found!";
//}

bool isfound(client& clnt, string accountNumber) {
	vector <client>clients;
	clients = loadFileDataToVector(filename);
	for (client& cln : clients) {
		if (cln.accountNumber == accountNumber) {
			clnt=cln;
			return true;
		}
	}
	return false;


}
int main() {
	string searchkey;
	client cln;
	cout << "please enter the account :";
	cin >> searchkey;

	if (isfound(cln, searchkey)) 
		printStruct(cln);
	else {
		cout << "client with account number (" << searchkey << ") not found!";
	}
}
 
//make ur program in the best way that functions understandable in main function and make it general 