import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;

public class FileManager implements DataSource{

    private ArrayList<Client> clients = new ArrayList<>();
    private ArrayList<Admin> admins = new ArrayList<>();
    private ArrayList<Employee> employees = new ArrayList<>();

    

    public ArrayList<Client> getAllClients() {
        try {
            FileReader fr = new FileReader("client.txt");
            BufferedReader br = new BufferedReader(fr);
            String line;

            while((line = br.readLine()) != null) {
                Client client = new Client(line, br.readLine(), Double.parseDouble(br.readLine()));
                clients.add(client);
            }

            br.close();
        } catch(IOException e) {
            e.printStackTrace();
        }
        return clients;  
    }

    public ArrayList<Admin> getAllAdmins() {
        try{
            FileReader fr = new FileReader("admin.txt");
            BufferedReader br = new BufferedReader(fr);
            String line;

            while((line = br.readLine()) != null) {
                Admin admin = new Admin(line, br.readLine(), Double.parseDouble(br.readLine()));
                admins.add(admin);
            }

            br.close();
        } catch(IOException e) {
            e.printStackTrace();
        }
        return admins;
    }

    public ArrayList<Employee> getAllEmployees() {
        try{
            FileReader fr = new FileReader("employee.txt");
            BufferedReader br = new BufferedReader(fr);
            String line;

            while((line = br.readLine()) != null) {
                Employee employee = new Employee(line, br.readLine(), Double.parseDouble(br.readLine()));
                employees.add(employee);
            }

            br.close();
        } catch(IOException e) {
            e.printStackTrace();
        }
        return employees;  
    }

    public void removeAllClients() {
        clients.clear();
    }

    public void removeAllAdmins() {
        admins.clear();
    }

    public void removeAllEmployees() {
        employees.clear();
    }

    void saveDataToFiles() {
        
    }

}
