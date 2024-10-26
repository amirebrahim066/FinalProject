#pragma once
#include<iostream>
#include<string>
#include"Employee.h"
#include"Client.h"

class Admin :public Employee {
public:
	Admin() : Employee() {}
	Admin(int id, string name, string pass, double salary)
		:Employee(id, name, pass, salary)
	{}

	void addEmployee(Employee& employee) {
		allEmployees.push_back(employee);
	}
	Employee* searchEmployee(int id) {
		for (eIt = allEmployees.begin(); eIt != allEmployees.end(); eIt++) {
			if (eIt->getId() == id)
				return eIt._Ptr;
		}
		return NULL;
	}
	void editEmployee(int id, string name, string password, double salary) {
		searchEmployee(id)->setName(name);
		searchEmployee(id)->setPassword(password);
		searchEmployee(id)->setSalary(salary);
	}
	void listEmployee() {
		for (eIt = allEmployees.begin(); eIt != allEmployees.end(); eIt++) {
			eIt->display_info();
			cout << "--------------------\n";
		}
	}

	void display_info() {
		cout << "\nAdmin Info\n===========" << endl
			<< "name :" << name << endl
			<< "id :" << id << endl
			<< "Salary: " << salary << endl;
	}

	/*static vector<Admin> allAdmins;
	static vector<Admin>::iterator aIt;*/


};

static vector<Admin> allAdmins;
static vector<Admin>::iterator aIt;









