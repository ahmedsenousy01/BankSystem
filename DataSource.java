import java.util.ArrayList;

public interface DataSource {

    ArrayList<Client> getAllClients();

    ArrayList<Employee> getAllEmployees();
    
    ArrayList<Admin> getAllAdmins();

    void removeAllClients();

    void removeAllEmployees();
    
    void removeAllAdmins();
}
