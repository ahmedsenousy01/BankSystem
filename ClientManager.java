import java.io.BufferedReader;
import java.io.FileReader;
import java.util.ArrayList;
import java.util.Scanner;

public class ClientManager {

    FileManager fm = new FileManager();

    void printStartingMenu() {
            System.out.println("Welcome!\nLogin as:\n1-Admin\n2-Client\n3-Employee");
    }

    boolean clientLogin(ArrayList<Client> clients, String attemptedUserName, String attemptedPinCode, Client currClient) {
        for(int i = 0; i < clients.size(); i++) {
            if(clients.get(i).get_name().equals(attemptedUserName)) {
                if(clients.get(i).get_pin_code().equals(attemptedPinCode)) {
                    currClient = clients.get(i);
                    return true;
                }
            }
        }
        return false;
    }
    
    boolean adminLogin(ArrayList<Admin> admins, String attemptedUserName, String attemptedPassword, Admin currAdmin) {
        for(int i = 0; i < admins.size(); i++) {
            if(admins.get(i).get_name().equals(attemptedUserName)) {
                if(admins.get(i).get_password().equals(attemptedPassword)) {
                    currAdmin = admins.get(i);
                    return true;
                }
            }
        }
        return false;
    }
    
    boolean employeeLogin(ArrayList<Employee> employees, String attemptedUserName, String attemptedPassword, Employee currEmployee) {
        for(int i = 0; i < employees.size(); i++) {
            if(employees.get(i).get_name().equals(attemptedUserName)) {
                if(employees.get(i).get_password().equals(attemptedPassword)) {
                    currEmployee = employees.get(i);
                    return true;
                }
            }
        }
        return false;
    }

    void printMenu(int option) {
        switch(option) {
            case 1:
                printClientMenu();
                break;
            case 2:
                printAdminMenu();
                break;
            case 3:
                printEmployeeMenu();
                break;
        }
    }
    
    void printClientMenu() {
        System.out.println("Choose a number:\n1-Deposit\n2-Withdraw\n3-Transfer\n4-Check your balance\n5-Logout");
    }
    
    void printEmployeeMenu() {
        System.out.println("Choose a number:\n1-Add Client\n2-Search for Client by ID\n3-List all Clients\n4-Display your Info\n5-Logout");
    }
    
    void printAdminMenu() {
        System.out.println("Choose a number:\n1-Add Employee\n2-Search for Employee by ID\n3-List all Employees\n4-Display your Info\n5-Add Client\n6-Search for Client by ID\n7-List all Clients\n8-Logout");
    }

}
