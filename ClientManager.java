import java.util.Scanner;

public class ClientManager {

    int printStartingMenu() {
        try (Scanner sc = new Scanner(System.in)) {
            System.out.println("Welcome!\nLogin as:\n1-Admin\n2-Client\n3-Employee");
            return sc.nextInt();
        }
    }

    void loginOrSignUp() {
        switch(printStartingMenu()) {
            case 1:
                adminLogin();
                break;
            case 2:
                clientLogin();
                break;
            case 3:
                employeeLogin();
                break;
        }
    }

    boolean clientLogin() {

        return true;

    }
    
    boolean adminLogin() {

        return true;

    }
    
    boolean employeeLogin() {

        return true;

    }
    
    void printClientMenu() {
        
    }
    
    void printEmployeeMenu() {

    }
    
    void printAdminMenu() {

    }

}
