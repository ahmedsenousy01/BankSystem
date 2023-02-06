#pragma once
#include <iostream>
#include <string>
#include "Person.h"
#include "Validation.h"

using namespace std;

class Client : public Person {
  private:
    static inline int counter = 33000;
    double balance;
  public:
    double getBalance() { return this->balance; }
    bool setBalance(double balance) {
      if (Validation::validateBalance(balance))
      {
        this->balance = balance;
        return true;
      }
      else
      {
        cout << "Invalid balance (balance must be more than 1500)" << endl;
        return false;
      }
    }

    Client() : Person() {
      counter++;
      this->id = counter;
    }

    Client(string name, string password, double balance) : Person(name, password) {
      setBalance(balance);
      counter++;
      this->id = counter;
    }

    void deposit(double amount) {
      setBalance(getBalance() + amount);
    }

    void withdraw(double amount) {
      setBalance(getBalance() - amount);
    }

    void transferTo(double amount, Client& recipient) {
      withdraw(amount);
      recipient.deposit(amount);
    }

    void checkBalance() {
      cout << "Balance: " << getBalance() << endl;
    }
};

static vector<Client> allClients;