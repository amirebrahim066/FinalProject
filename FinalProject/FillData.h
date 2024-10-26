#pragma once
#include<iostream>
#include"Validation.h"
using namespace std;
class FillData
{
public:
	//enterName
	static string enterName() {
		string name;
		cout << "Enter name: ";
		cin >> name;
		while (!Validation::ValidateName(name)) {
			cout << "invalid name\n";
			cout << "name must be 5 to 20 char\n";
			cout << "enter name: ";
			//cin >> name;
			getline(cin, name);
		}
		return name;
	}

	//enterPassword
	static string enterPassword() {
		string password;
		cout << "enter password: ";
		cin >> password;
		while (!Validation::ValidatePassword(password)) {

			cout << "invalid password\n";
			cout << "password must be 8 to 20 character\n";
			cout << "enter password: ";
			cin >> password;

		}
		return password;
	}

	//enterbalance 
	static double enterBalance() {

		double balance;
		cout << "enter balance: ";
		cin >> balance;
		while (balance < 1500) {
			cout << "invalid balance\n";
			cout << "balance must be at least 1500\n";
			cout << "enter balance : ";
			cin >> balance;
		}
		return balance;

	}

	//enterSalary
	static double enterSalary() {
		double salary;
		cout << "enetr salary: ";
		cin >> salary;
		while (salary < 5000) {
			cout << "invalid salary\n";
			cout << "salary must be at least 5000\n";
			cout << "enter salary: ";
			cin >> salary;
		}
		return salary;
	}
};

