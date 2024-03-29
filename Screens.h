#pragma once 

#include <iostream>
#include "Admin.h"
#include "Employee.h"
#include "Client.h"
#include "AdminManager.h"
#include "EmployeeManager.h"
#include "ClientManager.h"
#include "FileManager.h"
#include <windows.h>
using namespace std;

class Screens {
public:
  static void loginOptions()
  {
    cout << "\t\t\t\t\t\tLogin As\n";
    cout << "1 - Client\n\n";
    cout << "2 - Employee\n\n";
    cout << "3 - Admin\n\n";
    cout << "4 - Exit\n\n";
  }
  static int loginAs()
  {
    int x;
    cout << "Login As : ";
    cin >> x;

    switch (x)
    {
    case 1:
    {
      return 1;
      break;
    }
    case 2:
    {
      return 2;
      break;
    }
    case 3:
    {
      return 3;
      break;
    }
    case 4:
    {
      return 4;
      break;
    }
    default:
    {
      Invalid(x);
      break;
    }
    }
    return 0;
  }
  static void Invalid(int c)
  {
    cout << "\n\n*************************************\n";
    cout << "Your Choise Not Found In List\n";
    cout << "*************************************\n\n";
    loginAs();
  }
  static void LoginClient()
  {
    cout << "\t\t\t\t\t\tLogin Client Page\n";
    int id;
    string password;
    cout << "Id : ";
    cin >> id;
    cout << "Password : ";
    cin >> password;
    Client *client = ClientManager::login(id, password);
    if (client != NULL)
    {
      ClientManager::printClientMenu();
      if (ClientManager::clientOptions(client))
      {
        system("cls");
        loginOptions();
        loginScreen(loginAs());
      }
    }
    else
    {
      cout << "\n1 - Try Again\n";
      cout << "2 - Return\n";
      int x;
      cout << "\nEnter Your Choise : ";
      cin >> x;
      system("cls");
      if (x == 1)
      {
        LoginClient();
      }
      else if (x == 2)
      {
        system("cls");
        loginOptions();
        loginScreen(loginAs());
      }
      else
      {
        cout << "\n\n*************************************\n";
        cout << "Your Choise Not Found In List\n";
        cout << "*************************************\n\n";
        system("pause");
        system("cls");
        loginOptions();
        loginScreen(loginAs());
      }
    }
  }
  static void LoginEmployee()
  {
    cout << "\t\t\t\t\t\tLogin Employee Page\n";
    int id;
    string password;
    cout << "Id : ";
    cin >> id;
    cout << "Password : ";
    cin >> password;
    Employee *employee = EmployeeManager::login(id, password);
    if (employee != NULL)
    {
      EmployeeManager::printEmployeeMenu();
      if (EmployeeManager::employeeOptions(employee))
      {
        system("cls");
        loginOptions();
        loginScreen(loginAs());
      }
    }
    else
    {
      cout << "\n1 - Try Again\n";
      cout << "2 - Return\n";
      int x;
      cout << "\nEnter Your Choise : ";
      cin >> x;
      if (x == 1)
      {
        LoginEmployee();
      }
      else if (x == 2)
      {
        system("cls");
        loginOptions();
        loginScreen(loginAs());
      }
      else
      {
        cout << "\n\n*************************************\n";
        cout << "Your Choise Not Found In List\n";
        cout << "*************************************\n\n";
        system("pause");
        system("cls");
        loginOptions();
        loginScreen(loginAs());
      }
    }
  }
  static void LoginAdmin()
  {
    cout << "\t\t\t\t\t\tLogin Admin Page\n";
    int id;
    string password;
    cout << "Id : ";
    cin >> id;
    cout << "Password : ";
    cin >> password;

    Admin *admin = AdminManager::login(id, password);
    if (admin != NULL)
    {
      AdminManager::printAdminMenu();
      if (AdminManager::AdminOptions(admin))
      {
        system("cls");
        loginOptions();
        loginScreen(loginAs());
      }
    }
    else
    {
      cout << "\n1 - Try Again\n";
      cout << "2 - Return\n";
      int x;
      cout << "\nEnter Your Choise : ";
      cin >> x;
      if (x == 1)
      {
        LoginAdmin();
      }
      else if (x == 2)
      {
        system("cls");
        loginOptions();
        loginScreen(loginAs());
      }
      else
      {
        cout << "\n\n*************************************\n";
        cout << "Your Choise Not Found In List\n";
        cout << "*************************************\n\n";
        system("pause");
        system("cls");
        loginOptions();
        loginScreen(loginAs());
      }
    }
  }
  static void loginScreen(int c)
  {
    switch (c)
    {

    case 1:
    {
      system("cls");
      LoginClient();
      break;
    }
    case 2:
    {
      system("cls");
      LoginEmployee();
      break;
    }
    case 3:
    {
      system("cls");
      LoginAdmin();
      break;
    }
    case 4:
    {
      FileManager::saveData();
    }
    }
  }
  static void BankName()
  {
    cout << "\n\n\n\n\n\n\n\n\n";
    cout << "\t\t      ##     ##      ######      ##     ##     #######   ########  ####    ##  ##   ##\n";
    cout << "\t\t      ###   ###     ##    ##     ###   ###     ##    ##  ##    ##  ## ##   ##  ##  ##\n";
    cout << "\t\t      ## # # ##     ########     ## # # ##     #######   ########  ##  ##  ##  ## #\n";
    cout << "\t\t      ##  #  ##     ##    ##     ##  #  ##     ##    ##  ##    ##  ##   ## ##  ##  ##\n";
    cout << "\t\t      ##     ##  @  ##    ##  @  ##     ##     #######   ##    ##  ##    ####  ##   ##\n   ";
    Sleep(2500);
  }
  static void Welcome()
  {
    cout << "\n\n\n\n\n\n\n\n\n";
    cout << "\t\t\t##       ##   ######    ##      #######  ########   ##     ##   ######\n";
    cout << "\t\t\t##   #   ##   ##        ##      ##       ##    ##   ###   ###   ##\n";
    cout << "\t\t\t##  # #  ##   ######    ##      ##       ##    ##   ## # # ##   ######\n";
    cout << "\t\t\t## #   # ##   ##        ##      ##       ##    ##   ##  #  ##   ##\n";
    cout << "\t\t\t###     ###   ######    ######  #######  ########   ##     ##   ######\n";
    Sleep(2500);
  }

  static void runApp() {
    Welcome();
    // Sleep(2500);
    system("cls");
    BankName();
    // Sleep(2500);
    system("cls");
    FileManager::getData();
    loginOptions();
    loginScreen(loginAs());
  }
};