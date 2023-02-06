#pragma once

#include <iostream>
#include "Person.h"
#include "Client.h"
#include "Employee.h"
using namespace std;

class ClientManager
{
public:
  static void printClientMenu()
  {
    system("cls");
    cout << "\t\t\t\t\t\tClient Functions\n";
    cout << "1-Deposit\n";
    cout << "2-Withdraw\n";
    cout << "3-transferTo\n";
    cout << "4-checkBalance\n";
    cout << "5-Display\n";
    cout << "6-Update Password\n";
    cout << "7-Logout\n";
    cout << endl;
  }

  static void updatePassword(Person *p)
  {
    string password;
    cout << "enter new password" << endl;
    cin >> password;
    p->setPassword(password);
  }

  static Client *login(int id, string password)
  {
    Employee *e = new Employee();
    Client *c = e->searchClient(id);
    if (c)
    {
      if (c->getPassword() == password)
      {
        return c;
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

  static bool clientOptions(Client *_Client)
  {
    int x = 0;

    cout << "Enter your choise : ";

    cin >> x;

    switch (x)
    {
    case 1:
    {
      system("cls");
      double amount = 1500;
      cout << "Enter Amount To Deposit : ";
      cin >> amount;
      _Client->deposit(amount);
      break;
    }
    case 2:
    {
      system("cls");
      double amount = 1500;
      cout << "Enter Amount To Withdraw : ";
      cin >> amount;
      _Client->withdraw(amount);
      break;
    }
    case 3:
    {
      system("cls");
      double amount = 1500;
      Client *otherClient;
      Employee *e = new Employee();
      int id = 0;
      cout << "Enter Client Id you want TransferTo : ";
      cin >> id;
      otherClient = e->searchClient(id);
      cout << "Enter Amount To transferTo : ";
      cin >> amount;
      if (otherClient != NULL)
      {
        _Client->transferTo(amount, *otherClient);
      }
      else
      {
        cout << "\n******************************************\n";
        cout << "The Other Client Not Found In System\n";
        cout << "******************************************\n\n";
      }
      break;
    }
    case 4:
    {
      system("cls");
      _Client->checkBalance();
      break;
    }
    case 5:
    {
      system("cls");
      _Client->display();
      break;
    }
    case 6:
    {
      system("cls");
      updatePassword(_Client);
      break;
    }
    case 7:
    {
      return true;
    }
    default:
    {
      cout << "\n*************************************\n";
      cout << "Your Choise Not Found In List\n";
      cout << "*************************************\n\n";
      clientOptions(_Client);
    }
    }
      return false;
  }
};