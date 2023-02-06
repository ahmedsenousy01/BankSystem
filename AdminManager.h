#pragma once

#include <iostream>
#include "EmployeeManager.h"
#include "Employee.h"
#include "Admin.h"
using namespace std;

class AdminManager {
  public:
  static void printAdminMenu()
  {
    system("cls");
    cout << "\t\t\t\t\t\tAdmin Functions\n";
    cout << "1-Add New Client\n";
    cout << "2-List Of All Clients\n";
    cout << "3-Search For A Client\n";
    cout << "4-Edit Client\n";
    cout << "5-Add New Employee\n";
    cout << "6-List Of All Employee\n";
    cout << "7-Search For An Employee\n";
    cout << "8-Edit Employee\n";
    cout << "9-Display\n";
    cout << "10-Update Password\n";
    cout << "11-Logout\n";
    cout << endl;
  }

  static Admin *login(int id, string password)
  {
    Admin *a = searchForAdmin(id);
    if (a)
    {
      if (a->getPassword() == password)
      {
        return a;
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

  static Admin *searchForAdmin(int id) {
    Admin *a;
    for(int i = 0; i < allAdmins.size(); i++) {
      if(allAdmins[i].getId() == id) {
        a = &allAdmins[i];
        return a;
      }
    }
    return nullptr;
  }

  static void newEmployee(Admin *a)
  {
    string name, password;
    double salary;
    cout << "enter name:\n";
    cin >> name;
    cout << "enter password:\n";
    cin >> password;
    cout << "enter salary:\n";
    cin >> salary;

    Employee *e = new Employee();
    if (e->setName(name) && e->setPassword(password) && e->setSalary(salary))
    {
      a->addEmployee(*e);
    }
    else
    {
      cout << "new Employee not suitable\n";
    }
  }

  static void listAllEmployees(Admin *a)
  {
    for (int i = 0; i < allEmployees.size(); i++)
    {
      a->listEmployee(allEmployees[i]);
    }
  }

  static void searchForEmployee(Admin *a)
  {
    int id;
    cout << "enter id:\n";
    cin >> id;
    Employee *e = a->searchEmployee(id);
    if (e)
    {
      e->display();
    }
    else
    {
      cout << "not found\n";
    }
  }

  static void editEmployeeInfo(Admin *a)
  {
    int x;
    int id;
    string name, password;
    double salary;
    cout << "Enter Id : ";
    cin >> id;

    Employee *e = a->searchEmployee(id);

    if (e != NULL)
    {
      cout << "\nWhat You Want To Edit : \n";
      cout << "1-All data\n";
      cout << "2-Name\n";
      cout << "3-Password\n";
      cout << "4-Salary\n";

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
        cout << "\nEnter New salary : ";
        cin >> salary;
        a->editEmployee(id, name, password, salary);

        break;
      }
      case 2:
      {
        cout << "\nEnter New Name : ";
        cin >> name;
        password = e->getPassword();
        salary = e->getSalary();
        a->editEmployee(id, name, password, salary);
        break;
      }
      case 3:
      {
        cout << "\nEnter New Password : ";
        cin >> password;
        name = e->getName();
        salary = e->getSalary();
        a->editClient(id, name, password, salary);
        break;
      }
      case 4:
      {
        cout << "\nEnter New Balance : ";
        cin >> salary;
        name = e->getName();
        password = e->getPassword();
        a->editEmployee(id, name, password, salary);
        break;
      }
      default:
      {

        cout << "\n*************************************\n";
        cout << "Your Choise Not Found In List\n";
        cout << "*************************************\n\n";
        editEmployeeInfo(a);
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
        editEmployeeInfo(a);
      }
      else if (x == 2)
      {
        printAdminMenu();
        AdminOptions(a);
      }
      else
      {
        cout << "\n*************************************\n";
        cout << "Your Choise Not Found In List\n";
        cout << "*************************************\n\n";
        system("pause");
        printAdminMenu();
        AdminOptions(a);
      }
    }
  }

  static bool AdminOptions(Admin *admin)
  {
    int x = 0;

    cout << "Enter your choise : ";

    cin >> x;

    switch (x)
    {
    case 1:
    {
      system("cls");
      EmployeeManager::newClient(admin);
      break;
    }
    case 2:
    {
      system("cls");
      EmployeeManager::listAllClients(admin);
      break;
    }
    case 3:
    {
      system("cls");
      EmployeeManager::searchForClient(admin);
      break;
    }
    case 4:
    {
      system("cls");
      EmployeeManager::editClientInfo(admin);
      break;
    }
    case 5:
    {
      system("cls");
      newEmployee(admin);
      break;
    }
    case 6:
    {
      system("cls");
      listAllEmployees(admin);
      break;
    }
    case 7:
    {
      system("cls");
      searchForEmployee(admin);
      break;
    }
    case 8:
    {
      system("cls");
      editEmployeeInfo(admin);
      break;
    }
    case 9:
    {
      system("cls");
      admin->display();
      break;
    }
    case 10:
    {
      system("cls");
      ClientManager::updatePassword(admin);
      break;
    }
    case 11:
    {
      return true;
    }
    default:
    {
      cout << "\n*************************************\n";
      cout << "Your Choise Not Found In List\n";
      cout << "*************************************\n\n";
      AdminOptions(admin);
    }
    }
      return false;
  }
};