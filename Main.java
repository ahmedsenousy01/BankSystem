public class Main {
    // TODO phase 2 part 3 (for file manager class to implement data resources interface)

    static FileManager fm = new FileManager();
    
    public static void main(String[] args) {

        

    }

    protected void finalize() {
        fm.saveDataToFiles();
    }
}