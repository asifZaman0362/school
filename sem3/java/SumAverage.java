import java.util.Scanner;

public class SumAverage {

    private static int Sum(int x, int y, int z) {
        return x + y + z;
    }

    private static float Average(int x, int y, int z) {
        return (float)Sum(x, y, z) / 3;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n1, n2, n3;
        System.out.print("Enter the first number: ");
        n1 = sc.nextInt();
        System.out.print("Enter the second number: ");
        n2 = sc.nextInt();
        System.out.print("Enter the third number: ");
        n3 = sc.nextInt();
        System.out.println("The sum of the numbers is : " + Sum(n1, n2, n3));
        System.out.println("The average of the numbers is : " + Average(n1, n2, n3));
        sc.close();
    }
}
