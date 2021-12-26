import java.util.Scanner;

interface Sports {
    public static final int SportsWt = 10;
}

class Student {
    int Id;
    String Name;
    int[] Marks;

    public Student(int id, String name, int[] marks) {
        Id = id;
        Name = name;
        Marks = marks;
    }

    public void Display() {
        System.out.println("Name: " + Name);
        System.out.println("ID: " + Id);
    }
}

class Result extends Student implements Sports {
    public Result(int id, String name, int[] marks) {
        super(id, name, marks);
    }

    public float Total() {
        int sum = SportsWt;
        for (int i = 0; i < super.Marks.length; i++) {
            sum += super.Marks[i];
        }
        return sum;
    }

    public void Display() {
        System.out.println("Marks:--");
        super.Display();
        System.out.println("Total marks: " + Total());
    }
}

public class InterfaceSports {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter student name: ");
        String name = sc.nextLine();
        System.out.print("Enter student ID: ");
        int id = sc.nextInt();
        System.out.println("Enter student marks:");
        int[] marks = new int[5];
        for (int i = 0; i < 5; i++) {
            marks[i] = sc.nextInt();
        }
        Result res = new Result(id, name, marks);
        res.Display();
    }
}
