#pragma once
#include <iostream>
#include<string>
using namespace std;
class Validation
{
public:
	static bool ValidateName(const string& name) {
	
		if (name.length() < 3 || name.length() > 20) {
			return false;
		}
		for (char c : name) {
			if (!isalpha(c)) {
				return false;
			}
		}
		return true;
	}
	static bool ValidatePassword(const string& password) {
		
		if (password.length() < 8 || password.length() > 20) {
			return false;
		}
		for (int i = 0; i < password.size(); i++)
		{
			if(isspace(password[i])) {
				return false;
			}
		}
		return true;
	}
	static bool ValidateBalance(double balance) {
		if (balance < 1500) {
			return false;
		}
		return true;
	}
	static bool ValidateSalary(double salary) {
		if (salary < 5000) {
			return false;
		}	
		return true;
	}
};

