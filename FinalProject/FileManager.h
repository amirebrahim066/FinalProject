#pragma once

#include "DataSourceInterface.h"
#include"FilesHelper.h"

class FileManager : public DataSourceInterface {
public:
		
	/*static vector<Client> allClients;
	static vector<Client>::iterator clIt;*/
	/*static vector<Employee> allEmployees;
	static vector<Employee>::iterator eIt;*/
	/*static vector<Admin> allAdmins;
	static vector<Admin>::iterator aIt;*/

	void addClient(Client client) {
		FilesHelper::saveClient(client);
	}
	void addEmployee(Employee employee) {
		FilesHelper::saveEmployee("Employees.txt", "EmployeeLastId.txt", employee);
	}
	void addAdmin(Admin admin) {
		FilesHelper::saveEmployee("Admins.txt", "AdminLastId.txt", admin);
	}
	void getAllClients() {
		FilesHelper::getClients();
	}
	void getAllEmployees() {
		FilesHelper::getEmployees();   //remove all static
	}
	void getAllAdmins() {
		FilesHelper::getAdmins();
	}
	void removeAllClients() {
		FilesHelper::clearFile("Clients.txt", "ClientLastId.txt");
	}
	void removeAllEmployees() {
		FilesHelper::clearFile("Employees.txt", "EmployeeLastId.txt");
	}
	void removeAllAdmins() {
		FilesHelper::clearFile("Admins.txt", "AdminLastId.txt");
	}

	 void getAllData() {
		getAllClients();
		getAllEmployees();
		getAllAdmins();
	}
	 void updateClients() {
		removeAllClients();
		for (clIt = allClients.begin(); clIt != allClients.end(); clIt++) addClient(*clIt);
	}
	 void updateEmployees() {
		removeAllEmployees();
		for (eIt = allEmployees.begin(); eIt != allEmployees.end(); eIt++) addEmployee(*eIt);
	}
	 void updateAdmins() {
		removeAllAdmins();
		for (aIt = allAdmins.begin(); aIt != allAdmins.end(); aIt++) addAdmin(*aIt);
	}

};


