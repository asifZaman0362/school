import java.util.Scanner;

public class NumbersToWords {

    public static String GetWords(long number) {
        int length = 0;
        for (long x = number; x > 0; x /= 10) length++;

        String digitNames[] = { "Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", 
		                        "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen",
                                "Seventeen", "Eighteen", "Nineteen" };
	    String tens[] = { "", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety" };

        if (length >= 16) {
            return GetWords(number / 1000000000000000l) + " Quadrillion " + GetWords(number % 1000000000000000l);
        } else if (length >= 13) {
            return GetWords(number / 1000000000000l) + " Trillion " + GetWords(number % 1000000000000l);
        } else if (length >= 10) {
            return GetWords(number / 1000000000) + " Billion " + GetWords(number % 1000000000);
        } else if (length >= 7) {
            return GetWords(number / 1000000) + " Million " + GetWords(number % 1000000);
        } else if (length >= 4) {
            return GetWords(number / 1000) + " Thousand " + GetWords(number % 1000);
        } else if (length == 3) {
            return GetWords(number / 100) + " Hundred " + (number % 100 > 0 ? "and " + GetWords(number % 100) : "");
        } else if (length == 2) {
            if (number < 20) return digitNames[(int)number];
            else return tens[(int)number / 10] + ((int)number % 10 > 0 ? " " + digitNames[(int)number % 10] : "");
        } else if (length == 1) return digitNames[(int)number];
        else return "0";
    }

    public static void main(String[] args) {
        long number;
        Scanner sc = new Scanner(System.in);
        number = sc.nextLong();
        sc.close();
        System.out.println("The number in words is: " + GetWords(number));
    }
}