package second;
import java.util.Scanner;

class Data {
    int[] data;

    public Data() {
        data = new int[] { 0, 0, 0, 0, 0 };
    }

    public Data(int[] arr) {
        data = arr;
    }

    public void Sort() {
        int i = 0;
        Boolean sorted = false;
        while ((++i < 5) && !sorted) {
            sorted = true;
            for (int j = 0; j < 5 - i; j++) {
                if (data[j + 1] < data[j]) {
                    sorted = false;
                    int tmp = data[j];
                    data[j] = data[j + 1];
                    data[j + 1] = tmp;
                }
            }
        }
    }

    public void Display() {
        System.out.println("The data is:");
        for (int i = 0; i < 5; i++) {
            System.out.println(data[i]);
        }
    }
}

public class IntegerDataSort {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int[] arr = new int[5];
        System.out.println("Enter the numbers:");
        for (int i = 0; i < 5; i++) {
            arr[i] = sc.nextInt();
        }
        sc.close();
        Data dat = new Data(arr);
        dat.Sort();
        dat.Display();
    }
}
