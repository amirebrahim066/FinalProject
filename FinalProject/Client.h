#pragma once
#include <iostream>
#include<string>
#include <vector>
#include"Person.h"
class Client :public Person {
	//Attributes
private:
	double balance;

public:
	//default
	Client() :balance(0) {}
	// parametrize constructor
	Client(int id, string name, string password, double initialBalance) : Person(id, name, password), balance(initialBalance) {
		if (Validation::ValidateBalance(initialBalance)) {
			balance = initialBalance;
		}
		else {
			balance = 1500;
		}
	}
	Client( string name, string password, double initialBalance) : Person( name, password) {
		if (Validation::ValidateBalance(initialBalance)) {
			balance = initialBalance;
		}
		else {
			balance = 1500;
		}
	}
	//getters
	double getBalance() {
		return balance;
	}
	void setBalance(double balance) {
		this->balance = balance;
	}
	//method
	void Deposit(double amount) {
		if (amount > 0) {
			balance += amount;
			cout << "Successfully Deposited: " << amount << " New balance: " << balance << endl;
		}
		else {
			cout << "Failed to Deposit , Deposit cant be negative" << endl;
		}
	}
	void Withdraw(double amount) {
		if (amount <= balance && amount > 0) {
			balance -= amount;
			cout << "Withdrawn: " << amount << " New balance: " << balance << endl;
		}
		else {
			cout << "Failed to withdraw , Withdrawl cant exceed balance " << endl;
		}
	}
	void TransferTo(double amount, Client& recipient) {
		if (amount > 0 && amount <= balance) {
			balance -= amount;
			recipient.Deposit(amount);
			cout << "Transferred: " << amount << " to " << recipient.getName() << " New balance: " << balance << endl;
		}
		else {
			cout << "Failed to Transfer." << endl;
		}
	}

	void Checkbalance() {
		cout << "balance = " << balance << endl;
	}

	void display_info() {
		cout << "\nClient Info\n===========" << endl
			<< "name :" << name << endl
			<< "id :" << id << endl
			<< "balance = " << balance << endl;

	}


};

static vector<Client> allClients;
static vector<Client>::iterator clIt;



