public class Employee extends User{
    //attributes
    private String password;
    private double salary;
    private static int employee_id = 1001;

    //setters
    void set_password(String password) {
        if(password.contains(" ")) {
            System.out.println("the password shouldn't contain whitespaces");
            return;
        }
        if(password.length() < 8 || password.length() > 20) {
            System.out.println("the password should be between 8 and 20 characters long");
            return;
        }
        this.password = password;
    }

    void set_salary(double salary) {
        if(salary < 5000) {
            System.out.println("the minimum salary should be 5000");
            return;
        }
        this.salary = salary;
    }


    // getters
    String get_password() {
        return this.password;
    }

    double get_salary() {
        return this.salary;
    }

    // more functions
    void display() {
        System.out.println("name : " + this.get_name());
        System.out.println("ID : " + this.get_id());
        System.out.println("balance : " + this.get_salary());
        System.out.println("password : " + this.get_password());
    }

    void addClient() {
        
    }

    void searchForClient() {

    }

    void editClient() {

    }
    
    void listClient() {

    }

    Employee(String name, String password, double salary) {
        super.set_name(name);
        this.set_password(password);
        this.set_salary(salary);
        super.id = employee_id;
        employee_id++;
    }
}
