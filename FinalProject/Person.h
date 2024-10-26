#pragma once
#include <iostream>
#include<string>
#include <vector>
#include "Validation.h"
using namespace std;

class Person {

	//Attributes
protected:
	string name;
	int id;
	string password;
	double salary;

public:

	//default constructor
	Person() : id(0),salary(0) {}

	// parametrize constructor
	Person(int id,string name , string password) : id(id) {
		if (Validation::ValidateName(name)) {
			this->name = name;
		}
		
		if (Validation::ValidatePassword(password)) {
			this->password = password;
		}
	}
	Person(string name , string password) : id(id) {
		if (Validation::ValidateName(name)) {
			this->name = name;
		}
		
		if (Validation::ValidatePassword(password)) {
			this->password = password;
		}
	}
	//setters
	void setName(string name) {
		if (Validation::ValidateName(name)) {
			this->name = name;
		}
	}
	void setPassword(string password) {
		if (Validation::ValidatePassword(password)) {
			this->password = password;
		}
	}
	void setId(int id) {
		this->id = id;
	}
	void setSalary(double salary) {
		if (Validation::ValidateSalary(salary)) {
			this->salary = salary;
		}
	}
	//getters     
	string getName() {
		return name;
	}
	int getId() {
		return id;
	}
	string getPassword() {
		return password;
	}
	//method
	virtual void display_info() = 0; 


};
