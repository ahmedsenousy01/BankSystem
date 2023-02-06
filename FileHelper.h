#pragma once
#include <fstream>
#include "Client.h"
#include "Admin.h"
#include "Employee.h"
#include "Parser.h"

using namespace std;

class FileHelper
{

public:
  static void saveClient(Client c)
  {
    fstream file("D:\\prgramming\\BankSystem\\client.txt", ios::app);
    file << c.getName() << '&' << c.getPassword() << '&' << c.getBalance() << endl;
    file.close();
  }

  static void saveEmployee(Employee e)
  {
    fstream file("D:\\prgramming\\BankSystem\\employee.txt", ios::app);
    file << e.getName() << '&' << e.getPassword() << '&' << e.getSalary() << endl;
    file.close();
  }

  static void saveAdmin(Admin a)
  {
    fstream file("D:\\prgramming\\BankSystem\\admin.txt", ios::app);
    file << a.getName() << '&' << a.getPassword() << '&' << a.getSalary() << endl;
    file.close();
  }

  static void getClients()
  {
    fstream file("D:\\prgramming\\BankSystem\\client.txt", ios::in);
    string line;
    while (getline(file, line))
    {
      Client c = Parser::parseToClient(line);
      allClients.push_back(c);
    }
    file.close();
  }

  static void getEmployees()
  {
    fstream file("D:\\prgramming\\BankSystem\\employee.txt", ios::in);
    string line;
    while (getline(file, line))
    {
      Employee e = Parser::parseToEmployee(line);
      allEmployees.push_back(e);
    }
    file.close();
  }

  static void getAdmins()
  {
    fstream file("D:\\prgramming\\BankSystem\\admin.txt", ios::in);
    string line;
    while (getline(file, line))
    {
      Admin a = Parser::parseToAdmin(line);
      allAdmins.push_back(a);
    }
    file.close();
  }

  static void saveAllAdmins() {
    for(int i = 0; i < allAdmins.size(); i++) {
      saveAdmin(allAdmins[i]);
    }
  }

  static void saveAllClients() {
    for(int i = 0; i < allClients.size(); i++) {
      saveClient(allClients[i]);
    }
  }

  static void saveAllEmployees() {
    for(int i = 0; i < allEmployees.size(); i++) {
      saveEmployee(allEmployees[i]);
    }
  }

  static void clearFile(string fileName)
  {
    fstream file(fileName, ios::out | ios::trunc);
    file.close();
  }
};