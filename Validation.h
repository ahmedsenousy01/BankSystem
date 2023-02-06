#pragma once

#include <iostream>
#include <string>
using namespace std;

class Validation {
  public:
    static bool validateName(string name) {
      for(int i = 0; i < name.length(); i++) {
        if(!isalpha(name[i])) {
          return false;
        }
      }
      if(name.length() <= 20 && name.length() >= 5) {
        return true;
      } else {
        return false;
      }
    }

    static bool validatePassword(string password) {
      if(password.length() <=20 && password.length() >= 8) {
        return true;
      } else {
        return false;
      }
    }

    static bool validateBalance(double balance) {
      if(balance >= 1500) {
        return true;
      } else {
        return false;
      }
    }

    static bool validateSalary(double salary)
    {
      if (salary >= 5000)
      {
        return true;
      }
      else
      {
        return false;
      }
    }
};