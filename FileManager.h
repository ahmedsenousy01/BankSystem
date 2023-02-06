#pragma once
#include "DataSourceInterface.h"
#include "FileHelper.h"

class FileManager : public DataSourceInterface
{
public:
  static void addClient(Client c)
  {
    FileHelper::saveClient(c);
  }

  static void addEmployee(Employee e)
  {
    FileHelper::saveEmployee(e);
  }

  static void addAdmin(Admin a)
  {
    FileHelper::saveAdmin(a);
  }

  static void getAllClients() {
    FileHelper::getClients();
  }

  static void getAllEmployees() {
    FileHelper::getEmployees();
  }

  static void getAllAdmins() {
    FileHelper::getAdmins();
  }

  static void getData() {
    getAllClients();
    getAllEmployees();
    getAllAdmins();
  }

  static void saveData() {
    FileHelper::saveAllEmployees();
    FileHelper::saveAllClients();
    FileHelper::saveAllAdmins();
  }
  
};