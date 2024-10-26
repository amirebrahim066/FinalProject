#pragma once
#include <iostream>
#include<string>
#include <vector>
#include <iterator>
#include"Client.h"
#include"Person.h"
using namespace std;

class Employee : public Person {
protected:
	
	double salary;
public:
	//default constuctor
	Employee() :salary(0) {}

	//parametrized constructor
	Employee(int id, string name, string password, double salary) : Person(id, name, password), salary(salary) {
		if (Validation::ValidateSalary(salary)) {
			this->salary = salary;

		}
		else {
			this->salary = 5000;
		}
	}
	//setters

	void setSalary(double salary) {
		if (Validation::ValidateSalary(salary)) {
			this->salary = salary;
		}
	}
	//getters
	double getSalary() {
		return salary;
	}
	void display_info() {
		cout << "\nEmployee Info\n===========" << endl
			<< "name :" << name << endl
			<< "id :" << id << endl
			<< "Salary: " << salary << endl;
	}

	void addClient(Client& client) {
		allClients.push_back(client);

	}

	Client* searchClient(int id) {
		for (clIt = allClients.begin(); clIt != allClients.end(); clIt++) {
			if (clIt->getId() == id) return clIt._Ptr;
		}	
		return NULL;
	}

	void listClient() {
		for (clIt = allClients.begin(); clIt != allClients.end(); clIt++) {
			clIt->display_info();
			cout << "-------------------------\n";
		}
	}

	void editClient(int id, string name, string password, double balance) {
		searchClient(id)->setName(name);
		searchClient(id)->setPassword(password);
		searchClient(id)->setSalary(balance);
	}
		
	//static vector<Client> allClients;
	
	//static vector<Client>::iterator clIt;
	//static vector<Employee> allEmployees;
	//static vector<Employee>::iterator eIt;
};

static vector<Employee> allEmployees;
static vector<Employee>::iterator eIt;