#pragma once
#include <string>
#include <iostream>
#include "Validation.h"
using namespace std;

class Person {
  protected:
    int id;
  private:
    string name, password;
  public:

    Person() {};

    Person(string name, string password) {
      setName(name);
      setPassword(password);
    }

    // getters
    int getId() { return this->id; }
    string getName() { return this->name; }
    string getPassword() { return this->password; }

    // setters
    bool setName(string name) {
      if(Validation::validateName(name)) {
        this->name = name;
        return true;
      } else {
        cout << "Invalid name (name must be 5 to 20 chars and alphabetic only)" << endl;
        return false;
      }
    }

    bool setPassword(string password) {
      if (Validation::validatePassword(password))
      {
        this->password = password;
        return true;
      }
      else
      {
        cout << "Invalid password (password must be 8 to 20 chars)" << endl;
        return false;
      }
    }

    void display() {
      cout << "name" << " " << this->name << endl;
      cout << "id" << " " << this->id << endl;
    }
};