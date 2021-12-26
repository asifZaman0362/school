package first;
class Employee {
    public String name;
    public int joiningYear;
    public String block;
    public String street;

    public Employee(String pName, int pJoiningYear, String pBlock, String pStreet) {
        name = pName;
        joiningYear = pJoiningYear;
        block = pBlock;
        street = pStreet;
    }
}

public class EmployeePrint {
    public static void main(String[] args) {
        Employee[] employees = {
            new Employee("Robert", 1994, "64C", "Walls Street"),
            new Employee("Sam", 2000, "68D", "Walls Street"),
            new Employee("John", 1999, "26B", "Walls Street")
        };
        System.out.println("Name\tJoining year\tAddress");
        System.out.println("-----------------------------------------");
        for (int i = 0; i < 3; i++) {
            System.out.println(employees[i].name + "\t" + employees[i].joiningYear + "\t\t" + employees[i].block + "-" + employees[i].street);
        }
    }
}
