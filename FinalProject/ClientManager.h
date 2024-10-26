#pragma once
#include <iostream>
#include <string>
#include <vector>
#include"FileManager.h"
#include"Client.h"
using namespace std;

class ClientManager
{
public:
    static vector<Client*> clients;

    //  Print the client menu
    static void printClientMenu() {
        cout << "===== Client Menu =====" << endl;
        cout << "1. Check Balance" << endl;
        cout << "2. Withdraw" << endl;
        cout << "3. Deposit" << endl;
        cout << "4. Update Password" << endl;
        cout << "5. Logout" << endl;
        cout << "=======================" << endl;
    }

    //  Update the password for a given Person
    static void updatePassword(Person* person) {
        string newPassword;
        cout << "Enter new password: ";
        cin >> newPassword;
        person->setPassword(newPassword);
        cout << "Password updated successfully." << endl;

    }

    //  Login with id and password, returns a Client pointer if successful
    //static Client* login(int id, const string& password) {
    //    for (Client& client : Employee::allClients) { // Using reference to avoid copying
    //        if (client.getId() == id && client.getPassword() == password) {
    //            cout << "Login successful!" << endl;
    //            return &client; // Return a pointer to the client object
    //        }
    //    }
    //    cout << "Invalid ID or password!" << endl;
    //    return nullptr;
    //}

    static Client* login(int id, string password) {
        for (clIt = allClients.begin(); clIt != allClients.end(); clIt++) {
            if (clIt->getId() == id && clIt->getPassword() == password) return clIt._Ptr;
        }
        return NULL;
        
    }

    //  Client options menu
    static bool clientOptions(Client* client) {
        while (true) {
            printClientMenu();
            int choice;
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
            case 1:
                client->Checkbalance();
                break;
            case 2:
                double amount;
                cout << "Enter the amount to withdraw: ";
                cin >> amount;
                client->Withdraw(amount);
                break;
            case 3:
                double Amount;
                cout << "Enter the amount to deposit: ";
                cin >> Amount;
                client->Deposit(Amount);
                break;
            case 4:
                updatePassword(client);
                break;
            case 5:
                cout << "Logging out..." << endl;
                return false;
            default:
                cout << "Invalid choice. Please try again." << endl;
            }
        }
    }
    
};

