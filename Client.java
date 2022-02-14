public class Client extends User{
    // attributes
    private String pin_code;
    private double balance;
    private static int client_id = 2001;

    // setters
    void set_pin_code(String pin_code) {
        for(int i = 0; i < pin_code.length(); i++) {
            if(!(Character.isDigit(pin_code.toCharArray()[i]))) {
                System.out.println("your pin code must be digits only");
                return;
            }
        }
        if(pin_code.length() != 4) {
            System.out.println("your pin code must be 4 digits only");
            return;
        }
        this.pin_code = pin_code;
    }

    void set_balance(double balance) {
        if(balance < 1500) {
            System.out.println("minimum balance should be 1500");
            return;
        }
        this.balance = balance;
    }

    // getters
    String get_pin_code() {
        return pin_code;
    }

    double get_balance() {
        return this.balance;
    }

    // more functions
    void display() {
        System.out.println("name : " + this.get_name());
        System.out.println("ID : " + this.get_id());
        System.out.println("balance : " + this.get_balance());
        System.out.println("pin code : " + this.get_pin_code());
    }

    void deposite(Double depositedAmount) {
        this.set_balance((balance + depositedAmount));
    }

    void withdraw(Double withdrawalAmount) {
        this.set_balance(balance - withdrawalAmount);
    }

    void transferTo(Client receivingClient, Double transferAmount) {
        this.set_balance(balance - transferAmount);
        receivingClient.set_balance(balance + transferAmount);
    }

    void logout() {

    }

    Client(String name, String pin_code, double balance) {
        super.set_name(name);
        this.set_pin_code(pin_code);
        this.set_balance(balance);
        super.id = client_id;
        client_id++;
    }

    Client(){}
}
