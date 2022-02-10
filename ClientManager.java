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
    
    boolean adminLogin(ArrayList<Admin> admins) {
        String attemptedUserName, attemptedPassword;
        try(Scanner sc = new Scanner(System.in)) {
            System.out.println("Enter username:");
            attemptedUserName = sc.nextLine();
            System.out.println("Enter pin code:");
            attemptedPassword = sc.nextLine();
            
            for(int i = 0; i < admins.size(); i++) {
                if(admins.get(i).get_name() == attemptedUserName) {
                    if(admins.get(i).get_password() == attemptedPassword) {
                        return true;
                    }
                }
            }
            return false;
        }
    }
    
    boolean employeeLogin(ArrayList<Employee> employees) {
        String attemptedUserName, attemptedPassword;
        try(Scanner sc = new Scanner(System.in)) {
            System.out.println("Enter username:");
            attemptedUserName = sc.nextLine();
            System.out.println("Enter pin code:");
            attemptedPassword = sc.nextLine();
            
            for(int i = 0; i < employees.size(); i++) {
                if(employees.get(i).get_name() == attemptedUserName) {
                    if(employees.get(i).get_password() == attemptedPassword) {
                        return true;
                    }
                }
            }
            return false;
        }
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
        
    }
    
    void printEmployeeMenu() {

    }
    
    void printAdminMenu() {

    }

}
