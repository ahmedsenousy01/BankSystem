import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        
        Scanner sc = new Scanner(System.in);
        FileManager fm = new FileManager();
        ClientManager cm = new ClientManager();

        ArrayList<Client> clients = new ArrayList<>();
        ArrayList<Admin> admins = new ArrayList<>();
        ArrayList<Employee> employees = new ArrayList<>();

        fm.getAllClients(clients);
        fm.getAllAdmins(admins);
        fm.getAllEmployees(employees);

        
        int loginMenuNumber;
        String attemptedUserName, attemptedPinCode;

        cm.printStartingMenu();
        loginMenuNumber = sc.nextInt();
        
        System.out.println("Enter username:");
        attemptedUserName = sc.next();
        System.out.println("Enter pin code:");
        attemptedPinCode = sc.next();
        
        switch(loginMenuNumber) {
            case 1:
                cm.adminLogin(admins);
                break;
            case 2:
                Client currClient = null;
                //cm.clientLogin(clients, attemptedUserName, attemptedPinCode, currClient);
                if(cm.clientLogin(clients, attemptedUserName, attemptedPinCode,currClient)) {
                    cm.printClientMenu();
                    System.out.println("done");
                } else {
                    System.out.println("Invalid Login Data");
                }
                break;
            case 3:
                cm.employeeLogin(employees);
                break;
        }

        sc.close();
    }
}