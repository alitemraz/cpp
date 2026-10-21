#pragma once

#define WIN32_LEAN_AND_MEAN

#include "Algo.h";
#include<Windows.h>
#include<cctype>
#include <conio.h>
#include <cstdlib>

using namespace Bank;

void printMenueScreen();
void printTransactionMenueScreen();

void printTitleScreen(string title) {
	system("cls");

	const int width = 54;

	cout << string(width, '-') << endl;
	cout << "\t\t" << title << endl;
	cout << string(width, '-') << endl;
}

void printAllClientsScreen() {
	system("cls");
	printClients();
	cout << "\n\nPress any key to go back to Main Menue...";
	(void)_getch();
	printMenueScreen();
}

void addNewClientScreen() {
	Client client;
	char choice = 'y';

	while (tolower(choice) == 'y') {
		system("cls");
		printTitleScreen("Add New Client Screen");
		client = readNewClient();
		saveRecordsToFile(convertRecordToALine(client));
		cout << "\n\nClient was added successfully. Do you want to add another client? [y/n]: ";
		cin >> choice;
	}
	printMenueScreen();
}

void deleteClientScreen() {
	string accountNumber;
	system("cls");
	printTitleScreen("Delete Client Screen");

	cout << "\nEnter Account Number to be deleted: ";
	cin >> accountNumber;
	deleteClientByAccountNumber(accountNumber);

	printMenueScreen();

}

void updateClientScreen() {
	string accountNumber;

	system("cls");
	printTitleScreen("Update Client Screen");

	cout << "\nEnter Account Number to be updated: ";
	cin >> accountNumber;
	updateClientByAccountNumber(accountNumber);

	printMenueScreen();

}

void findClientScreen() {
	string accountNumber;
	Client client;

	system("cls");
	printTitleScreen("Find Client Screen");

	cout << "\nEnter Account Number: ";
	cin >> accountNumber;

	if (findClientByAccountNumber(accountNumber, client)) {
		printRecord(client);
	}
	else {
		system("cls");
		cout << "Client With Account number \'" << accountNumber << "\' doesn\'t Exist!" << endl;
		cout << "\nYou will be redirected to Main Menue shortly!";
		Sleep(2000);
		printMenueScreen();
	}
	cout << "\n\nPress any key to go back to Main Menue...";
	(void)_getch();
	printMenueScreen();

}

void deposite() {
	string accountNumber;
	double depositeAmount;
	char choice = 'y';
	printTitleScreen("Deposite Screen");

	cout << "\n\nEnter Account Number: ";
	cin >> accountNumber;

	while (!clientExists(accountNumber)) {
		cout << "\nClient with account number \'" << accountNumber << "\' Doesn\'t Exist. Please Enter valid Account Number: ";
		cin >> accountNumber;
	}

	cout << "\nPlease Enter Deposite Amount: ";
	cin >> depositeAmount;

	while (depositeAmount <= 0) {
		cout << "\nPlease Enter A valid Deposite Amount: ";
		cin >> depositeAmount;
	}

	cout << "\nAre you sure you want to perform this transaction? [y/n]: ";
	cin >> choice;

	if (!(tolower(choice) == 'y')) {
		printTransactionMenueScreen();
	}

	double result = depositeToBalance(accountNumber, depositeAmount);

	if (result == 0) {
		cout << "\nTransaction could\'nt be made please try again later." << endl;
	}
	else {
		cout << "\nTransaction was Successfull! \'" << accountNumber << "\' has now total Balance of $" << result << endl;
	}

	cout << "\nPress Any key to go back to Transactions Menue...";
	(void)_getch();
	printTransactionMenueScreen();

}

void withdraw() {
	string accountNumber;
	double withdrawAmount;
	char choice = 'y';
	printTitleScreen("WithDraw Screen");

	cout << "\n\nEnter Account Number: ";
	cin >> accountNumber;

	while (!clientExists(accountNumber)) {
		cout << "\nClient with account number \'" << accountNumber << "\' Doesn\'t Exist. Please Enter valid Account Number: ";
		cin >> accountNumber;
	}

	cout << "\nPlease Enter Withdraw Amount: ";
	cin >> withdrawAmount;

	while (withdrawAmount <= 0) {
		cout << "\nPlease Enter A valid Withdraw Amount: ";
		cin >> withdrawAmount;
	}

	cout << "\nAre you sure you want to perform this transaction? [y/n]: ";
	cin >> choice;

	if (!(tolower(choice) == 'y')) {
		printTransactionMenueScreen();
	}

	double result = withdrawFromBalance(accountNumber, withdrawAmount);

	if (result == 0) {
		cout << "\nTransaction could\'nt be made please try again later." << endl;
	}
	else {
		cout << "\nTransaction was Successfull! \'" << accountNumber << "\' has now total Balance of $" << result << endl;
	}
	cout << "\nPress Any key to go back to Transactions Menue...";
	(void)_getch();
	printTransactionMenueScreen();
}

void showBalanceList() {
	system("cls");
	printBalances();

	cout << "\n\nPress any key to go back to Transaction Menue...";
	(void)_getch();
	printTransactionMenueScreen();
}

void selectTransactionMenueOption(int choice) {
	switch (choice) {
	case 1:
		deposite();
		break;
	case 2:
		withdraw();
		break;
	case 3:
		showBalanceList();
		break;
	case 4:
		printMenueScreen();
		break;
	default:
		system("cls");
		cout << "Not a valid input, pleas wait shortly and you can again!" << endl;
		cout << "\nMake sure you enter a valid option this time!";
		Sleep(3000);
		printTransactionMenueScreen();
	}
}

void printTransactionMenueScreen() {

	system("cls");
	int choice;

	const string line(75, '=');
	const string sep(75, '-');

	cout << "\n" << line << endl;
	cout << "||" << setw(43) << right << "Transaction MENU SCREEN"
		<< setw(30) << "||" << endl;
	cout << line << endl;

	cout << left;
	cout << "||   " << setw(68) << "[1]  Deposit" << "||" << endl;
	cout << "||   " << setw(68) << "[2]  WithDraw" << "||" << endl;
	cout << "||   " << setw(68) << "[3]  Total Balances" << "||" << endl;
	cout << "||   " << setw(68) << "[4]  Main Menue" << "||" << endl;

	cout << line << endl;
	cout << ">> What do you want to do? [1 to 4]: ";
	cin >> choice;
	selectTransactionMenueOption(choice);
}


void transactionsScreen() {

	printTransactionMenueScreen();
}

void exitApplication() {
	exit(0);
}

void selectMenueOption(int choice) {
	

	switch (choice) {
	case 1:
		printAllClientsScreen();
		break;
	case 2:
		addNewClientScreen();
		break;
	case 3:
		deleteClientScreen();
		break;
	case 4:
		updateClientScreen();
		break;
	case 5:
		findClientScreen();
		break;
	case 6:
		transactionsScreen();
		break;
	case 7:
		exitApplication();
		break;
	default:
		system("cls");
		cout << "Not a valid input, pleas wait shortly and you can again!"<<endl;
		cout << "\nMake sure you enter a valid option this time!";
		Sleep(3000);
		printMenueScreen();
	}

}


void printMenueScreen() {

	system("cls");
	int choice;

	const string line(75, '=');
	const string sep(75, '-');

	cout << "\n" << line << endl;
	cout << "||" << setw(43) << right << "MAIN MENU SCREEN"
		<< setw(30) << "||" << endl;
	cout << line << endl;

	cout << left;
	cout << "||   " << setw(68) << "[1]  Show Client List" << "||" << endl;
	cout << "||   " << setw(68) << "[2]  Add New Client" << "||" << endl;
	cout << "||   " << setw(68) << "[3]  Delete A Client" << "||" << endl;
	cout << "||   " << setw(68) << "[4]  Update Client Info" << "||" << endl;
	cout << "||   " << setw(68) << "[5]  Find Client" << "||" << endl;
	cout << "||   " << setw(68) << "[6]  Transactions" << "||" << endl;
	cout << "||   " << setw(68) << "[7]  Exit" << "||" << endl;

	cout << line << endl;
	cout << ">> What do you want to do? [1 to 7]: "; 
	cin >> choice;
	selectMenueOption(choice);
}


