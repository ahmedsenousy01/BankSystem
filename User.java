public class User {
    // attributes
    private String name;
    protected int id;

    // setters
    void set_name(String name) {
        for(int i = 0; i < name.length(); i++) {
            if(Character.isDigit(name.toCharArray()[i])) {
                System.out.println("please enter alphabetic characters only");
                return;
            }
        }
        if(name.length() < 5 || name.length() > 20) {
            System.out.println("please enter a name between 5 and 20 characters");
            return;
        }
        this.name = name;
    }

    // getters
    String get_name() {
        return this.name;
    }

    int get_id() {
        return this.id;
    }

}
