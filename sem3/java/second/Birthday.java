import java.util.Scanner;

class Birthdate {
    int day;
    int month;
    int year;

    public Birthdate(int d, int m, int y) throws Exception {
        boolean valid = false;
        if (y > 0) {
            if (m > 0 && m <= 12) {
                if (m % 2 == 1 || m == 7)   valid = d > 0 && d <= 31;
                else if (m == 2)            valid = (d > 0) && d <= (y % 4 == 0 ? 29 : 28);
                else                        valid = d > 0 && d <= 30;
            }
        }
        if (!valid) throw new Exception("Invalid date!");
        else {
            day = d;
            month = m;
            year = y;
        }
    }

    public void Print() {
        System.out.println("Birthdate: " + day + "-" + month + "-" + year);
        
    }
}

public class Birthday {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int d, m, y;
        System.out.print("Enter the day: ");
        d = sc.nextInt();
        System.out.print("Enter the month: ");
        m = sc.nextInt();
        System.out.print("Enter the year: ");
        y = sc.nextInt();
        sc.close();
        try {
            Birthdate bd = new Birthdate(d, m, y);
            bd.Print();
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }
    }
}
