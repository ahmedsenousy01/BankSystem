#pragma once

#include <iostream>
#include "Employee.h"
#include "Admin.h"
#include "ClientManager.h"
using namespace std;


class EmployeeManager {
public:
  static void printEmployeeMenu()
  {
    system("cls");
    cout << "\t\t\t\t\t\tEmployee Functions\n";
    cout << "1-Add New Client\n";
    cout << "2-List Of All Clients\n";
    cout << "3-Search For A Client\n";
    cout << "4-Edit Client\n";
    cout << "5-Display\n";
    cout << "6-Update Password\n";
    cout << "7-Logout\n";
    cout << endl;
  }

  static void newClient(Employee * e) {
    string name, password;
    double balance;
    cout << "enter name:\n";
    cin >> name;
    cout << "enter password:\n";
    cin >> password;
    cout << "enter balance:\n";
    cin >> balance;

    Client * c = new Client();
    if(c->setName(name) && c->setPassword(password) && c->setBalance(balance)) {
      e->addClient(*c);
    } else {
      cout << "newClient not suitable\n";
    }
  }

  static void listAllClients(Employee * e) {
    for(int i = 0; i < allClients.size(); i++) {
      e->listClient(allClients[i]);
    }
  }

  static void searchForClient(Employee * e) {
    int id;
    cout << "enter id:\n";
    cin >> id;
    Client * c = e->searchClient(id);
    if(c) {
      c->display();
    } else {
      cout << "not found\n";
    }
  }

  static void editClientInfo(Employee *employee)
  {
    int x;
    int id;
    string name, password;
    double balance;
    cout << "Enter Id : ";
    cin >> id;

    Client *client = employee->searchClient(id);

    if (client != NULL)
    {
      cout << "\nWhat You Want To Edit : \n";
      cout << "1-All data\n";
      cout << "2-Name\n";
      cout << "3-Password\n";
      cout << "4-Balance\n";

      cout << "\nEnter Your Choise : ";
      cin >> x;

      switch (x)
      {
      case 1:
      {
        cout << "\nEnter New Name : ";
        cin >> name;
        cout << "\nEnter New Password : ";
        cin >> password;
        cout << "\nEnter New balance : ";
        cin >> balance;
        employee->editClient(id, name, password, balance);

        break;
      }
      case 2:
      {
        cout << "\nEnter New Name : ";
        cin >> name;
        password = client->getPassword();
        balance = client->getBalance();
        employee->editClient(id, name, password, balance);
        break;
      }
      case 3:
      {
        cout << "\nEnter New Password : ";
        cin >> password;
        name = client->getName();
        balance = client->getBalance();
        employee->editClient(id, name, password, balance);
        break;
      }
      case 4:
      {
        cout << "\nEnter New Balance : ";
        cin >> balance;
        name = client->getName();
        password = client->getPassword();
        employee->editClient(id, name, password, balance);
        break;
      }
      default:
      {

        cout << "\n*************************************\n";
        cout << "Your Choise Not Found In List\n";
        cout << "*************************************\n\n";
        editClientInfo(employee);
        break;
      }
      }
    }
    else
    {
      cout << "\n************************\n";
      cout << "Client not found\n\n";
      cout << "************************\n\n";
      cout << "\n1 - Try Again\n";
      cout << "2 - Return\n";
      int x;
      cout << "\nEnter Your Choise : ";
      cin >> x;
      system("cls");
      if (x == 1)
      {
        editClientInfo(employee);
      }
      else if (x == 2)
      {
        printEmployeeMenu();
        employeeOptions(employee);
      }
      else
      {
        cout << "\n*************************************\n";
        cout << "Your Choise Not Found In List\n";
        cout << "*************************************\n\n";
        system("pause");
        printEmployeeMenu();
        employeeOptions(employee);
      }
    }
  }

  static Employee *login(int id, string password)
  {
    Admin *a = new Admin();
    Employee *e = a->searchEmployee(id);
    if (e)
    {
      if (e->getPassword() == password)
      {
        return e;
      }
      else
      {
        cout << "Password incorrect" << endl;
        return NULL;
      }
    }
    else
    {
      cout << "id incorrect" << endl;
      return NULL;
    }
  }

  static bool employeeOptions(Employee *employee)
  {
    int x = 0;

    cout << "Enter your choise : ";

    cin >> x;

    switch (x)
    {
    case 1:
    {
      system("cls");
      newClient(employee);
      break;
    }
    case 2:
    {
      system("cls");
      listAllClients(employee);
      break;
    }
    case 3:
    {
      system("cls");
      searchForClient(employee);
      break;
    }
    case 4:
    {
      system("cls");
      editClientInfo(employee);
      break;
    }
    case 5:
    {
      system("cls");
      employee->display();
      break;
    }
    case 6:
    {
      system("cls");
      ClientManager::updatePassword(employee);
      break;
    }
    case 7:
    {
      return true;
    }
    default:
    {
      cout << "\nYour Choise Not Found In List\n";
      employeeOptions(employee);
    }
    }
    return false;
  }
};
