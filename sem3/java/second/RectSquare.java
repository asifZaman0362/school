import java.util.Scanner;

class Rectangle {
    float length;
    float breadth;

    public Rectangle(float length, float breadth) {
        this.length = length;
        this.breadth = breadth;
    }

    public float GetArea() {
        return this.length * this.breadth;
    }

    public float GetPerimeter() {
        return 2 * (length + breadth);
    }
}

class Square extends Rectangle {

    public Square(float side) {
        super(side, side);
    }

}

public class RectSquare {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the side length of the square: ");
        Square square = new Square(sc.nextFloat());
        System.out.println("Area of the square = " + square.GetArea());
        System.out.println("Perimeter of the square = " + square.GetPerimeter());

        System.out.println("Enter the length of the rectangle: ");
        float l = sc.nextFloat();
        System.out.println("Enter the breadth of the rectangle: ");
        float b = sc.nextFloat();
        Rectangle rect = new Rectangle(l, b);
        System.out.println("Area of the rectangle = " + rect.GetArea());
        System.out.println("Perimeter of the rectangle = " + rect.GetPerimeter());
        
        sc.close();
    }
}
