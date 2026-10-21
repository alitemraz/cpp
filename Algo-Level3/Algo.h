#pragma once

#define WIN32_LEAN_AND_MEAN

#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<iomanip>
#include<time.h>
#include<math.h>
#include <sstream>
#include<cctype>
#include<random>
#include<Windows.h>

using namespace std;

struct Client {
	string accountNumber;
	string name;
	string phone;
	string pinCode;
	double accountBalance;
};

namespace Matrix {

	int randomNumber(int from, int to) {

		return rand() % (to-from + 1) + from;
	}

	void fillRandomMatrix(int matrix[3][3],short rows,short cols) {

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0;j < 3;j++) {
				matrix[i][j] = randomNumber(0, 10);
			}
		}

	}

	void fillOrderedMatrix(int matrix[3][3], short rows, short cols,int start=1) {
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0;j < cols;j++) {
				matrix[i][j] = start++;
			}
		}
	}

	void transposeMatrix(int matrix[3][3], int tp_matrix[3][3], short rows, short cols) {
		for (int i = 0;i < rows;i++) {
			for (int j = 0;j < cols;j++) {
				tp_matrix[i][j] = matrix[j][i];
			}
		}
	}

	void printTransposedMatrix(int matrix[3][3], short rows, short cols) {
		cout << "The transposed matrix is: " << endl;
		for (int i = 0;i < rows;i++) {
			for (int j = 0;j < cols;j++) {
				cout << setw(3) << matrix[i][j] << " ";
			}
			cout << endl;
		}
	}

	int getRowSum(int arr[3], short rows) {
		int sum = 0;

		for (int i = 0;i < rows;i++) {
			sum += arr[i];
		}
		return sum;
	}

	int getColSum(int arr[3], short cols) {
		int sum = 0;

		for (int i = 0;i < cols;i++) {
			sum += arr[i];
		}
		return sum;
	}

	void mulTwoMatricies(int m1[3][3], int m2[3][3], int res[3][3]) {

		for (int i = 0;i < size(m1[0]);i++) {
			for (int j = 0;j < size(m1[0]);j++) {
				res[i][j] = m1[i][j] * m2[i][j];
			}
		}

	}

	void printMiddleRowAndCol(int m1[3][3]) {
		int middle = size(m1[0]) / 2;

		cout << setw(9) << "Middle Row of Matrix is: " << endl;

		for (int i = 0;i < size(m1[0]);i++) {
			cout << setw(3) << m1[middle][i];
		}

		cout << endl;

		cout << setw(9) << "Middle Col of Matrix is: " << endl;

		for (int i = 0;i < size(m1[0]);i++) {
			cout << setw(3) << m1[i][middle];
		}


	}

	int getMatrixSum(int m1[3][3]) {
		int length = size(m1[0]);
		int sum = 0;
		for (int i = 0; i < length; i++)
		{
			for (int j = 0; j < length; j++) {
				sum += m1[i][j];
			}
		}
		return sum;

	}

	bool areMatraciesEqual(int m1[3][3], int m2[3][3]) {
		return getMatrixSum(m1) == getMatrixSum(m2);
	}

	bool areMatraciesTypical(int m1[3][3], int m2[3][3]) {
		for (int i = 0; i < size(m1[0]); i++)
		{
			for (int j = 0; j < size(m1[0]); j++) {
				if (m1[i][j] != m2[i][j]) {
					return false;
				}
			}
		}
		return true;
	}

	bool isIdentity(int m1[3][3]) {
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0;j < 3;j++) {
				if (i == j && (m1[i][j] != 1)) {
					return false;
				}
				else if (i != j && (m1[i][j] != 0)) {
					return false;
				}
			}
		}
		return true;
	}

	bool isScalar(int m1[3][3]) {

		int toCheck = m1[0][0];
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0;j < 3;j++) {
				if (i == j && (m1[i][j] != toCheck)) {
					return false;
				}
				else if (i != j && (m1[i][j] != 0)) {
					return false;
				}
			}
		}
		return true;
	}

	int checkCount(int m1[3][3], int toCheck) {
		int count = 0;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0;j < 3;j++) {
				if (m1[i][j] == toCheck)
					count++;
			}
		}
		return count;
	}

	bool isSparse(int m1[3][3]) {
		int count = checkCount(m1,0);
		int totalElements = size(m1[0]) * size(m1[0]);

		return count > (totalElements/2);

	}

	bool checkExistance(int m1[3][3], int toCheck) {
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0;j < 3;j++) {
				if (m1[i][j] == toCheck)
					return true;
			}
		}
		return false;
	}

	void printIntersection(int m1[3][3], int m2[3][3]) {
		int number;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0;j < 3;j++) {
				number = m1[i][j];
				if (checkExistance(m2, number)) {
					cout << number << " ";
				}
			}
		}
	}

	void printMinAndMaxInMatrix(int m1[3][3]) {
		int min = m1[0][0], max = m1[0][0];
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0;j < 3;j++) {
				if (m1[i][j] < min) {
					min = m1[i][j];
				}
				else if (m1[i][j] > max) {
					max = m1[i][j];
				}
			}
		}

		cout << "min number in matrix is " << min << endl;
		cout << "max number in matrix is " << max << endl;

	}

	bool isPalindromeMatrix(int m1[3][3],short rows,short cols) {
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0;j < cols / 2;j++) {

				if (m1[i][j] != m1[i][cols - 1 - j])
					return false;
			}
			
		}
		return true;
	}


	void printMatrix(int matrix[3][3],short rows,short cols,bool r_sum=false,bool c_sum=false) {
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0;j < 3;j++) {
				cout << setw(3) << matrix[i][j] << " ";
			}

			cout << endl;
		}

		if (r_sum) {
			cout << "\nThe following row sum for each row in the matrix is:\n";

			for (int i = 0; i < rows; i++)
			{
				cout << "Row " << (i+1) << " Sum = " << getRowSum(matrix[i],rows) << endl;
			}
		}

		if (c_sum) {
			cout << "\nThe following col sum for each col in the matrix is:\n";
			int colVals[3];
			for (int i = 0; i < cols; i++)
			{
				for (int j = 0;j < rows;j++) {
					colVals[j] =  matrix[j][i];
				}
				
				cout << "Col " << (i + 1) << " Sum = " << getColSum(colVals,cols) << endl;
			}
		}
	}

	
}

namespace Algorithms {
	void fibbonaci(int num) {
		int prev1 = 0,prev2 = 0,total = 1;

		for (int i = 0; i <num; i++)
		{
			total += prev1;
			prev1 = prev2;
			prev2 = total;

			cout << total << " ";
		}

	}

	void fibbonaciRecursion(int num,int prev1=0,int prev2=1) {
		
		if (num > 0) {
			cout << prev2 << " ";

			fibbonaciRecursion(num - 1, prev2, prev1 + prev2);
		}
			
	}

}

namespace StringMan {

	void printFirstLetter(string s1) {

		cout << s1[0] << endl;

		while (s1.find(" ") != s1.npos) {

			s1 = s1.substr(s1.find(" ") + 1, -1);
			cout << s1[0] <<endl; 

		}

	}

	string toUpperCaseFisrtLetter(string s1) {

		bool isFirstLetter = true;

		for (int i = 0;i < s1.length();i++) {

			if (s1[i] != ' ' && isFirstLetter) {
				s1[i] = toupper(s1[i]);
			}
			isFirstLetter = s1[i] == ' ' ? true : false;
		}

		return s1;

	}

	string toLowerCaseFisrtLetter(string s1) {

		bool isFirstLetter = true;

		for (int i = 0;i < s1.length();i++) {

			if (s1[i] != ' ' && isFirstLetter) {
				s1[i] = tolower(s1[i]);
			}
			isFirstLetter = s1[i] == ' ' ? true : false;
		}

		return s1;

	}

	string toLowerString(string s1) {
		for (int i = 0;i < s1.length();i++) {
			s1[i] = tolower(s1[i]);
		}

		return s1;
	}

	string toUpperString(string s1) {
		for (int i = 0;i < s1.length();i++) {
			s1[i] = toupper(s1[i]);
		}

		return s1;

	}

	void printAllCases(string s1) {

		cout << "string after Upper: " << endl;
		
		cout << toUpperString(s1) << endl;

		cout << endl;

		cout << "string after Lower: " << endl;
		
		cout << toLowerString(s1) << endl;
	}

	char invertCharacter(char c) {
		return isupper(c) ? tolower(c) : toupper(c);
	}

	void printInvertCase(string s1) {

		for (int i = 0;i < s1.length();i++) {
			s1[i] = invertCharacter(s1[i]);
		}

		cout << "string after inverting: " << endl;
		cout << s1 << endl;

	}

	int countUpperLetters(string s1) {
		int count = 0;

		for (int i = 0;i < s1.length();i++) {
			if (isupper(s1[i]))
				count++;
		}

		return count;

	}

	int countLowerLetters(string s1) {
		int count = 0;

		for (int i = 0;i < s1.length();i++) {
			if (islower(s1[i]))
				count++;
		}

		return count;

	}

	void printStringProperties(string s1) {

		cout << "String Length: " << s1.length() <<endl;

		cout << "Capital Letters Count: " << countUpperLetters(s1) <<endl;

		cout << "Lower Letters Count: " << countLowerLetters(s1) << endl;


	}

	int countLetter(string s1, char c,bool matchCase=false) {

		int count = 0;

		for (int i = 0;i < s1.length();i++) {
			if (matchCase) {
				if (tolower(s1[i]) == tolower(c))
					count++;
			}
			else {
				if (s1[i] == c)
					count++;
			}
		}

		return count;

	}

	bool isVowel(char c) {

		char vowles[] = { 'a','e','o','i','u' };

		for (int i = 0;i < size(vowles);i++) {
			if (tolower(vowles[i]) == tolower(c))
				return true;
		}

		return false;

	}

	int vowelCount(string s1) {
		int count = 0;

		for (int i = 0;i < s1.length();i++) {

			if (isVowel(s1[i]))
				count++;
		}
		return count;
	}

	void printVowlesInString(string s1) {

		for (int i = 0;i < s1.length();i++) {

			if (isVowel(s1[i]))
				cout << s1[i] << " ";
		}
	}

	void printWordsOfString(string s1,char delim=' ') {

		while (s1.find(delim) != s1.npos) {

			int pos = s1.find(delim);
			int firstWordLength = s1.length() - (s1.length() - pos);
			string s2 = s1.substr(0, firstWordLength);
			cout << s2 << endl;

			s1 = s1.substr(pos+1, -1);
		}

		if (s1 != "") {
			cout << s1;
		}

	}

	int countWordsInString(string s1, char delim = ' ') {

		int count = 0;

		while (s1.find(delim) != s1.npos) {

			int pos = s1.find(delim);
			int firstWordLength = s1.length() - (s1.length() - pos);
			count++;
			s1 = s1.substr(pos + 1, -1);
		}

		if (s1 != "") {
			count++;
		}

		return count;
	}

	vector<string> splitString(string s1, string delim = " ") {

		vector<string> words;

		while (s1.find(delim) != s1.npos) {

			int pos = s1.find(delim);
			int firstWordLength = s1.length() - (s1.length() - pos);
			string s2 = s1.substr(0, firstWordLength);
			words.push_back(s2);

			s1 = s1.substr(pos + delim.length(), -1);
		}

		if (s1 != "") {
			words.push_back(s1);
		}

		return words;
	}

	string trimLeft(string s1) {
		string s2 = s1;
		for (int i = s1.length() - 1; i > 0;i--) {
			if (s1[i] == ' ') {
				s2 = s1.substr(0, i);
			}

			if (s1[i] != ' ') {
				return s2;
			}
		}
		
		return s1;
	}

	string trimRight(string s1) {
		string s2 = s1;


		for (int i = 1; i < s1.length();i++) {
			if (s1[i] == ' ') {
				s2 = s1.substr(i+1,-1);
			}

			if (s1[i] != ' ') {
				return s2;
			}
		}

		return s1;
	}

	string trim(string s1) {

		s1 = trimRight(s1);
		s1 = trimLeft(s1);

		return s1;

	}

	string joinString(vector<string> words, string delim = " ") {

		string s1 = "";

		for (string &word:words) {
			s1.append(word);
			s1.append(delim);
		}

		return s1.substr(0,s1.length()- delim.length());
	}

	string joinString(string words[],int length, string delim = " ") {

		string s1 = "";

		for (int i = 0;i < length;i++) {
			s1 += words[i] + delim;
		}

		return s1.substr(0, s1.length() - delim.length());
	}

	string reverseString(string s1) {

		vector<string> words = splitString(s1);
		string s2;
		for (int i = words.size() - 1;i >= 0;i--) {
			s2 += words.at(i) + " ";
		}
		return trimLeft(s2);

	}

	string replaceInString(string s1, string target, string newWord) {

		vector<string> words = splitString(s1);

		for (string& word : words) {
			if (word == target)
				word = newWord;
		}

		return joinString(words);
	}

	string removePunct(string s1) {

		string s2 = "";

		for (int i = 0;i < s1.length();i++) {

			if (!ispunct(s1[i]))
				s2 += s1[i];
		}
		return s2;

	}

}

namespace Bank {

	bool findClientByAccountNumber(string accountNumber, Client& client, string fileName, string dilem);

	Client readNewClient() {

		Client client;

		cout << endl;

		cout << "Enter Account Number: ";
		// Usage of std::ws will extract all the whitespace character
		getline(cin >> ws, client.accountNumber);

		while (findClientByAccountNumber(client.accountNumber,client,"clients.txt","###")) {
			cout << "\nClient with account number \'" << client.accountNumber << "\' already exists!"<<endl;
			cout <<"\nEnter another account number : ";
			cin >> client.accountNumber;
		}

		cout << "Enter Pin Code: ";
		getline(cin >> ws, client.pinCode);

		cout << "Enter Name: ";
		getline(cin, client.name);

		cout << "Enter Phone: ";
		getline(cin, client.phone);

		cout << "Enter Account Balance: ";
		cin >> client.accountBalance;
		
		return client;

	}

	Client updateClientDetails(string accountNumber) {

		Client client;

		client.accountNumber = accountNumber;

		cout << "\n\nEnter Pin Code: ";
		getline(cin >> ws, client.pinCode);

		cout << "Enter Name: ";
		getline(cin, client.name);

		cout << "Enter Phone: ";
		getline(cin, client.phone);

		cout << "Enter Account Balance: ";
		cin >> client.accountBalance;

		return client;

	}

	string convertRecordToALine(Client c,string dilem="###") {

		string s1 = "";

		vector<string> values;

		values.push_back(c.accountNumber);
		values.push_back(c.pinCode);
		values.push_back(c.name);
		values.push_back(c.phone);
		values.push_back(to_string(c.accountBalance));

		return StringMan::joinString(values, dilem);
	}

	Client convertLineToARecord(string s1,string dilem) {

		Client client;
		vector<string> values = StringMan::splitString(s1, dilem);

		client.accountNumber = values[0];
		client.pinCode = values[1];
		client.name = values[2];
		client.phone = values[3];
		client.accountBalance = stod(values[4]);

		return client;
	}

	void printRecord(const Client& client) {
		const string border = "+" + string(38, '=') + "+";
		const string divider = "+" + string(38, '-') + "+";

		auto row = [](const string& label, const auto& value) {
			ostringstream ss;
			ss << value;
			cout << "| " << left << setw(16) << label << ": "
				<< setw(18) << ss.str() << " |" << endl;
			};

		cout << "\n\n>> Client with the Following Details was Found <<\n\n";
		cout << border << endl;
		cout << "|" << string(10, ' ') << "[ CLIENT RECORD ]" << string(11, ' ') << "|" << endl;
		cout << divider << endl;
		row("Account Number", client.accountNumber);
		row("Pin Code", client.pinCode);
		row("Name", client.name);
		row("Phone", client.phone);
		row("Account Balance", client.accountBalance);
		cout << border << endl;
	}

	void saveRecordsToFile(string s1) {

		fstream file;

		file.open("clients.txt", ios::out | ios::app);

		try {
			if (file.is_open()) {
				file << s1 << endl;
				file.close();
			}
		}
		catch (exception e) {
			cout << "Error. " << e.what() << endl;
			file.close();
		}
	}

	void saveRecordsToFileAfterTransaction(string s1) {

		fstream file;

		file.open("clients.txt", ios::out);

		try {
			if (file.is_open()) {
				file << s1 << endl;
				file.close();
			}
		}
		catch (exception e) {
			cout << "Error. " << e.what() << endl;
			file.close();
		}
	}

	vector<Client> readRecordFromAFile(string fileName = "clients.txt",string dilem="###") {

		fstream file;
		string line;
		vector<Client> clients;
		file.open(fileName, ios::in);

		try {
			while (getline(file, line)) {
				Client client = convertLineToARecord(line,dilem);
				clients.push_back(client);
			}
		}
		catch (exception e) {
			cout << "Error. " << e.what() << endl;
			file.close();
		}
		return clients;

	}

	void addClients(string dilem = "###") {

		char choice = 'y';

		while (tolower(choice) == 'y') {
			system("cls");
			Client client = readNewClient();

			string lineClient = convertRecordToALine(client, dilem);

			saveRecordsToFile(lineClient);

			cout << "\nClient was added successfully, do you want to add another client? [ y/n ]:";
			cin >> choice;
		}

	}

	void printClients() {

		vector<Client> clients = readRecordFromAFile();

		const string line(97, '=');
		const string sep(97, '-');

		cout << "\n" << line << endl;
		cout << "||" << setw(52) << right << "CLIENT LIST"
			<< setw(43) << "||" << endl;
		cout << "||" << setw(55) << right << ("Total: " + to_string(clients.size()) + " client(s)")
			<< setw(40) << "||" << endl;
		cout << line << endl;

		cout << left
			<< "|| " << setw(14) << "Account No."
			<< "| " << setw(9) << "PIN"
			<< "| " << setw(28) << "Client Name"
			<< "| " << setw(16) << "Phone"
			<< "| " << setw(17) << "Balance"
			<< "||" << endl;
		cout << sep << endl;

		for (Client& client : clients) {
			cout << left
				<< "|| " << setw(14) << client.accountNumber
				<< "| " << setw(9) << client.pinCode
				<< "| " << setw(28) << client.name
				<< "| " << setw(16) << client.phone
				<< "| " << setw(17) << fixed << setprecision(2) << client.accountBalance
				<< "||" << endl;
		}

		cout << line << endl;
	}

	void printBalances() {

		vector<Client> clients = readRecordFromAFile();

		double totalBalance = 0;

		const string line(97, '=');
		const string sep(97, '-');

		cout << "\n" << line << endl;
		cout << "||" << setw(52) << right << "Balance LIST"
			<< setw(43) << "||" << endl;
		cout << "||" << setw(55) << right << ("Total: " + to_string(clients.size()) + " client(s)")
			<< setw(40) << "||" << endl;
		cout << line << endl;

		cout << left
			<< "|| " << setw(14) << "Account No."
			<< "| " << setw(28) << "Client Name"
			<< "| " << setw(46) << "Balance"
			<< "||" << endl;
		cout << sep << endl;

		for (Client& client : clients) {
			totalBalance += client.accountBalance;
			cout << left
				<< "|| " << setw(14) << client.accountNumber
				<< "| " << setw(28) << client.name
				<< "| " << setw(46) << fixed << setprecision(2) << client.accountBalance
				<< "||" << endl;
		}

		cout << line << endl;

		cout << "\n\n>>" << setw(52) << right << "Total Balances = $" << totalBalance << endl;
	}

	bool clientExists(string accountNumber,string fileName="clients.txt",string dilem="###") {
		vector<Client> clients = readRecordFromAFile(fileName,dilem);

		for (Client& client : clients) {
			if (client.accountNumber == accountNumber)
				return true;
		}
		return false;
	}

	bool findClientByAccountNumber(string accountNumber,Client& client,string fileName="clients.txt",string dilem="###") {

		vector<Client> clients = readRecordFromAFile(fileName,dilem);


		for (Client myClient : clients) {
			if (myClient.accountNumber == accountNumber) {
				client = myClient;
				return true;
			}
		}

		return false;
			
		

	}

	void deleteClientByAccountNumber(string accountNumber, string fileName = "clients.txt", string dilem = "###") {


		if (!clientExists(accountNumber, fileName, dilem)) {
			cout << "\nClient with account number \'" << accountNumber << "\' Doesn\'t Exist!" << endl;
			Sleep(2000);
			return;
		}

		vector<Client> clients = readRecordFromAFile(fileName,dilem);
		bool isDeleted = false;
		fstream file;
		char choice = 'y',cancelationChoice = 'n';
		file.open(fileName, ios::out);

		if (file.is_open()) {

			for (Client& client : clients) {
				if (client.accountNumber == accountNumber) {
					printRecord(client);
					cout << "\nAre you sure you want to delete this client? [y/n]: ";
					cin >> choice;
					if(tolower(choice) == 'y')
						isDeleted = true;
					else {
						file << convertRecordToALine(client, dilem) << endl;
						cout << "\nDeletion was canceled!" << endl;
						cancelationChoice = 'y';
					}
				}
				else {
					file << convertRecordToALine(client, dilem) << endl;
				}
			}
		}
		if (isDeleted) {
			system("cls");
			cout << "\nclient was Deleted Successfully!"<<endl;
			cout << "\nPlease wait you will be directed to the Main Menue shortly!";
			Sleep(2000);
		}
		file.close();

	}

	void updateClientByAccountNumber(string accountNumber, string fileName = "clients.txt", string dilem = "###") {

		if (!clientExists(accountNumber, fileName, dilem)) {
			cout << "\nClient with account number \'" << accountNumber << "\' Doesn\'t Exist!" << endl;
			Sleep(2000);
			return;
		}

		vector<Client> clients = readRecordFromAFile(fileName, dilem);
		bool isUpdated = false;
		fstream file;
		char choice = 'y', updateChoice = 'n';
		file.open(fileName, ios::out);

		if (file.is_open()) {
			for (Client& client : clients) {
				if (client.accountNumber == accountNumber) {
					printRecord(client);
					cout << "\nAre you sure you want to update this client? [y/n]: ";
					cin >> choice;
					if (tolower(choice) == 'y') {
						client = updateClientDetails(client.accountNumber);
						file << convertRecordToALine(client, dilem) << endl;
						isUpdated = true;
					}
					else {
						file << convertRecordToALine(client, dilem) << endl;
						cout << "\nUpdate Client was canceled!" << endl;
						updateChoice = 'y';
					}
				}
				else {
					file << convertRecordToALine(client, dilem) << endl;
				}
			}
		}
		if (isUpdated) {
			system("cls");
			cout << "\nClient was Updated Successfully!" << endl;
			cout << "\nPlease wait you will be directed to the Main Menue shortly!";
			Sleep(2000);
		}

		file.close();

	}

	double depositeToBalance(string accountNumber,double amount) {

		Client myClient;

		if (amount < 0)
			return 0.0;

		findClientByAccountNumber(accountNumber, myClient);

		myClient.accountBalance += amount;

		double result = myClient.accountBalance;

		vector<Client> clients = readRecordFromAFile();

		if (clients.size() == 1) {
			saveRecordsToFileAfterTransaction(convertRecordToALine(myClient));
			return result;
		}

		for (Client& client : clients) {
			if (!(client.accountNumber == accountNumber))
				saveRecordsToFileAfterTransaction(convertRecordToALine(client));
		}

		saveRecordsToFile(convertRecordToALine(myClient));
		return result;
	}

	double withdrawFromBalance(string accountNumber, double amount) {

		Client myClient;

		findClientByAccountNumber(accountNumber, myClient);

		if (amount > myClient.accountBalance)
			return 0.0;

		myClient.accountBalance -= amount;

		double result = myClient.accountBalance;

		vector<Client> clients = readRecordFromAFile();

		if (clients.size() == 1) {
			saveRecordsToFileAfterTransaction(convertRecordToALine(myClient));
			return result;
		}

		for (Client& client : clients) {
			if (!(client.accountNumber == accountNumber))
				saveRecordsToFileAfterTransaction(convertRecordToALine(client));
		}

		saveRecordsToFile(convertRecordToALine(myClient));

		return result;
	}



}