package first;
import java.util.Scanner;

public class DigitSum {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter a number: ");
        int number = sc.nextInt(), sum = 0;
        for (int x = number; x > 0; x /= 10) {
            sum += x % 10;
        }
        System.out.println("The sum of the digits in " + number + " = " + sum);
        sc.close();
    }
}
