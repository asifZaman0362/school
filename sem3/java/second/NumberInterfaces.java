import java.util.Scanner;

interface Number {
    public Boolean Check();
}

class Pallindrome implements Number {
    int number;

    public Pallindrome(int number) {
        this.number = number;
    }

    @Override
    public Boolean Check() {
        int reverse = 0;
        for (int x = number; x > 0; x /= 10)
            reverse = (reverse * 10) + (x % 10);
        return number == reverse;
    }
}

class Parity implements Number {
    int number;

    public Parity(int number) {
        this.number = number;
    }

    @Override
    public Boolean Check() {
        return (number % 2 == 0);
    }
}

public class NumberInterfaces {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter a number: ");
        int num = sc.nextInt();
        Parity parity = new Parity(num);
        Pallindrome pallindrome = new Pallindrome(num);
        System.out.println("The number is " + (parity.Check() ? "even" : "odd"));
        System.out.println("The number is" + (pallindrome.Check() ? " " : " not ") + "a pallindrome");
        sc.close();
    }
}
