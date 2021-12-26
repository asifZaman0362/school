import java.util.Scanner;

abstract class Employee {
    int Emp_code;
    long Ph_no;
    float basicPay = 0;
    
    String Emp_name;
    String Address;
    
    static final float da = 0.1f;
    static final float hra = 0.2f;

    Employee(int c, long p, float bp, String n, String a) {
        Emp_code = c;
        Ph_no = p;
        basicPay = bp;
        Emp_name = n;
        Address = a;
    }

    float CalculateSalary() {
        return basicPay + basicPay * (da + hra);
    }

    public void Print() {
        System.out.println("Employee Information---------");
        System.out.println("Name: " + Emp_name);
        System.out.println("Address: " + Address);
        System.out.println("Phone: " + Ph_no);
        System.out.println("Code: " + Emp_code);
        System.out.println("Salary: Rs." + CalculateSalary());
    }
}

class Manager extends Employee {
    public Manager(int code, long phone, String name, String addr) {
        super(code, phone, 120000, name, addr);
    }
}

class Typist extends Employee {
    public Typist(int code, long phone, String name, String addr) {
        super(code, phone, 42000, name, addr);
    }
}

class Officer extends Employee {
    public Officer(int code, long phone, String name, String addr) {
        super(code, phone, 75000, name, addr);
    }
}

public class OfficeSalary {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter employee code: ");
        int code = sc.nextInt();
        sc.nextLine();
        System.out.print("Enter employee name: ");
        String name = sc.nextLine();
        System.out.print("Enter employee address: ");
        String addr = sc.nextLine();
        System.out.print("Enter employee phone: ");
        long phone = sc.nextLong();
        Manager m = new Manager(code, phone, name, addr);
        m.Print();
    }
}
