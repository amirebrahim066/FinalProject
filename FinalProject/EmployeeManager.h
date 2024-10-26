#pragma once
#include"ClientManager.h"
#include"FillData.h"


class EmployeeManager
{
    private:
        // A list of clients stored in a vector

    public:
        //  Print the Employee menu
       /* static vector<Employee> allEmployees;
        static vector<Employee>::iterator eIt;*/
        static vector<Employee*> Employees;
      
        static void printEmployeeMenu() {
            cout << "(1) Display my info" << endl;
            cout << "(2) Update Password" << endl;
            cout << "(3) Add new client" << endl;
            cout << "(4) Search for client" << endl;
            cout << "(5) List all clients" << endl;
            cout << "(6) Edit client info" << endl;
        }
        //back 
        static void back(Employee* employee) {
            cout << endl;
            system("pause");
            employeeOptions(employee);
        }

        //new client
        static void newClient(Employee* employee) {
            FileManager f;
            Client client;
            client.setId(FilesHelper::getLast("ClientLastId.txt") + 1);
            string password;
            client.setName(FillData::enterName());
            client.setPassword(FillData::enterPassword());
            client.setBalance(FillData::enterBalance());
            employee->addClient(client);
            f.updateClients();
            
            cout << "\nClient added successfully.\n";
        }

        //search for client
        static void searchForClient(Employee* employee) {
            int id;
            system("cls");
            cout << "Enter client id: ";
            cin >> id;
            if (employee->searchClient(id) == NULL) cout << "\nClient not found.\n";
            else employee->searchClient(id)->display_info();
        }

        //list all clients
        static void listAllClients(Employee* employee) {
            system("cls");
            cout << "All clients: \n" << endl;
            employee->listClient();
        }

        //edit client info
        static void editClientInfo(Employee* employee) {
            FileManager f;
            int id;
            system("cls");
            cout << "Enter client id: ";
            cin >> id;
            if (employee->searchClient(id) == NULL) cout << "\nClient not found.\n";
            else {
                string name = FillData::enterName();
                string password = FillData::enterPassword();
                double balance = FillData::enterBalance();
                employee->editClient(id, name, password, balance);
                f.updateClients();
               
                cout << "\nClient info updated.\n";
            }
        }

        //login
        static Employee* login(int id, string password) {
            for (eIt = allEmployees.begin(); eIt != allEmployees.end(); eIt++) {
                if (eIt->getId() == id && eIt->getPassword() == password) return eIt._Ptr;
            }
            return NULL;
        }
        //empployee options
        static bool employeeOptions(Employee* employee) {
            FileManager f;
            printEmployeeMenu();
            cout << "Your choice is: ";
            int choice;
            cin >> choice;
            switch (choice) {
            case 1:
                system("cls");
                employee->display_info();
                break;
            case 2:
                ClientManager::updatePassword(employee);
                f.updateEmployees();
                break;
            case 3:
                newClient(employee);
                break;
            case 4:
                searchForClient(employee);
                break;
            case 5:
                listAllClients(employee);
                break;
            case 6:
                editClientInfo(employee);
                break;
            case 7:
                return false;
                break;
            default:
                system("cls");
                employeeOptions(employee);
                return true;
            }
            back(employee);
            return true;
        }

    };

