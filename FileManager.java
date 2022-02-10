import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;

public class FileManager implements DataSource{    

    public ArrayList<Client> getAllClients(ArrayList<Client> clients) {
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

    public ArrayList<Admin> getAllAdmins(ArrayList<Admin> admins) {
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

    public ArrayList<Employee> getAllEmployees(ArrayList<Employee> employees) {
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

    public void removeAllClients(ArrayList<Client> clients) {
        clients.clear();
    }

    public void removeAllAdmins(ArrayList<Admin> admins) {
        admins.clear();
    }

    public void removeAllEmployees(ArrayList<Employee> employees) {
        employees.clear();
    }

    void saveDataToFiles() {
        
    }

}
