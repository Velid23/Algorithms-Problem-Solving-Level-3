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
	bool marked = false;/*this is abouhadhoud line*/
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
client askForNewClientInfo(string accountnumber) {
	client cln;

	cln.accountNumber = accountnumber;

	cout << "Enter Pin Code:";
	cin >> cln.pinCode;

	cout << "Enter Name";
	cin >> cln.name;

	cout << "Enter Phone";
	cin >> cln.phone;

	cout << "Enter Account Balance:";
	cin >> cln.accountBalance;

	return cln;
}
void printStruct(client info) {

	cout << "Account number:" << info.accountNumber << endl;
	cout << "Pin code: " << info.pinCode << endl;
	cout << "Name : " << info.name << endl;
	cout << "Phone :" << info.phone << endl;
	cout << "Account Balance : " << info.accountBalance << endl;

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

bool isfound(vector <client>& clients, client& clnt, string accountNumber) {

	for (client& cln : clients) {
		if (cln.accountNumber == accountNumber) {
			clnt = cln;
			return true;
		}
	}
	return false;
}

bool  update(vector <client>& clients, string accountNumber) {
	//abouhadhoud function
	for (client& cln : clients) {
		if (cln.accountNumber == accountNumber) {
			cln = askForNewClientInfo(accountNumber);

			return true;
		}
	}
	return false;
}

string joinclientinfo(client info, string delim) {
	string line;
	line = info.accountNumber + delim + info.pinCode + delim + info.name + delim +
		info.phone + delim + to_string(info.accountBalance);
	return line;
}
vector <client> saveUpdatedClientDataToFile(string fileName, vector <client>& clients) {
	fstream file;
	file.open(filename, ios::out);
	if (file.is_open()) {

		for (client& cln : clients) {
			if (cln.marked == false) {
				string dataline = joinclientinfo(cln, "#//#");
				file << dataline << endl;
			}
		}

	}
	file.close();


	return   clients;
}
bool updateClientByAccountNumber(vector <client>& clients, string accountNumber) {
	client cln;
	if (isfound(clients, cln, accountNumber)) {
		printStruct(cln);
		char sure = 'Y';
		cout << "are you sure that you want to update ?";
		cin >> sure;

		if (toupper(sure) == 'Y') {

			update(clients, accountNumber);
			saveUpdatedClientDataToFile(filename, clients);

			clients = loadFileDataToVector(filename);
			cout << "\n\nClient updated Successfully.";
			return true;
		}
		else {
			cout << "update canceled succsesfully" << endl;
		}
	}
	else
	{
		cout << "\nClient with Account Number (" << accountNumber
			<< ") is Not Found!";
		return false;
	}
}

int main() {
	string searchkey;
	client cln;
	cout << "please enter the account :";
	cin >> searchkey;

	vector <client> vClients = loadFileDataToVector(filename);
	updateClientByAccountNumber(vClients, searchkey);
}


