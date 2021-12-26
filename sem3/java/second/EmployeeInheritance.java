package second;
import java.util.Scanner;

class Person {
    String name;
    int age;
    String address;

    public void PrintInfo() {
        System.out.println("Name: " + name);
        System.out.println("Age: " + age);
        System.out.println("Address: " + address);
    }

    public void GetInfo(Scanner sc) {
        System.out.println("Enter name: ");
        this.name = sc.nextLine();
        System.out.println("Enter address: ");
        this.address = sc.nextLine();
        System.out.println("Enter age: ");
        this.age = sc.nextInt();
        sc.nextLine();
    }

}

class Employee extends Person {
    int employeeId;
    String department;
    float salary;
    String position;

    public void GetInfo(Scanner sc) {
        super.GetInfo(sc);
        System.out.println("Enter employee department: ");
        this.department = sc.nextLine();
        System.out.println("Enter employee position: ");
        this.position = sc.nextLine();
        System.out.println("Enter employee id: ");
        this.employeeId = sc.nextInt();
        System.out.println("Enter employee salary: ");
        this.salary = sc.nextFloat();
        sc.nextLine();
    }

    public void PrintInfo() {
        super.PrintInfo();
        System.out.println("Employee ID: " + employeeId);
        System.out.println("Department: " + department);
        System.out.println("Salary: " + salary);
        System.out.println("Position: " + position);
    }
}

class Manager extends Employee {
    
    public void GetInfo(Scanner sc) {
        super.GetInfo(sc);
        this.salary = 250000;
        this.position = "Manager";
    }

}

public class EmployeeInheritance {
    public static void main(String[] args) {
        Manager e = new Manager();
        e.GetInfo(new Scanner(System.in));
        e.PrintInfo();
    }
}
