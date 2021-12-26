package first;
import java.util.Scanner;

class Employee {
    public float workHoursPerDay;
    public float salary;

    public void getInfo(Scanner sc) {
        System.out.print("Enter the hours of work per day: ");
        workHoursPerDay = sc.nextFloat();
        System.out.print("Enter the salary: ");
        salary = sc.nextFloat();
    }

    public void addSal() {
        if (salary < 5000) {
            salary += 1000;
            System.out.println("Added Rs. 1000 to salary");
        }
    }

    public void addWork() {
        if (workHoursPerDay >= 6) {
            salary += 500;
            System.out.println("Added bonus Rs. 500 for more working hours.");
        }
    }
}

public class EmployeeInfo {
    public static void main(String[] args) {
        Employee emp = new Employee();
        Scanner sc = new Scanner(System.in);
        emp.getInfo(sc);
        emp.addSal();
        emp.addWork();
        System.out.println("The final salary of the employee is Rs. " + emp.salary);
        sc.close();
    }
}
