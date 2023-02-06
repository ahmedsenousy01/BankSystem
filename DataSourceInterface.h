#pragma once
#include "Client.h"
#include "Employee.h"
#include "Admin.h"
#include <vector>

class DataSourceInterface
{
  // ahmed&ahmed123&2000
  public:
  // virtual void addClient(Client c) = 0;
  // virtual void addEmployee(Employee e) = 0;
  // virtual void addAdmin(Admin a) = 0;

  // virtual vector<Client> getAllClients() = 0;
  // virtual vector<Employee> getAllEmployees() = 0;
  // virtual vector<Admin> getAllAdmins() = 0;

  virtual void removeAllClients() = 0;
  virtual void removeAllEmployees() = 0;
  virtual void removeAllAdmins() = 0;
};