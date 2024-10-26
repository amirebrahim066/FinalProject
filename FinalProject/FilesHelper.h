#pragma once
#include <fstream>
#include <sstream>
#include<iostream>
#include<vector>
#include"Parser.h"

class FilesHelper {
private:
	static void saveLast(string fileName, int id) {
		ofstream file(fileName, ios::out);  
		if (file.is_open()) {
			file << id;  
			file.close();
		}
		else {
			cerr << "Error: Could not open " << fileName << " for writing." << endl;
		}
	}
public:
	//static vector<Client> allClients;
	//static vector<Employee> allEmployees;
	//static vector<Admin> allAdmins;

	static int getLast(string fileName) {
		ifstream file(fileName);  
		int id = 0;  
		if (file.is_open()) {
			file >> id;  
			if (file.fail()) {
				cerr << "Error: Failed to read ID from " << fileName << endl;
				id = 0;  
			}
			file.close();
		}
		else {
			cerr << "Error: Could not open " << fileName << " for reading." << endl;
		}
		return id;
	}
	static void saveClient(Client c) {
		int id = getLast("ClientLastId.txt");
		fstream file;
		file.open("Clients.txt", ios::app);
		file << id + 1 << '&' << c.getName() << '&' << c.getPassword() << '&' << c.getBalance() << "\n"; //overload constructor without id
		file.close();
		saveLast("ClientLastId.txt", id + 1);
	}
	static void saveEmployee(string fileName, string lastIdFile, Employee e) {
		int id = getLast(lastIdFile);
		fstream file;
		file.open(fileName, ios::app);
		file << e.getId() << '&' << e.getName() << '&' << e.getPassword() << '&' << e.getSalary() << "\n";
		file.close();
		saveLast(lastIdFile, id + 1);
	}
	static void getClients() {
		string line;
		ifstream file;
		file.open("Clients.txt");
		while (getline(file, line)) {
			Client c = Parser::parseToClient(line);
			allClients.push_back(c);
		}
		file.close();
	}
	static void getEmployees() {
		string line;
		ifstream file;
		file.open("Employees.txt");
		while (getline(file, line)) {
			Employee e = Parser::parseToEmployee(line);
			allEmployees.push_back(e);
		}
		file.close();
	}
	static void getAdmins() {
		string line;
		ifstream file;
		file.open("Admins.txt");
		while (getline(file, line)) {
			Admin a = Parser::parseToAdmin(line);
			allAdmins.push_back(a);
		}
		file.close();
	}
	static void clearFile(string fileName, string lastIdFile) {
		fstream file1, file2;
		file1.open(fileName, ios::out);
		file1.close();
		file2.open(lastIdFile, ios::out);
		file2 << 0;
		file2.close();
	}
};