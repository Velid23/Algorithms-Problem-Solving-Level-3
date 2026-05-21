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

bool isfound(vector <client>&clients,client& clnt, string accountNumber) {
	
 	for (client& cln : clients) {
		if (cln.accountNumber == accountNumber) {
			clnt = cln;
			return true;
		}
	}
	return false;
}

bool  MarkClientForDeleteByAccountNumber(vector <client>&clients, string accountNumber) {
	//abouhadhoud function
	for (client &cln : clients) {
		if (cln.accountNumber == accountNumber) {
			cln.marked=true;
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
vector <client> saveOnlyNonMarkedClientDataToFile(string fileName, vector <client>& clients) {
 	fstream file;
	file.open(filename, ios::out);
	if (file.is_open()) {

		for (client &cln : clients) {
			if (cln.marked==false) {
				string dataline = joinclientinfo(cln, "#//#");
				file << dataline << endl;
			}
		}

	}	
	file.close();


	return   clients;
}
bool deleteClientByAccountNumber(vector <client>& clients, string accountNumber) {
	client cln;
	if (isfound(clients, cln, accountNumber)) {
		printStruct(cln);
		char sure = 'Y';
		cout << "are you sure that you want to remove?";
		cin >> sure;

		if (toupper(sure) == 'Y') {

			MarkClientForDeleteByAccountNumber(clients, accountNumber);
			saveOnlyNonMarkedClientDataToFile(filename, clients);

			clients = loadFileDataToVector(filename);
			cout << "\n\nClient Deleted Successfully.";
			return true;
		}
		else {
			cout << "deletion canceled succsesfully" << endl;
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
	deleteClientByAccountNumber(vClients, searchkey);
}

//make your program generall and can be improve and clean and safe 
//try to think step by step and do function to each step