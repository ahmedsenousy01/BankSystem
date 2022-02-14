import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    //TODO logout func and check on the transfer balance mechanism (client module)
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
        System.out.println("Enter pin code or password:");
        attemptedPinCode = sc.next();
        
        switch(loginMenuNumber) {
            case 1:
                Admin currAdmin = null;
                if(cm.adminLogin(admins, attemptedUserName, attemptedPinCode, currAdmin)) {
                    cm.printAdminMenu();
                } else {

                }
                break;
            case 2:
                Client currClient = new Client();
                int choice;
                if(cm.clientLogin(clients, attemptedUserName, attemptedPinCode,currClient)) {
                    cm.printClientMenu();
                    choice = sc.nextInt();
                    switch(choice) {
                        case 1:
                            Double depositedAmount;
                            System.out.println("Enter the amount you want to deposite:");
                            depositedAmount = sc.nextDouble();
                            currClient.deposite(depositedAmount);
                            break;
                        case 2:
                            Double withdrawalAmount;
                            System.out.println("Enter the amount you want to withdraw:");
                            withdrawalAmount = sc.nextDouble();
                            currClient.withdraw(withdrawalAmount);
                            break;
                        case 3:
                            Client receivingClient = new Client();
                            int receivingClientId;
                            Double transferAmount;
                            System.out.println("Enter the ID of the client you want to transfer to:");
                            receivingClientId = sc.nextInt();
                            receivingClient = cm.searchForClientById(receivingClientId, clients);
                            System.out.println("Enter the amount you want to transfer:");
                            transferAmount = sc.nextDouble();
                            currClient.transferTo(receivingClient, transferAmount);
                            break;
                        case 4:
                            System.out.println("Your balance is: " + currClient.get_balance());
                            break;
                        case 5:
                            currClient.logout();
                            break;
                    }
                    System.out.println("done");
                } else {
                    System.out.println("Invalid Login Data");
                }
                break;
            case 3: 
                Employee currEmployee = null;
                if(cm.employeeLogin(employees , attemptedUserName, attemptedPinCode, currEmployee)) {
                    cm.printEmployeeMenu();
                } else {

                }
                break;
        }

        sc.close();
    }
}