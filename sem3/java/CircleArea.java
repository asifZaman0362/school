import java.util.Scanner;

class Circle {
    double radius;
    final double pi = 3.1415926;

    public Circle(int radius) {
        this.radius = radius;
    }

    public Circle(double radius) {
        this.radius = radius;
    }

    public double CalArea() {
        return pi * radius * radius;
    }
}

public class CircleArea {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the integer radius: ");
        int intRad = sc.nextInt();
        System.out.print("Enter the double radius: ");
        double dubRad = sc.nextDouble();
        Circle c1 = new Circle(intRad), c2 = new Circle(dubRad);
        System.out.println("Area of the circle with integer radius : " + c1.CalArea());
        System.out.println("Area of the circle with double radius : " + c2.CalArea());
        sc.close();
    }
}
