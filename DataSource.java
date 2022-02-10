import java.util.ArrayList;

public interface DataSource {

    ArrayList<Client> getAllClients(ArrayList<Client> clients);

    ArrayList<Employee> getAllEmployees(ArrayList<Employee> employees);
    
    ArrayList<Admin> getAllAdmins(ArrayList<Admin> admins);

    void removeAllClients(ArrayList<Client> clients);

    void removeAllEmployees(ArrayList<Employee> employees);
    
    void removeAllAdmins(ArrayList<Admin> admins);
}
