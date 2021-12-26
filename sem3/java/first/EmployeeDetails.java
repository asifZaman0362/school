import java.util.Scanner;

import second.Employee;

class Employee {
    public String firstName;
    public String lastName;
    public int yearsWithCompany;
    public float hourlyWage;

    public Employee(String pFirstName, String pLastName, int pYearsWithCompany, float pHourlyWage) {
        this.firstName = pFirstName;
        this.lastName = pLastName;
        this.yearsWithCompany = pYearsWithCompany;
        this.hourlyWage = pHourlyWage;
    }

    public void PrintEmployee() {
        System.out.println("Name: " + firstName + " " + lastName);
        System.out.println("Hourly Wage: " + hourlyWage);
    }
}

public class EmployeeDetails {
    public static void main(String[] args) {
        Employee[] employees = new Employee[100];
        int len;
        System.out.print("Enter the number of employees: ");
        Scanner sc = new Scanner(System.in);
        len = sc.nextInt();
        for (int i = 0; i < len; i++) {
            System.out.print("Enter the first name of the employee: ");
            employees[i].firstName = sc.nextLine();
            System.out.print("Enter the last name of the employee: ");
            employees[i].lastName = sc.nextLine();
            System.out.print("Enter the hourly wage: ");
            employees[i].hourlyWage = sc.nextFloat();
            System.out.print("Enter the years with the company: ");
            employees[i].yearsWithCompany = sc.nextInt();
        }
        System.out.println("The employees who have been 20 years or more with the company are:");
        for (int i = 0; i < len; i++) {
            if (employees[i].yearsWithCompany >= 20) employees[i].PrintEmployee();
        }
        sc.close();
    }
}
