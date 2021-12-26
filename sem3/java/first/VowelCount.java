import java.util.Scanner;

public class VowelCount {
    private static int CountVowels(String str) {
        int count = 0;
        char[] arr = str.toUpperCase().toCharArray();
        for (int i = 0; i < str.length(); i++) {
            if (arr[i] == 'A' || arr[i] == 'E' || arr[i] == 'I' || arr[i] == 'O' || arr[i] == 'U')
                count++;
        }
        return count;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter a string:");
        String str = sc.nextLine();
        System.out.println("There are " + CountVowels(str) + " vowels in the string.");
        sc.close();
    }
}
