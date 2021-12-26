package second;
import java.util.Scanner;

class Employee {
    String department;

    public Employee() {
        department = "not assigned";
    }

    public Employee(String pDepartment) {
        department = pDepartment;
    }

    public void Print() {
        System.out.println("Department: " + department);
    }
}

public class EmployeeDept {
    public static void main(String[] args) {
        String dpt;
        Employee e;
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter department: ");
        dpt = sc.nextLine();
        if (dpt.isEmpty()) e = new Employee();
        else e = new Employee(dpt);
        e.Print();
        sc.close();
    }
}
