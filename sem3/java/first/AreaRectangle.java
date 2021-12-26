package first;
import java.util.Scanner;

class Area {
    float length;
    float breadth;

    public Area(float pLength, float pBreadth) {
        this.length = pLength;
        this.breadth = pBreadth;
    }

    public float returnArea() {
        return length * breadth;
    }
}

public class AreaRectangle {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        float length, breadth;
        System.out.print("Enter the length: ");
        length = scanner.nextFloat();
        System.out.print("Enter the breadth: ");
        breadth = scanner.nextFloat();
        Area area = new Area(length, breadth);
        System.out.println("The area of the rectangle is " + area.returnArea() + " m2");
        scanner.close();
    }
}
