#pragma once
#include <string>
#include <vector>
#include "Employee.h"

class Admin : public Employee {
  private:
    static inline int counter = 11000;
  public:
    Admin() : Employee() {
      counter++;
      Employee::counter--;
      this->id = counter;
    }

    Admin(string name, string password, double salary) : Employee(name, password, salary) {
      counter++;
      Employee::counter--;
      this->id = counter;
    }

    //other methods
    void addEmployee(Employee &c)
    {
      allEmployees.push_back(c);
    }

    Employee *searchEmployee(int id)
    {
      for (int i = 0; i < allEmployees.size(); i++)
      {
        if (allEmployees[i].getId() == id)
        {
          Employee *c = &allEmployees[i];
          return c;
        }
      }
      return nullptr;
    }

    void listEmployee(Employee c)
    {
      cout << c.getId() << endl;
      cout << c.getName() << endl;
      cout << c.getPassword() << endl;
      cout << c.getSalary() << endl;
    }

    void editEmployee(int id, string name, string password, double salary)
    {
      Employee *c = searchEmployee(id);
      c->setName(name);
      c->setPassword(password);
      c->setSalary(salary);
    }
};

static vector<Admin> allAdmins;

