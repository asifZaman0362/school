package first;
import java.util.Scanner;

public class AreaTriangle {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the base of the triangle: ");
        float base = sc.nextFloat();
        System.out.print("Enter the height of the triangle: ");
        float height = sc.nextFloat();
        PrintArea(base, height);
        sc.close();
    }

    public static void PrintArea(float base, float height) {
        float area = 0.5f * base * height;
        System.out.println("The area of the triangle is = " + area);
    }
}
