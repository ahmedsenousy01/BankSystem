#pragma once
#include <iostream>
#include <vector>
#include "Person.h"
#include "Client.h"
#include "Validation.h"

using namespace std;

class Employee : public Person {
  protected:
    static inline int counter = 22000;
    double salary;
  public:
  // constructors
    Employee() : Person()
    {
      counter++;
      this->id = counter;
    }
    Employee(string name, string password, double salary) : Person(name, password)
    {
      setSalary(salary);
      counter++;
      this->id = counter;
    }

  // setters & getters
    bool setSalary(double salary) {
      if (Validation::validateSalary(salary))
      {
        this->salary = salary;
        return true;
      }
      else
      {
        cout << "Invalid salary (salary must be more than 5000)" << endl;
        return false;
      }
    }
    double getSalary() {
      return this->salary;
    }

  // other methods
    void display() {
      Person::display();
      cout << "Salary: " << this->salary << endl;
    }

    void addClient(Client& c) {
      allClients.push_back(c);
    }

    Client* searchClient(int id) {
      for(int i = 0; i < allClients.size(); i++) {
        if(allClients[i].getId() == id) {
          Client* c = &allClients[i];
          return c;
        }
      }
      return nullptr;
    }

    void listClient(Client c) {
      cout << c.getId() << endl;
      cout << c.getName() << endl;
      cout << c.getPassword() << endl;
      cout << c.getBalance() << endl;
    }

    void editClient(int id, string name, string password, double balance) {
      Client* c = searchClient(id);
      c->setName(name);
      c->setPassword(password);
      c->setBalance(balance);
    }
};

static vector<Employee> allEmployees;